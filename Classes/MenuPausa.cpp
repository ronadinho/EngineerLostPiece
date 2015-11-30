#include "MenuPausa.h"
#include "MenuPrincipal.h"
#include "GameScene.h"

USING_NS_CC;
void MenuPausa::volver_a_Partida(Ref *pSender) {
	Director::getInstance()->popScene();
}
void MenuPausa::ir_Menu_Principal(Ref *pSender) {
	auto scene = MenuPrincipal::createScene();

	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}
void MenuPausa::retryGameScene(Ref *pSender) {
	auto scene = GameScene::createScene();

	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}
Scene* MenuPausa::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MenuPausa::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MenuPausa::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Cargamos el fondo de la pantalla de pausa
	auto background = Sprite::create("images/f2.jpg");
	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));
	background->setOpacity(50);//Cambiamos la opacidad del fondo
	addChild(background, 0);

	//Creamos el boton volver del menu de pausa
	auto volver = MenuItemImage::create("images/volver.fw.png", "images/volver.fw.png",
		CC_CALLBACK_1(MenuPausa::volver_a_Partida, this));

	//Creamos el boton de salir de la partida
	auto salir_partida = MenuItemImage::create("images/salir.png", "images/salir.png",
		CC_CALLBACK_1(MenuPausa::ir_Menu_Principal, this));

	//Creamos el menu de pausa de nuestro juego
	auto menu = Menu::create(volver,salir_partida, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height /4);
	addChild(menu, 1);


	return true;
}

