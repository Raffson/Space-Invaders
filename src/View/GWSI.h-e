/*
 * GWSI.h
 *
 *  Created on: Nov 19, 2013
 *      Author: raffson
 */

#ifndef GWSI_H_
#define GWSI_H_

#include "GameWindow.h"

namespace AR {

/**
 *  \class GWSI
 *  \brief Abbreviated class for GameWindowSpaceInvaders.
 *
 *	This class will control the output for the SpaceInvaders game. This is done by passing
 *	the objects from SpaceInvaders to the Update() function. More specifically this call is
 *	made in main.cpp at line 86.
 */
class GWSI: public GameWindow {
private:
	/**
	 *  \brief Private variable for the messages that have to be drawn.
	 *
	 *  The first 2 elements are for the start-screen.
	 *  3 & 4 are for the pause-screen.
	 *  5 & 6 are for the the game-over-screen.
	 */
	std::vector<sf::Text> messages;
	/**
	 *  \brief Private variable for the font.
	 *
	 *  This is because messages that are initialized with a temporary
	 *  font will cause a segmentation fault, therefore keep it as a member.
	 */
	sf::Font font;

	/**
	 *  \brief Function which draws the messages for the start-screen.
	 */
	void StartScreen();

	/**
	 *  \brief Function which draws the messages for the pause-screen.
	 */
	void PauseScreen();

	/**
	 *  \brief Function which draws the messages for the game-over-screen.
	 */
	void GameOverScreen();

	/**
	 *  \brief Function which draws the messages for the player statistics.
	 *  \param p The player from which the info will be displayed.
	 */
	void PlayerStats(const Player& p);

public:
	/**
	 *  \brief Will initialize settings for the window.
	 */
	GWSI();

	/**
	 *  \brief Default destructor.
	 */
	virtual ~GWSI();

	/**
	 *  \brief Function to update the window of "this" object.
	 *  \param started True if the game started, i.e. after pressing enter.
	 *  \param paused True if the game is paused, i.e. after pressing p.
	 *  \param gameOver True if the game is over, i.e. when the player ran out of lives.
	 *  \param data Objects that must be drawn.
	 *  \param lvl Indicates which level must be drawn on the screen
	 *
	 * 	The boolean values will control the state of the screen. For example, if the
	 * 	game is paused, a message will be drawn on the screen with instructions to resume.
	 * 	The data will be used as a parameter for the factory to produce the shapes.
	 *	lvl will be converted into a message so it can be displayed.
	 */
	virtual void Update(const bool& started=false, const bool& paused=false,
			const bool& gameOver=false,
			const std::vector<std::shared_ptr<Object> >& data=
					std::vector<std::shared_ptr<Object> >(),
			const unsigned int& lvl=0);
};

}  // namespace AR

#endif /* GWSI_H_ */
