#pragma once

#include "util/chain_of_command.h"

namespace util {

class help_linkt final : public link_with_optionst {
public:
  explicit help_linkt(registered_optionst const &opts);

  void register_options(registered_optionst &opts) override;

  void run(std::vector<std::string> const &values) override;

private:
  registered_optionst const &opts_;
  bool help_ = false;
};

} // namespace util
