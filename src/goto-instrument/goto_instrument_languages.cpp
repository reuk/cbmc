/// \file Language Registration

#include <langapi/mode.h>

#include <ansi-c/ansi_c_language.h>
#include <cpp/cpp_language.h>
#include <java_bytecode/java_bytecode_language.h>

#include "goto_instrument_parse_options.h"

void goto_instrument_parse_optionst::register_languages()
{
  register_language(new_ansi_c_language);
  register_language(new_cpp_language);
  register_language(new_java_bytecode_language);
}
