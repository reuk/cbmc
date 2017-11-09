/*******************************************************************\

Module: Traces of GOTO Programs

Author: Daniel Kroening

Date: November 2005

\*******************************************************************/

/// \file
/// Traces of GOTO Programs

#ifndef CPROVER_GOTO_PROGRAMS_JSON_GOTO_TRACE_H
#define CPROVER_GOTO_PROGRAMS_JSON_GOTO_TRACE_H

class jsont;
class namespacet;
class safe_goto_tracet;

void convert(const namespacet &, const safe_goto_tracet &, jsont &);

#endif // CPROVER_GOTO_PROGRAMS_JSON_GOTO_TRACE_H
