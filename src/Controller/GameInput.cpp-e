/*
 * GameInput.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 */

#include "GameInput.h"

namespace AR {

GameInput::GameInput() { }

GameInput::~GameInput() { }

const sf::Event& GameInput::getEvent() const
{
	return event;
}

const bool GameInput::CloseGame(sf::RenderWindow& w)
{
	while (w.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) return true;
	}
	return false;
}

}  // namespace AR
