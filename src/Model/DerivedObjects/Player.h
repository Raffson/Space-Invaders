/*
 * Player.h
 *
 *  Created on: Nov 19, 2013
 *      Author: raffson
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Object.h"

namespace AR {

/**
 *  \class Player
 *  \brief This class will represent a player for AR::SpaceInvaders.
 */
class Player: public Object {
private:
	/**
	 *  \brief Indicates the current score of the Player.
	 */
	int score;

	/**
	 *  \brief Indicates the number of lives left for "this" Player.
	 */
	unsigned int lives;

public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 *
	 *  Data members 'score' & 'lives' will be initialized respectively 0 & 3.
	 */
	Player(const Location& loc=Location(-350, -700), const float& sp=1);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Player();

	/**
	 *  \brief This (overridden) function will move the Player left.
	 */
	virtual void MoveLeft();

	/**
	 *  \brief This (overridden) function will move the Player right.
	 */
	virtual void MoveRight();

	/**
	 *  \brief This (overridden) function will do nothing since a Player can't move up.
	 */
	virtual void MoveUp();

	/**
	 *  \brief This (overridden) function will do nothing since a Player can't move down.
	 */
	virtual void MoveDown();

	/**
	 *  \brief Indicates whether the Player is alive or not.
	 *  \return Always true for a Player.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Increase the number of 'lives' by 1.
	 */
	virtual void Revive();

	/**
	 *  \brief Decrease the number of 'lives' by 1.
	 *  \throws AR::GameException (GameOver) if Die() is called & 'lives'=0
	 */
	virtual void Die();

	/**
	 *  \brief Increase the 'score' by 1.
	 */
	virtual void Award(const int& s=1);

	/**
	 *  \brief Resets 'score' to 0 & 'lives' to 3.
	 */
	void Reset();

	/**
	 *  \brief Getter for data member 'score'.
	 *  \return Data member 'score'
	 */
	const int getScore() const;

	/**
	 *  \brief Getter for data member 'lives'.
	 *  \return Data member 'lives'
	 */
	const unsigned int getLives() const;

};

}  // namespace AR

#endif /* PLAYER_H_ */
