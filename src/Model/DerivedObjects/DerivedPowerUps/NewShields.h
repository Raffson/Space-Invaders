/*
 * NewShields.h
 *
 *  Created on: Dec 3, 2013
 *      Author: raffson
 */

#ifndef NEWSHIELDS_H_
#define NEWSHIELDS_H_

#include "../PowerUp.h"

namespace AR {

/**
 *  \class NewShields
 *  \brief This class will represent a new-shields power-up for AR::SpaceInvaders.
 *
 *  This type of PowerUp doesn't have a timeout period, therefore AR::PowerUp::Alive() &
 *  AR::PowerUp::Die() are not overridden.
 */
class NewShields: public PowerUp {
public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 */
	NewShields(const Location& loc=Location(50, 125), const float& s=0.25);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~NewShields();
};

}  // namespace AR

#endif /* NEWSHIELDS_H_ */
