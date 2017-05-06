/*******************************************************************\

Module: Solvers for VCs Generated by Symbolic Execution of ANSI-C

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <memory>
#include <iostream>
#include <fstream>

#include <util/unicode.h>

#include <solvers/sat/satcheck.h>
#include <solvers/refinement/bv_refinement.h>
#include <solvers/smt1/smt1_dec.h>
#include <solvers/smt2/smt2_dec.h>
#include <solvers/cvc/cvc_dec.h>
#include <solvers/prop/aig_prop.h>
#include <solvers/sat/dimacs_cnf.h>

#include "cbmc_solvers.h"
#include "bv_cbmc.h"
#include "cbmc_dimacs.h"
#include "counterexample_beautification.h"
#include "version.h"

/*******************************************************************\

Function: cbmc_solverst::get_smt1_solver_type

  Inputs: None

 Outputs: An smt1_dect::solvert giving the solver to use.

 Purpose: Uses the options to pick an SMT 1.2 solver

\*******************************************************************/

smt1_dect::solvert cbmc_solverst::get_smt1_solver_type() const
{
  assert(options.get_bool_option("smt1"));

  smt1_dect::solvert s= smt1_dect::GENERIC;

  if(options.get_bool_option("boolector"))
    s= smt1_dect::BOOLECTOR;
  else if(options.get_bool_option("mathsat"))
    s= smt1_dect::MATHSAT;
  else if(options.get_bool_option("cvc3"))
    s= smt1_dect::CVC3;
  else if(options.get_bool_option("cvc4"))
    s= smt1_dect::CVC4;
  else if(options.get_bool_option("opensmt"))
    s= smt1_dect::OPENSMT;
  else if(options.get_bool_option("yices"))
    s= smt1_dect::YICES;
  else if(options.get_bool_option("z3"))
    s= smt1_dect::Z3;
  else if(options.get_bool_option("generic"))
    s= smt1_dect::GENERIC;

  return s;
}

/*******************************************************************\

Function: cbmc_solverst::get_smt2_solver_type

  Inputs: None

 Outputs: An smt2_dect::solvert giving the solver to use.

 Purpose: Uses the options to pick an SMT 2.0 solver

\*******************************************************************/

smt2_dect::solvert cbmc_solverst::get_smt2_solver_type() const
{
  assert(options.get_bool_option("smt2"));

  smt2_dect::solvert s= smt2_dect::GENERIC;

  if(options.get_bool_option("boolector"))
    s= smt2_dect::BOOLECTOR;
  else if(options.get_bool_option("mathsat"))
    s= smt2_dect::MATHSAT;
  else if(options.get_bool_option("cvc3"))
    s= smt2_dect::CVC3;
  else if(options.get_bool_option("cvc4"))
    s= smt2_dect::CVC4;
  else if(options.get_bool_option("opensmt"))
    s= smt2_dect::OPENSMT;
  else if(options.get_bool_option("yices"))
    s= smt2_dect::YICES;
  else if(options.get_bool_option("z3"))
    s= smt2_dect::Z3;
  else if(options.get_bool_option("generic"))
    s= smt2_dect::GENERIC;

  return s;
}

/*******************************************************************\

Function: cbmc_solverst::get_default

  Inputs:

 Outputs:

 Purpose: Get the default decision procedure

\*******************************************************************/

cbmc_solverst::solvert *cbmc_solverst::get_default()
{
  solvert *solver= new solvert;

  if(
    options.get_bool_option("beautify") ||
    !options.get_bool_option("sat-preprocessor")) // no simplifier
  {
    // simplifier won't work with beautification
    solver->set_prop(new satcheck_no_simplifiert());
  }
  else // with simplifier
  {
    solver->set_prop(new satcheckt());
  }

  solver->prop().set_message_handler(get_message_handler());

  bv_cbmct *bv_cbmc= new bv_cbmct(ns, solver->prop());

  if(options.get_option("arrays-uf") == "never")
    bv_cbmc->unbounded_array= bv_cbmct::U_NONE;
  else if(options.get_option("arrays-uf") == "always")
    bv_cbmc->unbounded_array= bv_cbmct::U_ALL;

  solver->set_prop_conv(bv_cbmc);

  return solver;
}

/*******************************************************************\

Function: cbmc_solverst::get_dimacs

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

cbmc_solverst::solvert *cbmc_solverst::get_dimacs()
{
  no_beautification();
  no_incremental_check();

  dimacs_cnft *prop= new dimacs_cnft();
  prop->set_message_handler(get_message_handler());

  std::string filename= options.get_option("outfile");

  return new solvert(new cbmc_dimacst(ns, *prop, filename), prop);
}

/*******************************************************************\

Function: cbmc_solverst::get_bv_refinement

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

cbmc_solverst::solvert *cbmc_solverst::get_bv_refinement()
{
  propt *prop;

  // We offer the option to disable the SAT preprocessor
  if(options.get_bool_option("sat-preprocessor"))
  {
    no_beautification();
    prop= new satcheckt();
  }
  else
    prop= new satcheck_no_simplifiert();

  prop->set_message_handler(get_message_handler());

  bv_refinementt *bv_refinement= new bv_refinementt(ns, *prop);
  bv_refinement->set_ui(ui);

  // we allow setting some parameters
  if(options.get_option("max-node-refinement") != "")
    bv_refinement->max_node_refinement=
      options.get_unsigned_int_option("max-node-refinement");

  bv_refinement->do_array_refinement= options.get_bool_option("refine-arrays");
  bv_refinement->do_arithmetic_refinement=
    options.get_bool_option("refine-arithmetic");

  return new solvert(bv_refinement, prop);
}

/*******************************************************************\

Function: cbmc_solverst::get_smt1

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

cbmc_solverst::solvert *cbmc_solverst::get_smt1(smt1_dect::solvert solver)
{
  no_beautification();
  no_incremental_check();

  const std::string &filename= options.get_option("outfile");

  if(filename == "")
  {
    if(solver == smt1_dect::GENERIC)
    {
      error() << "please use --outfile" << eom;
      throw 0;
    }

    smt1_dect *smt1_dec= new smt1_dect(
      ns, "cbmc", "Generated by CBMC " CBMC_VERSION, "QF_AUFBV", solver);

    return new solvert(smt1_dec);
  }
  else if(filename == "-")
  {
    smt1_convt *smt1_conv= new smt1_convt(
      ns,
      "cbmc",
      "Generated by CBMC " CBMC_VERSION,
      "QF_AUFBV",
      solver,
      std::cout);

    smt1_conv->set_message_handler(get_message_handler());

    return new solvert(smt1_conv);
  }
  else
  {
#ifdef _MSC_VER
    std::ofstream *out= new std::ofstream(widen(filename));
#else
    std::ofstream *out= new std::ofstream(filename);
#endif

    if(!out)
    {
      error() << "failed to open " << filename << eom;
      throw 0;
    }

    smt1_convt *smt1_conv= new smt1_convt(
      ns, "cbmc", "Generated by CBMC " CBMC_VERSION, "QF_AUFBV", solver, *out);

    smt1_conv->set_message_handler(get_message_handler());

    return new solvert(smt1_conv, out);
  }
}

/*******************************************************************\

Function: cbmc_solverst::get_smt2

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

cbmc_solverst::solvert *cbmc_solverst::get_smt2(smt2_dect::solvert solver)
{
  no_beautification();

  const std::string &filename= options.get_option("outfile");

  if(filename == "")
  {
    if(solver == smt2_dect::GENERIC)
    {
      error() << "please use --outfile" << eom;
      throw 0;
    }

    smt2_dect *smt2_dec= new smt2_dect(
      ns, "cbmc", "Generated by CBMC " CBMC_VERSION, "QF_AUFBV", solver);

    if(options.get_bool_option("fpa"))
      smt2_dec->use_FPA_theory= true;

    return new solvert(smt2_dec);
  }
  else if(filename == "-")
  {
    smt2_convt *smt2_conv= new smt2_convt(
      ns,
      "cbmc",
      "Generated by CBMC " CBMC_VERSION,
      "QF_AUFBV",
      solver,
      std::cout);

    if(options.get_bool_option("fpa"))
      smt2_conv->use_FPA_theory= true;

    smt2_conv->set_message_handler(get_message_handler());

    return new solvert(smt2_conv);
  }
  else
  {
#ifdef _MSC_VER
    std::ofstream *out= new std::ofstream(widen(filename));
#else
    std::ofstream *out= new std::ofstream(filename);
#endif

    if(!*out)
    {
      error() << "failed to open " << filename << eom;
      throw 0;
    }

    smt2_convt *smt2_conv= new smt2_convt(
      ns, "cbmc", "Generated by CBMC " CBMC_VERSION, "QF_AUFBV", solver, *out);

    if(options.get_bool_option("fpa"))
      smt2_conv->use_FPA_theory= true;

    smt2_conv->set_message_handler(get_message_handler());

    return new solvert(smt2_conv, out);
  }
}

/*******************************************************************\

Function: cbmc_solverst::no_beautification

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void cbmc_solverst::no_beautification()
{
  if(options.get_bool_option("beautify"))
  {
    error() << "sorry, this solver does not support beautification" << eom;
    throw 0;
  }
}

/*******************************************************************\

Function: cbmc_solverst::no_incremental_check

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void cbmc_solverst::no_incremental_check()
{
  if(
    options.get_bool_option("all-properties") ||
    options.get_option("cover") != "" ||
    options.get_option("incremental-check") != "")
  {
    error() << "sorry, this solver does not support incremental solving" << eom;
    throw 0;
  }
}
