#include "GameObjects.h"

float GameObjects::maxX = 1500.0f;
float GameObjects::maxY = 1000.0f;
GameObjects::GameObjects(cocos2d::Vec2 position, std::string spriteFile)
{
	theta = 0;

	sprite = cocos2d::Sprite::create(spriteFile);
	sprite->setPosition(position.x, position.y);
	boundingBox = sprite->getBoundingBox;

	velocity = cocos2d::Vec2(0.0f, 0.0f);
	acceleration = cocos2d::Vec2(0.0f, 0.0f);

}

GameObjects::~GameObjects()
{
	sprite->release();
}

cocos2d::Vec2 GameObjects::getPosition()
{
	return sprite->getPosition;
}

cocos2d::Sprite * GameObjects::getSprite()
{
	return sprite;
}

void GameObjects::deleteSprite()
{
	sprite->release();
	delete this;
}
