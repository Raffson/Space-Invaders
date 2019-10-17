/*
 * Object.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 */

#include "Object.h"

/**
 *  \file Object.cpp
 *  \brief Contains implementations for 'AR::Location' & 'AR::Object'.
 */

namespace AR {

Location::Location(float a, float b) : x(a), y(b) { }
Location::Location(const Location& loc) : x(loc.x), y(loc.y) { }
Location::~Location() { }
Location Location::operator+(const Location& rhand) const
{
	return Location( x + rhand.x, y + rhand.y );
}

Object::Object(const Location& loc, const float& s) : pos(loc), speed(s) { }

Object::~Object() { }

const bool Object::operator==(const Object& rhand) const
{
	return ( this == &rhand );
}

void Object::MoveLeft() { ++pos.x; }
void Object::MoveRight() { --pos.x; }
void Object::MoveUp() { ++pos.y; }
void Object::MoveDown() { --pos.y; }
const bool Object::IsPowerUp() const { return false; }

}  // namespace AR
