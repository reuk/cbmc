/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_CONTROL_VALUE_FLOAT_HELPER_H
#define CPROVER_CEGIS_CONTROL_VALUE_FLOAT_HELPER_H

#include <util/expr.h>

/**
 * @brief
 *
 * @details
 *
 * @param expr
 *
 * @return
 */
double to_control_float(const constant_exprt &expr);

/**
 * @brief
 *
 * @details
 *
 * @param st
 * @param value
 *
 * @return
 */
exprt to_control_float_expr(const class symbol_tablet &st, double value);

#endif // CPROVER_CEGIS_CONTROL_VALUE_FLOAT_HELPER_H
