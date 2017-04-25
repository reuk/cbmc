/// \file Various predicates over pointers in programs

#ifndef CPROVER_UTIL_POINTER_PREDICATES_H
#define CPROVER_UTIL_POINTER_PREDICATES_H

class exprt;
class namespacet;
class typet;

exprt same_object(const exprt &p1, const exprt &p2);
exprt deallocated(const exprt &pointer, const namespacet &ns);
exprt dead_object(const exprt &pointer, const namespacet &ns);
exprt dynamic_size(const namespacet &ns);
exprt pointer_offset(const exprt &pointer);
exprt malloc_object(const exprt &pointer, const namespacet &ns);
exprt object_size(const exprt &pointer);
exprt pointer_object_has_type(
  const exprt &pointer, const typet &type, const namespacet &ns);
exprt dynamic_object(const exprt &pointer);
exprt good_pointer(const exprt &pointer);
exprt good_pointer_def(const exprt &pointer, const namespacet &ns);
exprt null_object(const exprt &pointer);
exprt null_pointer(const exprt &pointer);
exprt integer_address(const exprt &pointer);
exprt invalid_pointer(const exprt &pointer);
exprt dynamic_object_lower_bound(
  const exprt &pointer,
  const namespacet &ns,
  const exprt &offset);
exprt dynamic_object_upper_bound(
  const exprt &pointer,
  const typet &dereference_type,
  const namespacet &ns,
  const exprt &access_size);
exprt object_lower_bound(
  const exprt &pointer,
  const namespacet &ns,
  const exprt &offset);
exprt object_upper_bound(
  const exprt &pointer,
  const typet &dereference_type,
  const namespacet &ns,
  const exprt &access_size);

#endif // CPROVER_UTIL_POINTER_PREDICATES_H
