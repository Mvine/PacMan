#pragma once
#include "cocos2d.h"
class GameObjects
{
public:
	GameObjects(cocos2d::Vec2 position, std::string spriteFile);
	virtual ~GameObjects();

	static float maxY;
	static float maxX;

	float width;
	float height;
	float theta;

	cocos2d::Vec2 lastFramePosition;

	cocos2d::Vec2 velocity;

	cocos2d::Sprite* sprite;
	cocos2d::Rect boundingBox;

	cocos2d::Vec2 getPosition();
	cocos2d::Sprite* getSprite();

	float getLeftSidePos();
	float getRightSidePos();
	float getTopSidePos();
	float getBottomSidePos();

	void deleteSprite();
	bool isCollision(GameObjects* otherObject);

	virtual void updatePhysics(float dt);
};

