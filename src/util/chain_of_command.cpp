#include "util/chain_of_command.h"

namespace util {

void chain_of_commandt::add_to_front(std::unique_ptr<link_with_optionst> link) {
  link->register_options(options_);
  auto tmp = std::move(front_);
  link->next_ = std::move(tmp);
  front_ = std::move(link);

  if (back_ == nullptr) {
    back_ = front_.get();
  }
}

void chain_of_commandt::add_to_back(std::unique_ptr<link_with_optionst> link) {
  link->register_options(options_);
  if (back_ == nullptr) {
    add_to_front(std::move(link));
  } else {
    back_->next_ = std::move(link);
    back_ = back_->next_.get();
  }
}

void chain_of_commandt::run(int argc, char const *const *argv) {
  if (front_ != nullptr) {
    front_->run(parse_cmdline(options_, argc, argv));
  }
}

} // namespace util
