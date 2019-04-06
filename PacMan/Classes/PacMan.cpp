#include "PacMan.h"
#include "Animation.h"

PacMan* PacMan::pacman = 0;

PacMan::PacMan() :GameObjects(cocos2d::Vec2(200, 200), "pacman.png"), 
powerState(PowerState::normal),
moveState(MoveState::still),
direction(Direction::right)
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
	return m_Speed;
}

void PacMan::setSpeed(float a_Speed)
{
	m_Speed = a_Speed;
}

//Move functions, would normally be handled by the state manager
void PacMan::moveUp()
{
	velocity = (cocos2d::Vec2(0.0f,100.0f));
	
}

void PacMan::moveDown()
{
	velocity = (cocos2d::Vec2(0.0f, -100.0f));
}

void PacMan::moveLeft()
{
	velocity = (cocos2d::Vec2(-100.0f, 0.0f));
}

void PacMan::moveRight()
{
	velocity = (cocos2d::Vec2(100.0f, 0.0f));
}

//reseting pacmans stats
void PacMan::reset()
{
	
}

//update functions
void PacMan::updateCollisions()
{
//TO DO:
}

void PacMan::update(float dt)
{
	this->updatePhysics(dt);

	//update
}
