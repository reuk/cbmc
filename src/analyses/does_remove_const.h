/*******************************************************************\

 Module: Analyses

 Author: DiffBlue Limited. All rights reserved.

\*******************************************************************/
#ifndef CPROVER_ANALYSES_DOES_REMOVE_CONST_H
#define CPROVER_ANALYSES_DOES_REMOVE_CONST_H

#include <util/type.h>

class goto_programt;
class namespacet;
class exprt;

class does_remove_constt
{
public:
  does_remove_constt(const goto_programt &goto_program, const namespacet &ns);
  bool operator()() const;

private:
  bool does_expr_lose_const(const exprt &expr) const;

  bool is_type_at_least_as_const_as(
    const typet *type_more_const, const typet *type_compare) const;

  const goto_programt &goto_program;
  const namespacet &ns;
};

#endif // CPROVER_ANALYSES_DOES_REMOVE_CONST_H
