#include "util/help_link.h"

#include <iostream>

namespace util {

help_linkt::help_linkt(registered_optionst const &opts) : opts_{opts} {}

void help_linkt::register_options(registered_optionst &opts) {
  opts.add("help", help_, "Show this help text");
}

void help_linkt::run(std::vector<std::string> const &values) {
  if (help_) {
    std::cout << opts_.help();
  } else {
    if (auto next = get_next()) {
      next->run(values);
    }
  }
}

} // namespace util
