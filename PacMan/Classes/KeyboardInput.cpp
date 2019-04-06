#include "KeyboardInput.h"




KeyboardInput::KeyboardInput(cocos2d::Scene * scene, cocos2d::EventDispatcher dispatcher)
{
	keyboardListener = cocos2d::EventListenerKeyboard::create();

}

KeyboardInput::~KeyboardInput()
{
}
