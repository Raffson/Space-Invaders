/*
 * GameException.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: raffson
 */

#include "GameException.h"

namespace AR {

GameException::GameException(const unsigned int& c)  : code(c) { }

GameException::~GameException() { }

const char* GameException::what() const noexcept
{
	std::stringstream s;
	if( code == GameException::Type::GameOver )
		s << "Game Over!" << std::endl;
	else if( code == GameException::Type::EntityNotFound )
		s << "Parameter 'Object' in SpaceInvaders::GetIterator()"
				<< " is not in the list of entities!" << std::endl;
	else if( code == GameException::Type::NoPlayer )
		s << "No player found!" << std::endl;
	else s << "Unknown GameException occurred!" << std::endl;
	return s.str().c_str();
}

const unsigned int& GameException::ErrorCode() const noexcept
{
	return code;
}

}  // namespace AR
