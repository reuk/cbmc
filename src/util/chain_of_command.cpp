#include "util/chain_of_command.h"

#include <iostream>

namespace util {

chain_of_command_linkt *chain_of_command_linkt::get_next() const {
  return next_.get();
}

void chain_of_commandt::add_to_front(
    std::unique_ptr<chain_of_command_linkt> link) {
  link->next_ = std::move(front_);
  front_ = std::move(link);

  if (back_ == nullptr) {
    back_ = front_.get();
  }
}

void chain_of_commandt::add_to_back(
    std::unique_ptr<chain_of_command_linkt> link) {
  if (back_ == nullptr) {
    add_to_front(std::move(link));
  } else {
    back_->next_ = std::move(link);
    back_ = back_->next_.get();
  }
}

void chain_of_commandt::run(std::vector<std::string> const &values) {
  if (front_ != nullptr) {
    front_->run(values);
  }
}

////////////////////////////////////////////////////////////////////////////////

void chain_of_command_with_optionst::add_to_front(
    std::unique_ptr<link_with_optionst> link) {
  link->register_options(options_);
  chain_.add_to_front(std::move(link));
}

void chain_of_command_with_optionst::add_to_back(
    std::unique_ptr<link_with_optionst> link) {
  link->register_options(options_);
  chain_.add_to_back(std::move(link));
}

void chain_of_command_with_optionst::run(int argc, char const *const *argv) {
  chain_.run(parse_cmdline(options_, argc, argv));
}

registered_optionst const &chain_of_command_with_optionst::options() const {
  return options_;
}

////////////////////////////////////////////////////////////////////////////////

void do_nothing_linkt::run(std::vector<std::string> const &values) {
  std::cout << "This link was passed the following options:\n";
  for (auto const &str : values) {
    std::cout << "- " << str << '\n';
  }
}

void do_nothing_linkt::register_options(registered_optionst &opts) {
  //  No options here!
}

} // namespace util
