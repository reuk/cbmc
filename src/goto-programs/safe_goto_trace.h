/*******************************************************************\

Module: Safe traces of GOTO Programs

Author: @reuk

\*******************************************************************/

/// \file
/// Safe traces of GOTO Programs

#ifndef CPROVER_GOTO_PROGRAMS_SAFE_GOTO_TRACE_H
#define CPROVER_GOTO_PROGRAMS_SAFE_GOTO_TRACE_H

#include <util/make_unique.h>

#include <iosfwd>
#include <list>
#include <memory>

class goto_trace_step_assignmentt;
class goto_trace_step_assumet;
class goto_trace_step_assertt;
class goto_trace_step_gotot;
class goto_trace_step_constraintt;
class goto_trace_step_function_callt;
class goto_trace_step_function_returnt;
class goto_trace_step_locationt;
class goto_trace_step_outputt;
class goto_trace_step_inputt;
class goto_trace_step_declt;
class goto_trace_step_deadt;
class goto_trace_step_shared_readt;
class goto_trace_step_shared_writet;
class goto_trace_step_spawnt;
class goto_trace_step_memory_barriert;
class goto_trace_step_atomic_begint;
class goto_trace_step_atomic_endt;

class goto_trace_visitort
{
public:
  virtual ~goto_trace_visitort() = default;

  virtual void visit(goto_trace_step_assignmentt) = 0;
  virtual void visit(goto_trace_step_assumet) = 0;
  virtual void visit(goto_trace_step_assertt) = 0;
  virtual void visit(goto_trace_step_gotot) = 0;
  virtual void visit(goto_trace_step_constraintt) = 0;
  virtual void visit(goto_trace_step_function_callt) = 0;
  virtual void visit(goto_trace_step_function_returnt) = 0;
  virtual void visit(goto_trace_step_locationt) = 0;
  virtual void visit(goto_trace_step_outputt) = 0;
  virtual void visit(goto_trace_step_inputt) = 0;
  virtual void visit(goto_trace_step_declt) = 0;
  virtual void visit(goto_trace_step_deadt) = 0;
  virtual void visit(goto_trace_step_shared_readt) = 0;
  virtual void visit(goto_trace_step_shared_writet) = 0;
  virtual void visit(goto_trace_step_spawnt) = 0;
  virtual void visit(goto_trace_step_memory_barriert) = 0;
  virtual void visit(goto_trace_step_atomic_begint) = 0;
  virtual void visit(goto_trace_step_atomic_endt) = 0;
};

class goto_trace_const_visitort
{
public:
  virtual ~goto_trace_const_visitort() = default;

  virtual void visit(goto_trace_step_assignmentt) const = 0;
  virtual void visit(goto_trace_step_assumet) const = 0;
  virtual void visit(goto_trace_step_assertt) const = 0;
  virtual void visit(goto_trace_step_gotot) const = 0;
  virtual void visit(goto_trace_step_constraintt) const = 0;
  virtual void visit(goto_trace_step_function_callt) const = 0;
  virtual void visit(goto_trace_step_function_returnt) const = 0;
  virtual void visit(goto_trace_step_locationt) const = 0;
  virtual void visit(goto_trace_step_outputt) const = 0;
  virtual void visit(goto_trace_step_inputt) const = 0;
  virtual void visit(goto_trace_step_declt) const = 0;
  virtual void visit(goto_trace_step_deadt) const = 0;
  virtual void visit(goto_trace_step_shared_readt) const = 0;
  virtual void visit(goto_trace_step_shared_writet) const = 0;
  virtual void visit(goto_trace_step_spawnt) const = 0;
  virtual void visit(goto_trace_step_memory_barriert) const = 0;
  virtual void visit(goto_trace_step_atomic_begint) const = 0;
  virtual void visit(goto_trace_step_atomic_endt) const = 0;
};

class goto_trace_visitor_const_argst
{
public:
  virtual ~goto_trace_visitor_const_argst() = default;

  virtual void visit(const goto_trace_step_assignmentt) = 0;
  virtual void visit(const goto_trace_step_assumet) = 0;
  virtual void visit(const goto_trace_step_assertt) = 0;
  virtual void visit(const goto_trace_step_gotot) = 0;
  virtual void visit(const goto_trace_step_constraintt) = 0;
  virtual void visit(const goto_trace_step_function_callt) = 0;
  virtual void visit(const goto_trace_step_function_returnt) = 0;
  virtual void visit(const goto_trace_step_locationt) = 0;
  virtual void visit(const goto_trace_step_outputt) = 0;
  virtual void visit(const goto_trace_step_inputt) = 0;
  virtual void visit(const goto_trace_step_declt) = 0;
  virtual void visit(const goto_trace_step_deadt) = 0;
  virtual void visit(const goto_trace_step_shared_readt) = 0;
  virtual void visit(const goto_trace_step_shared_writet) = 0;
  virtual void visit(const goto_trace_step_spawnt) = 0;
  virtual void visit(const goto_trace_step_memory_barriert) = 0;
  virtual void visit(const goto_trace_step_atomic_begint) = 0;
  virtual void visit(const goto_trace_step_atomic_endt) = 0;
};

class goto_trace_const_visitor_const_argst
{
public:
  virtual ~goto_trace_const_visitor_const_argst() = default;

  virtual void visit(const goto_trace_step_assignmentt) const = 0;
  virtual void visit(const goto_trace_step_assumet) const = 0;
  virtual void visit(const goto_trace_step_assertt) const = 0;
  virtual void visit(const goto_trace_step_gotot) const = 0;
  virtual void visit(const goto_trace_step_constraintt) const = 0;
  virtual void visit(const goto_trace_step_function_callt) const = 0;
  virtual void visit(const goto_trace_step_function_returnt) const = 0;
  virtual void visit(const goto_trace_step_locationt) const = 0;
  virtual void visit(const goto_trace_step_outputt) const = 0;
  virtual void visit(const goto_trace_step_inputt) const = 0;
  virtual void visit(const goto_trace_step_declt) const = 0;
  virtual void visit(const goto_trace_step_deadt) const = 0;
  virtual void visit(const goto_trace_step_shared_readt) const = 0;
  virtual void visit(const goto_trace_step_shared_writet) const = 0;
  virtual void visit(const goto_trace_step_spawnt) const = 0;
  virtual void visit(const goto_trace_step_memory_barriert) const = 0;
  virtual void visit(const goto_trace_step_atomic_begint) const = 0;
  virtual void visit(const goto_trace_step_atomic_endt) const = 0;
};

class namespacet;

class goto_trace_step_baset
{
public:
  virtual ~goto_trace_step_baset() = default;

  virtual void accept(goto_trace_visitort &) = 0;
  virtual void accept(const goto_trace_const_visitort &) = 0;
  virtual void accept(goto_trace_visitor_const_argst &) const = 0;
  virtual void accept(const goto_trace_const_visitor_const_argst &) const = 0;

  virtual std::unique_ptr<goto_trace_step_baset> clone() const = 0;

  virtual bool is_assignment() const
  {
    return false;
  }
  virtual bool is_assume() const
  {
    return false;
  }
  virtual bool is_assert() const
  {
    return false;
  }
  virtual bool is_goto() const
  {
    return false;
  }
  virtual bool is_constraint() const
  {
    return false;
  }
  virtual bool is_function_call() const
  {
    return false;
  }
  virtual bool is_function_return() const
  {
    return false;
  }
  virtual bool is_location() const
  {
    return false;
  }
  virtual bool is_output() const
  {
    return false;
  }
  virtual bool is_input() const
  {
    return false;
  }
  virtual bool is_decl() const
  {
    return false;
  }
  virtual bool is_dead() const
  {
    return false;
  }
  virtual bool is_shared_read() const
  {
    return false;
  }
  virtual bool is_shared_write() const
  {
    return false;
  }
  virtual bool is_spawn() const
  {
    return false;
  }
  virtual bool is_memory_barrier() const
  {
    return false;
  }
  virtual bool is_atomic_begin() const
  {
    return false;
  }
  virtual bool is_atomic_end() const
  {
    return false;
  }

  void output(const namespacet &, std::ostream &);

  bool internal() const
  {
    return internal_;
  }
  void internal(bool x)
  {
    internal_ = x;
  }

private:
  bool internal_ = false;
};

namespace detail
{
template <typename Instr>
class goto_trace_step_mixint : public goto_trace_step_baset
{
public:
  void accept(goto_trace_visitort &visitor) override
  {
    visitor.visit(get_instr());
  }

  void accept(const goto_trace_const_visitort &visitor) override
  {
    visitor.visit(get_instr());
  }

  void accept(goto_trace_visitor_const_argst &visitor) const override
  {
    visitor.visit(get_instr());
  }

  void
  accept(const goto_trace_const_visitor_const_argst &visitor) const override
  {
    visitor.visit(get_instr());
  }

  std::unique_ptr<goto_trace_step_baset> clone() const override
  {
    return util_make_unique<Instr>(get_instr());
  }

private:
  Instr &get_instr()
  {
    return static_cast<Instr &>(*this);
  }

  const Instr &get_instr() const
  {
    return static_cast<const Instr &>(*this);
  }
};
} // namespace detail

class goto_trace_step_assignmentt final
  : public detail::goto_trace_step_mixint<goto_trace_step_assignmentt>
{
public:
  bool is_assignment() const override
  {
    return true;
  }
};

class goto_trace_step_assumet final
  : public detail::goto_trace_step_mixint<goto_trace_step_assumet>
{
public:
  bool is_assume() const override
  {
    return true;
  }
};

class goto_trace_step_assertt final
  : public detail::goto_trace_step_mixint<goto_trace_step_assertt>
{
public:
  bool is_assert() const override
  {
    return true;
  }
};

class goto_trace_step_gotot final
  : public detail::goto_trace_step_mixint<goto_trace_step_gotot>
{
public:
  bool is_goto() const override
  {
    return true;
  }
};

class goto_trace_step_constaintt final
  : public detail::goto_trace_step_mixint<goto_trace_step_constaintt>
{
public:
  bool is_constraint() const override
  {
    return true;
  }
};

class goto_trace_step_function_callt final
  : public detail::goto_trace_step_mixint<goto_trace_step_function_callt>
{
public:
  bool is_function_call() const override
  {
    return true;
  }
};

class goto_trace_step_function_returnt final
  : public detail::goto_trace_step_mixint<goto_trace_step_function_returnt>
{
public:
  bool is_function_return() const override
  {
    return true;
  }
};

class goto_trace_step_locationt final
  : public detail::goto_trace_step_mixint<goto_trace_step_locationt>
{
public:
  bool is_location() const override
  {
    return true;
  }
};

class goto_trace_step_outputt final
  : public detail::goto_trace_step_mixint<goto_trace_step_outputt>
{
public:
  bool is_output() const override
  {
    return true;
  }
};

class goto_trace_step_inputt final
  : public detail::goto_trace_step_mixint<goto_trace_step_inputt>
{
public:
  bool is_input() const override
  {
    return true;
  }
};

class goto_trace_step_declt final
  : public detail::goto_trace_step_mixint<goto_trace_step_declt>
{
public:
  bool is_decl() const override
  {
    return true;
  }
};

class goto_trace_step_deadt final
  : public detail::goto_trace_step_mixint<goto_trace_step_deadt>
{
public:
  bool is_dead() const override
  {
    return true;
  }
};

class goto_trace_step_shared_readt final
  : public detail::goto_trace_step_mixint<goto_trace_step_shared_readt>
{
public:
  bool is_shared_read() const override
  {
    return true;
  }
};

class goto_trace_step_shared_writet final
  : public detail::goto_trace_step_mixint<goto_trace_step_shared_writet>
{
public:
  bool is_shared_write() const override
  {
    return true;
  }
};

class goto_trace_step_spawnt final
  : public detail::goto_trace_step_mixint<goto_trace_step_spawnt>
{
public:
  bool is_spawn() const override
  {
    return true;
  }
};

class goto_trace_step_memory_barriert final
  : public detail::goto_trace_step_mixint<goto_trace_step_memory_barriert>
{
public:
  bool is_memory_barrier() const override
  {
    return true;
  }
};

class goto_trace_step_atomic_begint final
  : public detail::goto_trace_step_mixint<goto_trace_step_atomic_begint>
{
public:
  bool is_atomic_begin() const override
  {
    return true;
  }
};

class goto_trace_step_atomic_endt final
  : public detail::goto_trace_step_mixint<goto_trace_step_atomic_endt>
{
public:
  bool is_atomic_end() const override
  {
    return true;
  }
};

class goto_tracet;

class safe_goto_tracet final
{
public:
  // [[deprecated]]
  explicit safe_goto_tracet(const goto_tracet &trace);

  // [[deprecated]]
  goto_tracet make_unsafe() const;

  void output(const namespacet &ns, std::ostream &os) const;

private:
  std::list<std::unique_ptr<goto_trace_step_baset>> steps_;
};

#endif
