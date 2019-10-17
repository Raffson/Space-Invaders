/*
 * SlowMotion.h
 *
 *  Created on: Nov 24, 2013
 *      Author: raffson
 */

#ifndef SLOWMOTION_H_
#define SLOWMOTION_H_

#include "../PowerUp.h"

namespace AR {

/**
 *  \class SlowMotion
 *  \brief This class will represent a slow-motion power-up for AR::SpaceInvaders.
 */
class SlowMotion: public PowerUp {
private:
	/**
	 *  \brief Will be used to determine whether or not SlowMotion is still active.
	 */
	std::chrono::time_point<std::chrono::system_clock> timeout;

public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 */
	SlowMotion(const Location& loc=Location(50, 125), const float& s=0.25);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~SlowMotion();

	/**
	 *  \brief Checks whether or not SlowMotion is timed out.
	 *  \return if 'used' is false, false is returned; if 'used' is true, this function will
	 *  return true during 15 seconds, after those 15 seconds false is returned.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Sets data member 'used' to true & save the current timepoint in 'timeout'.
	 */
	virtual void Die();
};

}  // namespace AR

#endif /* SLOWMOTION_H_ */
