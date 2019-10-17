/*
 * LaserGun.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: raffson
 */

#include "LaserGun.h"

namespace AR {

LaserGun::LaserGun(const Location& loc, const float& s)
	: PowerUp(loc, s)
{

}

LaserGun::~LaserGun() { }

const bool LaserGun::Alive() const
{
	if( !used ) return false;
	std::chrono::duration<double> diff = std::chrono::system_clock::now() - timeout;
	return ( (diff.count() < 10 ) ); //10sec timeout
}

void LaserGun::Die()
{
	if( !used )
	{
		timeout = std::chrono::system_clock::now();
		used = true;
	}
}

}  // namespace AR
