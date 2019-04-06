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

bool WallTile::resolveCollision(GameObjects * otherObject)
{
	return false; //TO DO:
}