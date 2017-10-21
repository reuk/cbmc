/*******************************************************************\

Module: XML Interface

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

/// \file
/// XML Interface

#ifndef CPROVER_CBMC_XML_INTERFACE_H
#define CPROVER_CBMC_XML_INTERFACE_H

#include <istream>
#include <string>
#include <vector>

namespace util {
class registered_optionst;
} // namespace

std::vector<std::string>
parse_xml_cmdline_options(util::registered_optionst const &opts,
                          std::istream &stream);

#endif // CPROVER_CBMC_XML_INTERFACE_H
