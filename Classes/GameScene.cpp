#include "GameScene.h"
#include "GameOverScene.h"
#include "MenuPausa.h"
#include <iostream>

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object
	auto layer = GameScene::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

void GameScene::ir_Pausa(Ref *pSender) {
	auto scene = MenuPausa::createScene();
	Director::getInstance()->pushScene(scene);
}
void GameScene::ir_Fin_Juego(Ref *pSender) {
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Cargamos las imagenes de fondo para la pantalla de game.
	auto background = Sprite::create("images/f2.jpg");
	background->setPosition(Point((visibleSize.width / 2),
									(visibleSize.height / 2)));
	addChild(background,0);

	/*cargamos el mapa del juego*/
	// reading in a tiled map.
	auto map = TMXTiledMap::create("images/mapa.tmx");
	//map->setPositionX(100);
	map->setPositionY(visibleSize.height - 300);
	addChild(map,0,99); // with a tag of '99'
	/*fin de la carga del mapa del juego*/


	/*PRUEBAS POSICIONAMIENTO DEL HUB EN PNATALLA DE JUEGO*/
	auto hub = Sprite::create("images/hub.fw.png");
	hub->setPositionX(visibleSize.width/2);
	hub->setPositionY(visibleSize.height-100);
	addChild(hub,0);
	/*FIN DE LAS PRUEBAS DEL HUB*/


	auto boton_pausa = MenuItemImage::create("images/pausa.fw.png","images/pausa.fw.png",
		CC_CALLBACK_1(GameScene::ir_Pausa, this));


	auto tamayo_boton = boton_pausa->getContentSize();//Obtenemoss el tamaño de ña imagen cargada
	//boton_pausa->setPosition(Point((tamayo_boton.width*2),visibleSize.height*2));
	//boton_pausa->setPositionX(tamayo_boton.width+10);
	//boton_pausa->setPositionY(visibleSize.height-tamayo_boton.height);
	auto menu = Menu::create(boton_pausa, NULL);
	menu->setPositionX(tamayo_boton.width + 10);
	menu->setPositionY(visibleSize.height - tamayo_boton.height);
	//menu->alignItemsVerticallyWithPadding(visibleSize.height /12);
	addChild(menu,1);
	return true;
}
