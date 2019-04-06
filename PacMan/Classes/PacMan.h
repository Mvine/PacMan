#pragma once
#include "cocos2d.h"
#include "GameObjects.h" 
class PacMan : public GameObjects
{
public:
	

	static PacMan* pacman;
	void createPacman();


	float getSpeed();
	void setSpeed(float a_Speed);

	enum PowerState
	{
		normal,
		powerUp,
		dead
	};
	PowerState powerState;

	enum MoveState
	{
		still,
		moving
	};
	MoveState moveState;

	enum Direction
	{
		up,
		down,
		left,
		right

	};
	Direction direction;


	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void reset();

	void updateCollisions();
	void update(float dt);

	float speed;

private:
	PacMan();

};