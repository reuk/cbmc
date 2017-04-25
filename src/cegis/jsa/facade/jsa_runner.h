/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_JSA_FACADE_JSA_RUNNER_H
#define CPROVER_CEGIS_JSA_FACADE_JSA_RUNNER_H

#include <util/message.h>

/**
 * @brief
 *
 * @details
 *
 * @param options
 * @param result
 * @param st
 * @param gf
 *
 * @return
 */
int run_jsa(class optionst &options, messaget::mstreamt &result,
    const class symbol_tablet &st, const class goto_functionst &gf);

#endif // CPROVER_CEGIS_JSA_FACADE_JSA_RUNNER_H
