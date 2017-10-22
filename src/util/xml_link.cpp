#include "util/xml_link.h"
#include "util/xml_interface.h"

#include <iostream>

namespace util {

xml_linkt::xml_linkt(registered_optionst const &opts) : opts_{opts} {}

void xml_linkt::register_options(registered_optionst &opts) {
  opts.add("xml-interface", xml_ui_, "Parse xml options from stdin");
}

void xml_linkt::run(std::vector<std::string> const &values) {
  auto copy = values;

  if (xml_ui_) {
    auto vec = parse_xml(opts_, std::cin);
    copy.insert(end(copy), begin(vec), end(vec));
  }

  if (auto next = get_next()) {
    next->run(copy);
  }
}

} // namespace util
