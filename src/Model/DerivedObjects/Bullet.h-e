/*
 * Bullet.h
 *
 *  Created on: Nov 21, 2013
 *      Author: raffson
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "../Object.h"

namespace AR {

/**
 *  \class Bullet
 *  \brief This class will represent a bullet for AR::SpaceInvaders.
 */
class Bullet: public Object {
public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 */
	Bullet(const Location& loc=Location(), const float& s=2);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Bullet();


	/**
	 *  \brief This (overridden) function will do nothing since a Bullet can't move left.
	 */
	virtual void MoveLeft();

	/**
	 *  \brief This (overridden) function will do nothing since a Bullet can't move right.
	 */
	virtual void MoveRight();

	/**
	 *  \brief This (overridden) function will move a Bullet up or down according to it's speed.
	 *
	 *  This function will add the speed to the current position.
	 */
	virtual void MoveUp();

	/**
	 *  \brief This (overridden) function will move a Bullet up or down according to it's speed.
	 *
	 *  This function will substract the speed to the current position.
	 */
	virtual void MoveDown();

	/**
	 *  \brief Indicates whether the Bullet is alive or not.
	 *  \return Always false for a Bullet.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Override by doing nothing since a Bullet can't be revived.
	 */
	virtual void Revive();

	/**
	 *  \brief Override by doing nothing since a Bullet can't die.
	 */
	virtual void Die();
};

}  // namespace AR

#endif /* BULLET_H_ */
