/*******************************************************************\

Module: Remove Java Nondet expressions

Author: Reuben Thomas, reuben.thomas@diffblue.com

\*******************************************************************/

#include "goto-programs/remove_java_nondet.h"
#include "goto-programs/goto_convert.h"
#include "goto-programs/goto_model.h"

#include "java_bytecode/java_object_factory.h"

#include "util/irep_ids.h"

#include <algorithm>
#include <regex>

/*******************************************************************\

  Struct: nondet_instruction_infot

 Purpose: Hold information about a nondet instruction invocation.

\*******************************************************************/

struct nondet_instruction_infot final
{
  bool is_nondet_instruction;
  bool is_never_null;
};

/*******************************************************************\

Function: is_nondet_returning_object

  Inputs:
    function_call: A function call expression.

 Outputs: Whether the function has a nondet signature, and whether the nondet
          item may be null.


 Purpose: Find whether the supplied function call has a recognised 'nondet'
          library signature.  If so, specify whether the function call is
          expected to return non-null.

\*******************************************************************/

static nondet_instruction_infot is_nondet_returning_object(
  const code_function_callt &function_call)
{
  const auto function_name=
    id2string(function_call.function().get(ID_identifier));
  std::smatch match_results;
  if(!std::regex_match(
       function_name,
       match_results,
       std::regex(".*org\\.cprover\\.CProver\\.nondetWith(out)?Null.*")))
  {
    return {false, false};
  }

  return {true, match_results[1].matched};
}

/*******************************************************************\

Function: get_nondet_instruction_info

  Inputs:
    instr: A goto program instruction.

 Outputs: Whether the instruction is a function with a nondet signautre, and
          whether the nondet item may be null.

 Purpose: Return whether the instruction has a recognised 'nondet' library
          signature.

\*******************************************************************/

static nondet_instruction_infot get_nondet_instruction_info(
  const goto_programt::targett &instr)
{
  if(!(instr->is_function_call() && instr->code.id()==ID_code))
  {
    return {false, false};
  }
  const auto &code=to_code(instr->code);
  if(code.get(ID_statement)!=ID_function_call)
  {
    return {false, false};
  }
  const auto &function_call=to_code_function_call(code);
  return is_nondet_returning_object(function_call);
}

// TODO Pascal suggested moving the following function to util, but I'm not
// sure.  If goto_programt has public data members, this implies that any state
// that these data members takes is valid for the goto_program as a whole,
// which is obviously not the case - if I insert a node into
// goto_programt::instructions without updating the iterator positions, this
// has a good chance of invalidating the program.  It should be *impossible* to
// place an object (with the strong exception safety guarantee) into an invalid
// state using its public interface.  Therefore, I suggest that the data
// members of goto_programt be made private, and that this function becomes a
// public member function on goto_programt.

/*******************************************************************\

Function: insert_before

  Inputs:
    target: A list of goto program instructions which will be modified.
    pos: The instruction before which further instructions should be inserted.
    instrs: A new list of instructions to insert.

 Outputs: An iterator past the end of the inserted range.

 Purpose: Return whether the instr is an assignment from the variable with
          identifier identifier. This function is required (as opposed to a
          standard insert) because the goto program instructions must be
          updated after insertion to maintain goto program invariants.

\*******************************************************************/

static goto_programt::targett insert_before(
  goto_programt::instructionst &target,
  const goto_programt::targett &pos,
  const goto_programt::instructionst &instrs)
{
  // Store the instruction before the newly-inserted range.
  assert(pos!=std::begin(instrs));
  const auto prev=std::prev(pos);

  std::map<goto_programt::const_targett, goto_programt::targett> target_map;
  for(auto it=instrs.begin(), instr_end=instrs.end();
      it!=instr_end;
      ++it)
  {
    const auto p=target_map[it]=
      target.insert(pos, goto_programt::instructiont());
    *p=*it;
  }

  for(auto i=std::next(prev); i!=pos; ++i)
  {
    for(auto &t : i->targets)
    {
      const auto new_target=target_map.find(t);
      assert(new_target!=std::end(target_map));
      t=new_target->second;
    }
  }

  return pos;
}

/*******************************************************************\

Function: is_symbol_with_id

  Inputs:
    expr: The expression which may be a symbol.
    identifier: Some identifier.

 Outputs: True if the expression is a symbol with the specified identifier.

 Purpose: Return whether the expression is a symbol with the specified
          identifier.

\*******************************************************************/

static bool is_symbol_with_id(const exprt& expr, const dstringt& identifier)
{
  return expr.id()==ID_symbol && expr.get(ID_identifier)==identifier;
}

/*******************************************************************\

Function: is_typecast_with_id

  Inputs:
    expr: The expression which may be a typecast.
    identifier: Some identifier.

 Outputs: True if the expression is a typecast with one operand, and the
          typecast's identifier matches the specified identifier.

 Purpose: Return whether the expression is a typecast with the specified
          identifier.

\*******************************************************************/

static bool is_typecast_with_id(const exprt& expr, const dstringt& identifier)
{
  if(!(expr.id()==ID_typecast && expr.operands().size()==1))
  {
    return false;
  }
  const auto &typecast=to_typecast_expr(expr);
  // Return whether the typecast has the expected operand
  return typecast.op().get(ID_identifier)==identifier;
}

/*******************************************************************\

Function: is_assignment_from

  Inputs:
    instr: A goto program instruction.
    identifier: Some identifier.

 Outputs: True if the expression is a typecast with one operand, and the
          typecast's identifier matches the specified identifier.

 Purpose: Return whether the instruction is an assignment, and the rhs is a
          symbol or typecast expression with the specified identifier.

\*******************************************************************/

static bool is_assignment_from(
  const goto_programt::instructiont &instr,
  const dstringt &identifier)
{
  // If not an assignment, return false
  if(!instr.is_assign())
  {
    return false;
  }
  const auto &rhs=to_code_assign(instr.code).rhs();
  return is_symbol_with_id(rhs, identifier) ||
         is_typecast_with_id(rhs, identifier);
}

/*******************************************************************\

Function: process_target

  Inputs:
    message_handler: Handles logging.
    symbol_table: The table of known symbols.
    max_nondet_array_length: Max length of arrays in new nondet objects.
    instructions: The list of all instructions.
    instr: The instruction to check.

 Outputs: The next instruction to process, probably with this function.

 Purpose: Given an iterator into a list of instructions, modify the list to
          replace 'nondet' library functions with CBMC-native nondet
          expressions, and return an iterator to the next instruction to check.

\*******************************************************************/

static goto_programt::targett process_target(
  message_handlert &message_handler,
  symbol_tablet &symbol_table,
  const size_t max_nondet_array_length,
  goto_programt::instructionst &instructions,
  const goto_programt::targett &instr)
{
  // Check whether this is our nondet library method, and return if not
  const auto instr_info=get_nondet_instruction_info(instr);
  if(!instr_info.is_nondet_instruction)
  {
    return std::next(instr);
  }

  // Look at the next instruction, ensure that it is an assignment
  const auto next_instr=std::next(instr, 1);
  assert(next_instr->is_assign());
  // Get the name of the LHS of the assignment
  const auto return_identifier=
    to_code_assign(next_instr->code).lhs().get(ID_identifier);

  const auto end=std::end(instructions);

  // Look for an instruction where this name is on the RHS of an assignment
  const auto matching_assignment=std::find_if(
      next_instr,
      end,
      [&return_identifier](const goto_programt::instructiont &instr)
      {
        return is_assignment_from(instr, return_identifier);
      });

  assert(matching_assignment!=end);

  // Assume that the LHS of *this* assignment is the actual nondet variable
  const auto &code_assign=to_code_assign(matching_assignment->code);
  const auto nondet_var=code_assign.lhs();
  const auto source_loc=instr->source_location;

  // Erase from the nondet function call to the assignment
  const auto after_matching_assignment=std::next(matching_assignment);
  assert(after_matching_assignment!=end);
  const auto after_erased=
    instructions.erase(instr, after_matching_assignment);

  // Generate nondet init code
  code_blockt init_code;
  gen_nondet_init(
    nondet_var,
    init_code,
    symbol_table,
    source_loc,
    false,
    true,
    instr_info.is_never_null,
    message_handler,
    max_nondet_array_length);

  // Convert this code into goto instructions
  goto_programt new_instructions;
  goto_convert(init_code, symbol_table, new_instructions, message_handler);

  // Insert the new instructions into the instruction list
  return insert_before(
    instructions,
    after_erased,
    new_instructions.instructions);
}

/*******************************************************************\

Function: remove_java_nondet

  Inputs:
    message_handler: Object which prints messages.
    symbol_table: The list of known symbols.
    max_nondet_array_length: The maximum length of new nondet arrays.
    goto_program: The program to modify.

 Purpose: Modify a goto_programt to replace 'nondet' library functions with
          CBMC-native nondet expressions.

\*******************************************************************/

static void remove_java_nondet(
  message_handlert &message_handler,
  symbol_tablet &symbol_table,
  const size_t max_nondet_array_length,
  goto_programt &goto_program)
{
  // Check each instruction.
  // `process_target` may modify the list in place, and returns the next
  // iterator to look at.
  for(auto instruction_iterator=std::begin(goto_program.instructions),
        end=std::end(goto_program.instructions);
      instruction_iterator!=end;
      instruction_iterator=process_target(
        message_handler,
        symbol_table,
        max_nondet_array_length,
        goto_program.instructions,
        instruction_iterator))
  {
    // Loop body deliberately empty.
  }
}

void remove_java_nondet(
  message_handlert &message_handler,
  symbol_tablet &symbol_table,
  const size_t max_nondet_array_length,
  goto_functionst &goto_functions)
{
  for(auto &f : goto_functions.function_map)
  {
    remove_java_nondet(
      message_handler,
      symbol_table,
      max_nondet_array_length,
      f.second.body);
  }
  goto_functions.compute_location_numbers();
}
