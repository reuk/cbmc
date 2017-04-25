/// \file Counterexample-Guided Inductive Synthesis

#ifndef CPROVER_CEGIS_GENETIC_GENETIC_PREPROCESSING_H
#define CPROVER_CEGIS_GENETIC_GENETIC_PREPROCESSING_H

/**
 * @brief
 *
 * @details
 */
template<class preproct>
class genetic_preprocessingt
{
  const class optionst &options;
  preproct &preproc;
public:
  /**
   * @brief
   *
   * @details
   *
   * @param options
   * @param preproc
   */
  genetic_preprocessingt(const optionst &options, preproct &preproc);

  /**
   * @brief
   *
   * @details
   */
  ~genetic_preprocessingt();

  /**
   * @brief Provides the minimum solution size.
   *
   * @details Properties like the number of skolem choices dictate the minimum
   * solution size.
   */
  size_t get_min_solution_size() const;

  /**
   * @brief
   *
   * @details
   */
  void operator()();

  /**
   * @brief
   *
   * @details
   *
   * @param max_solution_length
   */
  void operator()(const size_t max_solution_length);
};

#include "genetic_preprocessing.inc"

#endif // CPROVER_CEGIS_GENETIC_GENETIC_PREPROCESSING_H
