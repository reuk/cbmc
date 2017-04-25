/// \file Type Naming for C

#ifndef CPROVER_ANSI_C_TYPE2NAME_H
#define CPROVER_ANSI_C_TYPE2NAME_H

#include <string>

#include <util/type.h>

std::string type2name(const typet &type);
std::string type2name(const typet &type, const namespacet &ns);

#endif // CPROVER_ANSI_C_TYPE2NAME_H
