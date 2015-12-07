#include "GameScene.h"
#include "GameOverScene.h"
#include "MenuPausa.h"
#include "Puzzle.h"
#include "ui/CocosGUI.h"

using namespace std;

Scene* Puzzle::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object
	auto layer = Puzzle::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

void Puzzle::onMouseDown(Event *event) {

	auto *e = dynamic_cast<EventMouse *>(event);
	_POS_INI_X= e->getCursorX();
	_POS_INI_Y = e->getCursorY();
}
void Puzzle::onMouseUp(Event *event) {
	auto *e = dynamic_cast<EventMouse *>(event);
	_POS_FIN_X = e->getCursorX();
	_POS_FIN_Y = e->getCursorY();
	calcularDesplazamientoCursor();
}
void Puzzle::calcularDesplazamientoCursor() {
	int mov_x = 0; 
	mov_x= _POS_INI_X - _POS_FIN_X;
	int mov_y = 0; 
	mov_y = _POS_INI_Y - _POS_FIN_Y;

}
// on "init" you need to initialize your instance
bool Puzzle::init(){
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Vector2 origin = Director::getInstance()->getVisibleOrigin();

	//Cargamos las imagenes de fondo para la pantalla de game.
	auto background = Sprite::create("images/PantallaMinijuegos.png");
	background->setPosition(Point((visibleSize.width / 2),(visibleSize.height / 2)));
	addChild(background,0);

	//Cargamos la solucion de la imagen que vamos a montar
	auto sol_puzzle = Sprite::create("images/Piramide/solpira.png");
	sol_puzzle->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
	sol_puzzle->setScale(0.15,0.15);
	sol_puzzle->setPositionX(275);
	sol_puzzle->setPositionY(625);
	addChild(sol_puzzle, 1);

	//Cargamos la piramide para arrastrar en ella las piezas sueltas
	auto puzzle_vacio = Sprite::create("images/Piramide/Blanco.png");
	puzzle_vacio->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
	puzzle_vacio->setScale(0.15, 0.15);
	puzzle_vacio->setPositionX(725);
	puzzle_vacio->setPositionY(625);
	addChild(puzzle_vacio, 1);

	//Cargamos las piezas sueltas para montar la piramide a obtener
	auto pieza_1 = Sprite::create("images/Piramide/pieza.png");
	pieza_1->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
	pieza_1->setScale(0.15, 0.15);
	pieza_1->setPositionX(725);
	pieza_1->setPositionY(400);
	auto pro=pieza_1->getBoundingBox();
	addChild(pieza_1, 1);

	auto pieza_2 = Sprite::create("images/Piramide/pieza2.png");
	pieza_2->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
	pieza_2->setScale(0.15, 0.15);
	pieza_2->setPositionX(575);
	pieza_2->setPositionY(400);
	addChild(pieza_2, 1);

	auto pieza_3 = Sprite::create("images/Piramide/Pieza3.png");
	pieza_3->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
	pieza_3->setScale(0.15, 0.15);
	pieza_3->setPositionX(425);
	pieza_3->setPositionY(400);
	addChild(pieza_3, 1);

	auto pieza_4 = Sprite::create("images/Piramide/pieza4.png");
	pieza_4->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
	pieza_4->setScale(0.15, 0.15);
	pieza_4->setPositionX(275);
	pieza_4->setPositionY(400);
	addChild(pieza_4, 1);

	Label *eti2;
	__String *texto_piramide = __String::create("Obten la piramide de la izquierda moviendo las piezas de bajo");
	eti2 = Label::createWithTTF(texto_piramide->getCString(), "fonts/Marker Felt.ttf", 24);
	eti2->setPosition(Vec2(visibleSize.width/2, (visibleSize.height /2)-15));
	eti2->setColor(ccc3(255, 0, 0));
	addChild(eti2,3);

	/************************************************************************/
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(Puzzle::onMouseDown, this);
	mouseListener->onMouseUp = CC_CALLBACK_1(Puzzle::onMouseUp, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
	/**************************************************************************************************************/

	return true;
}
