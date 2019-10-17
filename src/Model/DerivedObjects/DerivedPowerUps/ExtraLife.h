/*
 * ExtraLife.h
 *
 *  Created on: Nov 24, 2013
 *      Author: raffson
 */

#ifndef EXTRALIFE_H_
#define EXTRALIFE_H_

#include "../PowerUp.h"

namespace AR {


/**
 *  \class ExtraLife
 *  \brief This class will represent an extra-life power-up for AR::SpaceInvaders.
 *
 *  This type of PowerUp doesn't have a timeout period, therefore AR::PowerUp::Alive() &
 *  AR::PowerUp::Die() are not overridden.
 */
class ExtraLife: public PowerUp {
public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 */
	ExtraLife(const Location& loc=Location(50, 125), const float& s=0.25);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~ExtraLife();

};

}  // namespace AR

#endif /* EXTRALIFE_H_ */
