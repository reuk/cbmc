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
class expected_flag_visitort : public util::option_visitort {
public:
  void visit(util::flag_optiont const &opt) const override { opt.invoke(); }

  void visit(util::value_optiont const &opt) const override {
    throw std::runtime_error{"This is a flag option"};
  }
};

class expected_value_visitort : public util::option_visitort {
public:
  explicit expected_value_visitort(std::string value)
      : value_{std::move(value)} {}

  void visit(util::flag_optiont const &opt) const override {
    throw std::runtime_error{"This is a value option"};
  }

  void visit(util::value_optiont const &opt) const override {
    opt.invoke(value_.c_str());
  }

private:
  std::string value_;
};

std::vector<std::string>
parse_xml_cmdline_options(util::registered_optionst const &opts,
                          xmlt const &xml) {
  for (const auto &e : xml.elements) {
    parse_xml_cmdline_options(opts, e);
  }

  std::vector<std::string> ret;

  if (xml.name == "valueOption") {
    std::string const name = xml.get_attribute("name");
    std::string value = xml.get_attribute("actual");
    if (name.empty()) {
      ret.emplace_back(std::move(value));
    } else {
      opts.option_ref(name).accept(expected_value_visitort{value});
    }
  } else if (xml.name == "flagOption") {
    std::string const name = xml.get_attribute("name");
    if (!name.empty() && xml.get_attribute("actual") == "on") {
      opts.option_ref(name).accept(expected_flag_visitort{});
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
