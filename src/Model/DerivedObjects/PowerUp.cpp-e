/*
 * PowerUp.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: raffson
 */

#include "PowerUp.h"

namespace AR {

PowerUp::PowerUp(const Location& loc, const float& s)
	:  Object(loc, s), used(false)
{ }

PowerUp::~PowerUp() { }

void PowerUp::MoveLeft() { if( !used and (pos.x < 50) ) pos.x += speed; }
void PowerUp::MoveRight() { if( !used and (pos.x > -820) ) pos.x -= speed; }
void PowerUp::MoveUp() { } //power up can't move up or down
void PowerUp::MoveDown() { }

const bool PowerUp::IsPowerUp() const { return true; }

const bool PowerUp::Alive() const { return false; }
void PowerUp::Revive() { } //power up can't be revived
void PowerUp::Die() { used = true; }

const bool PowerUp::Used() const { return used; }

}  // namespace AR
