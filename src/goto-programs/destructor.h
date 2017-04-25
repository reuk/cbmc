/// \file Destructor Calls

#ifndef CPROVER_GOTO_PROGRAMS_DESTRUCTOR_H
#define CPROVER_GOTO_PROGRAMS_DESTRUCTOR_H

#include <util/expr.h>
#include <util/namespace.h>

code_function_callt get_destructor(
  const namespacet &ns,
  const typet &type);

#endif // CPROVER_GOTO_PROGRAMS_DESTRUCTOR_H
