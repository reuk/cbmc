/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_JSA_PREPROCESSING_ADD_SYNTHESIS_LIBRARY_H
#define CPROVER_CEGIS_JSA_PREPROCESSING_ADD_SYNTHESIS_LIBRARY_H

#include <goto-programs/goto_program.h>

/**
 * @brief
 *
 * @details
 *
 * @param prog
 * @param max_sz
 * @param pred_op_locations
 */
void add_jsa_library(
    class jsa_programt &prog,
    size_t max_sz,
    const goto_programt::targetst &pred_op_locations);

#endif // CPROVER_CEGIS_JSA_PREPROCESSING_ADD_SYNTHESIS_LIBRARY_H
