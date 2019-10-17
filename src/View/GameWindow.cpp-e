/*
 * GameWindow.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 */

#include "GameWindow.h"

namespace AR {

GameWindow::GameWindow()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window.create(sf::VideoMode(800, 600), "Game Window", sf::Style::Default, settings);

	window.clear();
	window.setVisible(true);
	view.setCenter(0, 0);
	window.setView( view );
	window.display();

	//initialize a window that has a start-button or something like that
	//	-> do this in draw/update function
	//		-> check the game-state, if yet to be started do 'this', otherwise do 'that'
}

GameWindow::~GameWindow()
{

}

sf::RenderWindow& GameWindow::getWindow() { return window; }

const bool GameWindow::Open() const
{
	return window.isOpen();
}

void GameWindow::Close()
{
	window.close();
}

void GameWindow::Update(const bool& started, const bool& paused, const bool& gameOver,
		const std::vector<std::shared_ptr<Object> >& data, const unsigned int& lvl)
{
	sf::Font font;
	font.loadFromFile("default.ttf");
	sf::Text message("Generic GameWindow", font);
	message.setCharacterSize(60);
	message.setStyle(sf::Text::Bold);
	message.setColor(sf::Color::Green);
	message.setPosition(-315, 0);
	window.clear();
	window.draw(message);
	view.setCenter(0, 0);
	window.setView( view );
	window.display();
}

}  // namespace AR
