/// \file Memory-mapped I/O Instrumentation for Goto Programs

#ifndef CPROVER_GOTO_INSTRUMENT_MMIO_H
#define CPROVER_GOTO_INSTRUMENT_MMIO_H

class value_setst;
class symbol_tablet;
class goto_functionst;

void mmio(
  value_setst &value_sets,
  class symbol_tablet &symbol_table,
  goto_functionst &goto_functions);

#endif // CPROVER_GOTO_INSTRUMENT_MMIO_H
