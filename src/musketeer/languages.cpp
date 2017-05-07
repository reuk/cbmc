/*******************************************************************\

Module: Language Registration

Author:

\*******************************************************************/

#include "musketeer_parse_options.h"

#include <langapi/mode.h>

#include <ansi-c/ansi_c_language.h>

/*******************************************************************\

Function: goto_instrument_parse_optionst::register_languages

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void goto_fence_inserter_parse_optionst::register_languages()
{
  register_language(new_ansi_c_language);
}
