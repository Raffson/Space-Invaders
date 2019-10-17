/*
 * DoubleBulletSpeed.h
 *
 *  Created on: Nov 24, 2013
 *      Author: raffson
 */

#ifndef DOUBLEBULLETSPEED_H_
#define DOUBLEBULLETSPEED_H_

#include "../PowerUp.h"

namespace AR {

/**
 *  \class DoubleBulletSpeed
 *  \brief This class will represent a double-bullet-speed power-up for AR::SpaceInvaders.
 */
class DoubleBulletSpeed: public PowerUp {
private:
	/**
	 *  \brief Will be used to determine whether or not DoubleBulletSpeed is still active.
	 */
	std::chrono::time_point<std::chrono::system_clock> timeout;

public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 */
	DoubleBulletSpeed(const Location& loc=Location(50, 125), const float& s=0.25);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~DoubleBulletSpeed();

	/**
	 *  \brief Checks whether or not DoubleBulletSpeed is timed out.
	 *  \return if 'used' is false, false is returned; if 'used' is true, this function will
	 *  return true during 30 seconds, after those 30 seconds false is returned.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Sets data member 'used' to true & save the current timepoint in 'timeout'.
	 */
	virtual void Die();

};

}  // namespace AR

#endif /* DOUBLEBULLETSPEED_H_ */
