/*
 * GameState.h
 *
 *  Created on: Nov 18, 2013
 *      Author: raffson
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <vector>
#include <memory>
#include <cmath>
#include <typeinfo>
#include "Object.h"

namespace AR {

/**
 *  \class GameState
 *  \brief Abstract base class for games.
 */
class GameState {
protected:
	/**
	 *  \brief Vector of all objects in the game.
	 */
	std::vector<std::shared_ptr<Object> > entities;

	/**
	 *  \brief Boolean value to determine whether or not the game has started.
	 */
	bool started;

	/**
	 *  \brief Boolean value to determine whether or not the game is paused.
	 */
	bool paused;

	/**
	 *  \brief Boolean value to determine whether or not the game is over.
	 */
	bool gameOver;

	/**
	 *  \brief Pure virtual protected function that will act as an internal factory
	 *  for the derived games.
	 */
	virtual void AddObject(const int& obj, const Location& loc=Location()) = 0;

public:
	/**
	 *	Default constructor.
	 */
	GameState();

	/**
	 *	Default destructor.
	 */
	virtual ~GameState();

	/**
	 *	\brief Checks whether or not the game has started.
	 *	\return Data member 'started'
	 */
	virtual const bool Started() const;

	/**
	 *	\brief Checks whether or not the game is paused.
	 *	\return Data member 'paused'
	 */
	virtual const bool Paused() const;

	/**
	 *	\brief Checks whether or not the game is over.
	 *	\return Data member 'gameOver'
	 */
	virtual const bool GameOver() const;

	/**
	 *	\brief Resets the game.
	 *
	 *	More specifically 'entities' is emptied & all boolean data members are set to false.
	 */
	virtual void Reset();

	/**
	 *	\brief Sets 'started' to true.
	 */
	virtual void StartGame();

	/**
	 *	\brief Sets 'gameOver' to true.
	 */
	virtual void EndGame();

	/**
	 *	\brief Sets 'paused' to true.
	 */
	virtual void PauseGame();

	/**
	 *	\brief Sets 'paused' to false.
	 */
	virtual void ResumeGame();

	/**
	 *	\brief Checks if there are bullets within 'entities'.
	 *	\return Always true, unless overridden by a dervied game (with bullets).
	 */
	virtual const bool NoBullets() const;

	/**
	 *	\brief Getter for 'entities'.
	 *	\return A constant reference to the vector 'entities'.
	 */
	const std::vector<std::shared_ptr<Object> >& GetObjects() const;

	/**
	 *	\brief Pure virtual function which will be used by derived games
	 *	to move the player left.
	 */
	virtual void MovePlayerLeft() = 0;

	/**
	 *	\brief Pure virtual function which will be used by derived games
	 *	to move the player right.
	 */
	virtual void MovePlayerRight() = 0;

	/**
	 *	\brief Pure virtual function which will be used by derived games
	 *	to allow a player to fire.
	 */
	virtual void PlayerFires() = 0;

	/**
	 *	\brief Pure virtual function which will be used to update the state of the game.
	 */
	virtual void Update() = 0;

	/**
	 *	\brief Pure virtual function which will be used to get the level of a game.
	 *	\return Current level of the game.
	 *
	 *	In case the derived game is "levelless", implement this function returning 0.
	 */
	virtual const unsigned int GetLevel() const = 0;

};

}  // namespace AR

#endif /* GAMESTATE_H_ */
