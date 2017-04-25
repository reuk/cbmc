/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_JSA_VALUE_JSA_COUNTEREXAMPLE_H
#define CPROVER_CEGIS_JSA_VALUE_JSA_COUNTEREXAMPLE_H

#include <deque>
#include <map>

#include <util/expr.h>

/**
 * @brief
 *
 * @details List of values per CE location.
 */
typedef std::map<const irep_idt, exprt> jsa_counterexamplet;

typedef std::deque<jsa_counterexamplet> jsa_counterexamplest;

#endif // CPROVER_CEGIS_JSA_VALUE_JSA_COUNTEREXAMPLE_H
