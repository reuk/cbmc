#pragma once

#include "util/cmdline_parser.h"

namespace util {

class chain_of_commandt;

class chain_of_command_linkt {
public:
  virtual ~chain_of_command_linkt() noexcept = default;

  /// This will be called with any remaining unrecognised values.
  virtual void run(std::vector<std::string> const &values) = 0;

  chain_of_command_linkt *get_next() const;

private:
  friend chain_of_commandt;
  std::unique_ptr<chain_of_command_linkt> next_;
};

class link_with_optionst : public chain_of_command_linkt {
public:
  /// Call this to add flags or values that this link cares about.
  virtual void register_options(registered_optionst &opts) = 0;
};

////////////////////////////////////////////////////////////////////////////////

class chain_of_commandt final {
public:
  void add_to_front(std::unique_ptr<link_with_optionst> link);
  void add_to_back(std::unique_ptr<link_with_optionst> link);

  void run(int argc, char const *const *argv);

private:
  registered_optionst options_;
  std::unique_ptr<link_with_optionst> front_;
  chain_of_command_linkt *back_ = nullptr;
};

} // namespace util
