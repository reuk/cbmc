/*******************************************************************\

Module: Safe traces of GOTO Programs

Author: @reuk

\*******************************************************************/

#include "safe_goto_trace.h"

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

safe_goto_tracet::safe_goto_tracet(const goto_tracet &trace)
{
}

goto_tracet safe_goto_tracet::make_unsafe() const
{
  return goto_tracet{};
}

void safe_goto_tracet::output(const namespacet &ns, std::ostream &os) const
{
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
