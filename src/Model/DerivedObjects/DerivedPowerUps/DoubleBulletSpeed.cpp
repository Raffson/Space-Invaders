/*
 * DoubleBulletSpeed.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: raffson
 */

#include "DoubleBulletSpeed.h"

namespace AR {

DoubleBulletSpeed::DoubleBulletSpeed(const Location& loc, const float& s)
	: PowerUp(loc, s)
{

}

DoubleBulletSpeed::~DoubleBulletSpeed() { }

const bool DoubleBulletSpeed::Alive() const
{
	if( !used ) return false;
	std::chrono::duration<double> diff = std::chrono::system_clock::now() - timeout;
	return ( (diff.count() < 30 ) ); //30sec timeout
}

void DoubleBulletSpeed::Die()
{
	if( !used )
	{
		timeout = std::chrono::system_clock::now();
		used = true;
	}
}

}  // namespace AR
