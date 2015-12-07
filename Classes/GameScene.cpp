#include "GameScene.h"
#include "GameOverScene.h"
#include "MenuPausa.h"
#include "Puzzle.h"
#include "Acertijos.h"
#include <iostream>
#include <string>

using namespace std;

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
void GameScene::ir_MiniJuego_Puzzle(Ref *pSender) {
	auto scene = Puzzle::createScene();
	Director::getInstance()->pushScene(scene);
}
void GameScene::ir_MiniJuego_Acertijos(Ref *pSender) {
	auto scene = Acertijos::createScene();
	Director::getInstance()->pushScene(scene);
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

	/*cargamos el mapa del juego*/
	map = TMXTiledMap::create("images/proves.tmx");
	map->setPosition(Point(0, 0));
	addChild(map,0); // with a tag of '99'
	/*fin de la carga del mapa del juego*/


	/*PRUEBAS POSICIONAMIENTO DEL HUB EN PNATALLA DE JUEGO*/
	auto hub = Sprite::create("images/hub.fw.png");
	hub->setPositionX(visibleSize.width/2);
	hub->setPositionY(visibleSize.height-100);
	addChild(hub,1);
	/*FIN DE LAS PRUEBAS DEL HUB*/


	auto boton_pausa = MenuItemImage::create("images/pausa.fw.png","images/pausa.fw.png",
		CC_CALLBACK_1(GameScene::ir_Pausa, this));

	auto boton_minijuego = MenuItemImage::create("images/mini.png", "images/mini.png",
		CC_CALLBACK_1(GameScene::ir_MiniJuego_Puzzle, this));
	boton_minijuego->setPositionX(200);

	auto boton_minijuego2 = MenuItemImage::create("images/mini.png", "images/mini.png",
		CC_CALLBACK_1(GameScene::ir_MiniJuego_Acertijos, this));
	boton_minijuego2->setPositionX(480);

	auto tamayo_boton = boton_pausa->getContentSize();//Obtenemoss el tamaño de ña imagen cargada

	auto menu = Menu::create(boton_pausa, boton_minijuego, boton_minijuego2, NULL);
	menu->setPositionX(tamayo_boton.width + 10);
	menu->setPositionY(visibleSize.height - tamayo_boton.height);
	addChild(menu,1);

	return true;
}
