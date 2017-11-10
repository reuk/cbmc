/*******************************************************************\

Module: Safe traces of GOTO Programs

Author: @reuk

\*******************************************************************/

/// \file
/// Safe traces of GOTO Programs

#ifndef CPROVER_GOTO_PROGRAMS_SAFE_GOTO_TRACE_H
#define CPROVER_GOTO_PROGRAMS_SAFE_GOTO_TRACE_H

#include <goto-programs/goto_program.h>
#include <goto-programs/goto_trace.h>

#include <util/dereference_iterator.h>
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

  virtual void visit(goto_trace_step_assignmentt &) = 0;
  virtual void visit(goto_trace_step_assumet &) = 0;
  virtual void visit(goto_trace_step_assertt &) = 0;
  virtual void visit(goto_trace_step_gotot &) = 0;
  virtual void visit(goto_trace_step_constraintt &) = 0;
  virtual void visit(goto_trace_step_function_callt &) = 0;
  virtual void visit(goto_trace_step_function_returnt &) = 0;
  virtual void visit(goto_trace_step_locationt &) = 0;
  virtual void visit(goto_trace_step_outputt &) = 0;
  virtual void visit(goto_trace_step_inputt &) = 0;
  virtual void visit(goto_trace_step_declt &) = 0;
  virtual void visit(goto_trace_step_deadt &) = 0;
  virtual void visit(goto_trace_step_shared_readt &) = 0;
  virtual void visit(goto_trace_step_shared_writet &) = 0;
  virtual void visit(goto_trace_step_spawnt &) = 0;
  virtual void visit(goto_trace_step_memory_barriert &) = 0;
  virtual void visit(goto_trace_step_atomic_begint &) = 0;
  virtual void visit(goto_trace_step_atomic_endt &) = 0;
};

class goto_trace_const_visitort
{
public:
  virtual ~goto_trace_const_visitort() = default;

  virtual void visit(goto_trace_step_assignmentt &) const = 0;
  virtual void visit(goto_trace_step_assumet &) const = 0;
  virtual void visit(goto_trace_step_assertt &) const = 0;
  virtual void visit(goto_trace_step_gotot &) const = 0;
  virtual void visit(goto_trace_step_constraintt &) const = 0;
  virtual void visit(goto_trace_step_function_callt &) const = 0;
  virtual void visit(goto_trace_step_function_returnt &) const = 0;
  virtual void visit(goto_trace_step_locationt &) const = 0;
  virtual void visit(goto_trace_step_outputt &) const = 0;
  virtual void visit(goto_trace_step_inputt &) const = 0;
  virtual void visit(goto_trace_step_declt &) const = 0;
  virtual void visit(goto_trace_step_deadt &) const = 0;
  virtual void visit(goto_trace_step_shared_readt &) const = 0;
  virtual void visit(goto_trace_step_shared_writet &) const = 0;
  virtual void visit(goto_trace_step_spawnt &) const = 0;
  virtual void visit(goto_trace_step_memory_barriert &) const = 0;
  virtual void visit(goto_trace_step_atomic_begint &) const = 0;
  virtual void visit(goto_trace_step_atomic_endt &) const = 0;
};

class goto_trace_visitor_const_argst
{
public:
  virtual ~goto_trace_visitor_const_argst() = default;

  virtual void visit(const goto_trace_step_assignmentt &) = 0;
  virtual void visit(const goto_trace_step_assumet &) = 0;
  virtual void visit(const goto_trace_step_assertt &) = 0;
  virtual void visit(const goto_trace_step_gotot &) = 0;
  virtual void visit(const goto_trace_step_constraintt &) = 0;
  virtual void visit(const goto_trace_step_function_callt &) = 0;
  virtual void visit(const goto_trace_step_function_returnt &) = 0;
  virtual void visit(const goto_trace_step_locationt &) = 0;
  virtual void visit(const goto_trace_step_outputt &) = 0;
  virtual void visit(const goto_trace_step_inputt &) = 0;
  virtual void visit(const goto_trace_step_declt &) = 0;
  virtual void visit(const goto_trace_step_deadt &) = 0;
  virtual void visit(const goto_trace_step_shared_readt &) = 0;
  virtual void visit(const goto_trace_step_shared_writet &) = 0;
  virtual void visit(const goto_trace_step_spawnt &) = 0;
  virtual void visit(const goto_trace_step_memory_barriert &) = 0;
  virtual void visit(const goto_trace_step_atomic_begint &) = 0;
  virtual void visit(const goto_trace_step_atomic_endt &) = 0;
};

class goto_trace_const_visitor_const_argst
{
public:
  virtual ~goto_trace_const_visitor_const_argst() = default;

  virtual void visit(const goto_trace_step_assignmentt &) const = 0;
  virtual void visit(const goto_trace_step_assumet &) const = 0;
  virtual void visit(const goto_trace_step_assertt &) const = 0;
  virtual void visit(const goto_trace_step_gotot &) const = 0;
  virtual void visit(const goto_trace_step_constraintt &) const = 0;
  virtual void visit(const goto_trace_step_function_callt &) const = 0;
  virtual void visit(const goto_trace_step_function_returnt &) const = 0;
  virtual void visit(const goto_trace_step_locationt &) const = 0;
  virtual void visit(const goto_trace_step_outputt &) const = 0;
  virtual void visit(const goto_trace_step_inputt &) const = 0;
  virtual void visit(const goto_trace_step_declt &) const = 0;
  virtual void visit(const goto_trace_step_deadt &) const = 0;
  virtual void visit(const goto_trace_step_shared_readt &) const = 0;
  virtual void visit(const goto_trace_step_shared_writet &) const = 0;
  virtual void visit(const goto_trace_step_spawnt &) const = 0;
  virtual void visit(const goto_trace_step_memory_barriert &) const = 0;
  virtual void visit(const goto_trace_step_atomic_begint &) const = 0;
  virtual void visit(const goto_trace_step_atomic_endt &) const = 0;
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

  virtual bool is_assignment() const;
  virtual bool is_assume() const;
  virtual bool is_assert() const;
  virtual bool is_goto() const;
  virtual bool is_constraint() const;
  virtual bool is_function_call() const;
  virtual bool is_function_return() const;
  virtual bool is_location() const;
  virtual bool is_output() const;
  virtual bool is_input() const;
  virtual bool is_decl() const;
  virtual bool is_dead() const;
  virtual bool is_shared_read() const;
  virtual bool is_shared_write() const;
  virtual bool is_spawn() const;
  virtual bool is_memory_barrier() const;
  virtual bool is_atomic_begin() const;
  virtual bool is_atomic_end() const;

  void output(const namespacet &, std::ostream &);

  bool hidden() const
  {
    return hidden_;
  }
  void hidden(bool hidden)
  {
    hidden_ = hidden;
  }

  bool internal() const
  {
    return internal_;
  }
  void internal(bool internal)
  {
    internal_ = internal;
  }

  goto_programt::const_targett pc() const
  {
    return pc_;
  }
  void pc(goto_programt::const_targett pc)
  {
    pc_ = std::move(pc);
  }

  unsigned thread_nr() const
  {
    return thread_nr_;
  }
  void thread_nr(unsigned thread_nr)
  {
    thread_nr_ = thread_nr;
  }

private:
  bool hidden_ = false;
  bool internal_ = false;
  goto_programt::const_targett pc_;
  unsigned thread_nr_;
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
  explicit goto_trace_step_assignmentt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_assignment() const override;

  ssa_exprt lhs_object() const
  {
    return step_.lhs_object;
  }
  void lhs_object(ssa_exprt lhs_object)
  {
    step_.lhs_object = std::move(lhs_object);
  }

  exprt full_lhs() const
  {
    return step_.full_lhs;
  }
  void full_lhs(exprt full_lhs)
  {
    step_.full_lhs = std::move(full_lhs);
  }

  exprt full_lhs_value() const
  {
    return step_.full_lhs_value;
  }
  void full_lhs_value(exprt full_lhs_value)
  {
    step_.full_lhs_value = std::move(full_lhs_value);
  }

  goto_trace_stept::assignment_typet assignment_type() const
  {
    return step_.assignment_type;
  }
  void assignment_type(goto_trace_stept::assignment_typet assignment_type)
  {
    step_.assignment_type = assignment_type;
  }

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_assumet final
  : public detail::goto_trace_step_mixint<goto_trace_step_assumet>
{
public:
  explicit goto_trace_step_assumet(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_assume() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_assertt final
  : public detail::goto_trace_step_mixint<goto_trace_step_assertt>
{
public:
  explicit goto_trace_step_assertt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_assert() const override;

  bool cond_value() const
  {
    return step_.cond_value;
  }
  void cond_value(bool cond_value)
  {
    step_.cond_value = cond_value;
  }

  std::string comment() const
  {
    return step_.comment;
  }
  void comment(std::string comment)
  {
    step_.comment = std::move(comment);
  }

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_gotot final
  : public detail::goto_trace_step_mixint<goto_trace_step_gotot>
{
public:
  explicit goto_trace_step_gotot(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_goto() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_constraintt final
  : public detail::goto_trace_step_mixint<goto_trace_step_constraintt>
{
public:
  explicit goto_trace_step_constraintt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_constraint() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_function_callt final
  : public detail::goto_trace_step_mixint<goto_trace_step_function_callt>
{
public:
  explicit goto_trace_step_function_callt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_function_call() const override;

  irep_idt identifier() const
  {
    return step_.identifier;
  }
  void identifier(irep_idt identifier)
  {
    step_.identifier = std::move(identifier);
  }

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_function_returnt final
  : public detail::goto_trace_step_mixint<goto_trace_step_function_returnt>
{
public:
  explicit goto_trace_step_function_returnt(goto_trace_stept &step)
    : step_(step)
  {
  }

  bool is_function_return() const override;

  irep_idt identifier() const
  {
    return step_.identifier;
  }
  void identifier(irep_idt identifier)
  {
    step_.identifier = std::move(identifier);
  }

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_locationt final
  : public detail::goto_trace_step_mixint<goto_trace_step_locationt>
{
public:
  explicit goto_trace_step_locationt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_location() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_outputt final
  : public detail::goto_trace_step_mixint<goto_trace_step_outputt>
{
public:
  explicit goto_trace_step_outputt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_output() const override;

  irep_idt format_string() const
  {
    return step_.format_string;
  }
  void format_string(irep_idt format_string)
  {
    step_.format_string = std::move(format_string);
  }

  irep_idt io_id() const
  {
    return step_.io_id;
  }
  void io_id(irep_idt io_id)
  {
    step_.io_id = std::move(io_id);
  }

  std::list<exprt> io_args() const
  {
    return step_.io_args;
  }
  void io_args(std::list<exprt> io_args)
  {
    step_.io_args = std::move(io_args);
  }

  bool formatted() const
  {
    return step_.formatted;
  }
  void formatted(bool formatted)
  {
    step_.formatted = formatted;
  }

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_inputt final
  : public detail::goto_trace_step_mixint<goto_trace_step_inputt>
{
public:
  explicit goto_trace_step_inputt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_input() const override;

  irep_idt format_string() const
  {
    return step_.format_string;
  }
  void format_string(irep_idt format_string)
  {
    step_.format_string = std::move(format_string);
  }

  irep_idt io_id() const
  {
    return step_.io_id;
  }
  void io_id(irep_idt io_id)
  {
    step_.io_id = std::move(io_id);
  }

  std::list<exprt> io_args() const
  {
    return step_.io_args;
  }
  void io_args(std::list<exprt> io_args)
  {
    step_.io_args = std::move(io_args);
  }

  bool formatted() const
  {
    return step_.formatted;
  }
  void formatted(bool formatted)
  {
    step_.formatted = formatted;
  }

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_declt final
  : public detail::goto_trace_step_mixint<goto_trace_step_declt>
{
public:
  explicit goto_trace_step_declt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_decl() const override;

  ssa_exprt lhs_object() const
  {
    return step_.lhs_object;
  }
  void lhs_object(ssa_exprt lhs_object)
  {
    step_.lhs_object = std::move(lhs_object);
  }

  exprt full_lhs() const
  {
    return step_.full_lhs;
  }
  void full_lhs(exprt full_lhs)
  {
    step_.full_lhs = std::move(full_lhs);
  }

  exprt full_lhs_value() const
  {
    return step_.full_lhs_value;
  }
  void full_lhs_value(exprt full_lhs_value)
  {
    step_.full_lhs_value = std::move(full_lhs_value);
  }

  goto_trace_stept::assignment_typet assignment_type() const
  {
    return step_.assignment_type;
  }
  void assignment_type(goto_trace_stept::assignment_typet assignment_type)
  {
    step_.assignment_type = assignment_type;
  }

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_deadt final
  : public detail::goto_trace_step_mixint<goto_trace_step_deadt>
{
public:
  explicit goto_trace_step_deadt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_dead() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_shared_readt final
  : public detail::goto_trace_step_mixint<goto_trace_step_shared_readt>
{
public:
  explicit goto_trace_step_shared_readt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_shared_read() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_shared_writet final
  : public detail::goto_trace_step_mixint<goto_trace_step_shared_writet>
{
public:
  explicit goto_trace_step_shared_writet(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_shared_write() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_spawnt final
  : public detail::goto_trace_step_mixint<goto_trace_step_spawnt>
{
public:
  explicit goto_trace_step_spawnt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_spawn() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_memory_barriert final
  : public detail::goto_trace_step_mixint<goto_trace_step_memory_barriert>
{
public:
  explicit goto_trace_step_memory_barriert(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_memory_barrier() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_atomic_begint final
  : public detail::goto_trace_step_mixint<goto_trace_step_atomic_begint>
{
public:
  explicit goto_trace_step_atomic_begint(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_atomic_begin() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

class goto_trace_step_atomic_endt final
  : public detail::goto_trace_step_mixint<goto_trace_step_atomic_endt>
{
public:
  explicit goto_trace_step_atomic_endt(goto_trace_stept &step) : step_(step)
  {
  }

  bool is_atomic_end() const override;

private:
  goto_trace_stept &step_; // MUST remain private
};

#endif
