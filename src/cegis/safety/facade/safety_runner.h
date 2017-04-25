/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_SAFETY_FACADE_SAFETY_RUNNER_H
#define CPROVER_CEGIS_SAFETY_FACADE_SAFETY_RUNNER_H

#include <util/message.h>

/**
 * @brief
 *
 * @details
 *
 * @param cmdline
 * @param options
 * @param result
 * @param st
 * @param gf
 *
 * @return
 */
int run_safety(class optionst &options, messaget::mstreamt &result,
    const class symbol_tablet &st, const class goto_functionst &gf);

#endif // CPROVER_CEGIS_SAFETY_FACADE_SAFETY_RUNNER_H
