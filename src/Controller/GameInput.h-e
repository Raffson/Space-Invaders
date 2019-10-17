/*
 * GameInput.h
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 */

#ifndef GAMEINPUT_H_
#define GAMEINPUT_H_

#include "SFML/Graphics.hpp"

namespace AR {

/**
 *  \class GameInput
 *  \brief Abstract base class for inputs based on SFML.
 *
 *	This class contains a variable which describes the event.
 *	This event can be a button press, closing window, etc...
 *	That particular event can be retrieved by derived classes by calling the 'getEvent()'
 *	function.
 */
class GameInput {
private:

	/**
	 *  \brief Private variable that contains the current event.
	 */
	sf::Event event;

protected:

	/**
	 *  \brief Getter for private variable 'event'.
	 *	\return A constant reference to the current event.
	 *
	 *	Should be used by derived classes to access 'event' & handle things accordingly.
	 */
	const sf::Event& getEvent() const;

public:
	/**
	 *  \brief Default constructor.
	 */
	GameInput();

	/**
	 *  \brief Default destructor.
	 */
	virtual ~GameInput();

	/**
	 *  \brief Trigger to close a window.
	 *  \param w The window which needs to be checked for "closure".
	 *	\return True if user clicked on close button, else false.
	 *
	 *	"closure", i.e. checking if the user pressed the close button.
	 */
	const bool CloseGame(sf::RenderWindow& w);

	/**
	 *  \brief Pure virtual function which will be used as a trigger in derived classes.
	 *	\return A boolean value.
	 */
	virtual const bool StartGame() const = 0;

	/**
	 *  \brief Pure virtual function which will be used as a trigger in derived classes.
	 *	\return A boolean value.
	 */
	virtual const bool PauseGame() const = 0;

	/**
	 *  \brief Pure virtual function which will be used as a trigger in derived classes.
	 *	\return A boolean value.
	 */
	virtual const bool ResumeGame() const = 0;

	/**
	 *  \brief Pure virtual function which will be used as a trigger in derived classes.
	 *	\return A boolean value.
	 */
	virtual const bool Fire() const = 0;

	/**
	 *  \brief Pure virtual function which will be used as a trigger in derived classes.
	 *	\return A boolean value.
	 */
	virtual const bool MoveLeft() const = 0;

	/**
	 *  \brief Pure virtual function which will be used as a trigger in derived classes.
	 *	\return A boolean value.
	 */
	virtual const bool MoveRight() const = 0;
};

}  // namespace AR

#endif /* GAMEINPUT_H_ */
