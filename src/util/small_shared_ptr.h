/*******************************************************************\

Module: Small intrusive shared pointers

Author: Reuben Thomas, reuben.thomas@diffblue.com

\*******************************************************************/

#ifndef CPROVER_UTIL_SMALL_SHARED_PTR_H
#define CPROVER_UTIL_SMALL_SHARED_PTR_H

#include <iosfwd>  // ostream
#include <utility> // swap

// TODO We should liberally scatter `constexpr`s and `noexcept`s on platforms
// that support them.

// This class is really similar to boost's intrusive_pointer, but can be a bit
// simpler seeing as we're only using it one place...

template <typename T>
class small_shared_ptrt final
{
public:
  small_shared_ptrt() = default;

  explicit small_shared_ptrt(T *t) : t_(t)
  {
    if(t_)
    {
      pointee_increment_use_count(*t_);
    }
  }

  small_shared_ptrt(const small_shared_ptrt &rhs) : t_(rhs.t_)
  {
    if(t_)
    {
      pointee_increment_use_count(*t_);
    }
  }

  small_shared_ptrt &operator=(const small_shared_ptrt &rhs)
  {
    auto copy(rhs);
    swap(copy);
    return *this;
  }

  small_shared_ptrt(small_shared_ptrt &&rhs)
  {
    swap(rhs);
  }

  small_shared_ptrt &operator=(small_shared_ptrt &&rhs)
  {
    swap(rhs);
    return *this;
  }

  ~small_shared_ptrt()
  {
    if(!t_)
    {
      return;
    }
    if(pointee_use_count(*t_) == 1)
    {
      delete t_;
      return;
    }
    pointee_decrement_use_count(*t_);
  }

  void swap(small_shared_ptrt &rhs)
  {
    std::swap(t_, rhs.t_);
  }

  T *get() const
  {
    return t_;
  }

  T &operator*() const
  {
    return *t_;
  }

  T *operator->() const
  {
    return t_;
  }

  auto use_count() const -> decltype(pointee_use_count(std::declval<T>()))
  {
    return t_ ? pointee_use_count(*t_) : 0;
  }

  explicit operator bool() const
  {
    return t_ != nullptr;
  }

private:
  T *t_ = nullptr;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const small_shared_ptrt<T> &ptr)
{
  return os << ptr.get();
}

template <typename T, typename... Ts>
small_shared_ptrt<T> make_small_shared_ptr(Ts &&... ts)
{
  return small_shared_ptrt<T>(new T(std::forward<Ts>(ts)...));
}

template <typename T, typename U>
bool operator==(
  const small_shared_ptrt<T> &lhs,
  const small_shared_ptrt<U> &rhs)
{
  return lhs.get() == rhs.get();
}

template <typename T, typename U>
bool operator!=(
  const small_shared_ptrt<T> &lhs,
  const small_shared_ptrt<U> &rhs)
{
  return lhs.get() != rhs.get();
}

template <typename T, typename U>
bool operator<(const small_shared_ptrt<T> &lhs, const small_shared_ptrt<U> &rhs)
{
  return lhs.get() < rhs.get();
}

template <typename T, typename U>
bool operator>(const small_shared_ptrt<T> &lhs, const small_shared_ptrt<U> &rhs)
{
  return lhs.get() > rhs.get();
}

template <typename T, typename U>
bool operator<=(
  const small_shared_ptrt<T> &lhs,
  const small_shared_ptrt<U> &rhs)
{
  return lhs.get() <= rhs.get();
}

template <typename T, typename U>
bool operator>=(
  const small_shared_ptrt<T> &lhs,
  const small_shared_ptrt<U> &rhs)
{
  return lhs.get() >= rhs.get();
}

////////////////////////////////////////////////////////////////////////////////

template <typename Num>
class small_shared_pointeet
{
public:
  small_shared_pointeet() = default;

  // These can't be `= default` because we need the use_count_ to be unaffected
  small_shared_pointeet(const small_shared_pointeet &rhs)
  {
  }
  small_shared_pointeet &operator=(const small_shared_pointeet &rhs)
  {
    return *this;
  }
  small_shared_pointeet(small_shared_pointeet &&rhs)
  {
  }
  small_shared_pointeet &operator=(small_shared_pointeet &&rhs)
  {
    return *this;
  }

  void increment_use_count()
  {
    use_count_ += 1;
  }
  void decrement_use_count()
  {
    use_count_ -= 1;
  }
  Num use_count() const
  {
    return use_count_;
  }

protected:
  // Enables public inheritance but disables polymorphic usage
  ~small_shared_pointeet() = default;

private:
  Num use_count_ = 0;
};

template <typename Num>
inline void pointee_increment_use_count(small_shared_pointeet<Num> &p)
{
  p.increment_use_count();
}

template <typename Num>
inline void pointee_decrement_use_count(small_shared_pointeet<Num> &p)
{
  p.decrement_use_count();
}

template <typename Num>
inline Num pointee_use_count(const small_shared_pointeet<Num> &p)
{
  return p.use_count();
}

#endif