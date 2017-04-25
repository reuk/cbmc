#include "typecheck.h"

bool typecheckt::typecheck_main()
{
  try
  {
    typecheck();
  }

  catch(int)
  {
    error_found=true;
  }

  catch(const char *e)
  {
    error() << e << eom;
  }

  catch(const std::string &e)
  {
    error() << e << eom;
  }

  return error_found;
}
