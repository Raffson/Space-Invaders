/*
 * SlowMotion.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: raffson
 */

#include "SlowMotion.h"

namespace AR {

SlowMotion::SlowMotion(const Location& loc, const float& s)
	: PowerUp(loc, s)
{

}

SlowMotion::~SlowMotion() { }

const bool SlowMotion::Alive() const
{
	if( !used ) return false;
	std::chrono::duration<double> diff = std::chrono::system_clock::now() - timeout;
	return ( (diff.count() < 15 ) ); //15sec timeout
}

void SlowMotion::Die()
{
	if( !used )
	{
		timeout = std::chrono::system_clock::now();
		used = true;
	}
}

}  // namespace AR
