/*******************************************************************\

Module: Safe SSA steps

Author: @reuk

\*******************************************************************/

#include "safe_ssa_step.h"

bool ssa_step_baset::is_assert() const
{
  return false;
}
bool ssa_step_baset::is_assume() const
{
  return false;
}
bool ssa_step_baset::is_assignment() const
{
  return false;
}
bool ssa_step_baset::is_goto() const
{
  return false;
}
bool ssa_step_baset::is_location() const
{
  return false;
}
bool ssa_step_baset::is_output() const
{
  return false;
}
bool ssa_step_baset::is_decl() const
{
  return false;
}
bool ssa_step_baset::is_function_call() const
{
  return false;
}
bool ssa_step_baset::is_function_return() const
{
  return false;
}
bool ssa_step_baset::is_shared_read() const
{
  return false;
}
bool ssa_step_baset::is_shared_write() const
{
  return false;
}
bool ssa_step_baset::is_spawn() const
{
  return false;
}
bool ssa_step_baset::is_memory_barrier() const
{
  return false;
}
bool ssa_step_baset::is_atomic_begin() const
{
  return false;
}
bool ssa_step_baset::is_atomic_end() const
{
  return false;
}
