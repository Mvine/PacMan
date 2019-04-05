#include "MainMenuScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

// Print useful error message when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("testBG.png");
	background->setPosition(Director::getInstance()->getVisibleSize().width / 2 + origin.x, Director::getInstance()->getVisibleSize().height / 2 + origin.y);
	this->addChild(background, 0);

	auto button = MenuItemImage::create("MockStart.png", "MockStartSelected.png" ,CC_CALLBACK_1(MainMenu::goToGameScene, this));
	button->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);


	auto menu = Menu::create(button, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu, 1);

    return true;
}

void MainMenu::goToGameScene(cocos2d::Ref *a_sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}
