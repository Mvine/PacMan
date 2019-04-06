#pragma once
#include "BaseTile.h"
class WallTile : public BaseTile
{
public:
	WallTile(cocos2d::Vec2 position, float tileSize);

	static std::vector<WallTile*> wallTileList;

	bool ignoreCollisionLeft;
	bool ignoreCollisionRight;
	bool ignoreCollsiionUp;
	bool ignoreCollsiionDown;

	bool resolveCollision(GameObjects* otherObject) override;

};

