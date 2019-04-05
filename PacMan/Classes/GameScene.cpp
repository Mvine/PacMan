#include "GameScene.h"
#include "SimpleAudioEngine.h"

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

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto emitter = ParticleSun::create();
	emitter->setPosition(visibleSize.height / 2 + origin.x, visibleSize.width / 2 + origin.y);
	emitter->setBlendAdditive(1);
	addChild(emitter, 1);

	auto emitter2 = ParticleFireworks::create();
	emitter2->setPosition(visibleSize.height / 2 + origin.x, visibleSize.width / 2 + origin.y);
	emitter2->setBlendAdditive(0);
	addChild(emitter2, 0);

	auto emitter3 = ParticleFireworks::create();
	emitter3->setPosition(visibleSize.height / 2 + origin.x, visibleSize.width / 2 + origin.y);
	emitter3->setBlendAdditive(0);
	emitter3->setRotation(90);
	addChild(emitter3, 0);

	auto emitter4 = ParticleFireworks::create();
	emitter4->setPosition(visibleSize.height / 2 + origin.x, visibleSize.width / 2 + origin.y);
	emitter4->setBlendAdditive(0);
	emitter4->setRotation(180);
	addChild(emitter4, 0);

	auto emitter5 = ParticleFireworks::create();
	emitter5->setPosition(visibleSize.height / 2 + origin.x, visibleSize.width / 2 + origin.y);
	emitter5->setBlendAdditive(0);
	emitter5->setRotation(270);
	addChild(emitter5, 0);

	return true;
}

