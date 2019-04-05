#include "PacMan.h"
PacMan* PacMan::pacman = 0;
PacMan::PacMan() :GameObjects(cocos2d::Vec2(200, 200), "a");
{

}

PacMan::~PacMan()
{
}

float PacMan::getSpeed()
{
	return m_Speed;
}

void PacMan::setSpeed(float a_Speed)
{
	m_Speed = a_Speed;
}

void PacMan::moveUp()
{
	velocity = (cocos2d::Vec2(0.0f,100.0f));
	
}

void PacMan::moveDown()
{
}

void PacMan::moveLeft()
{
}

void PacMan::moveRight()
{
}
