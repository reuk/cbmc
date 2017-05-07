/*******************************************************************\

Module: Read goto object files.

Author: CM Wintersteiger

Date: June 2006

\*******************************************************************/

#ifndef CPROVER_GOTO_CC_XML_BINARIES_READ_GOTO_OBJECT_H
#define CPROVER_GOTO_CC_XML_BINARIES_READ_GOTO_OBJECT_H

#include <goto-programs/goto_functions.h>
#include <util/message.h>
#include <util/symbol_table.h>

bool read_goto_object(std::istream &in, const std::string &filename,
                      symbol_tablet &symbol_table, goto_functionst &functions,
                      message_handlert &msg_hndlr);

#endif // CPROVER_GOTO_CC_XML_BINARIES_READ_GOTO_OBJECT_H
