//============================================================================
//                                  I B E X                                   
// File        : ibex_DefaultSolver.h
// Author      : Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : Sep 27, 2012
// Last Update : Jul 06, 2014
//============================================================================

#ifndef __IBEX_DEFAULT_SOLVER_H__
#define __IBEX_DEFAULT_SOLVER_H__

#include "ibex_Solver.h"
#include "ibex_System.h"
#include "ibex_CellBuffer.h"
#include "ibex_CtcCompo.h"

namespace ibex {

/**
 * \ingroup strategy
 *
 * \brief Default solver.
 */
class DefaultSolver : public Solver {
public:
	/**
	 * \brief Create a default solver.
	 *
	 * \param sys  - The system to solve
	 * \param eps_x_min - Stopping criterion for box splitting (absolute precision)
	 */
    DefaultSolver(System& sys, double eps_x_min=default_eps_x_min, double eps_x_max=default_eps_x_max, double random_seed=default_random_seed);

    /**
	 * \brief Create a default solver.
	 *
	 * \param sys  - The system to solve
	 * \param eps_x_min - Stopping criterion for box splitting (vector of absolute precisions,
	 *               one for each variable)
	 */
    DefaultSolver(System& sys, const Vector& eps_x_min, double eps_x_max=default_eps_x_max, double random_seed=default_random_seed);

    /**
	 * \brief Delete *this.
	 */
	~DefaultSolver();

	/**
	 * \brief Default minimal width: 1e-6.
	 */
	static const double default_eps_x_min;

	/**
	 * \brief Default maximal width: +oo.
	 */
	static const double default_eps_x_max;

	/** Default random seed: 1.0. */
	static const double default_random_seed;

	System & sys;

private:

	/**
	 * The contractor: hc4 + acid(hc4) + newton (if the system is square) + xnewton
	 */
	Ctc* ctc(System& sys, double prec);

//	std::vector<CtcXNewton::corner_point>* default_corners ();

	void* data;
};

} // end namespace ibex

#endif // __IBEX_DEFAULT_SOLVER_H__
