#pragma once
#include "cocos2d.h"
class KeyboardInput
{


public:


	KeyboardInput(cocos2d::Scene* scene, cocos2d::EventDispatcher dispatcher);
	~KeyboardInput();

	void init();


	cocos2d::EventListenerKeyboard * keyboardListener;

};

