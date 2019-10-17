/*
 * GameWindow.h
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 */

#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include "OutputFactory.h"

namespace AR {

/**
 *  \class GameWindow
 *  \brief Base class for windows based on SFML.
 *
 *	This class contains protected variables that will handle the output for the
 *	corresponding game. It also contains a factory to generate the figures.
 */
class GameWindow {
protected:

	/**
	 *  \brief Protected variable for an SFML window.
	 */
	sf::RenderWindow window;

	/**
	 *  \brief Protected variable for an SFML view which will can be used by the window.
	 */
	sf::View view;

	/**
	 *  \brief Protected variable to create figures.
	 */
	std::shared_ptr<OutputFactory> factory;

public:
	/**
	 *  \brief Will initialize settings for the window.
	 */
	GameWindow();

	/**
	 *  \brief Default destructor.
	 */
	virtual ~GameWindow();

	/**
	 *  \brief Getter for the window.
	 *  \return A reference to the window of "this" object.
	 *
	 *  This function is needed to determine whether or not the user is closing the window.
	 *  This is done by calling AR::GameInput::CloseGame( AR::GameWindow::getWindow() ).
	 *  More specifically this call is made in main.cpp at line 58.
	 */
	sf::RenderWindow& getWindow();

	/**
	 *  \brief Function to check if the window of "this" object is open.
	 *  \return True if the window is open, else false.
	 */
	const bool Open() const;

	/**
	 *  \brief Function to close the window.
	 *
	 *  This function will be called if AR::GameInput::CloseGame returns true in main.cpp at
	 *  line 58.
	 */
	void Close();

	/**
	 *  \brief Function to update the window of "this" object.
	 *  \param started True if the game started.
	 *  \param paused True if the game is paused.
	 *  \param gameOver True if the game is over.
	 *  \param data Objects that must be drawn.
	 *  \param lvl If applicable, indicates which level must be drawn on the screen.
	 *  If lvl is not specified, 0 will be passed as default argument to indicate the
	 *  game is "levelless".
	 *
	 *	This is a base class, therefor nothing fancy will happend in this function.
	 */
	virtual void Update(const bool& started=false, const bool& paused=false,
			const bool& gameOver=false,
			const std::vector<std::shared_ptr<Object> >& data=
					std::vector<std::shared_ptr<Object> >(),
			const unsigned int& lvl=0);
};

}  // namespace AR

#endif /* GAMEWINDOW_H_ */
