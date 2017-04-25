/// \file Goto Program

#include <iostream>
#include <sstream>

#include <util/json_expr.h>
#include <util/json_irep.h>
#include <util/cprover_prefix.h>
#include <util/prefix.h>

#include <langapi/language_util.h>

#include "goto_functions.h"
#include "goto_model.h"
#include "show_goto_functions_json.h"

/// For outputing the GOTO program in a readable JSON format.
///
/// \param ns: the namespace to use to resolve names with
show_goto_functions_jsont::show_goto_functions_jsont(const namespacet &ns):
  ns(ns)
{}

/// Walks through all of the functions in the program and returns a JSON object
/// representing all their functions
///
/// \param goto_functions: the goto functions that make up the program
json_objectt show_goto_functions_jsont::convert(
  const goto_functionst &goto_functions)
{
  json_arrayt json_functions;
  const json_irept no_comments_irep_converter(false);
  for(const auto &function_entry : goto_functions.function_map)
  {
    const irep_idt &function_name=function_entry.first;
    const goto_functionst::goto_functiont &function=function_entry.second;

    json_objectt &json_function=
      json_functions.push_back(jsont()).make_object();
    json_function["name"]=json_stringt(id2string(function_name));
    json_function["isBodyAvailable"]=
      jsont::json_boolean(function.body_available());
    bool is_internal=(has_prefix(id2string(function_name), CPROVER_PREFIX) ||
                      function_name==goto_functions.entry_point());
    json_function["isInternal"]=jsont::json_boolean(is_internal);

    if(function.body_available())
    {
      json_arrayt json_instruction_array=json_arrayt();

      for(const goto_programt::instructiont &instruction :
        function.body.instructions)
      {
        json_objectt instruction_entry=json_objectt();

        instruction_entry["instructionId"]=
          json_stringt(instruction.to_string());

        if(instruction.code.source_location().is_not_nil())
        {
          instruction_entry["sourceLocation"]=
            json(instruction.code.source_location());
        }

        std::ostringstream instruction_builder;
        function.body.output_instruction(
          ns, function_name, instruction_builder, instruction);

        instruction_entry["instruction"]=
          json_stringt(instruction_builder.str());

        if(instruction.code.operands().size()>0)
        {
          json_arrayt operand_array;
          for(const exprt &operand : instruction.code.operands())
          {
            json_objectt operand_object;
            no_comments_irep_converter.convert_from_irep(
              operand, operand_object);
            operand_array.push_back(operand_object);
          }
          instruction_entry["operands"]=operand_array;
        }

        if(!instruction.guard.is_true())
        {
          json_objectt guard_object;
          no_comments_irep_converter.convert_from_irep(
            instruction.guard,
            guard_object);

          instruction_entry["guard"]=guard_object;
        }

        json_instruction_array.push_back(instruction_entry);
      }

      json_function["instructions"]=json_instruction_array;
    }
  }
  json_objectt json_result;
  json_result["functions"]=json_functions;
  return json_result;
}

/// Print the json object generated by
/// show_goto_functions_jsont::show_goto_functions to the provided stream (e.g.
/// std::cout)
///
/// \param goto_functions: the goto functions that make up the program
/// \param out: the stream to write the object to
/// \param append: should a command and newline be appended to the stream
///   before writing the JSON object. Defaults to true
void show_goto_functions_jsont::operator()(
  const goto_functionst &goto_functions,
  std::ostream &out,
  bool append)
{
  if(append)
  {
    out << ",\n";
  }
  out << convert(goto_functions);
}
