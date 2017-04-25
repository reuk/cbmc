/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_JSA_LEARN_INSERT_PREDICATES_AND_QUERIES_H
#define CPROVER_CEGIS_JSA_LEARN_INSERT_PREDICATES_AND_QUERIES_H

#include <cstddef>

/**
 * @brief
 *
 * @details
 *
 * @param prog
 * @param max_size
 */
void declare_jsa_predicates(class jsa_programt &prog, size_t max_size);

/**
 * @brief
 *
 * @details
 *
 * @param prog
 * @param max_size
 */
void declare_jsa_query(jsa_programt &prog, size_t max_size);

/**
 * @brief
 *
 * @details
 *
 * @param prog
 * @param max_size
 */
void declare_jsa_invariant(jsa_programt &prog, size_t max_size);

#endif // CPROVER_CEGIS_JSA_LEARN_INSERT_PREDICATES_AND_QUERIES_H
