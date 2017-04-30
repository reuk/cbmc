/*******************************************************************\

Module:

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include "boolbv.h"

/*******************************************************************\

Function: boolbvt::convert_array

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bvt boolbvt::convert_array(const exprt &expr)
{
  std::size_t width=boolbv_width(expr.type());

  if(width==0)
    return conversion_failed(expr);

  if(expr.type().id()==ID_array)
  {
    assert(expr.has_operands());
    const exprt::operandst &operands=expr.operands();
    assert(!operands.empty());
    std::size_t op_width=width/operands.size();

    bvt bv;
    bv.reserve(width);

    for(const auto &it : operands)
    {
      const bvt &tmp=convert_bv(it);

      if(tmp.size()!=op_width)
        throw "convert_array: unexpected operand width";

      for(const auto &it2 : tmp)
        bv.push_back(it2);
    }

    return bv;
  }

  return conversion_failed(expr);
}
