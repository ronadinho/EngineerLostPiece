#include "GameOverScene.h"
#include "MenuPrincipal.h"
#include "GameScene.h"

USING_NS_CC;
void GameOverScene::goToMainMenuScene(Ref *pSender) {
	auto scene = MenuPrincipal::createScene();
	Director::getInstance()->replaceScene(scene);
}
void GameOverScene::goToGameScene(Ref *pSender) {
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
Scene* GameOverScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create("images/fin_juego.png");
	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));
	addChild(background, 0);


	return true;
}

