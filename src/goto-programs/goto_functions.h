/*******************************************************************\

Module: Goto Programs with Functions

Author: Daniel Kroening

Date: June 2003

\*******************************************************************/

#ifndef CPROVER_GOTO_PROGRAMS_GOTO_FUNCTIONS_H
#define CPROVER_GOTO_PROGRAMS_GOTO_FUNCTIONS_H

#include "goto_program.h"
#include "goto_functions_template.h"

class goto_functionst:public goto_functions_templatet<goto_programt>
{
public:
};

void get_local_identifiers(
  const goto_function_templatet<goto_programt> &goto_function,
  std::set<irep_idt> &dest);

#endif // CPROVER_GOTO_PROGRAMS_GOTO_FUNCTIONS_H
