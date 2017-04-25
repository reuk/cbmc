/// \file Dump Goto-Program as DOT Graph

#ifndef CPROVER_GOTO_INSTRUMENT_DOT_H
#define CPROVER_GOTO_INSTRUMENT_DOT_H

#include <goto-programs/goto_functions.h>

void dot(
  const goto_functionst &src,
  const namespacet &ns,
  std::ostream &out);

#endif // CPROVER_GOTO_INSTRUMENT_DOT_H
