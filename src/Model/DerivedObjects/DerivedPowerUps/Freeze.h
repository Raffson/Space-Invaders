/*
 * Freeze.h
 *
 *  Created on: Nov 24, 2013
 *      Author: raffson
 */

#ifndef FREEZE_H_
#define FREEZE_H_

#include "../PowerUp.h"

namespace AR {

/**
 *  \class Freeze
  *  \brief This class will represent a freeze power-up for AR::SpaceInvaders.
  *
  *  More specifically when this PowerUp is active, all aliens & alienbullets will freeze.
  */
class Freeze: public PowerUp {
private:
	/**
	 *  \brief Will be used to determine whether or not Freeze is still active.
	 */
	std::chrono::time_point<std::chrono::system_clock> timeout;

public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
]	 */
	Freeze(const float& s=0.25, const Location& loc=Location(50, 125));

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Freeze();

	/**
	 *  \brief Checks whether or not Freeze is timed out.
	 *  \return if 'used' is false, false is returned; if 'used' is true, this function will
	 *  return true during 5 seconds, after those 5 seconds false is returned.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Sets data member 'used' to true & save the current timepoint in 'timeout'.
	 */
	virtual void Die();

};

}  // namespace AR

#endif /* FREEZE_H_ */
