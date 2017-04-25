/// \file Nondeterministic initialization of certain global scope
/// variables

#ifndef CPROVER_GOTO_INSTRUMENT_NONDET_STATIC_H
#define CPROVER_GOTO_INSTRUMENT_NONDET_STATIC_H

class goto_functionst;
class namespacet;

void nondet_static(
  const namespacet &ns,
  goto_functionst &goto_functions);

#endif // CPROVER_GOTO_INSTRUMENT_NONDET_STATIC_H
