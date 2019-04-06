#pragma once
#include "cocos2d.h"

class GameObjects;

enum TileType
{
	pacDots,
	walls
};

class BaseTile
{
public:
	BaseTile(cocos2d::Vec2 position, float tileSize);

	static std::vector<BaseTile*> tileList;
	static void deleteTiles();

	cocos2d::Rect boundingBox;
	TileType type;

	bool checkCollision(GameObjects* otherObject);
	virtual bool resolveCollision(GameObjects* otherObject) = 0;
};