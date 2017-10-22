#pragma once

#include "util/make_unique.h"

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace util {

class flag_already_exists_errort final : public std::runtime_error {
public:
  explicit flag_already_exists_errort(std::string flag);
};

template <typename T> inline T parse_cmdline_option(char const *opt);

template <> inline int parse_cmdline_option<int>(char const *opt) {
  return std::stoi(opt);
}

template <> inline double parse_cmdline_option<double>(char const *opt) {
  return std::stod(opt);
}

template <>
inline std::string parse_cmdline_option<std::string>(char const *opt) {
  return opt;
}

////////////////////////////////////////////////////////////////////////////////

class flag_optiont;
class value_optiont;

class option_visitort {
public:
  virtual ~option_visitort() noexcept = default;

  virtual void visit(flag_optiont const &opt) const = 0;
  virtual void visit(value_optiont const &opt) const = 0;
};

class registered_option_baset {
public:
  explicit registered_option_baset(std::string help);

  virtual ~registered_option_baset() noexcept = default;

  virtual std::unique_ptr<registered_option_baset> clone() const = 0;

  std::string help() const;

  virtual void accept(option_visitort const &visitor) const = 0;

private:
  std::string help_;
};

class flag_optiont final : public registered_option_baset {
public:
  flag_optiont(std::string help, bool &ref);

  std::unique_ptr<registered_option_baset> clone() const override;

  void accept(option_visitort const &visitor) const override;

  void invoke() const;

public:
  bool &ref_;
};

class value_optiont final : public registered_option_baset {
public:
  template <typename T>
  value_optiont(std::string help, T &ref)
      : registered_option_baset{std::move(help)},
        func_{[&](char const *opt) { ref = parse_cmdline_option<T>(opt); }} {}

  std::unique_ptr<registered_option_baset> clone() const override;

  void accept(option_visitort const &visitor) const override;

  void invoke(char const *opt) const;

private:
    std::function<void(char const *)> func_;
};

////////////////////////////////////////////////////////////////////////////////

/// Allows names to be registered along with references that should be modified
/// if a new value is set for that name.
class registered_optionst final {
public:
  template <typename T>
  void add(std::string name, T &ref, std::string help = "") {
    check_for_flag(name);
    listener_table_.emplace(
        std::move(name), util_make_unique<value_optiont>(std::move(help), ref));
  }

  void add(std::string name, bool &set, std::string help = "");

  registered_option_baset const *option(std::string const &str) const;
  registered_option_baset const &option_ref(std::string const &str) const;

  std::string help() const;

private:
  std::unordered_map<std::string, std::unique_ptr<registered_option_baset>>
      listener_table_;

  void check_for_flag(std::string const &str) const;
};

std::vector<std::string> parse_cmdline(registered_optionst const &opts,
                                       int argc, char const *const *argv);

std::vector<std::string> parse_cmdline(registered_optionst const &opts,
                                       std::vector<char const *> const &vec);

std::vector<std::string> parse_cmdline(registered_optionst const &opts,
                                       std::vector<std::string> const &vec);

} // namespace util
