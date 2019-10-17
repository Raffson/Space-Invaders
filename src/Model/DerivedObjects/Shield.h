/*
 * Shield.h
 *
 *  Created on: Dec 3, 2013
 *      Author: raffson
 */

#ifndef SHIELD_H_
#define SHIELD_H_

#include "../Object.h"

namespace AR {

/**
 *  \class Shield
 *  \brief Represents a shield for AR::SpaceInvaders.
 */
class Shield: public Object {
private:
	/**
	 *  \brief An integer value that will be used as a red color component indicating health.
	 */
	int red;

	/**
	 *  \brief An integer value that will be used as a green color component indicating health.
	 */
	int green;

public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 *
	 *  This constructor will also initialize red to 0 & green to 255, indicating full health.
	 *  Data member speed will be initialized, but will have no effect on the shield.
	 */
	Shield(const Location& loc=Location(), const float& s=0);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Shield();

	/**
	 *  \brief This (overridden) function will do nothing since a shield can't move.
	 */
	virtual void MoveLeft();

	/**
	 *  \brief This (overridden) function will do nothing since a shield can't move.
	 */
	virtual void MoveRight();

	/**
	 *  \brief This (overridden) function will do nothing since a shield can't move.
	 */
	virtual void MoveUp();

	/**
	 *  \brief This (overridden) function will do nothing since a shield can't move.
	 */
	virtual void MoveDown();

	/**
	 *  \brief Indicates whether the shield is destroyed or not.
	 *  \return False if the shield is destroyed, else true.
	 */
	virtual const bool Alive() const;

	/**
	 *  \brief Resets red & green components to restore full health.
	 */
	virtual void Revive();

	/**
	 *  \brief Adjusts the red & green components to simulate damage.
	 *
	 *  The color of the shield will progressively change from green to yellow to red
	 *  untill it's fully destroyed.
	 */
	virtual void Die();

	/**
	 *  \brief Get the current health state.
	 *  \return A pair with components <red, green>.
	 */
	std::pair<int, int> GetHealth() const;
};

}  // namespace AR

#endif /* SHIELD_H_ */
