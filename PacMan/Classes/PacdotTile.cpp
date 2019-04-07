#include "PacdotTile.h"
#include "GameObjects.h"
#include <iostream>

std::vector<PacdotTile*> PacdotTile::pacdotTileList = std::vector<PacdotTile*>();

PacdotTile::PacdotTile(cocos2d::Vec2 position, float tileSize)
	:BaseTile(position, tileSize),
	ignoreLeftCollision(false),
	ignoreRightCollision(false),
	ignoreTopCollision(false),
	ignoreBottomCollision(false)
{
	type = TileType::pacDots;
	boundingBox.setRect(position.x, position.y, tileSize, tileSize);
	
	pacdotTileList.push_back(this);
}

bool PacdotTile::resolveCollision(GameObjects * otherObject)
{
	//first see if there is any collision in the first place
	if (!this->checkCollision(otherObject))
		return false;
	//there is collision. time to resolve it
	else
	{
		for (int i = 0; i < BaseTile::tileList.size(); i++)
		{
			if (BaseTile::tileList[i] = this)
			{
			}
		}
	}
}

