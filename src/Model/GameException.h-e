/*
 * GameException.h
 *
 *  Created on: Nov 21, 2013
 *      Author: raffson
 */

#ifndef GAMEEXCEPTION_H_
#define GAMEEXCEPTION_H_

#include <sstream>
#include <exception>

namespace AR {

/**
 *  \class GameException
 *  \brief Used to throw exceptions that are related to a game.
 */
class GameException: public std::exception {
private:
	/**
	 *  \brief Private variable to represent the type of exception (=error code).
	 */
	unsigned int code;
public:
	/**
	 *  \brief Custom constructor
	 *  \param c Error code that will be used to initialize "this" exception.
	 */
	GameException(const unsigned int& c = 0);

	/**
	 *  \brief Default destructor
	 */
	virtual ~GameException();

	/**
	 *  \brief Overridden what() returning a specific message according to code.
	 *  \return The appropriate message.
	 */
	virtual const char* what() const noexcept;

	/**
	 *  \brief Returns the error code.
	 *  \return Date member 'code'
	 *
	 *  This function will only be used once in main.cpp at line 77. Although the program
	 *  should never reach this execution path, it is still better to play it safe.
	 */
	virtual const unsigned int& ErrorCode() const noexcept;

	/**
	 *  \brief Possibilities for the different (supported) exceptions.
	 */
	enum Type
	{
		DefaultGameException = 0, /**< = 0   ---> Indicating a default game exception
									(should not be used). */
		GameOver, /**< = 1   ---> Indicating game over
							(will be thrown if player is out of lives or aliens breached).*/
		EntityNotFound, /**< = 2   ---> Indicating an entitiy was not found
							(will be thrown in SpaceInvaders.cpp at line 203). */
		NoPlayer /**< = 3   ---> Indicating no player was found
							(will be thrown in SpaceInvaders.cpp at line 505. */
		//maybe more to come...
	};
};

}  // namespace AR

#endif /* GAMEEXCEPTION_H_ */
