#include "util/help_link.h"

#include <iostream>

namespace util {

void help_linkt::register_options(registered_optionst &opts) {
  opts_ = &opts;

  opts.add("help", help_, "Show this help text");
}

void help_linkt::run(std::vector<std::string> const &values) {
  if (help_ && opts_ != nullptr) {
    std::cout << opts_->help();
  } else {
    if (auto next = get_next()) {
      next->run(values);
    }
  }
}

} // namespace util
