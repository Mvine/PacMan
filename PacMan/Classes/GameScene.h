

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "PacMan.h"
#include "WallTile.h"
#include "PacdotTile.h"
#include "Ghosts.h"
#include "InputHandler.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void goToMenuScene(float dt);
	void goToGameOverScene(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);


	void initGameObjects();
	void initSprites();
	void spawnEnemies();


	void update(float dt);
	void updateGameObjects(float dt);
	void updateEnemies(float dt);
	void removeAllObjects();

	void keyDown(EventKeyboard::KeyCode key, Event* event);
	void keyUp(EventKeyboard::KeyCode key, Event* event);

	//Audio
	bool Chomp = false;
	bool Death = false;
	bool eatfood = false;
	bool PowerUp = false;
	int count; //May not need, its an attempt at a timer

private:
	cocos2d::Director* director;


};

#endif // __HELLOWORLD_SCENE_H__
