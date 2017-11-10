#include "goto_trace_safe_view.h"

#include <util/make_unique.h>

#include <goto-programs/goto_trace.h>
#include <goto-programs/safe_goto_trace.h>

std::unique_ptr<goto_trace_step_baset> make_view(goto_trace_stept &step)
{
  switch(step.type)
  {
  case goto_trace_stept::typet::ASSIGNMENT:
    return util_make_unique<goto_trace_step_assignmentt>(step);

  case goto_trace_stept::typet::ASSUME:
    return util_make_unique<goto_trace_step_assumet>(step);

  case goto_trace_stept::typet::ASSERT:
    return util_make_unique<goto_trace_step_assertt>(step);

  case goto_trace_stept::typet::GOTO:
    return util_make_unique<goto_trace_step_gotot>(step);

  case goto_trace_stept::typet::LOCATION:
    return util_make_unique<goto_trace_step_locationt>(step);

  case goto_trace_stept::typet::INPUT:
    return util_make_unique<goto_trace_step_inputt>(step);

  case goto_trace_stept::typet::OUTPUT:
    return util_make_unique<goto_trace_step_outputt>(step);

  case goto_trace_stept::typet::DECL:
    return util_make_unique<goto_trace_step_declt>(step);

  case goto_trace_stept::typet::DEAD:
    return util_make_unique<goto_trace_step_deadt>(step);

  case goto_trace_stept::typet::FUNCTION_CALL:
    return util_make_unique<goto_trace_step_function_callt>(step);

  case goto_trace_stept::typet::FUNCTION_RETURN:
    return util_make_unique<goto_trace_step_function_returnt>(step);

  case goto_trace_stept::typet::CONSTRAINT:
    return util_make_unique<goto_trace_step_constraintt>(step);

  case goto_trace_stept::typet::SHARED_READ:
    return util_make_unique<goto_trace_step_shared_readt>(step);

  case goto_trace_stept::typet::SHARED_WRITE:
    return util_make_unique<goto_trace_step_shared_writet>(step);

  case goto_trace_stept::typet::SPAWN:
    return util_make_unique<goto_trace_step_spawnt>(step);

  case goto_trace_stept::typet::MEMORY_BARRIER:
    return util_make_unique<goto_trace_step_memory_barriert>(step);

  case goto_trace_stept::typet::ATOMIC_BEGIN:
    return util_make_unique<goto_trace_step_atomic_begint>(step);

  case goto_trace_stept::typet::ATOMIC_END:
    return util_make_unique<goto_trace_step_atomic_endt>(step);

  default:
    UNREACHABLE;
    break;
  }
}

