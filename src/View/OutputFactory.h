/*
 * OutputFactories.h
 *
 *  Created on: Dec 10, 2013
 *      Author: raffson
 */

#ifndef OUTPUTFACTORY_H_
#define OUTPUTFACTORY_H_

#include <memory>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Model/DerivedObjects/Alien.h"
#include "../Model/DerivedObjects/Bullet.h"
#include "../Model/DerivedObjects/Player.h"
#include "../Model/DerivedObjects/PowerUp.h"
#include "../Model/DerivedObjects/Shield.h"
#include "../Model/DerivedObjects/DerivedPowerUps/DoubleBulletSpeed.h"
#include "../Model/DerivedObjects/DerivedPowerUps/ExtraLife.h"
#include "../Model/DerivedObjects/DerivedPowerUps/Freeze.h"
#include "../Model/DerivedObjects/DerivedPowerUps/LaserGun.h"
#include "../Model/DerivedObjects/DerivedPowerUps/NewShields.h"
#include "../Model/DerivedObjects/DerivedPowerUps/Points.h"
#include "../Model/DerivedObjects/DerivedPowerUps/SlowMotion.h"

namespace AR {

/**
 *  \class OutputFactory
 *  \brief Class that will create output for a GameWindow.
 *
 *	This class will represent the AbstractFactory to create figures.
 */
class OutputFactory {
public:
	/**
	 *  Default constructor.
	 */
	OutputFactory();
	/**
	 *  Default destructor.
	 */
	virtual ~OutputFactory();

	/**
	 *  \brief Pure virtual function that will create SFML shapes that can be drawn
	 *  onto an SFML window.
	 *	\param obj A reference to the object that must be drawn.
	 *	\return A shared pointer to the drawable SFML object.
	 */
	virtual std::shared_ptr<sf::Drawable> GetSFMLshape(const Object& obj) = 0;

	/**
	 *  \brief Function that will create a factory according to the specified type.
	 *	\param type An integer that represents the kind of factory according to 'TYPE'.
	 *	\return A shared pointer to the created factory.
	 */
	static std::shared_ptr<OutputFactory> CreateFactory(const int& type);

	/**
	 *  \brief Possibilities for the different factories which can be used as a parameter.
	 */
	enum TYPE {
		SFML = 0	/**< = 0   ---> Indicating an SFMLFactory. */
	};
};

} /* namespace AR */

#endif /* OUTPUTFACTORY_H_ */
