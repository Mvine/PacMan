#include "BaseTile.h"
#include "WallTile.h"
#include "PacdotTile.h"
#include "PacMan.h"

std::vector<BaseTile*> BaseTile::tileList = std::vector<BaseTile*>();

BaseTile::BaseTile(cocos2d::Vec2 position, float tileSize)
{
	boundingBox.setRect(position.x, position.y, tileSize, tileSize);
	tileList.push_back(this);
}

void BaseTile::deleteTiles()
{
	tileList.clear();
	WallTile::wallTileList.clear();
}

bool BaseTile::checkCollision(GameObjects * otherObject)
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


