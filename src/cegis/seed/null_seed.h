/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_SEED_NULL_SEED_H
#define CPROVER_CEGIS_SEED_NULL_SEED_H

#include <cegis/danger/symex/verify/danger_verify_config.h>

/**
 * @brief
 *
 * @details
 */
class null_seedt
{
public:
  /**
   * @brief
   *
   * @details
   *
   * @param ces
   * @tparam ces
   */
  template<class cest>
  void operator()(cest &ces) const;
};

#include "null_seed.inc"

#endif // CPROVER_CEGIS_SEED_NULL_SEED_H
