#include "util/cmdline_parser.h"

#include <iomanip>
#include <sstream>

namespace util {

flag_already_exists_errort::flag_already_exists_errort(std::string flag)
    : std::runtime_error("The flag '" + flag + "' already exists") {}

////////////////////////////////////////////////////////////////////////////////

registered_option_baset::registered_option_baset(std::string help)
    : help_{std::move(help)} {}

std::string registered_option_baset::help() const { return help_; }

flag_optiont::flag_optiont(std::string help, bool &ref)
    : registered_option_baset{std::move(help)}, ref_{ref} {}

std::unique_ptr<registered_option_baset> flag_optiont::clone() const {
  return util_make_unique<flag_optiont>(*this);
}

void flag_optiont::accept(option_visitort const &visitor) const {
  visitor.visit(*this);
}

void flag_optiont::invoke() const { ref_ = true; }

std::unique_ptr<registered_option_baset> value_optiont::clone() const {
  return util_make_unique<value_optiont>(*this);
}

void value_optiont::accept(option_visitort const &visitor) const {
  visitor.visit(*this);
}

void value_optiont::invoke(char const *opt) const { func_(opt); }

////////////////////////////////////////////////////////////////////////////////

void registered_optionst::add(std::string name, bool &set, std::string help) {
  check_for_flag(name);
  listener_table_.emplace(std::move(name),
                          util_make_unique<flag_optiont>(std::move(help), set));
}

std::vector<std::string>
registered_optionst::parse(int argc, char const *const *argv) const {
  class parser_visitort : public option_visitort {
  public:
    explicit parser_visitort(char const *const *argv, int &it)
        : argv_{argv}, it_{it} {}

    void visit(flag_optiont const &opt) const override {
      opt.invoke();
      it_ += 1;
    }

    void visit(value_optiont const &opt) const override {
      opt.invoke(argv_[it_ + 1]);
      it_ += 2;
    }

  private:
    char const *const *argv_;
    int &it_;
  };

  std::vector<std::string> ret;
  for (decltype(argc) i = 1; i < argc;) {
    if (auto const entry = option(argv[i])) {
      entry->accept(parser_visitort{argv, i});
    } else {
      ret.emplace_back(argv[i]);
      ++i;
    }
  }
  return ret;
}

std::string registered_optionst::help() const {
  auto const left_column = 30;
  std::ostringstream ss;
  ss << std::left;
  for (auto const &details : listener_table_) {
    ss << std::setw(left_column) << details.first;
    if (details.first.size() < left_column) {
      ss << std::setw(50) << details.second->help() << '\n';
    } else {
      ss << '\n'
         << std::string(left_column, ' ') << std::setw(50)
         << details.second->help() << '\n';
    }
  }
  return ss.str();
}

void registered_optionst::check_for_flag(std::string const &tag) const {
  auto const it = listener_table_.find(tag);
  if (it != listener_table_.end()) {
    throw flag_already_exists_errort(tag);
  }
}

registered_option_baset const *
registered_optionst::option(std::string const &str) const {
  auto const it = listener_table_.find(str);
  return it == listener_table_.end() ? nullptr : it->second.get();
}

std::vector<std::string> parse(const registered_optionst &opts, int argc,
                               char const *const *argv) {
  return opts.parse(argc, argv);
}

std::vector<std::string> parse(const registered_optionst &opts,
                               std::vector<char const *> const &vec) {
  return parse(opts, vec.size(), vec.data());
}

std::vector<std::string> parse(const registered_optionst &opts,
                               std::vector<std::string> const &vec) {
  std::vector<char const *> ptrs;
  ptrs.reserve(vec.size());
  transform(begin(vec), end(vec), back_inserter(ptrs),
            [](std::string const &str) { return str.data(); });
  return parse(opts, ptrs);
}

} // namespace util
