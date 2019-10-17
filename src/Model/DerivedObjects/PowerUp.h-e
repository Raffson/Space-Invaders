/*
 * PowerUp.h
 *
 *  Created on: Nov 23, 2013
 *      Author: raffson
 */

#ifndef POWERUP_H_
#define POWERUP_H_

#include <chrono>
#include "../Object.h"

namespace AR {

/**
 *  \class PowerUp
 *  \brief Superclass for all derived power-ups for AR::SpaceInvaders.
 */
class PowerUp: public Object {
protected:
	/**
	 *  \brief Indicates the state of the PowerUp.
	 *
	 *  This value is set to true once a bullet hits the PowerUp, otherwise false.
	 */
	bool used;

public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 *
	 *  Data member 'used' will be initialized with false.
	 */
	PowerUp(const Location& loc=Location(50, 125), const float& s=0.25);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~PowerUp();

	/**
	 *  \brief This (overridden) function will move the PowerUp left.
	 */
	virtual void MoveLeft();

	/**
	 *  \brief This (overridden) function will move the PowerUp right.
	 */
	virtual void MoveRight();

	/**
	 *  \brief This (overridden) function will do nothing since a PowerUp can't move up.
	 */
	virtual void MoveUp();

	/**
	 *  \brief This (overridden) function will do nothing since a PowerUp can't move down.
	 */
	virtual void MoveDown();

	/**
	 *  \brief This (overridden) function will indicate that "this" object is a
	 *  (derived) PowerUp.
	 *  \return Always true for a PowerUp.
	 */
	virtual const bool IsPowerUp() const;

	/**
	 *  \brief Indicates whether the PowerUp is timed out or not.
	 *  \return Always false for a PowerUp.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Does nothing since a PowerUp can't be revived.
	 */
	virtual void Revive();

	/**
	 *  \brief Sets data member 'used' to true.
	 *
	 *	Since this superclass is still too abstract, nothing else happends.
	 */
	virtual void Die();

	/**
	 *  \brief Getter for data member 'used'
	 *	\return Data meber 'used'
	 */
	const bool Used() const;
};

}  // namespace AR

#endif /* POWERUP_H_ */
