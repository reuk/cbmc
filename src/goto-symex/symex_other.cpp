/*******************************************************************\

Module: Symbolic Execution

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <cassert>

#include <util/arith_tools.h>
#include <util/base_type.h>
#include <util/byte_operators.h>
#include <util/rename.h>
#include <util/std_expr.h>

#include <ansi-c/c_types.h>

#include "goto_symex.h"

/*******************************************************************\

Function: goto_symext::symex_other

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void goto_symext::symex_other(const goto_functionst &goto_functions,
                              statet &state) {
  const goto_programt::instructiont &instruction = *state.source.pc;

  const codet &code = to_code(instruction.code);

  const irep_idt &statement = code.get_statement();

  if (statement == ID_expression) {
    // ignore
  } else if (statement == ID_cpp_delete || statement == "cpp_delete[]") {
    codet clean_code = code;
    clean_expr(clean_code, state, false);
    symex_cpp_delete(state, clean_code);
  } else if (statement == ID_free) {
    // ignore
  } else if (statement == ID_printf) {
    codet clean_code = code;
    clean_expr(clean_code, state, false);
    symex_printf(state, nil_exprt(), clean_code);
  } else if (statement == ID_input) {
    codet clean_code(code);
    clean_expr(clean_code, state, false);
    symex_input(state, clean_code);
  } else if (statement == ID_output) {
    codet clean_code(code);
    clean_expr(clean_code, state, false);
    symex_output(state, clean_code);
  } else if (statement == ID_decl) {
    assert(false); // see symex_decl.cpp
  } else if (statement == ID_nondet) {
    // like skip
  } else if (statement == ID_asm) {
    // we ignore this for now
  } else if (statement == ID_array_copy) {
    assert(code.operands().size() == 2);

    codet clean_code(code);

    // we need to add dereferencing for both operands
    dereference_exprt d0, d1;
    d0.op0() = code.op0();
    d0.type() = code.op0().type().subtype();
    d1.op0() = code.op1();
    d1.type() = code.op1().type().subtype();

    clean_code.op0() = d0;
    clean_code.op1() = d1;

    clean_expr(clean_code.op0(), state, true);
    clean_expr(clean_code.op1(), state, false);

    process_array_expr(clean_code.op0());
    clean_expr(clean_code.op0(), state, true);
    process_array_expr(clean_code.op1());
    clean_expr(clean_code.op1(), state, false);

    if (!base_type_eq(clean_code.op0().type(), clean_code.op1().type(), ns)) {
      byte_extract_exprt be(byte_extract_id());
      be.type() = clean_code.op0().type();
      be.op() = clean_code.op1();
      be.offset() = from_integer(0, index_type());

      clean_code.op1() = be;
    }

    code_assignt assignment;
    assignment.lhs() = clean_code.op0();
    assignment.rhs() = clean_code.op1();
    symex_assign(state, assignment);
  } else if (statement == ID_array_set) {
    assert(code.operands().size() == 2);

    codet clean_code(code);

    // we need to add dereferencing for the first operand
    dereference_exprt d0;
    d0.op0() = code.op0();
    d0.type() = code.op0().type().subtype();

    clean_code.op0() = d0;

    clean_expr(clean_code.op0(), state, true);
    clean_expr(clean_code.op1(), state, false);

    process_array_expr(clean_code.op0());
    clean_expr(clean_code.op0(), state, true);

    const typet &op0_type = ns.follow(clean_code.op0().type());

    if (op0_type.id() != ID_array)
      throw "array_set expects array operand";

    const array_typet &array_type = to_array_type(op0_type);

    if (!base_type_eq(array_type.subtype(), clean_code.op1().type(), ns))
      clean_code.op1().make_typecast(array_type.subtype());

    code_assignt assignment;
    assignment.lhs() = clean_code.op0();
    assignment.rhs() = array_of_exprt(clean_code.op1(), array_type);
    symex_assign(state, assignment);
  } else if (statement == ID_user_specified_predicate ||
             statement == ID_user_specified_parameter_predicates ||
             statement == ID_user_specified_return_predicates) {
    // like skip
  } else if (statement == ID_fence) {
    target.memory_barrier(state.guard.as_expr(), state.source);
  } else
    throw "unexpected statement: " + id2string(statement);
}
