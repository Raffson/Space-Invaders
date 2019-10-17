/*
 * Shield.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: raffson
 */

#include "Shield.h"

namespace AR {

Shield::Shield(const Location& loc, const float& s)
	: Object(loc, s), red(0), green(255)
{ }

Shield::~Shield() { }

void Shield::MoveLeft() { } //do nothing, shield isn't supposed to move
void Shield::MoveRight() { }
void Shield::MoveUp() { }
void Shield::MoveDown() { }

const bool Shield::Alive() const { return !(red == 255 and green == 0); }

void Shield::Revive() { green = 255; red = 0; }

void Shield::Die()
{
	if( red < 255 ) red += 5;
	else if( red >= 255 and green > 0 ) green -= 5;
}

std::pair<int, int> Shield::GetHealth() const
{
	return std::pair<int, int>(red, green);
}

}  // namespace AR
