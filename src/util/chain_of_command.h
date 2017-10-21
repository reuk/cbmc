#pragma once

namespace util {

class chain_linkt {
public:
  virtual ~chain_linkt() noexcept = default;

  virtual void register_options(registered_optionst &opts) const = 0;
};

} // namespace util
