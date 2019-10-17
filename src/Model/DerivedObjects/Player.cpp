/*
 * Player.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: raffson
 */

#include "Player.h"

namespace AR {

Player::Player(const Location& loc, const float& sp)
	: Object(loc, sp), score(0), lives(3)
{
	//-> player should move between x= -800...50
}

Player::~Player() { }

const bool Player::Alive() const { return true; }
void Player::Award(const int& s) { score += s; }
void Player::Revive() { ++lives; }
void Player::Die()
{
	if( lives == 0 ) throw GameException(GameException::Type::GameOver);
	--lives;
}

void Player::MoveLeft()
{
	if( pos.x < 50 ) pos.x += speed;
	if( pos.x >= 50 ) pos.x = 50;
}

void Player::MoveRight()
{
	if( pos.x > -800 ) pos.x -= speed;
	if( pos.x <= -800 ) pos.x = -800;
}

void Player::MoveUp()
{
	//player should not be able to move up
}

void Player::MoveDown()
{
	//player should not be able to move down
}

void Player::Reset()
{
	score = 0;
	lives = 3;
}

const int Player::getScore() const { return score; }


const unsigned int Player::getLives() const { return lives; }


}  // namespace AR
