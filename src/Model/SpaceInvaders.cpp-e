/*
 * SpaceInvaders.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: raffson
 */

#include "SpaceInvaders.h"

namespace AR {

/**
 *  \brief Global random number generator for AR::SpaceInvaders::RandomAlienFire.
 */
std::mt19937_64 gen;

void SpaceInvaders::InitObjects(const unsigned int& players)
{
	for(unsigned int i=0; i < players; i++)
	{
		//in case of MP, specific locations should be passed along
		AddObject(objType::_Player);
	}
	Location first(50, 100); // -> 50 & -550 are limits for movement
	for(unsigned int i=0; i < 6; i++)
	{
		for(unsigned int j=0; j < 12; j++)
		{
			Location offset( -float(j*50), -float(i*50) );
			Location pos = first+offset;
			AddObject(objType::_Alien, pos);
		}
	}
	AddObject(objType::_Shield, Location(0, -500));
	AddObject(objType::_Shield, Location(-350, -500));
	AddObject(objType::_Shield, Location(-700, -500));
}

SpaceInvaders::SpaceInvaders(const unsigned int& players) : level(1), mright(true)
{
	gen.seed(time(NULL));
	InitObjects(players);
}

SpaceInvaders::~SpaceInvaders() { }

const unsigned int SpaceInvaders::GetLevel() const { return level; }
void SpaceInvaders::NextLevel() { ++level; }

void SpaceInvaders::MovePlayerLeft()
{
	for( auto &i : entities )
	{
		if( typeid(*i) == typeid(Player) )
		{
			i->MoveLeft();
			return;
		}
	}
}

void SpaceInvaders::MovePlayerRight()
{
	for( auto &i : entities )
	{
		if( typeid(*i) == typeid(Player) )
		{
			i->MoveRight();
			return;
		}
	}
}

//adjust this function to get aliens to move further when a column was destroyed
const bool SpaceInvaders::BorderReached(const Object& first)
{
	return ( (first.pos.x >= 50 and !mright) or
			(first.pos.x <= -250 and mright) );
}

void SpaceInvaders::MoveAliensDown()
{
	mright = !mright; //change direction
	for( auto &i : entities )
	{
		if( typeid(*i) != typeid(Alien) ) continue;
		i->MoveDown();
	}
}

void SpaceInvaders::MoveAliensLeft()
{
	for( auto &i : entities )
	{
		if( typeid(*i) != typeid(Alien) ) continue;
		i->MoveLeft();
	}
}

void SpaceInvaders::MoveAliensRight()
{
	for( auto &i : entities )
	{
		if( typeid(*i) != typeid(Alien) ) continue;
		i->MoveRight();
	}
}

const bool SpaceInvaders::NoFreeze() const
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(Freeze) ) return !i->Alive();
	}
	return true;
}

void SpaceInvaders::MoveAliens()
{
	if( NoFreeze() )
	{
		//bounds are 50 to -250 for most left row..
		bool flag = false;
		for( auto &i : entities )
		{
			if( typeid(*i) == typeid(Alien) )
			{
				if( !flag ) //check the first alien for bounds (only once)
				{
					if( BorderReached(*i) )
					{
						MoveAliensDown();
						return;
					}
					flag = true;
				}
				//normal move left/right
				if( mright ) MoveAliensRight();
				else MoveAliensLeft();
			}
		}
	}
}

void SpaceInvaders::RandomAlienFire()
{
	if( (gen() % (998+2*level)) >= (999+level-1) )
	{
		unsigned int randomIndex = gen() % 72;
		unsigned int counter = 0;
		for( auto& i : entities )
		{
			if( typeid(*i) == typeid(Alien) )
			{
				if( counter >= randomIndex and i->Alive() )
				{
					AddObject(objType::AlienBullet, i->pos);
					return;
				}
				++counter;
			}
		}
	}
}

void SpaceInvaders::MoveBullets()
{
	for( std::vector<std::shared_ptr<Object> >::iterator it=entities.begin();
			it < entities.end(); ++it)
	{
		//delete bullets out of bounds
		if( typeid(*(*it)) == typeid(Bullet) )
		{
			if( ((*it)->speed > 0 and (*it)->pos.y >= 150)
					or
				((*it)->speed < 0 and (*it)->pos.y <= -750) )
			{
				it = entities.erase(it);
				--it;
				continue;
			}
			if( NoFreeze() or (!NoFreeze() and ((*it)->speed > 0)) ) (*it)->MoveUp();
		}
	}
}

/**
 *  \brief Helper function for AR::SpaceInvaders::CollisionHandler that checks
 *  whether or not a bullet is close enough to another object.
 *  \param bullet The location of the bullet.
 *  \param obj The location of the object.
 *  \param range Will be used as a radius around the object to check if the
 *  bullet is close enough.
 *  \param offset Adjusts the center of the radius depending on the object.
 *  \return True if the bullet is close enough, else false.
 */
const bool inKillRange(const Location& bullet, const Location& obj,
		const float& range=25, const float& offset=20)
{
	float distance = std::sqrt( std::pow((bullet.x - (obj.x-offset)), 2)
				+ std::pow((bullet.y - (obj.y-offset)), 2) );
	if( distance <= range ) return true;
	else return false;
}

std::vector<std::shared_ptr<Object> >::iterator
	SpaceInvaders::GetIterator(const Object& b)
{
	for( std::vector<std::shared_ptr<Object> >::iterator it=entities.begin();
			it < entities.end(); ++it )
	{
		if( *(*it) == b ) { return it; }
	}
	//if we get here -> wrong use of function
	throw GameException(GameException::Type::EntityNotFound);
}

/**
 *  \brief Helper function for AR::SpaceInvaders::CollisionHandler that checks
 *  whether or not the speeds are opposing.
 *  \param v1 The speed of the object.
 *  \param v2 The speed of the object.
 *  \return True if (v1 < 0 < v2 or v1 > 0 > v2), otherwise false.
 */
const bool OpposingSpeeds(const float& v1, const float& v2)
{
	if( v1 > 0 and v2 < 0 ) return true;
	else if( v1 < 0 and v2 > 0 ) return true;
	else return false;
}

/**
 *  \brief Helper function for AR::SpaceInvaders::CollisionHandler that checks
 *  whether or not a shield got hit.
 *  \param bullet The bullet which we're using to do this check.
 *  \param shield The shield which we're using to do this check.
 *  \return True if the bullet is close enough to the shield, otherwise false.
 *
 *  This function is needed since AR::inKillRange uses a radius which we don't want in
 *  case of a shield, therefore we use this adapted function.
 */
const bool ShieldHit(const Object& bullet, const Object& shield)
{
	if( (bullet.pos.y-5) <= shield.pos.y and (bullet.pos.y+5) >= (shield.pos.y-5) )
	{
		if( (bullet.pos.x-5) <= shield.pos.x and (bullet.pos.x+5) >= (shield.pos.x-100) )
			return true;
	}
	return false;
}

void SpaceInvaders::RenewShields()
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(Shield) )
		{
			i->Revive();
		}
	}
}

void SpaceInvaders::CollisionHandler()
{
	Player& player = GetPlayer();
	//get a reference to the player in case we need to award him

	for( std::vector<std::shared_ptr<Object> >::iterator it=entities.begin();
			it < entities.end(); ++it)
	{
		//iterate through all objects & execute the following code for bullets only
		if( typeid(*(*it)) == typeid(Bullet) )
		{
			//compare the bullet vs all other objects
			for( auto& i : entities )
			{
				if( typeid(*i) == typeid(Alien) ) //bullet vs alien
				{
					//alien must be alive, bullet's speed > 0 indicating a player-bullet
					//& finally the bullet must be in kill-range
					if( i->Alive() and ((*it)->speed > 0)
							and inKillRange((*it)->pos, i->pos) )
					{
						//kill the alien
						i->Die();
						//erase the bullet & adjust the iterator "it"
						it = entities.erase(it);
						--it;
						//award the player
						player.Award();
						//break out of "for( auto& i : entities )" loop
						break;
					}
				}
				else if( typeid(*i) == typeid(Player) ) //bullet vs player
				{
					//bullet's speed < 0 indicating an alien-bullet & must be in kill-range
					if( ((*it)->speed < 0) and inKillRange((*it)->pos, i->pos) )
					{
						//kill the player(=decrease the amount of lives)
						i->Die();
						//erase the bullet & adjust the iterator "it"
						it = entities.erase(it);
						--it;
						//pause the game
						PauseGame();
						//break out of "for( auto& i : entities )" loop
						break;
					}
				}
				//bullet vs bullet if and only if the 2 bullets are different,
				//otherwise a bullet will collide with itself, which is no good
				else if( (typeid(*i) == typeid(Bullet)) and !( (*(*it)) == (*i) )  )
				{
					//if the bullets are close enough to eachother & have opposing speeds,
					//indicating it's a player-bullet vs alien-bullet
					if( inKillRange((*it)->pos, i->pos, 10, 0)
							and OpposingSpeeds((*it)->speed, i->speed) )
					{
						//erase the "second" bullet
						entities.erase( GetIterator(*i) );
						//erase the "first" bullet & ajdust the iterator "it"
						it = entities.erase(it);
						--it;
						//break out of "for( auto& i : entities )" loop
						break;
					}
				}
				else if( i->IsPowerUp() and !i->Alive() ) //bullet vs power-up
					//if this is a class derived from PowerUp && !alive(=!used) ->true
				{
					//no bullet speed check since PUs float above the aliens,
					//thus, only check if the bullet is in kill-range
					if( inKillRange((*it)->pos, i->pos, 17.5, 7.5) )
					{
						//Killing the power-up will set its member "used" to true,
						//optionally a timer will start running
						i->Die();
						//erase the bullet & adjust the iterator "it"
						it = entities.erase(it);
						--it;
						//Depending on the power-up, do something accordingly
						if( typeid(*i) == typeid(Points) ) player.Award(10);
						else if( typeid(*i) == typeid(ExtraLife) ) player.Revive();
						else if( typeid(*i) == typeid(SlowMotion) ) SetSloMoSpeeds();
						else if( typeid(*i) == typeid(NewShields) ) RenewShields();
						//DoubleBulletSpeed gets handled in addObject when player fires
						//break out of "for( auto& i : entities )" loop
						break;
					}
				}
				else if( (typeid(*i) == typeid(Shield)) and i->Alive() ) //bullet vs shield
				{
					//"inKillRange" gets evaluated by a radius, which is not the case here
					//therefore, use a diffrent algorithm to determine a "ShieldHit"
					if( ShieldHit(*(*it), *i) )
					{
						//Damage the shield
						i->Die();
						//erase the bullet & adjust the iterator "it"
						it = entities.erase(it);
						--it;
						//break out of "for( auto& i : entities )" loop
						break;
					}
				}
			}
			//after a break statement, we get here, which is also the end of the first loop
			//thus, we carry on with the next bullet
		}
	}
}

void SpaceInvaders::InitAlienPositions()
{
	Location first(50, 100); // -> 50 & -550 are limits for movement
	unsigned int k = 0;
	unsigned int j = 0;
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(Alien) )
		{
			Location offset( -float(j*50), -float(k*50) );
			i->pos = first+offset;
			i->Revive();
			i->speed = level * 0.0005;
			if( SloMo() ) i->speed /= 5;
			++j;
			if( j >= 12 )
			{
				++k;
				j = 0;
			}
		}
	}
}

const bool SpaceInvaders::AllAliensDead() const
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(Alien) )
		{
			if( i->Alive() ) return false;
		}
	}
	return true;
}

void SpaceInvaders::RemoveTimedOutPUs()
{
	for( std::vector<std::shared_ptr<Object> >::iterator it=entities.begin();
			it < entities.end(); ++it)
	{
		if( (*it)->IsPowerUp() )
		{
			//As long as Die() wasn't called -> Used() returns false
			//Alive will return false, unless PU is 'timing out'
			//	-> 'timing out' starts as soon as Die() is called & lasts for a given time
			//	-> when PU is timed out -> false is returned again.
			if( dynamic_cast<PowerUp&>(*(*it)).Used() and !(*it)->Alive() )
			{
				if( typeid(*(*it)) == typeid(SlowMotion) ) SetNormalSpeeds();
				it = entities.erase(it);
				--it;
			}
		}
	}
}

void SpaceInvaders::LevelChecker()
{
	if( AllAliensDead() )
	{
		NextLevel();
		InitAlienPositions(); //aliens also get revived
		GetPlayer().Revive();
	}
}

void SpaceInvaders::GameCore()
{
	CollisionHandler(); //if aliens die, the movent envelope might change... -> how?
	RemoveTimedOutPUs();
	LevelChecker();
}

void SpaceInvaders::DeleteBullets()
{
	for( std::vector<std::shared_ptr<Object> >::iterator it=entities.begin();
			it < entities.end(); ++it)
	{
		if( typeid(*(*it)) == typeid(Bullet) ) //check the speed of bullet
		{
			it = entities.erase(it);
			--it;
		}
	}
}

void SpaceInvaders::DeletePUs()
{
	for( std::vector<std::shared_ptr<Object> >::iterator it=entities.begin();
			it < entities.end(); ++it)
	{
		if( (*it)->IsPowerUp() )
		{
			it = entities.erase(it);
			--it;
		}
	}
}

void SpaceInvaders::Reset()
{
	started = false;
	paused = false;
	gameOver = false;
	level = 1;
	mright = false;
	GetPlayer().Reset();
	DeleteBullets();
	InitAlienPositions();
	DeletePUs();
	RenewShields();
}

const bool SpaceInvaders::NoPowerUps() const
{
	for( auto&i : entities )
	{
		if( i->IsPowerUp() ) return false;
	}
	return true;
}

void SpaceInvaders::AddPowerUp(int type)
{
	//NOTE : LASERGUN CAUSES LAG! HOW DO WE GET RID OF IT?
	//only 1 PU at a time
	if( NoPowerUps() and ((gen() % 1000) == 0) ) //still need to tweak the chance...
	{
		if( type == Generic) type = (gen() % 7) + 1;
		if( type ==  _Points)
			entities.push_back( std::make_shared<Points>() );
		else if( type == _ExtraLife )
			entities.push_back( std::make_shared<ExtraLife>() );
		else if( type == _LaserGun )
			entities.push_back( std::make_shared<LaserGun>() );
		else if( type == _Freeze )
			entities.push_back( std::make_shared<Freeze>() );
		else if( type == _SlowMotion )
			entities.push_back( std::make_shared<SlowMotion>() );
		else if( type == _DoubleBulletSpeed )
			entities.push_back( std::make_shared<DoubleBulletSpeed>() );
		else if( type == _NewShields )
			entities.push_back( std::make_shared<NewShields>() );
		else std::cout << "Unknown PowerUp-type in SpaceInvaders::AddPowerUp." << std::endl;
	}
}

void SpaceInvaders::MovePowerUps()
{
	for( std::vector<std::shared_ptr<Object> >::iterator it=entities.begin();
			it < entities.end(); ++it )
	{
		if( (*it)->IsPowerUp() and !(*it)->Alive() )
		{
			if( (*it)->pos.x > -820 ) (*it)->MoveRight();
			else
			{
				it = entities.erase(it);
				--it;
			}
		}
	}
}

void SpaceInvaders::Update()
{
	try
	{
		AddPowerUp();
		MovePowerUps();
		MoveAliens();
		RandomAlienFire();
		MoveBullets();
		GameCore(); //-> checks collisions & updates scores, handles 'alive' of alien...
	}
	catch( GameException& e )
	{
		if( e.ErrorCode() == GameException::Type::GameOver ) EndGame();
		else std::cout << e.what() << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl;
	} catch (...) { std::cout << "Unknown exception occurred." << std::endl; }
}

Player& SpaceInvaders::GetPlayer()
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(Player) ) return (*dynamic_cast<Player*>(&*i));
	}
	//throw exception -> no player found, should never be the case though
	throw GameException(GameException::Type::NoPlayer);
}

const bool SpaceInvaders::DBS() const
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(DoubleBulletSpeed) ) return i->Alive();
	}
	return false;
}

const bool SpaceInvaders::SloMo() const
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(SlowMotion) ) return i->Alive();
	}
	return false;
}

void SpaceInvaders::AddObject(const int& obj, const Location& loc)
{
	if( obj == objType::_Player )
	{
		//for MP, a specific location should be used
		entities.push_back( std::make_shared<Player>() );
	}
	else if( obj == objType::_Alien )
	{
		entities.push_back( std::make_shared<Alien>(loc) );
	}
	else if( obj == objType::PlayerBullet )
	{
		//for MP, need to distinguish the players
		const Player& player = GetPlayer();
		Location bpos = player.pos + Location(-20, 20);
		entities.push_back( std::make_shared<Bullet>(bpos) );
		if( DBS() ) entities.back()->speed *= 10;
	}
	else if( obj == objType::AlienBullet )
	{
		Location bpos = loc + Location(-20, -40);
		entities.push_back( std::make_shared<Bullet>(bpos,
				-std::min<double>(2, (0.45+(0.05*level))) ) );
		if( SloMo() ) entities.back()->speed /= 5;
	}
	else if( obj == objType::RandomPU )
	{
		AddPowerUp();
	}
	else if( obj == objType::_Shield )
	{
		entities.push_back( std::make_shared<Shield>(loc) );
	}
}

const bool SpaceInvaders::LaserGunActive() const
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(LaserGun) ) return i->Alive();
	}
	return false;
}

const bool SpaceInvaders::NoBullets() const
{
	if( LaserGunActive() ) return true;
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(Bullet) and i->speed > 0 ) return false;
	}
	return true;
}

void SpaceInvaders::SetSloMoSpeeds()
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(Alien) or
				typeid(*i) == typeid(PowerUp) or
				(typeid(*i) == typeid(Bullet) and i->speed < 0) )
		{
			i->speed /= 5;
		}
	}
}

void SpaceInvaders::SetNormalSpeeds()
{
	for( auto& i : entities )
	{
		if( typeid(*i) == typeid(Alien) or
				typeid(*i) == typeid(PowerUp) or
				(typeid(*i) == typeid(Bullet) and i->speed < 0) )
		{
			i->speed *= 5;
		}
	}
}

void SpaceInvaders::PlayerFires()
{
	AddObject(SpaceInvaders::objType::PlayerBullet);
}

}  // namespace AR
