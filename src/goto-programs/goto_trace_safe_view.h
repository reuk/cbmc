/*******************************************************************\

Module: Typesafe views of GOTO Traces

Author: @reuk

\*******************************************************************/

/// \file
/// Typesafe views of GOTO Traces

#ifndef CPROVER_UTIL_GOTO_TRACE_SAFE_VIEW_H
#define CPROVER_UTIL_GOTO_TRACE_SAFE_VIEW_H

#include "util/mapping_iterator.h"

#include <memory>

class goto_trace_step_baset;
class goto_trace_stept;

std::unique_ptr<goto_trace_step_baset> make_view(goto_trace_stept &step);

namespace detail // NOLINT
{
struct view_makert final
{
  std::unique_ptr<goto_trace_step_baset>
  operator()(goto_trace_stept &step) const
  {
    return make_view(step);
  }
};
} // namespace detail

template <typename It>
using goto_trace_step_view_iteratort =
  mapping_iteratort<It, detail::view_makert>;

template <typename It>
goto_trace_step_view_iteratort<It> make_goto_trace_step_view_iterator(It &&it)
{
  return goto_trace_step_view_iteratort<It>{std::forward<It>(it)};
}

template <typename T>
class goto_trace_step_view_facadet final
{
public:
  explicit goto_trace_step_view_facadet(T &t) : t_(t)
  {
  }

  using iterator =
    goto_trace_step_view_iteratort<decltype(std::begin(std::declval<T>()))>;

  iterator begin() const
  {
    return iterator{std::begin(t_)};
  }

  iterator end() const
  {
    return iterator{std::end(t_)};
  }

private:
  T &t_;
};

template <typename T>
goto_trace_step_view_facadet<T> make_goto_trace_step_view_facade(T &t)
{
  return goto_trace_step_view_facadet<T>{t};
}

#endif
