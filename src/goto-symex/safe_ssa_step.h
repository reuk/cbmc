/*******************************************************************\

Module: Safe SSA steps

Author: @reuk

\*******************************************************************/

/// \file
/// Safe SSA steps

#ifndef CPROVER_GOTO_SYMEX_SAFE_SSA_STEP_H
#define CPROVER_GOTO_SYMEX_SAFE_SSA_STEP_H

#include "symex_target.h"
#include "symex_target_equation.h"

#include <util/make_unique.h>
#include <util/merge_irep.h>

class ssa_step_assertt;
class ssa_step_assumet;
class ssa_step_assignmentt;
class ssa_step_gotot;
class ssa_step_constraintt;
class ssa_step_locationt;
class ssa_step_intputt;
class ssa_step_outputt;
class ssa_step_declt;
class ssa_step_function_callt;
class ssa_step_function_returnt;
class ssa_step_shared_readt;
class ssa_step_shared_writet;
class ssa_step_spawnt;
class ssa_step_memory_barriert;
class ssa_step_atomic_begint;
class ssa_step_atomic_endt;

class ssa_step_visitort
{
  virtual ~ssa_step_visitort() = default;

  virtual void visit(ssa_step_assertt &) = 0;
  virtual void visit(ssa_step_assumet &) = 0;
  virtual void visit(ssa_step_assignmentt &) = 0;
  virtual void visit(ssa_step_gotot &) = 0;
  virtual void visit(ssa_step_constraintt &) = 0;
  virtual void visit(ssa_step_locationt &) = 0;
  virtual void visit(ssa_step_intputt &) = 0;
  virtual void visit(ssa_step_outputt &) = 0;
  virtual void visit(ssa_step_declt &) = 0;
  virtual void visit(ssa_step_function_callt &) = 0;
  virtual void visit(ssa_step_function_returnt &) = 0;
  virtual void visit(ssa_step_shared_readt &) = 0;
  virtual void visit(ssa_step_shared_writet &) = 0;
  virtual void visit(ssa_step_spawnt &) = 0;
  virtual void visit(ssa_step_memory_barriert &) = 0;
  virtual void visit(ssa_step_atomic_begint &) = 0;
  virtual void visit(ssa_step_atomic_endt &) = 0;
};

class ssa_step_const_visitort
{
  virtual ~ssa_step_const_visitort() = default;

  virtual void visit(ssa_step_assertt &) const = 0;
  virtual void visit(ssa_step_assumet &) const = 0;
  virtual void visit(ssa_step_assignmentt &) const = 0;
  virtual void visit(ssa_step_gotot &) const = 0;
  virtual void visit(ssa_step_constraintt &) const = 0;
  virtual void visit(ssa_step_locationt &) const = 0;
  virtual void visit(ssa_step_intputt &) const = 0;
  virtual void visit(ssa_step_outputt &) const = 0;
  virtual void visit(ssa_step_declt &) const = 0;
  virtual void visit(ssa_step_function_callt &) const = 0;
  virtual void visit(ssa_step_function_returnt &) const = 0;
  virtual void visit(ssa_step_shared_readt &) const = 0;
  virtual void visit(ssa_step_shared_writet &) const = 0;
  virtual void visit(ssa_step_spawnt &) const = 0;
  virtual void visit(ssa_step_memory_barriert &) const = 0;
  virtual void visit(ssa_step_atomic_begint &) const = 0;
  virtual void visit(ssa_step_atomic_endt &) const = 0;
};

class ssa_step_visitor_const_argst
{
  virtual ~ssa_step_visitor_const_argst() = default;

  virtual void visit(const ssa_step_assertt &) = 0;
  virtual void visit(const ssa_step_assumet &) = 0;
  virtual void visit(const ssa_step_assignmentt &) = 0;
  virtual void visit(const ssa_step_gotot &) = 0;
  virtual void visit(const ssa_step_constraintt &) = 0;
  virtual void visit(const ssa_step_locationt &) = 0;
  virtual void visit(const ssa_step_intputt &) = 0;
  virtual void visit(const ssa_step_outputt &) = 0;
  virtual void visit(const ssa_step_declt &) = 0;
  virtual void visit(const ssa_step_function_callt &) = 0;
  virtual void visit(const ssa_step_function_returnt &) = 0;
  virtual void visit(const ssa_step_shared_readt &) = 0;
  virtual void visit(const ssa_step_shared_writet &) = 0;
  virtual void visit(const ssa_step_spawnt &) = 0;
  virtual void visit(const ssa_step_memory_barriert &) = 0;
  virtual void visit(const ssa_step_atomic_begint &) = 0;
  virtual void visit(const ssa_step_atomic_endt &) = 0;
};

class ssa_step_const_visitor_const_argst
{
  virtual ~ssa_step_const_visitor_const_argst() = default;

  virtual void visit(const ssa_step_assertt &) const = 0;
  virtual void visit(const ssa_step_assumet &) const = 0;
  virtual void visit(const ssa_step_assignmentt &) const = 0;
  virtual void visit(const ssa_step_gotot &) const = 0;
  virtual void visit(const ssa_step_constraintt &) const = 0;
  virtual void visit(const ssa_step_locationt &) const = 0;
  virtual void visit(const ssa_step_intputt &) const = 0;
  virtual void visit(const ssa_step_outputt &) const = 0;
  virtual void visit(const ssa_step_declt &) const = 0;
  virtual void visit(const ssa_step_function_callt &) const = 0;
  virtual void visit(const ssa_step_function_returnt &) const = 0;
  virtual void visit(const ssa_step_shared_readt &) const = 0;
  virtual void visit(const ssa_step_shared_writet &) const = 0;
  virtual void visit(const ssa_step_spawnt &) const = 0;
  virtual void visit(const ssa_step_memory_barriert &) const = 0;
  virtual void visit(const ssa_step_atomic_begint &) const = 0;
  virtual void visit(const ssa_step_atomic_endt &) const = 0;
};

class ssa_step_baset
{
public:
  virtual ~ssa_step_baset() = default;

  virtual void accept(ssa_step_visitort &) = 0;
  virtual void accept(const ssa_step_const_visitort &) = 0;
  virtual void accept(ssa_step_visitor_const_argst &) const = 0;
  virtual void accept(const ssa_step_const_visitor_const_argst &) const = 0;

  virtual std::unique_ptr<ssa_step_baset> clone() const = 0;

  virtual bool is_assert() const;
  virtual bool is_assume() const;
  virtual bool is_assignment() const;
  virtual bool is_goto() const;
  virtual bool is_location() const;
  virtual bool is_output() const;
  virtual bool is_decl() const;
  virtual bool is_function_call() const;
  virtual bool is_function_return() const;
  virtual bool is_shared_read() const;
  virtual bool is_shared_write() const;
  virtual bool is_spawn() const;
  virtual bool is_memory_barrier() const;
  virtual bool is_atomic_begin() const;
  virtual bool is_atomic_end() const;

  bool hidden() const { return hidden_; }
  void hidden(bool hidden) { hidden_ = hidden; }

private:
  bool hidden_;
};

namespace detail
{
template <typename Instr>
class ssa_step_mixint : public ssa_step_baset
{
public:
  void accept(ssa_step_visitort &visitor) override
  {
    visitor.visit(get_instr());
  }

  void accept(const ssa_step_const_visitort &visitor) override
  {
    visitor.visit(get_instr());
  }

  void accept(ssa_step_visitor_const_argst &visitor) const override
  {
    visitor.visit(get_instr());
  }

  void accept(const ssa_step_const_visitor_const_argst &visitor) const override
  {
    visitor.visit(get_instr());
  }

  std::unique_ptr<ssa_step_baset> clone() const override
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

class ssa_step_assertt : public detail::ssa_step_mixint<ssa_step_assertt>
{
public:
  bool is_assert() const override;

private:
};

class ssa_step_assumet : public detail::ssa_step_mixint<ssa_step_assumet>
{
public:
  bool is_assume() const override;

private:
};

class ssa_step_assignmentt
  : public detail::ssa_step_mixint<ssa_step_assignmentt>
{
public:
  bool is_assignment() const override;

private:
};

class ssa_step_gotot : public detail::ssa_step_mixint<ssa_step_gotot>
{
public:
  bool is_goto() const override;

private:
};

class ssa_step_constraintt
  : public detail::ssa_step_mixint<ssa_step_constraintt>
{
public:
private:
};

class ssa_step_locationt : public detail::ssa_step_mixint<ssa_step_locationt>
{
public:
  bool is_location() const override;

private:
};

class ssa_step_intputt : public detail::ssa_step_mixint<ssa_step_intputt>
{
public:
private:
};

class ssa_step_outputt : public detail::ssa_step_mixint<ssa_step_outputt>
{
public:
  bool is_output() const override;

private:
};

class ssa_step_declt : public detail::ssa_step_mixint<ssa_step_declt>
{
public:
  bool is_decl() const override;

private:
};

class ssa_step_function_callt
  : public detail::ssa_step_mixint<ssa_step_function_callt>
{
public:
  bool is_function_call() const override;

private:
};

class ssa_step_function_returnt
  : public detail::ssa_step_mixint<ssa_step_function_returnt>
{
public:
  bool is_function_return() const override;

private:
};

class ssa_step_shared_readt
  : public detail::ssa_step_mixint<ssa_step_shared_readt>
{
public:
  bool is_shared_read() const override;

private:
};

class ssa_step_shared_writet
  : public detail::ssa_step_mixint<ssa_step_shared_writet>
{
public:
  bool is_shared_write() const override;

private:
};

class ssa_step_spawnt : public detail::ssa_step_mixint<ssa_step_spawnt>
{
public:
  bool is_spawn() const override;

private:
};

class ssa_step_memory_barriert
  : public detail::ssa_step_mixint<ssa_step_memory_barriert>
{
public:
  bool is_memory_barrier() const override;

private:
};

class ssa_step_atomic_begint
  : public detail::ssa_step_mixint<ssa_step_atomic_begint>
{
public:
  bool is_atomic_begin() const override;

private:
};

class ssa_step_atomic_endt
  : public detail::ssa_step_mixint<ssa_step_atomic_endt>
{
public:
  bool is_atomic_end() const override;

private:
};

class safe_symex_target_equationt : public symex_targett
{
public:
  explicit safe_symex_target_equationt(const namespacet &ns): ns_(ns) {}

  // [[deprecated]]
  safe_symex_target_equationt(const symex_target_equationt &other);

private:
  std::list<std::unique_ptr<ssa_step_baset>> steps_;
  const namespacet &ns_;
  merge_irept merge_irep_;
};

#endif
