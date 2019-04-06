#pragma once
#include "BaseTile.h"


class PacdotTile :
	public BaseTile
{
public:
	PacdotTile(cocos2d::Vec2 position, float tileSize);
	static std::vector<PacdotTile*> pacdotTileList;

	bool ignoreLeftCollision;
	bool ignoreRightCollision;
	bool ignoreBottomCollision;
	bool ignoreTopCollision;

	bool resolveCollision(GameObjects * otherObject) override;
};

