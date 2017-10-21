/*******************************************************************\

Module: XML Interface

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

/// \file
/// XML Interface

#include "xml_interface.h"

#include <iostream>

#include <util/cmdline_parser.h>
#include <util/message.h>

#include <xmllang/xml_parser.h>

namespace {
std::vector<std::string>
parse_xml_cmdline_options(util::registered_optionst const &opts,
                          xmlt const &xml) {
  for (const auto &e : xml.elements) {
    parse_xml_cmdline_options(opts, e);
  }

  std::vector<std::string> ret;

  if (xml.name == "valueOption") {
    std::string const name = xml.get_attribute("name");
    std::string const value = xml.get_attribute("actual");
    for (auto &ptr :
         util::parse(opts, name.empty() ? std::vector<std::string>{value}
                                        : std::vector<std::string>{"--" + name,
                                                                   value})) {
      ret.emplace_back(std::move(ptr));
    }
  } else if (xml.name == "flagOption") {
    std::string const name = xml.get_attribute("name");
    if (!name.empty() && xml.get_attribute("actual") == "on") {
      util::parse(opts, std::vector<std::string>{"--" + name});
      for (auto &ptr :
           util::parse(opts, std::vector<std::string>{"--" + name})) {
        ret.emplace_back(std::move(ptr));
      }
    }
  }

  return ret;
}
} // namespace

std::vector<std::string>
parse_xml_cmdline_options(util::registered_optionst const &opts,
                          std::istream &stream) {
  null_message_handlert message_handler;
  xmlt xml;
  parse_xml(stream, "", message_handler, xml);

  return parse_xml_cmdline_options(opts, xml);
}
