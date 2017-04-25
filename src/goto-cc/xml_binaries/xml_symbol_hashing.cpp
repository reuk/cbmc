/// \file XML-symbol conversions with irep hashing

#include "xml_symbol_hashing.h"
#include "xml_irep_hashing.h"

/// converts a symbol to an xml symbol node
///
/// parameters: a symbol and an xml node
///
/// \returns none
void xml_symbol_convertt::convert(const symbolt &sym, xmlt &root)
{
  xmlt &xmlsym = root.new_element("symbol");
  irepcache.push_back(irept());
  sym.to_irep(irepcache.back());
  irepconverter.reference_convert(irepcache.back(), xmlsym);
}

/// converts an xml symbol node to a symbol
///
/// parameters: an xml node and a symbol
///
/// \returns none
void xml_symbol_convertt::convert(const xmlt &xmlsym, symbolt &symbol)
{
  irept t;

  irepconverter.convert(xmlsym, t);
  irepconverter.resolve_references(t);
  symbol.from_irep(t);
}
