#include "GameObjects.h"

float GameObjects::maxX = 1500.0f;
float GameObjects::maxY = 1000.0f;

GameObjects::GameObjects(cocos2d::Vec2 position, std::string spriteFile)
{
	theta = 0;

	sprite = cocos2d::Sprite::create(spriteFile);
	sprite->setPosition(position.x, position.y);
	//boundingBox = sprite->getBoundingBox();
	boundingBox.setRect(getLeftSidePos(), getBottomSidePos(), width, height);

	velocity = cocos2d::Vec2(0.0f, 0.0f);
}

GameObjects::~GameObjects()
{
	sprite->release();
}

cocos2d::Vec2 GameObjects::getPosition()
{
	return sprite->getPosition();
}

cocos2d::Sprite * GameObjects::getSprite()
{
	return sprite;
}

float GameObjects::getLeftSidePos()
{
	return getPosition().x - width / 2;
}

float GameObjects::getRightSidePos()
{
	return getPosition().x + width / 2;
}

float GameObjects::getTopSidePos()
{
	return getPosition().y - height / 2;
}

float GameObjects::getBottomSidePos()
{
	return getPosition().y + height / 2;
}

void GameObjects::deleteSprite()
{
	sprite->runAction(cocos2d::RemoveSelf::create());
	delete this;
}

bool GameObjects::isCollision(GameObjects * otherObject)
{
	if (this->boundingBox.getMinX() >= otherObject->boundingBox.getMaxX() || otherObject->boundingBox.getMinX() >= this->boundingBox.getMaxX())
	{
		return false;
	}
	else if (this->boundingBox.getMinY() >= otherObject->boundingBox.getMaxY() || otherObject->boundingBox.getMinY() >= this->boundingBox.getMaxY())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void GameObjects::updatePhysics(float dt)
{
	lastFramePosition = getPosition();
	sprite->setPosition(sprite->getPosition() + cocos2d::Vec2(velocity.x, velocity.y) * dt);
}
