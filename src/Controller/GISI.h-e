/*
 * GISI.h
 *
 *  Created on: Nov 19, 2013
 *      Author: raffson
 */

#ifndef GISI_H_
#define GISI_H_

#include "GameInput.h"

namespace AR {

/**
 *  \class GISI
 *  \brief Abbreviated class for GameInputSpaceInvaders.
 *
 *  This class will contains functions which will act as triggers to indicate inputs.
 *	These inputs will be translated into changes in the model according to 'main.cpp'
 *	starting at line 57 till 62.
 */
class GISI: public GameInput {
public:
	/**
	 *	Default constructor.
	 */
	GISI();
	/**
	 *	Default destructor.
	 */
	virtual ~GISI();

	/**
	 *  \brief Trigger to start the game.
	 *	\return True if the enter button was pressed, otherwise false.
	 *	\see AR::GameInput::StartGame()
	 *	\see AR::GameState::StartGame()
	 */
	virtual const bool StartGame() const;

	/**
	 *  \brief Trigger to pause the game.
	 *	\return True if the P button was pressed, otherwise false.
	 *	\see AR::GameInput::PauseGame()
	 *	\see AR::GameState::PauseGame()
	 */
	virtual const bool PauseGame() const;

	/**
	 *  \brief Trigger to resume the game.
	 *	\return True if the R button was pressed, otherwise false.
	 *	\see AR::GameInput::ResumeGame()
	 *	\see AR::GameState::ResumeGame()
	 */
	virtual const bool ResumeGame() const;

	/**
	 *  \brief Trigger to let the player fire.
	 *	\return True if the space button was pressed, otherwise false.
	 *	\see AR::SpaceInvaders::PlayerFires()
	 */
	virtual const bool Fire() const;

	/**
	 *  \brief Trigger to move the player left.
	 *	\return True if the left arrow button was pressed, otherwise false.
	 *	\see AR::SpaceInvaders::MovePlayerLeft()
	 */
	virtual const bool MoveLeft() const;

	/**
	 *  \brief Trigger to move the player right.
	 *	\return True if the right arrow button was pressed, otherwise false.
	 *	\see AR::SpaceInvaders::MovePlayerRight()
	 */
	virtual const bool MoveRight() const;
};

}  // namespace AR

#endif /* GISI_H_ */
