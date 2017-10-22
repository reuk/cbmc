#pragma once

#include "util/chain_of_command.h"

namespace util {

class xml_linkt final : public link_with_optionst {
public:
  void register_options(registered_optionst &opts) override;

  void run(std::vector<std::string> const &values) override;

private:
  registered_optionst *opts_ = nullptr;
  bool xml_ui_ = false;
};

} // namespace util
