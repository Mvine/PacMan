#include "PacMan.h"
#include "Animation.h"
#include "BaseTile.h"

PacMan* PacMan::pacman = 0;

PacMan::PacMan() :GameObjects(cocos2d::Vec2(200, 200), "pacman.png"),
powerState(PowerState::normal),
moveState(MoveState::still),
direction(Direction::right),
speed(100.0f)
{
	marcos::AnimationManager::init();

}

//singleton
void PacMan::createPacman()
{
	if (!pacman)
		pacman = new PacMan;
}

float PacMan::getSpeed()
{
	return speed;
}

void PacMan::setSpeed(float a_Speed)
{
	speed = a_Speed;
}

//Move functions, would normally be handled by the state manager
void PacMan::moveUp()
{
	velocity = (cocos2d::Vec2(0.0f,1.0f) * speed);
	
}

void PacMan::moveDown()
{
	velocity = (cocos2d::Vec2(0.0f, -1.0f) * speed);
}

void PacMan::moveLeft()
{
	velocity = (cocos2d::Vec2(-1.0f, 0.0f) * speed);
}

void PacMan::moveRight()
{
	velocity = (cocos2d::Vec2(1.0f, 0.0f) * speed);
}

//reseting pacmans stats
void PacMan::reset()
{
	
}

//update functions
void PacMan::updateCollisions()
{
	//unsigned int ghostListSize = BaseTile::tileList.size(); /

	//for (int i = 0; i < tileListSize; i++)
	//{
	//	if(BaseTile::tileList[i]->checkCollision(this) )
	//}

	//TO DO : Ghost Collision
}

void PacMan::update(float dt)
{
	this->updatePhysics(dt);

	//update
}
