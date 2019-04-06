#include "WallTile.h"
#include "GameObjects.h"
#include <iostream>

std::vector<WallTile*> WallTile::wallTileList = std::vector<WallTile*>();


WallTile::WallTile(cocos2d::Vec2 position, float tileSize)
	:BaseTile(position, tileSize),
	ignoreCollisionLeft(false),
	ignoreCollisionRight(false),
	ignoreCollsiionUp(false),
	ignoreCollsiionDown(false)
{
	type = TileType::walls;
	boundingBox.setRect(position.x, position.y, tileSize, tileSize);

	wallTileList.push_back(this);
}

//bool WallTile::resolveCollision(GameObjects * otherObject)
//{
//	if (!this->checkCollision(otherObject))
//	{
//		return false;
//	}
//	else
//	{
//		cocos2d::Vec2 overlap;
//		//left
//		if (!this->ignoreCollisionLeft)
//		{
//			if (otherObject->boundingBox.getMaxX() > this->boundingBox.getMinX())
//			{
//				overlap = cocos2d::Vec2(abs(otherObject->boundingBox.getMaxX() - this->boundingBox.getMinX()), 0);
//				//otherObject->sprite->setPosition(otherObject->sprite->getPosition().x - 1, otherObject->sprite->getPosition().y);
//				otherObject->velocity = cocos2d::Vec2(0.0f, 0.0f);
//			}
//		}
//		//down
//		if (!this->ignoreCollsiionDown)
//		{
//			if (otherObject->boundingBox.getMinY() < this->boundingBox.getMaxY())
//			{
//				overlap = cocos2d::Vec2(abs(this->boundingBox.getMaxY() - otherObject->boundingBox.getMinY()), 0);
//				//otherObject->sprite->setPosition(otherObject->sprite->getPosition().x, otherObject->sprite->getPosition().y - 1);
//				otherObject->velocity = cocos2d::Vec2(0.0f, 0.0f);
//			}
//		}
//		//up
//		if (!this->ignoreCollsiionUp)
//		{
//			if (otherObject->boundingBox.getMaxY() > this->boundingBox.getMinY())
//			{
//				overlap = cocos2d::Vec2(abs(otherObject->boundingBox.getMaxY() - this->boundingBox.getMinY()), 0);
//				//otherObject->sprite->setPosition(otherObject->sprite->getPosition().x, otherObject->sprite->getPosition().y + 1);
//				otherObject->velocity = cocos2d::Vec2(0.0f, 0.0f);
//			}
//		}
//		//right
//		if (!this->ignoreCollisionRight)
//		{
//			if (otherObject->boundingBox.getMinX() > this->boundingBox.getMaxX())
//			{
//				overlap = cocos2d::Vec2(otherObject->boundingBox.getMinX() - this->boundingBox.getMaxX(), 0);
//				//otherObject->sprite->setPosition(otherObject->sprite->getPosition().x + 1, otherObject->sprite->getPosition().y);
//				otherObject->velocity = cocos2d::Vec2(0.0f, 0.0f);
//			}
//		}
//	}
//}

bool WallTile::resolveCollision(GameObjects * otherObject)
{
	//first see if there is any collision in the first place
	if (!this->checkCollision(otherObject))
		return false;
	//there is collision. time to resolve it
	else
	{
		cocos2d::Vec2 overlap;
		bool ignoreX = false;
		bool ignoreY = false;

		//get overlap on x
		float leftSideOverlap = abs(otherObject->sprite->getBoundingBox().getMaxX() - this->boundingBox.getMinX());
		float rightSideOverlap = abs(otherObject->sprite->getBoundingBox().getMinX() - this->boundingBox.getMaxX());
		overlap.x = std::min(leftSideOverlap, rightSideOverlap);

		//check for ignoring collision on x
		if ((otherObject->sprite->getBoundingBox().getMidX() > this->boundingBox.getMidX() && ignoreCollisionRight) || (otherObject->sprite->getBoundingBox().getMidX() < this->boundingBox.getMidX() && ignoreCollisionLeft))
			ignoreX = true;

		//get overlap on y
		float bottomOverlap = abs(otherObject->sprite->getBoundingBox().getMaxY() - this->boundingBox.getMinY());
		float topOverlap = abs(otherObject->sprite->getBoundingBox().getMinY() - this->boundingBox.getMaxY());
		overlap.y = std::min(bottomOverlap, topOverlap);

		//check for ignoring collision on y
		if ((otherObject->sprite->getBoundingBox().getMidY() > this->boundingBox.getMidY() && ignoreCollsiionUp) || (otherObject->sprite->getBoundingBox().getMidY() < this->boundingBox.getMidY() && ignoreCollsiionDown))
			ignoreY = true;

		if (overlap.y < overlap.x && !ignoreY) //overlap on y is more shallow, so we want to push the y back or if the object is at the top of the tile
		{
			if (bottomOverlap < topOverlap) //bottom is the shallow collision side
			{
				otherObject->sprite->setPositionY(otherObject->getPosition().y - overlap.y);
				otherObject->velocity.y = 0; //reset velocity after collision
			}
			else if (otherObject->velocity.y <= 0) //top side is the shallow collision side
			{
				otherObject->sprite->setPositionY(this->boundingBox.getMaxY() + (otherObject->sprite->getBoundingBox().size.height / 2));
				otherObject->velocity.y = 0; //reset velocity after collision
			}
		}
		else if (!ignoreX) //overlap on x is more shallow, so we want to push the x back
		{
			if (leftSideOverlap < rightSideOverlap) //left is the shallow collision side
				otherObject->sprite->setPositionX(this->boundingBox.getMinX() - (otherObject->sprite->getBoundingBox().size.width / 2) - 1);
			else //right side is the shallow collision side
				otherObject->sprite->setPositionX(this->boundingBox.getMaxX() + (otherObject->sprite->getBoundingBox().size.width / 2));

			//otherObject->sprite->setPositionX(otherObject->lastFramePosition.x); //push the object back to its x position last frame

			otherObject->velocity.x = 0; //reset velocity after collision
		}
		return true; //because a collision happened (and we resolved it)
	}
}
