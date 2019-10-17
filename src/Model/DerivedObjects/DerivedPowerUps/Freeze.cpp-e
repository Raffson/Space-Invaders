/*
 * Freeze.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: raffson
 */

#include "Freeze.h"

namespace AR {

Freeze::Freeze(const float& s, const Location& loc)
	: PowerUp(loc, s)
{

}

Freeze::~Freeze() { }

const bool Freeze::Alive() const
{
	if( !used ) return false;
	std::chrono::duration<double> diff = std::chrono::system_clock::now() - timeout;
	return ( (diff.count() < 5 ) ); //5sec timeout
}

void Freeze::Die()
{
	if( !used )
	{
		timeout = std::chrono::system_clock::now();
		used = true;
	}
}

}  // namespace AR
