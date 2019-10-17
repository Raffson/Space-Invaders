/*
 * LaserGun.h
 *
 *  Created on: Nov 23, 2013
 *      Author: raffson
 */

#ifndef LASERGUN_H_
#define LASERGUN_H_

#include "../PowerUp.h"

namespace AR {

/**
 *  \class LaserGun
 *  \brief This class will represent a laser-gun power-up for AR::SpaceInvaders.
 */
class LaserGun: public PowerUp {
private:
	/**
	 *  \brief Will be used to determine whether or not the LaserGun is still active.
	 */
	std::chrono::time_point<std::chrono::system_clock> timeout;

public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 */
	LaserGun(const Location& loc=Location(50, 125), const float& s=0.25);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~LaserGun();

	/**
	 *  \brief Checks whether or not the LaserGun is timed out.
	 *  \return if 'used' is false, false is returned; if 'used' is true, this function will
	 *  return true during 10 seconds, after those 10 seconds false is returned.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Sets data member 'used' to true & save the current timepoint in 'timeout'.
	 */
	virtual void Die();

};

}  // namespace AR

#endif /* LASERGUN_H_ */
