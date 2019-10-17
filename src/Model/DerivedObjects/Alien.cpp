/*
 * Alien.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: raffson
 */

#include "Alien.h"

namespace AR {

Alien::Alien(const Location& loc, const float& s) : Object(loc, s),  alive(true) { }

Alien::~Alien() { }

void Alien::MoveLeft()
{
	if( pos.x < 50 ) pos.x += speed;
	if( pos.x >= 50 ) pos.x = 50;
}

void Alien::MoveRight()
{
	if( pos.x > -800 ) pos.x -= speed;
	if( pos.x <= -800 ) pos.x = -800;
}

void Alien::MoveUp()
{
	if( pos.y < 100 ) pos.y += 10;
	if( pos.y >= 100 ) pos.y = 100;
}

void Alien::MoveDown()
{
	if( pos.y > -500 ) pos.y -= 10;
	if( pos.y <= -500 )
	{
		pos.y = -500;
		if(alive) throw GameException(GameException::Type::GameOver);
	}
}

const bool Alien::Alive() const { return alive; }

void Alien::Revive() { alive = true; }

void Alien::Die() { alive = false; }

}  // namespace AR
