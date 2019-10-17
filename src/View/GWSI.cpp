/*
 * GWSI.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: raffson
 */

#include "GWSI.h"

namespace AR {

GWSI::GWSI()
{
	window.setTitle("Space Invaders");
	view.setCenter(399.5, 299.5);
	window.setView(view);
	window.display();

	font.loadFromFile("default.ttf");
	sf::Text message("Start Game", font, 60);
	message.setStyle(sf::Text::Bold);
	message.setColor(sf::Color::Green);
	message.setPosition(250, 300);
	sf::Text message2("(press enter to start)", font, 30);
	message2.setColor(sf::Color::Green);
	message2.setPosition(275, 375);
	sf::Text message3("Paused", font, 60);
	message3.setStyle(sf::Text::Bold);
	message3.setColor(sf::Color::Green);
	message3.setPosition(275, 300);
	sf::Text message4("(press R to resume)", font, 30);
	message4.setColor(sf::Color::Green);
	message4.setPosition(250, 375);
	sf::Text message5("Game Over", font, 60);
	message5.setStyle(sf::Text::Bold);
	message5.setColor(sf::Color::Green);
	message5.setPosition(250, 300);
	sf::Text message6("(press R to restart)", font, 30);
	message6.setColor(sf::Color::Green);
	message6.setPosition(275, 375);

	messages.push_back(message);
	messages.push_back(message2);
	messages.push_back(message3);
	messages.push_back(message4);
	messages.push_back(message5);
	messages.push_back(message6);

	factory = OutputFactory::CreateFactory(OutputFactory::TYPE::SFML);
}

GWSI::~GWSI() { }

void GWSI::Update(const bool& started, const bool& paused, const bool& gameOver,
		const std::vector<std::shared_ptr<Object> >& data, const unsigned int& lvl)
{
	//if game did not start, show start screen
	//otherwise, draw the 'game'
	if ( !started )
	{
		this->StartScreen();
	}
	else
	{
		window.clear();
		for( auto &i : data )
		{
			window.draw( *factory->GetSFMLshape(*i.get()) );
			if( typeid(*i) == typeid(Player) )
				PlayerStats(dynamic_cast<Player&>(*i));
		}

		if (lvl > 0) //otherwise it's expected to be a game without levels
		{
			std::stringstream stream;
			stream << "LEVEL : " << lvl << "     (press P to pause)";
			sf::Text lvlText(stream.str(), font, 15);
			lvlText.setOrigin(-300, 175);
			lvlText.setColor(sf::Color::Green);
			lvlText.setStyle(sf::Text::Style::Bold);
			window.draw(lvlText);
		}

		if( gameOver ) GameOverScreen();
		else if( paused ) PauseScreen();
		window.display();
	}
}

void GWSI::StartScreen()
{
	window.clear();

	window.draw(messages[0]);
	window.draw(messages[1]);

	window.display();
}

void GWSI::PauseScreen()
{
	window.draw(messages[2]);
	window.draw(messages[3]);
}

void GWSI::GameOverScreen()
{
	window.draw(messages[4]);
	window.draw(messages[5]);
}

void GWSI::PlayerStats(const Player& p)
{
	std::stringstream scorestream;
	scorestream << "SCORE : " << p.getScore();
	std::stringstream livesstream;
	livesstream << "LIVES : " << p.getLives();

	sf::Text score(scorestream.str(), font, 15);
	score.setStyle(sf::Text::Bold);
	score.setColor(sf::Color::Green);
	score.setOrigin(50, 175);

	sf::Text lives(livesstream.str(), font, 15);
	lives.setStyle(sf::Text::Bold);
	lives.setColor(sf::Color::Green);
	lives.setOrigin(-750, 175);

	window.draw(score);
	window.draw(lives);
}

}  // namespace AR
