/*
 * Bullet.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: raffson
 */

#include "Bullet.h"

namespace AR {

Bullet::Bullet(const Location& loc, const float& s) : Object(loc, s) { }

Bullet::~Bullet() { }

void Bullet::MoveLeft()
{
	//should not be able to move left
}

void Bullet::MoveRight()
{
	//should not be able to move right
}

void Bullet::MoveUp()
{
	if(pos.y < 150) pos.y += speed;
}

void Bullet::MoveDown()
{
	if(pos.y > -725) pos.y -= speed;
}

const bool Bullet::Alive() const { return false; }
void Bullet::Revive() { }
void Bullet::Die() { }

}  // namespace AR
