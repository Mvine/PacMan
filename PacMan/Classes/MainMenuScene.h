

#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void goToGameScene(cocos2d::Ref *a_sender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};

#endif // __HELLOWORLD_SCENE_H__
