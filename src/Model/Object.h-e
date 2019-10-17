/*
 * Object.h
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "GameException.h"

/**
 *  \file Object.h
 *  \brief Contains interfaces for classes 'AR::Location' & 'AR::Object'.
 */

namespace AR {

/**
 *  \class Location
 *  \brief This class will represent a 2-dimensional location.
 */
class Location {
public:
	/**
	 *  \brief X coordinate.
	 */
	float x;

	/**
	 *  \brief Y coordinate.
	 */
	float y;

	/**
	 *  \brief Custom constructor.
	 *  \param a Coordinate that will be used to initialize data member 'x'
	 *  \param b Coordinate that will be used to initialize data member 'y'
	 */
	Location(float a=0, float b=0);

	/**
	 *  \brief Copy constructor.
	 *  \param loc Location that will be used to initialize 'x' & 'y'
	 */
	Location(const Location& loc);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Location();

	/**
	 *  \brief Overloaded operator to add locations with eachother.
	 *  \param rhand Parameter which is located after the + sign
	 *  \return The resulting location.
	 */
	Location operator+(const Location& rhand) const;
};

/**
 *  \class Object
 *  \brief Abstract base class for all entities needed for AR::SpaceInvaders.
 */
class Object {
public:
	/**
	 *  \brief Current position of the object.
	 */
	Location pos;

	/**
	 *  \brief Current speed of the object.
	 */
	float speed;

	/**
	 *  \brief Custom constructor.
	 *  \param loc Location that will be used to initialize 'pos'
	 *  \param s Speed that will be used to initialize data member 'speed'
	 */
	Object(const Location& loc=Location(), const float& s=1);

	/**
	 *  \brief Default destructor.
	 */
	virtual ~Object();

	/**
	 *  \brief Overloaded operator to check if 2 objects are the same.
	 *  \param rhand Object to be compared.
	 *  \return True if it's the same object (i.e. same memory address), else false.
	 */
	virtual const bool operator==(const Object& rhand) const;

	/**
	 *  \brief Adjusts the location.
	 *
	 *  This function will substract 1 from 'pos.x'
	 */
	virtual void MoveLeft();

	/**
	 *  \brief Adjusts the location.
	 *
	 *  This function will add 1 from 'pos.x'
	 */
	virtual void MoveRight();

	/**
	 *  \brief Adjusts the location.
	 *
	 *  This function will add 1 from 'pos.y'
	 */
	virtual void MoveUp();

	/**
	 *  \brief Adjusts the location.
	 *
	 *  This function will substract 1 from 'pos.y'
	 */
	virtual void MoveDown();

	/**
	 *  \brief Indicated if "this" object is a PowerUp.
	 *  \return True if "this" object is a (derived) PowerUp, else false.
	 */
	virtual const bool IsPowerUp() const;

	/**
	 *  \brief Pure virtual function to indicate whether the object is alive or not.
	 *  \return True if the object is alive, else false.
	 *
	 *  The definition of 'Alive' will be different for each derived object.
	 */
	virtual const bool Alive() const = 0;

	/**
	 *  \brief Pure virtual function to revive the object.
	 *
	 *  The definition of 'Revive' will be different for each derived object.
	 */
	virtual void Revive() = 0;

	/**
	 *  \brief Pure virtual function to kill the object.
	 *
	 *  The definition of 'Die' will be different for each derived object.
	 */
	virtual void Die() = 0;
};

}  // namespace AR

#endif /* OBJECT_H_ */
