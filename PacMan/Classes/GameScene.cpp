#include "GameScene.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameObjects.h"
#include "InputHandler.h"
#include <iostream>

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	srand(time(NULL));

	director = Director::getInstance();
	director->setAnimationInterval(1.0f / 60.0f);
	director->setDisplayStats(1);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
	//Initialization of scene
	initGameObjects();
	initSprites();
    

	scheduleUpdate();

	return true;
}

void GameScene::initGameObjects()
{
	GameObjects::maxX = 1920.0f;
	GameObjects::maxY = 1080.0f;
}

void GameScene::initSprites()
{
	cocos2d::Vec2 origin = Director::sharedDirector()->getVisibleOrigin();
	Size size = Director::sharedDirector()->getVisibleSize();
	Vec2 center = Vec2(size.width / 2 + origin.x, size.height / 2 + origin.y);

	BaseTile::deleteTiles();

	cocos2d::TMXTiledMap * tileMap = TMXTiledMap::create("Tilemaps/tilemap.tmx");
	addChild(tileMap, 1);


	cocos2d::TMXLayer * wallLayer = tileMap->getLayer("Walls");

	for (unsigned int x = 0; x < tileMap->getMapSize().width; x++)
	{
		for (unsigned int y = 0; y < tileMap->getMapSize().height; y++)
		{
			cocos2d::Sprite* tile = wallLayer->getTileAt(Vec2(x, y));
			if (tile != 0)
			{
				WallTile* newWallTile = new WallTile(tile->getPosition(), 32);
					if (x != 0)
					{
						if (wallLayer->getTileAt(Vec2(x - 1, y)) != 0)
						{
							newWallTile->ignoreCollisionLeft = true;
						}
					}
					if (x != tileMap->getMapSize().width - 1)
					{
						if (wallLayer->getTileAt(Vec2(x + 1, y)) != 0)
						{
							newWallTile->ignoreCollisionRight = true;
						}
					}
					if (y != 0)
					{
						if (wallLayer->getTileAt(Vec2(x, y - 1)) != 0)
						{
							newWallTile->ignoreCollsiionUp = true;
						}
					}
					if (y != tileMap->getMapSize().height - 1)
					{
						if (wallLayer->getTileAt(Vec2(x + 1, y)) != 0)
						{
							newWallTile->ignoreCollsiionDown = true;
						}
					}
			}
		}
	}
	//Pacman
	PacMan::pacman->sprite = Sprite::create("pacman.png");
	this->addChild(PacMan::pacman->sprite, 10);
	PacMan::pacman->sprite->setPosition(Vec2(128, 128));
	PacMan::pacman->moveState = PacMan::MoveState::still;
	PacMan::pacman->powerState = PacMan::PowerState::normal;//TO DO: this is not how statse are supposed to be used effectively
	PacMan::pacman->direction = PacMan::Direction::left;


}

void GameScene::update(float dt)
{
	PacMan::pacman->update(dt);
	updateGameObjects(dt);
	updateEnemies(dt);


}

void GameScene::updateGameObjects(float dt)
{
}

void GameScene::updateEnemies(float dt)
{
}

void GameScene::removeAllObjects()
{
}

void GameScene::keyDown(EventKeyboard::KeyCode key, Event * event)
{
	switch (key)
	{
	case EventKeyboard::KeyCode::KEY_A:
		PacMan::pacman->direction = PacMan::Direction::left;
		PacMan::pacman->moveLeft(); //No time for real states.

	case EventKeyboard::KeyCode::KEY_D:
		PacMan::pacman->direction = PacMan::Direction::right;
		PacMan::pacman->moveRight();

	case EventKeyboard::KeyCode::KEY_S:
		PacMan::pacman->direction = PacMan::Direction::down;
		PacMan::pacman->moveDown();

	case EventKeyboard::KeyCode::KEY_W:
		PacMan::pacman->direction = PacMan::Direction::up;
		PacMan::pacman->moveUp();
	}
}

