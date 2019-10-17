/*
 * Alien.h
 *
 *  Created on: Nov 20, 2013
 *      Author: raffson
 */

#ifndef ALIEN_H_
#define ALIEN_H_

#include "../Object.h"

namespace AR {

/**
 *  \class Alien
 *  \brief This class will represent an alien for AR::SpaceInvaders.
 */
class Alien: public Object {
private:
	/**
	 *  \brief Indicates whether or not "this" Alien is alive.
	 */
	bool alive;

public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 *
	 *  Data member 'alive' will be initialized with false.
	 */
	Alien(const Location& loc=Location(), const float& s=0.0005);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Alien();

	/**
	 *  \brief This (overridden) function will move "this" Alien left.
	 */
	virtual void MoveLeft();

	/**
	 *  \brief This (overridden) function will move "this" Alien right.
	 */
	virtual void MoveRight();

	/**
	 *  \brief This (overridden) function will move "this" Alien up.
	 *
	 *  Although aliens should not be moving up, it is implemented.
	 */
	virtual void MoveUp();

	/**
	 *  \brief This (overridden) function will move "this" Alien down.
	 *  \throws AR::GameException (game over) if MoveDown() is called & 'pos.y <= -500',
	 *	meaning "this" Alien is too close to earth.
	 */
	virtual void MoveDown();

	/**
	 *  \brief Indicates whether "this" Alien is alive or not.
	 *  \return Data member 'alive'.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Sets 'alive' to true.
	 */
	virtual void Revive();

	/**
	 *  \brief Sets 'alive' to false.
	 */
	virtual void Die();
};

}  // namespace AR

#endif /* ALIEN_H_ */
