#include "GameScene.h"
#include "GameOverScene.h"
#include "MenuPausa.h"
#include "Acertijos.h"
#include <fstream>
#include <stdio.h>
#include "ui/CocosGUI.h"

using namespace std;

Scene* Acertijos::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object
	auto layer = Acertijos::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}
/*Genramos un numero aleatorio para obtener el acertijo a mostrar por pantalla */
int generarNumeroAleatorio() {
	return 1;
}
vector<string> leerFicheroAcertijos() {

	ifstream archivo_entrada;
	string linea;
	vector<string> array_acertijos;

	archivo_entrada.open("images/acertijos.txt");//Abrimos el fichero para lectura

	while (getline(archivo_entrada, linea)) {//Leemos el fichero
		array_acertijos.push_back(linea);//Metemos dentro del vector el acertijo
	}
	archivo_entrada.close();//Cerramos el fichero donde tenemos los acertijos
	return array_acertijos;
}
vector<string> leerRespuestasAcertijos() {

	ifstream archivo_entrada;
	string linea;
	vector<string> array_respuestas;

	archivo_entrada.open("images/soluciones.txt");//Abrimos el fichero para lectura

	while (getline(archivo_entrada, linea)) {//Leemos el fichero
		array_respuestas.push_back(linea);//Metemos dentro del vector el acertijo
	}
	archivo_entrada.close();//Cerramos el fichero donde tenemos los acertijos
	return array_respuestas;
}
void Acertijos::buttonPressed(Ref* pSender,string r){

	ui::Button* pree = (ui::Button*) pSender;
	string re = pree->getTitleText();
	bool flag = false;
	if (re == r) {
		flag = true;
	}
	if (flag == true) {
		volver_a_Partida(pSender);
	}
	else {
		fin_Partida(pSender);
	}
}
void Acertijos::volver_a_Partida(Ref *pSender) {
	Director::getInstance()->popScene();
}
void Acertijos::fin_Partida(Ref *pSender) {
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
// on "init" you need to initialize your instance
bool Acertijos::init() {
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Cargamos las imagenes de fondo para la pantalla de game.
	auto background = Sprite::create("images/PantallaMinijuegos.png");
	background->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
	addChild(background, 0);

	/*obtenemos el array de acertijos leidos de un fichero de texto*/
	vector<string> preguntas_acertijos;
	string texto;
	preguntas_acertijos = leerFicheroAcertijos();

	/*Obtenemos el array de respuestas leidas desde un fichero de texto*/
	vector<string> respuestas_acertijos;
	string respuesta_corrrecta;
	respuestas_acertijos = leerRespuestasAcertijos();


	//Creamos una etiqueta label con texto dentro
	Label *eti;
	texto = preguntas_acertijos.at(1);
	respuesta_corrrecta = respuestas_acertijos.at(1);


	__String *text = __String::create(texto);
	eti = Label::createWithTTF(text->getCString(), "fonts/Marker Felt.ttf", 28);
	eti->setPosition(Vec2(visibleSize.width - 450, visibleSize.height -350));
	eti->setColor(ccc3(255, 0, 0));//Cambiamos el color al texto de la etiqueta label
	addChild(eti,0);
	
	/*Creamos los botones con las respuestas*/
	ui::Button* boton_a = ui::Button::create("images/boton.fw.png");
	boton_a->setPosition(Vec2(visibleSize.width - 735, visibleSize.height - 450));
	boton_a->setTitleFontSize(12);
	boton_a->setTitleText(respuesta_corrrecta);
	boton_a->setTitleColor(ccc3(255,0,0));
	boton_a->setScaleX(1.5);
	boton_a->setScaleY(0.75);
	boton_a->addTouchEventListener(CC_CALLBACK_1(Acertijos::buttonPressed, this,respuesta_corrrecta));
	addChild(boton_a,1);

	/*Creamos los botones con las respuestas*/
	ui::Button* boton_b = ui::Button::create("images/boton.fw.png");
	boton_b->setPosition(Vec2(visibleSize.width - 400, visibleSize.height - 450));
	boton_b->setTitleFontSize(12);
	boton_b->setTitleText("Para que los enfermos no tengan cura");
	boton_b->setTitleColor(ccc3(255, 0, 0));
	boton_b->setScaleX(1.5);
	boton_b->setScaleY(0.75);
	boton_b->addTouchEventListener(CC_CALLBACK_1(Acertijos::buttonPressed, this, respuesta_corrrecta));
	addChild(boton_b, 1);

	/*Creamos los botones con las respuestas*/
	ui::Button* boton_c = ui::Button::create("images/boton.fw.png");
	boton_c->setPosition(Vec2(visibleSize.width - 735, visibleSize.height - 650));
	boton_c->setTitleFontSize(12);
	boton_c->setTitleText("Para que los enfermos no mueran");
	boton_c->setTitleColor(ccc3(255, 0, 0));
	boton_c->setScaleX(1.5);
	boton_c->setScaleY(0.75);
	boton_c->addTouchEventListener(CC_CALLBACK_1(Acertijos::buttonPressed, this, respuesta_corrrecta));
	addChild(boton_c, 1);

	/*Creamos los botones con las respuestas*/
	ui::Button* boton_d = ui::Button::create("images/boton.fw.png");
	boton_d->setPosition(Vec2(visibleSize.width - 400, visibleSize.height - 650));
	boton_d->setTitleFontSize(12);
	boton_d->setTitleText("Para que los enfermos se recuperen");
	boton_d->setTitleColor(ccc3(255, 0, 0));
	boton_d->setScaleX(1.5);
	boton_d->setScaleY(0.75);
	boton_d->addTouchEventListener(CC_CALLBACK_1(Acertijos::buttonPressed, this, respuesta_corrrecta));
	addChild(boton_d, 1);


	return true;
}
