#include "SplashScene.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    return SplashScene::create();
}

// Print useful error message when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleOnce(schedule_selector(SplashScene::goToMainMenuScene), 2);

	auto background = Sprite::create("JampackLogo.png");
	background->setPosition(Director::getInstance()->getVisibleSize().width / 2 + origin.x, Director::getInstance()->getVisibleSize().height / 2 + origin.y);
	this->addChild(background);

    return true;
}

void SplashScene::goToMainMenuScene(float dt)
{
	auto scene = MainMenu::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}
