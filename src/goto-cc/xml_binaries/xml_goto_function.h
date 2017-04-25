/// \file Convert goto functions into xml structures and back

#ifndef CPROVER_GOTO_CC_XML_BINARIES_XML_GOTO_FUNCTION_H
#define CPROVER_GOTO_CC_XML_BINARIES_XML_GOTO_FUNCTION_H

#include <util/xml.h>
#include <goto-programs/goto_functions.h>

void convert(const xmlt&, goto_functionst::goto_functiont&);
void convert(const goto_functionst::goto_functiont&, xmlt&);

#endif // CPROVER_GOTO_CC_XML_BINARIES_XML_GOTO_FUNCTION_H
