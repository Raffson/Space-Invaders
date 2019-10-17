/*
 * Points.h
 *
 *  Created on: Nov 23, 2013
 *      Author: raffson
 */

#ifndef POINTS_H_
#define POINTS_H_

#include "../PowerUp.h"

namespace AR {

/**
 *  \class Points
 *  \brief This class will represent a points power-up for AR::SpaceInvaders.
 *
 *  This type of PowerUp doesn't have a timeout period, therefore AR::PowerUp::Alive() &
 *  AR::PowerUp::Die() are not overridden.
 */
class Points: public PowerUp {
public:
	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 */
	Points(const Location& loc=Location(50, 125), const float& s=0.25);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Points();

};

}  // namespace AR

#endif /* POINTS_H_ */
