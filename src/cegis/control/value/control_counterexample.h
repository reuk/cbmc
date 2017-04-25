/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_CONTROL_VALUE_CONTROL_COUNTEREXAMPLE_H
#define CPROVER_CEGIS_CONTROL_VALUE_CONTROL_COUNTEREXAMPLE_H

#include <deque>
#include <map>

#include <util/expr.h>

/**
 * @brief
 *
 * @details List of values per CE location.
 */
typedef std::map<const irep_idt, exprt::operandst> control_counterexamplet;

typedef std::deque<control_counterexamplet> control_counterexamplest;

#endif // CPROVER_CEGIS_CONTROL_VALUE_CONTROL_COUNTEREXAMPLE_H
