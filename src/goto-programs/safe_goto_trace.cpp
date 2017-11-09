/*******************************************************************\

Module: Safe traces of GOTO Programs

Author: @reuk

\*******************************************************************/

#include "safe_goto_trace.h"

#include <algorithm>

bool goto_trace_step_baset::is_assignment() const
{
  return false;
}

bool goto_trace_step_baset::is_assume() const
{
  return false;
}

bool goto_trace_step_baset::is_assert() const
{
  return false;
}

bool goto_trace_step_baset::is_goto() const
{
  return false;
}

bool goto_trace_step_baset::is_constraint() const
{
  return false;
}

bool goto_trace_step_baset::is_function_call() const
{
  return false;
}

bool goto_trace_step_baset::is_function_return() const
{
  return false;
}

bool goto_trace_step_baset::is_location() const
{
  return false;
}

bool goto_trace_step_baset::is_output() const
{
  return false;
}

bool goto_trace_step_baset::is_input() const
{
  return false;
}

bool goto_trace_step_baset::is_decl() const
{
  return false;
}

bool goto_trace_step_baset::is_dead() const
{
  return false;
}

bool goto_trace_step_baset::is_shared_read() const
{
  return false;
}

bool goto_trace_step_baset::is_shared_write() const
{
  return false;
}

bool goto_trace_step_baset::is_spawn() const
{
  return false;
}

bool goto_trace_step_baset::is_memory_barrier() const
{
  return false;
}

bool goto_trace_step_baset::is_atomic_begin() const
{
  return false;
}

bool goto_trace_step_baset::is_atomic_end() const
{
  return false;
}

////////////////////////////////////////////////////////////////////////////////

bool goto_trace_step_assignmentt::is_assignment() const
{
  return true;
}

bool goto_trace_step_assumet::is_assume() const
{
  return true;
}

bool goto_trace_step_assertt::is_assert() const
{
  return true;
}

bool goto_trace_step_gotot::is_goto() const
{
  return true;
}

bool goto_trace_step_constraintt::is_constraint() const
{
  return true;
}

bool goto_trace_step_function_callt::is_function_call() const
{
  return true;
}

bool goto_trace_step_function_returnt::is_function_return() const
{
  return true;
}

bool goto_trace_step_locationt::is_location() const
{
  return true;
}

bool goto_trace_step_outputt::is_output() const
{
  return true;
}

bool goto_trace_step_inputt::is_input() const
{
  return true;
}

bool goto_trace_step_declt::is_decl() const
{
  return true;
}

bool goto_trace_step_deadt::is_dead() const
{
  return true;
}

bool goto_trace_step_shared_readt::is_shared_read() const
{
  return true;
}

bool goto_trace_step_shared_writet::is_shared_write() const
{
  return true;
}

bool goto_trace_step_spawnt::is_spawn() const
{
  return true;
}

bool goto_trace_step_memory_barriert::is_memory_barrier() const
{
  return true;
}

bool goto_trace_step_atomic_begint::is_atomic_begin() const
{
  return true;
}

bool goto_trace_step_atomic_endt::is_atomic_end() const
{
  return true;
}

////////////////////////////////////////////////////////////////////////////////

static std::unique_ptr<goto_trace_step_baset>
make_step(const goto_trace_stept &step)
{
  switch(step.type)
  {
    case goto_trace_stept::typet::ASSIGNMENT:
    {
      auto ret = util_make_unique<goto_trace_step_assignmentt>();
      ret->lhs_object(step.lhs_object);
      ret->full_lhs(step.full_lhs);
      ret->full_lhs_value(step.full_lhs_value);
      ret->assignment_type(step.assignment_type);
      return ret;
    }

    case goto_trace_stept::typet::ASSUME:
    {
      auto ret = util_make_unique<goto_trace_step_assumet>();
      return ret;
    }

    case goto_trace_stept::typet::ASSERT:
    {
      auto ret = util_make_unique<goto_trace_step_assertt>();
      ret->cond_value(step.cond_value);
      ret->comment(step.comment);
      return ret;
    }

    case goto_trace_stept::typet::GOTO:
    {
      auto ret = util_make_unique<goto_trace_step_gotot>();
      return ret;
    }

    case goto_trace_stept::typet::LOCATION:
    {
      auto ret = util_make_unique<goto_trace_step_locationt>();
      return ret;
    }

    case goto_trace_stept::typet::INPUT:
    {
      auto ret = util_make_unique<goto_trace_step_inputt>();
      ret->format_string(step.format_string);
      ret->io_id(step.io_id);
      ret->io_args(step.io_args);
      ret->formatted(step.formatted);
      return ret;
    }

    case goto_trace_stept::typet::OUTPUT:
    {
      auto ret = util_make_unique<goto_trace_step_outputt>();
      ret->format_string(step.format_string);
      ret->io_id(step.io_id);
      ret->io_args(step.io_args);
      ret->formatted(step.formatted);
      return ret;
    }

    case goto_trace_stept::typet::DECL:
    {
      auto ret = util_make_unique<goto_trace_step_declt>();
      ret->lhs_object(step.lhs_object);
      ret->full_lhs(step.full_lhs);
      ret->full_lhs_value(step.full_lhs_value);
      ret->assignment_type(step.assignment_type);
      return ret;
    }

    case goto_trace_stept::typet::DEAD:
    {
      auto ret = util_make_unique<goto_trace_step_deadt>();
      return ret;
    }

    case goto_trace_stept::typet::FUNCTION_CALL:
    {
      auto ret = util_make_unique<goto_trace_step_function_callt>();
      ret->identifier(step.identifier);
      return ret;
    }

    case goto_trace_stept::typet::FUNCTION_RETURN:
    {
      auto ret = util_make_unique<goto_trace_step_function_returnt>();
      ret->identifier(step.identifier);
      return ret;
    }

    case goto_trace_stept::typet::CONSTRAINT:
    {
      auto ret = util_make_unique<goto_trace_step_constraintt>();
      return ret;
    }

    case goto_trace_stept::typet::SHARED_READ:
    {
      auto ret = util_make_unique<goto_trace_step_shared_readt>();
      return ret;
    }

    case goto_trace_stept::typet::SHARED_WRITE:
    {
      auto ret = util_make_unique<goto_trace_step_shared_writet>();
      return ret;
    }

    case goto_trace_stept::typet::SPAWN:
    {
      auto ret = util_make_unique<goto_trace_step_spawnt>();
      return ret;
    }

    case goto_trace_stept::typet::MEMORY_BARRIER:
    {
      auto ret = util_make_unique<goto_trace_step_memory_barriert>();
      return ret;
    }

    case goto_trace_stept::typet::ATOMIC_BEGIN:
    {
      auto ret = util_make_unique<goto_trace_step_atomic_begint>();
      return ret;
    }

    case goto_trace_stept::typet::ATOMIC_END:
    {
      auto ret = util_make_unique<goto_trace_step_atomic_endt>();
      return ret;
    }

    default:
      UNREACHABLE;
      break;
  }
}

template <typename It>
static std::list<std::unique_ptr<goto_trace_step_baset>> convert(It b, It e)
{
  std::list<std::unique_ptr<goto_trace_step_baset>> ret;
  std::transform(b, e, back_inserter(ret), [](const goto_trace_stept &step) {
    return make_step(step);
  });
  return ret;
}

////////////////////////////////////////////////////////////////////////////////

safe_goto_tracet::safe_goto_tracet(const goto_tracet &trace)
  : steps_(convert(std::begin(trace.steps), std::end(trace.steps)))
{
}

goto_tracet safe_goto_tracet::make_unsafe() const
{
  // TODO
  return goto_tracet{};
}

void safe_goto_tracet::output(const namespacet &ns, std::ostream &os) const
{
  // TODO
}

safe_goto_tracet::iteratort safe_goto_tracet::begin()
{
  return make_dereference_iterator(steps_.begin());
}

safe_goto_tracet::const_iteratort safe_goto_tracet::begin() const
{
  return make_dereference_iterator(steps_.begin());
}

safe_goto_tracet::const_iteratort safe_goto_tracet::cbegin() const
{
  return make_dereference_iterator(steps_.begin());
}

safe_goto_tracet::iteratort safe_goto_tracet::end()
{
  return make_dereference_iterator(steps_.end());
}

safe_goto_tracet::const_iteratort safe_goto_tracet::end() const
{
  return make_dereference_iterator(steps_.end());
}

safe_goto_tracet::const_iteratort safe_goto_tracet::cend() const
{
  return make_dereference_iterator(steps_.end());
}
