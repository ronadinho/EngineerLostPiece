#include "Ayuda.h"
#include "MenuPrincipal.h"

USING_NS_CC;

Scene* Ayuda::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object
	auto layer = Ayuda::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

void Ayuda::ir_Menu_Principal(Ref * pSender)
{
	auto scene = MenuPrincipal::createScene();
	Director::getInstance()->replaceScene(scene);
}

// on "init" you need to initialize your instance
bool Ayuda::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Cargamos los elementos visuales del menu del juego
	auto menuTitle = MenuItemImage::create("images/MainMenuScreen/Game_Title.png", "images/MainMenuScreen/Game_Title.png");

	auto volverMenuPrincipal = MenuItemImage::create("images/volver.fw.png", "images/MainMenuScreen/Play_Button(Click).png",
		CC_CALLBACK_1(Ayuda::ir_Menu_Principal, this));

	auto menu = Menu::create(menuTitle, volverMenuPrincipal, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 12);
	addChild(menu, 1);


	//Modificacion de la imagen de fondo de la escena, en la pantalla de menu
	auto background = Sprite::create("images/f3.jpg");
	background->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
	addChild(background, 0);
	//Fin de la modificación del tutorial
	return true;
}