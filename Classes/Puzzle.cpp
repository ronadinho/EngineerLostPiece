#include "GameScene.h"
#include "GameOverScene.h"
#include "MenuPausa.h"
#include "Puzzle.h"

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

void Puzzle::onMouseMove(Event *event) {
	static Vec2 *oldPosition;
	auto *e = dynamic_cast<EventMouse *>(event);

    if (oldPosition == NULL) {
		oldPosition = new Vec2(e->getCursorX(), e->getCursorY());
	} else {
		_podVector = Vec2(e->getCursorX() - oldPosition->x,e->getCursorY() - oldPosition->y);
		if (!_isMovingByMouse){
			_isMovingByMouse = true;
			oldPosition->x = e->getCursorX();
			oldPosition->y = e->getCursorY();
		}
	}
}
void Puzzle::onMouseDown(Event *event) {

	auto *e = dynamic_cast<EventMouse *>(event);
	//e->getCursorX();

	if (e->getCursorX()){}
	else {

	}

	

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
	__String *texto_piramide = __String::create("Obtén la piramide");
	eti2 = Label::createWithTTF(texto_piramide->getCString(), "fonts/Marker Felt.ttf", 24);
	eti2->setPosition(Vec2(visibleSize.width/2, visibleSize.height /2));
	eti2->setColor(ccc3(255, 0, 0));
	addChild(eti2,3);


	/************************************************************************/
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(Puzzle::onMouseDown, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);

	/**************************************************************************************************************/

	return true;
}
