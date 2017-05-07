/*******************************************************************\

Module: Literals

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include "literal.h"

#include <ostream>

/*******************************************************************\

Function: operator <<

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::ostream &operator << (std::ostream &out, literalt l)
{
  if(l.is_constant())
    return out << (l.is_true()?"true":"false");
  else
    return out << (l.sign()?"-":"") << l.var_no();
}
