/*******************************************************************\

Module: Copy on write class

Author: Reuben Thomas, reuben.thomas@diffblue.com

\*******************************************************************/

#ifndef CPROVER_UTIL_COW_H
#define CPROVER_UTIL_COW_H

#include "util/small_shared_ptr.h"
#include "util/invariant.h"

#include <limits>

template <typename T>
class copy_on_writet final
{
public:
  // Note that this *is* the default constructor. An invariant of a
  // copy-on-write object is that it is never null.
  template <typename... Ts>
  explicit copy_on_writet(Ts &&... ts)
    : t_(make_small_shared_ptr<T>(std::forward<Ts>(ts)...))
  {
    INVARIANT(
      pointee_is_shareable(*t_),
      "newly-constructed COW pointers must be shareable");
  }

  copy_on_writet(const copy_on_writet &rhs)
    : t_(
        pointee_is_shareable(*rhs.t_) ? rhs.t_
                                      : make_small_shared_ptr<T>(*rhs.t_))
  {
    INVARIANT(
      pointee_is_shareable(*t_),
      "newly-constructed COW pointers must be shareable");
  }

  copy_on_writet &operator=(const copy_on_writet &rhs)
  {
    auto copy(rhs);
    swap(copy);
    return *this;
  }

  copy_on_writet(copy_on_writet &&rhs)
  {
    swap(rhs);
  }

  copy_on_writet &operator=(copy_on_writet &&rhs)
  {
    swap(rhs);
    return *this;
  }

  ~copy_on_writet() = default; // delete if the refcount is 1, like usual

  void swap(copy_on_writet &rhs)
  {
    std::swap(t_, rhs.t_);
  }

  const T &read() const
  {
    return *t_;
  }

  T &write(bool mark_shareable)
  {
    if(pointee_use_count(*t_) != 1)
    {
      t_ = make_small_shared_ptr<T>(*t_);
    }
    INVARIANT(
      pointee_use_count(*t_) == 1,
      "mutable references to a COW pointer must be unique");
    pointee_set_shareable(*t_, mark_shareable);
    INVARIANT(
      pointee_is_shareable(*t_) == mark_shareable,
      "sharing flag must have expected value after obtaining mutable ref");
    return *t_;
  }

  // Ideally these would be non-members, but they depend on private member t_

  template <typename U>
  bool operator==(const copy_on_writet<U> &rhs) const
  {
    return t_ == rhs.t_;
  }

  template <typename U>
  bool operator!=(const copy_on_writet<U> &rhs) const
  {
    return t_ != rhs.t_;
  }

  template <typename U>
  bool operator<(const copy_on_writet<U> &rhs) const
  {
    return t_ < rhs.t_;
  }

  template <typename U>
  bool operator>(const copy_on_writet<U> &rhs) const
  {
    return t_ > rhs.t_;
  }

  template <typename U>
  bool operator<=(const copy_on_writet<U> &rhs) const
  {
    return t_ <= rhs.t_;
  }

  template <typename U>
  bool operator>=(const copy_on_writet<U> &rhs) const
  {
    return t_ >= rhs.t_;
  }

private:
  small_shared_ptrt<T> t_;
};

////////////////////////////////////////////////////////////////////////////////

template <typename Num>
class copy_on_write_pointeet
{
public:
  copy_on_write_pointeet() = default;

  copy_on_write_pointeet(const copy_on_write_pointeet &)
  {
  }

  copy_on_write_pointeet &operator=(const copy_on_write_pointeet &)
  {
    return *this;
  }

  copy_on_write_pointeet(copy_on_write_pointeet &&)
  {
  }

  copy_on_write_pointeet &operator=(copy_on_write_pointeet &&)
  {
    return *this;
  }

  void increment_use_count()
  {
    INVARIANT(
      is_shareable(),
      "cannot increment the use count of a non-shareable reference");
    use_count_ += 1;
  }

  void decrement_use_count()
  {
    INVARIANT(
      is_shareable(),
      "cannot decrement the use count of a non-shareable reference");
    use_count_ -= 1;
  }

  Num use_count() const
  {
    return is_shareable() ? use_count_ : 1;
  }

  void set_shareable(bool u)
  {
    use_count_ = u ? 1 : unshareable;
  }

  bool is_shareable() const
  {
    return use_count_ != unshareable;
  }

protected:
  ~copy_on_write_pointeet() = default;

private:
  static const Num unshareable;
  Num use_count_ = 0;
};

template <typename Num>
const Num copy_on_write_pointeet<Num>::unshareable =
  (std::numeric_limits<Num>::max)(); // suppress macro expansion on windows

template <typename Num>
inline void pointee_increment_use_count(copy_on_write_pointeet<Num> &p)
{
  p.increment_use_count();
}

template <typename Num>
inline void pointee_decrement_use_count(copy_on_write_pointeet<Num> &p)
{
  p.decrement_use_count();
}

template <typename Num>
inline Num pointee_use_count(const copy_on_write_pointeet<Num> &p)
{
  return p.use_count();
}

template <typename Num, typename T>
inline void pointee_set_use_count(copy_on_write_pointeet<Num> &p, T count)
{
  p.set_use_count(count);
}

template <typename Num>
inline void pointee_set_shareable(copy_on_write_pointeet<Num> &p, bool u)
{
  p.set_shareable(u);
}

template <typename Num>
inline bool pointee_is_shareable(const copy_on_write_pointeet<Num> &p)
{
  return p.is_shareable();
}

#endif
