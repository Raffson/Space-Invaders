/*
 * OutputFactories.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: raffson
 */

#include "OutputFactory.h"

/**
 *  \file OutputFactory.cpp
 *  \brief Contains implementations for 'AR::OutputFactory' & 'AR::SFMLFactory'.
 */

namespace AR {

/**
 *  \class SFMLFactory
 *  \brief Class that will create output based on SFML-library for a GameWindow.
 */
class SFMLFactory : public OutputFactory
{
private:

	/**
	 *  \brief Function that will create an Alien using SFML-library.
	 *	\param obj A reference to the object that has to be drawn.
	 *	\return A shared pointer to the created SFML alien.
	 */
	std::shared_ptr<sf::Drawable> CreateAlien(const Object& obj)
	{
		sf::CircleShape sq(25, 4); //square for alien
		sq.setOrigin(obj.pos.x, obj.pos.y);
		if( !obj.Alive() ) sq.setFillColor(sf::Color::Transparent);
		else sq.setFillColor(sf::Color::White);
		return std::make_shared<sf::CircleShape>(sq);

	}

	/**
	 *  \brief Function that will create a Bullet using SFML-library.
	 *	\param obj A reference to the object that has to be drawn.
	 *	\return A shared pointer to the created SFML bullet.
	 */
	std::shared_ptr<sf::Drawable> CreateBullet(const Object& obj)
	{
		sf::CircleShape c(5); // small circle for bullet
		if( obj.speed > 0 ) c.setFillColor(sf::Color::Red);
		else c.setFillColor(sf::Color::White);
		c.setOrigin(obj.pos.x, obj.pos.y);
		return std::make_shared<sf::CircleShape>(c);

	}

	/**
	 *  \brief Function that will create a Player using SFML-library.
	 *	\param obj A reference to the object that has to be drawn.
	 *	\return A shared pointer to the created SFML player.
	 */
	std::shared_ptr<sf::Drawable> CreatePlayer(const Object& obj)
	{
		sf::CircleShape tri(25, 3); //triangle figure for player
		tri.setFillColor(sf::Color::Green);
		tri.setOrigin(obj.pos.x, obj.pos.y);
		return std::make_shared<sf::CircleShape>(tri);
	}

	/**
	 *  \brief Function that will create a PowerUp using SFML-library.
	 *	\param obj A reference to the object that has to be drawn.
	 *	\return A shared pointer to the created SFML power-up.
	 */
	std::shared_ptr<sf::Drawable> CreatePowerUp(const Object& obj)
	{
		sf::CircleShape c(12.5);
		c.setOrigin(obj.pos.x, obj.pos.y);
		if( dynamic_cast<const PowerUp&>(obj).Used() )
		{
			c.setFillColor(sf::Color::Transparent);
			return std::make_shared<sf::CircleShape>(c);
		}
		if( typeid(obj) == typeid(DoubleBulletSpeed) )
			c.setFillColor(sf::Color(127, 0, 0));
		else if( typeid(obj) == typeid(ExtraLife) )
			c.setFillColor(sf::Color::Green);
		else if( typeid(obj) == typeid(Freeze) )
			c.setFillColor(sf::Color::Cyan);
		else if( typeid(obj) == typeid(LaserGun) )
			c.setFillColor(sf::Color::Red);
		else if( typeid(obj) == typeid(NewShields) )
			c.setFillColor(sf::Color(0, 127, 0));
		else if( typeid(obj) == typeid(Points) )
			c.setFillColor(sf::Color(255, 215, 0));
		else if( typeid(obj) == typeid(SlowMotion) )
			c.setFillColor(sf::Color::Blue);
		else c.setFillColor(sf::Color::White);; //default color
		return std::make_shared<sf::CircleShape>(c);
	}

	/**
	 *  \brief Function that will create a Shield using SFML-library.
	 *	\param obj A reference to the object that has to be drawn.
	 *	\return A shared pointer to the created SFML shield.
	 */
	std::shared_ptr<sf::Drawable> CreateShield(const Object& obj)
	{
		sf::RectangleShape line(sf::Vector2f(100, 5)); //square for alien
		line.setOrigin(obj.pos.x, obj.pos.y);
		std::pair<int, int> rg = dynamic_cast<const Shield&>(obj).GetHealth();
		sf::Color col( rg.first, rg.second, 0 );
		if( col != sf::Color::Red ) line.setFillColor(col);
		else line.setFillColor(sf::Color::Transparent);
		return std::make_shared<sf::RectangleShape>(line);
	}

public:

	/**
	 *  \brief Overriding function that will create an SFML shape by calling
	 *  the appropriate private function.
	 *	\param obj A reference to the object that has to be drawn.
	 *	\return A shared pointer to the created SFML shape.
	 */
	virtual std::shared_ptr<sf::Drawable> GetSFMLshape(const Object& obj)
	{
		if( typeid(obj) == typeid(Alien) )
			return CreateAlien(obj);
		else if( typeid(obj) == typeid(Bullet) )
			return CreateBullet(obj);
		else if( typeid(obj) == typeid(Player) )
			return CreatePlayer(obj);
		else if( obj.IsPowerUp() )
			return CreatePowerUp(obj);
		else if( typeid(obj) == typeid(Shield) )
			return CreateShield(obj);
		else return std::make_shared<sf::CircleShape>(); //return a default shape
	}

};

OutputFactory::OutputFactory() { }

OutputFactory::~OutputFactory() { }

std::shared_ptr<OutputFactory> OutputFactory::CreateFactory(const int& type)
{
	if( type == TYPE::SFML )
		return std::make_shared<SFMLFactory>();
	else //return a default factory -> in this case : SFMLFactory
		return std::make_shared<SFMLFactory>();
}

} /* namespace AR */
