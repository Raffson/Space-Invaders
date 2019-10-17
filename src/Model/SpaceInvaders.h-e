/*
 * SpaceInvaders.h
 *
 *  Created on: Nov 19, 2013
 *      Author: raffson
 */

#ifndef SPACEINVADERS_H_
#define SPACEINVADERS_H_

#include <memory>
#include <vector>
#include <iostream>
#include <random>

#include "DerivedObjects/Player.h"
#include "DerivedObjects/Alien.h"
#include "DerivedObjects/Bullet.h"
#include "DerivedObjects/Shield.h"
#include "DerivedObjects/DerivedPowerUps/LaserGun.h"
#include "DerivedObjects/DerivedPowerUps/Points.h"
#include "DerivedObjects/DerivedPowerUps/ExtraLife.h"
#include "DerivedObjects/DerivedPowerUps/Freeze.h"
#include "DerivedObjects/DerivedPowerUps/SlowMotion.h"
#include "DerivedObjects/DerivedPowerUps/DoubleBulletSpeed.h"
#include "DerivedObjects/DerivedPowerUps/NewShields.h"
#include "GameState.h"

namespace AR {

/**
 *  \class SpaceInvaders
 *  \brief This class will represent a space-invaders game.
 *
 *  I.e. the logic of the game will be defined/implemented in this class's members & methods.
 */
class SpaceInvaders : public GameState {
private:
	/**
	 *  \brief Indicated the current level.
	 *
	 *  The level will be used as a factor to determine the speed of aliens & their bullets.
	 */
	unsigned int level;

	/**
	 *  \brief Boolean value to indicate whether the aliens are moving left or right.
	 */
	bool mright;

	/**
	 *  \brief Initializes the objects needed to start the game.
	 *  \param players The number of players, although multiplayer is still unsupported.
	 *
	 *  This function will be only be called in the constructor.
	 */
	void InitObjects(const unsigned int& players);

	/**
	 *  \brief Moves all aliens one step left or right only if AR::SpaceInvaders::NoFreeze
	 *  returns true.
	 *  \see MoveAliensLeft
	 *  \see MoveAliensRight
	 *  \see MoveAliensDown
	 *  \see BorderReached
	 *
	 *  If 'mright' is true, aliens will move one step to the right, otherwise to the left.
	 *  If a border is reached, the aliens move down.
	 */
	virtual void MoveAliens();

	/**
	 *  \brief Moves all aliens one step up.
	 *  \see AR::Bullet::MoveUp()
	 *
	 *  Depending on the speed of the bullet, the bullet will move up or down.
	 */
	virtual void MoveBullets();

	/**
	 *  \brief Function which combines the following methods.
	 *  \see CollisionHandler()
	 *  \see RemoveTimedOutPUs()
	 *  \see LevelChecker()
	 */
	virtual void GameCore();

	/**
	 *  \brief Increments 'level' by 1.
	 */
	void NextLevel();

	/**
	 *  \brief Adjusts 'mright' if needed.
	 *  \param first Position of the top left alien, even when that alien is dead.
	 *  \return True if aliens reached a horizontal border, otherwise false.
	 *
	 *  If this alien reached one of the predefined borders, 'mright' will be set to the
	 *  opposite value. This function will also indicate when the aliens must move down.
	 */
	const bool BorderReached(const Object& first);

	/**
	 *  \brief Moves all aliens one step down.
	 *  \see AR::Alien::MoveDown()
	 */
	void MoveAliensDown();

	/**
	 *  \brief Moves all aliens one step left.
	 *  \see AR::Alien::MoveLeft()
	 */
	void MoveAliensLeft();

	/**
	 *  \brief Moves all aliens one step right.
	 *  \see AR::Alien::MoveRight()
	 */
	void MoveAliensRight();

	/**
	 *  \brief Find the player in the vector of entities
	 *  \return A reference to the player.
	 *  \throws AR::GameException (NoPlayer) if no player was found.
	 *
	 *  This function does not support multiplayer since it will return the first player
	 *  found.
	 */
	Player& GetPlayer();

	/**
	 *  \brief Handles all collisions between bullets & other objects,
	 *  using the following helper-functions.
	 *  \see AR::inKillRange
	 *  \see AR::OpposingSpeeds
	 *  \see AR::ShieldHit
	 */
	void CollisionHandler();

	/**
	 *  \brief Removes all "used & timed out" power-ups.
	 *  \see AR::SpaceInvaders::SetNormalSpeeds
	 *
	 *	Since the game only allows 1 PowerUp at a time, this function should only delete
	 *	1 element from the 'entities'. This particular PowerUp will be removed if it was
	 *	used (=hit by a bullet) & timed out (if applicable).
	 */
	void RemoveTimedOutPUs();

	/**
	 *  \brief Checks whether or not the level is completed.
	 *
	 *	If AR::SpaceInvaders::AllAliensDead returns true, the functions
	 *	AR::SpaceInvaders::NextLevel, AR::SpaceInvaders::InitAlienPositions
	 *	& AR::Player::Revive get called to initialize the new level. Otherwise nothing
	 *	will be done.
	 */
	void LevelChecker();

	/**
	 *  \brief Resets all aliens to their starting positions & revive them all.
	 */
	void InitAlienPositions();

	/**
	 *  \brief Checks whether or not all aliens are dead.
	 *	\return True if all aliens are dead, otherwise false.
	 */
	const bool AllAliensDead() const;

	/**
	 *  \brief Removes all bullets from the vector of 'entities'.
	 */
	void DeleteBullets();

	/**
	 *  \brief Choose a random Alien from the vector of 'entities' & add an alien bullet.
	 *  \see AddObject
	 */
	void RandomAlienFire();

	/**
	 *  \brief Checks if there's an active LaserGun power-up.
	 *  \return True there's an active LaserGun, else false.
	 *  \see AR::LaserGun::Alive
	 */
	const bool LaserGunActive() const;

	/**
	 *  \brief Add a PowerUp to the vector of 'entities'.
	 *  \param type If 0, a random PowerUp will be added, else 'type' should correspond to
	 *  a value from AR::SpaceInvaders::PUtype.
	 *  \see AR::Points
	 *  \see AR::ExtraLife
	 *  \see AR::LaserGun
	 *  \see AR::Freeze
	 *  \see AR::SlowMotion
	 *  \see AR::DoubleBulletSpeed
	 *  \see AR::NewShields
	 */
	void AddPowerUp(int type=0);

	/**
	 *  \brief Moves all power-ups one step to the right.
	 *  \see AR::PowerUp::MoveRight
	 */
	void MovePowerUps();

	/**
	 *  \brief Checks if there are power-ups present in the vector of 'entities'.
	 *  \return True if there are no power-ups in the vector of 'entities', else false.
	 *  \see AR::PowerUp::IsPowerUp
	 */
	const bool NoPowerUps() const;

	/**
	 *  \brief Removes all power-ups from the vector of 'entities'.
	 *  \see AR::PowerUp::IsPowerUp
	 *
	 *  This function is used when the game needs to be reset.
	 */
	void DeletePUs();

	/**
	 *  \brief Checks if there's an active Freeze present in the vector of 'entities'.
	 *  \return True if there's no active Freeze in the vector of 'entities', else false.
	 */
	const bool NoFreeze() const;

	/**
	 *  \brief Devides the speed of aliens & their bullets by 5.
	 */
	void SetSloMoSpeeds();

	/**
	 *  \brief Checks if there's an active DoubleBulletSpeed present
	 *  in the vector of 'entities'.
	 *  \return True if there's an active DoubleBulletSpeed
	 *  in the vector of 'entities', else false.
	 */
	const bool DBS() const;

	/**
	 *  \brief Multiply the speed of aliens & their bullets by 5.
	 */
	void SetNormalSpeeds();

	/**
	 *  \brief Checks if there's an active SlowMotion present in the vector of 'entities'.
	 *  \return True if there's an active SlowMotion in the vector of 'entities',
	 *  else false.
	 */
	const bool SloMo() const;

	/**
	 *  \brief Resets the shields.
	 */
	void RenewShields();

	/**
	 *  \brief Internal factory to create & add objects to the vector of 'entities'.
	 *  \param obj The type of the new object according to AR::SpaceInvaders::objType.
	 *  \param loc The location to be used for the new object.
	 */
	virtual void AddObject(const int& obj, const Location& loc=Location());

	//returns the iterator of the bullet that has to be destroyed

	/**
	 *  \brief Search & get an iterator according to b.
	 *  \param b The object to be found in the vector of 'entities'
	 *  \return Vector-iterator corresponding to the parameter b
	 *  \throws AR::GameException (AR::GameException::Type::EntityNotFound)
	 *
	 *  This function should only be used to get iterators of objects within the vector
	 *  of entities. Any attempt to find an object that is not in 'entities' will result
	 *  a GameException.
	 */
	std::vector<std::shared_ptr<Object> >::iterator
		GetIterator(const Object& b);

public:
	/**
	 *  \brief Custom constructor
	 *  \param players The number of players.
	 *
	 *  This constructor will seed the random number generator 'AR::gen'. It will also
	 *  call the AR::SpaceInvaders::InitObjects method.
	 */
	SpaceInvaders(const unsigned int& players=1);

	/**
	 *  \brief Default destructor
	 */
	virtual ~SpaceInvaders();

	/**
	 *  \brief This (overridden) function will move the Player left.
	 *  \see AR::Player::MoveLeft
	 *
	 *  This function does not support multiplayer movement.
	 *
	 */
	virtual void MovePlayerLeft();

	/**
	 *  \brief This (overridden) function will move the Player right.
	 *  \see AR::Player::MoveRight
	 *
	 *  This function does not support multiplayer movement.
	 */
	virtual void MovePlayerRight();

	/**
	 *  \brief This (overridden) function will add a player-bullet.
	 *  \see AddObject
	 */
	virtual void PlayerFires();

	/**
	 *  \brief This (overridden) function will update the game's state according to
	 *  the following methods.
	 *  \see AddPowerUp
	 *  \see MovePowerUps
	 *  \see MoveAliens
	 *  \see RandomAlienFire
	 *  \see MoveBullets
	 *  \see GameCore
	 *
	 *  This function catches all possible exceptions generated by the methods above.
	 */
	virtual void Update();

	/**
	 *  \brief This method resets the game's state.
	 *  \see AR::Player::Reset
	 *  \see DeleteBullets
	 *  \see InitAlienPositions
	 *  \see DeletePUs
	 *  \see RenewShields
	 *
	 *  This function also sets 'started', 'paused', 'gameOver' & 'mright' to false
	 *  & 'level to 1.
	 */
	virtual void Reset();

	/**
	 *  \brief This (overridden) function will check whether or not there are bullets
	 *  in the vector of 'entities'
	 *  \return True if no bullets where found, else false.
	 */
	virtual const bool NoBullets() const;

	/**
	 *  \brief This (overridden) function will indicate the current level of the game.
	 *  \return Data member 'level'
	 */
	virtual const unsigned int GetLevel() const;

	/**
	 *  \brief Possibilities for the different (supported) Object types.
	 */
	enum objType
	{
		_Player = 0, /**< = 0   ---> Indicating a Player */
		_Alien, /**< = 1   ---> Indicating an Alien */
		PlayerBullet, /**< = 2   ---> Indicating a PlayerBullet */
		AlienBullet, /**< = 3   ---> Indicating an AlienBullet */
		RandomPU, /**< = 4   ---> Indicating a random PowerUp */
		_Shield /**< = 5   ---> Indicating a Shield */
	};

	/**
	 *  \brief Possibilities for the different (supported) PowerUp types.
	 */
	enum PUtype
	{
		Generic = 0, /**< = 0   ---> Indicating PowerUp */
		_Points, /**< = 1   ---> Indicating Points */
		_ExtraLife, /**< = 2   ---> Indicating an ExtraLife */
		_LaserGun, /**< = 3   ---> Indicating a LaserGun */
		_Freeze, /**< = 4   ---> Indicating a Freeze */
		_SlowMotion, /**< = 5   ---> Indicating SlowMotion */
		_DoubleBulletSpeed, /**< = 6   ---> Indicating DoubleBulletSpeed */
		_NewShields /**< = 7   ---> Indicating NewShields */
	};
};

}  // namespace AR

#endif /* SPACEINVADERS_H_ */
