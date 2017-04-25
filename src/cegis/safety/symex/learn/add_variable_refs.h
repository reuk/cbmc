/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_SAFETY_SYMEX_LEARN_ADD_VARIABLE_REFS_H
#define CPROVER_CEGIS_SAFETY_SYMEX_LEARN_ADD_VARIABLE_REFS_H

#include <util/irep.h>

typedef std::map<const irep_idt, size_t> operand_variable_idst;

/**
 * @brief
 *
 * @details
 *
 * @param prog
 * @param var_ids
 * @parma max_solution_size
 */
void add_safety_learning_variable_refs(class invariant_programt &prog,
    const operand_variable_idst &var_ids, size_t max_solution_size);

#endif // CPROVER_CEGIS_SAFETY_SYMEX_LEARN_ADD_VARIABLE_REFS_H
