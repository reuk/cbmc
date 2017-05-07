/*******************************************************************\

Module: Function Inlining

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <cassert>

#include <util/base_type.h>
#include <util/cprover_prefix.h>
#include <util/prefix.h>
#include <util/std_code.h>
#include <util/std_expr.h>

#include "goto_inline.h"
#include "goto_inline_class.h"
#include "remove_skip.h"

/*******************************************************************\

Function: goto_inline

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void goto_inline(goto_modelt &goto_model, message_handlert &message_handler,
                 bool adjust_function) {
  const namespacet ns(goto_model.symbol_table);
  goto_inline(goto_model.goto_functions, ns, message_handler, adjust_function);
}

/*******************************************************************\

Function: goto_inline

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void goto_inline(goto_functionst &goto_functions, const namespacet &ns,
                 message_handlert &message_handler, bool adjust_function) {
  goto_inlinet goto_inline(goto_functions, ns, message_handler,
                           adjust_function);

  typedef goto_functionst::goto_functiont goto_functiont;

  // find entry point
  goto_functionst::function_mapt::iterator it =
      goto_functions.function_map.find(goto_functionst::entry_point());

  if (it == goto_functions.function_map.end())
    return;

  goto_functiont &goto_function = it->second;
  assert(goto_function.body_available());

  // gather all calls
  // we use non-transitive inlining to avoid the goto program
  // copying that goto_inlinet would do otherwise
  goto_inlinet::inline_mapt inline_map;

  Forall_goto_functions(f_it, goto_functions) {
    goto_functiont &goto_function = f_it->second;

    if (!goto_function.body_available())
      continue;

    goto_inlinet::call_listt &call_list = inline_map[f_it->first];

    goto_programt &goto_program = goto_function.body;

    Forall_goto_program_instructions(i_it, goto_program) {
      if (!goto_inlinet::is_call(i_it))
        continue;

      call_list.push_back(goto_inlinet::callt(i_it, false));
    }
  }

  goto_inline.goto_inline(goto_functionst::entry_point(), goto_function,
                          inline_map, true);

  // clean up
  Forall_goto_functions(f_it, goto_functions) {
    if (f_it->first != goto_functionst::entry_point()) {
      goto_functiont &goto_function = f_it->second;
      goto_function.body.clear();
    }
  }
}

/*******************************************************************\

Function: goto_partial_inline

  Inputs:
    goto_model:
      Source of the symbol table and function map to use.
    message_handler:
      Message handler used by goto_inlinet.
    smallfunc_limit:
      The maximum number of instructions in functions to be inlined.
    adjust_function:
      Tell goto_inlinet to adjust function.

 Outputs:

 Purpose:
    Inline all function calls to functions either marked as "inlined" or
    smaller than smallfunc_limit (by instruction count).

\*******************************************************************/

void goto_partial_inline(goto_modelt &goto_model,
                         message_handlert &message_handler,
                         unsigned smallfunc_limit, bool adjust_function) {
  const namespacet ns(goto_model.symbol_table);
  goto_partial_inline(goto_model.goto_functions, ns, message_handler,
                      smallfunc_limit, adjust_function);
}

/*******************************************************************\

Function: goto_partial_inline

  Inputs:
    goto_functions:
      The function map to use to find functions containing calls and function
      bodies.
    ns:
      Namespace used by goto_inlinet.
    message_handler:
      Message handler used by goto_inlinet.
    smallfunc_limit:
      The maximum number of instructions in functions to be inlined.
    adjust_function:
      Tell goto_inlinet to adjust function.

 Outputs:

 Purpose:
    Inline all function calls to functions either marked as "inlined" or
    smaller than smallfunc_limit (by instruction count).

\*******************************************************************/

void goto_partial_inline(goto_functionst &goto_functions, const namespacet &ns,
                         message_handlert &message_handler,
                         unsigned smallfunc_limit, bool adjust_function) {
  goto_inlinet goto_inline(goto_functions, ns, message_handler,
                           adjust_function);

  typedef goto_functionst::goto_functiont goto_functiont;

  // gather all calls
  goto_inlinet::inline_mapt inline_map;

  Forall_goto_functions(f_it, goto_functions) {
    goto_functiont &goto_function = f_it->second;

    if (!goto_function.body_available())
      continue;

    if (f_it->first == goto_functions.entry_point())
      // Don't inline any function calls made from the _start function.
      continue;

    goto_programt &goto_program = goto_function.body;

    goto_inlinet::call_listt &call_list = inline_map[f_it->first];

    Forall_goto_program_instructions(i_it, goto_program) {
      if (!goto_inlinet::is_call(i_it))
        continue;

      exprt lhs;
      exprt function_expr;
      exprt::operandst arguments;
      exprt constrain;
      goto_inlinet::get_call(i_it, lhs, function_expr, arguments, constrain);

      if (function_expr.id() != ID_symbol)
        // Can't handle pointers to functions
        continue;

      const symbol_exprt &symbol_expr = to_symbol_expr(function_expr);
      const irep_idt id = symbol_expr.get_identifier();

      goto_functionst::function_mapt::const_iterator f_it =
          goto_functions.function_map.find(id);

      if (f_it == goto_functions.function_map.end())
        // Function not loaded, can't check size
        continue;

      // called function
      const goto_functiont &goto_function = f_it->second;

      if (!goto_function.body_available())
        // The bodies of functions that don't have bodies can't be inlined.
        continue;

      const goto_programt &goto_program = goto_function.body;

      if (goto_function.is_inlined() ||
          goto_program.instructions.size() <= smallfunc_limit) {
        assert(goto_inlinet::is_call(i_it));
        call_list.push_back(goto_inlinet::callt(i_it, false));
      }
    }
  }

  goto_inline.goto_inline(inline_map, false);
}

/*******************************************************************\

Function: goto_function_inline

  Inputs:
    goto_model: Source of the symbol table and function map to use.
    function: The function whose calls to inline.
    message_handler: Message handler used by goto_inlinet.
    adjust_function: Tell goto_inlinet to adjust function.
    caching: Tell goto_inlinet to cache.

 Outputs:

 Purpose:
    Inline all function calls made from a particular function

\*******************************************************************/

void goto_function_inline(goto_modelt &goto_model, const irep_idt function,
                          message_handlert &message_handler,
                          bool adjust_function, bool caching) {
  const namespacet ns(goto_model.symbol_table);
  goto_function_inline(goto_model.goto_functions, function, ns, message_handler,
                       adjust_function, caching);
}

/*******************************************************************\

Function: goto_function_inline

  Inputs:
    goto_functions: The function map to use to find function bodies.
    function: The function whose calls to inline.
    ns: Namespace used by goto_inlinet.
    message_handler: Message handler used by goto_inlinet.
    adjust_function: Tell goto_inlinet to adjust function.
    caching: Tell goto_inlinet to cache.

 Outputs:

 Purpose:
    Inline all function calls made from a particular function

\*******************************************************************/

void goto_function_inline(goto_functionst &goto_functions,
                          const irep_idt function, const namespacet &ns,
                          message_handlert &message_handler,
                          bool adjust_function, bool caching) {
  goto_inlinet goto_inline(goto_functions, ns, message_handler, adjust_function,
                           caching);

  goto_functionst::function_mapt::iterator f_it =
      goto_functions.function_map.find(function);

  if (f_it == goto_functions.function_map.end())
    return;

  goto_functionst::goto_functiont &goto_function = f_it->second;

  if (!goto_function.body_available())
    return;

  // gather all calls
  goto_inlinet::inline_mapt inline_map;

  goto_inlinet::call_listt &call_list = inline_map[f_it->first];

  goto_programt &goto_program = goto_function.body;

  Forall_goto_program_instructions(i_it, goto_program) {
    if (!goto_inlinet::is_call(i_it))
      continue;

    call_list.push_back(goto_inlinet::callt(i_it, true));
  }

  goto_inline.goto_inline(function, goto_function, inline_map, true);
}

/*******************************************************************\

Function: goto_function_inline_and_log

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

jsont goto_function_inline_and_log(goto_functionst &goto_functions,
                                   const irep_idt function,
                                   const namespacet &ns,
                                   message_handlert &message_handler,
                                   bool adjust_function, bool caching) {
  goto_inlinet goto_inline(goto_functions, ns, message_handler, adjust_function,
                           caching);

  goto_functionst::function_mapt::iterator f_it =
      goto_functions.function_map.find(function);

  if (f_it == goto_functions.function_map.end())
    return jsont();

  goto_functionst::goto_functiont &goto_function = f_it->second;

  if (!goto_function.body_available())
    return jsont();

  // gather all calls
  goto_inlinet::inline_mapt inline_map;

  // create empty call list
  goto_inlinet::call_listt &call_list = inline_map[f_it->first];

  goto_programt &goto_program = goto_function.body;

  Forall_goto_program_instructions(i_it, goto_program) {
    if (!goto_inlinet::is_call(i_it))
      continue;

    call_list.push_back(goto_inlinet::callt(i_it, true));
  }

  goto_inline.goto_inline(function, goto_function, inline_map, true);
  goto_functions.update();
  goto_functions.compute_loop_numbers();

  return goto_inline.output_inline_log_json();
}
