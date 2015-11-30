#include "MenuPrincipal.h"
#include "GameScene.h"
#include "Opciones.h"
#include "Acerca.h"
#include "Ayuda.h"

USING_NS_CC;

Scene* MenuPrincipal::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = MenuPrincipal::create();
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

void MenuPrincipal::ir_Pantalla_Game(Ref * pSender)
{
	auto scene = GameScene::createScene();

	/* transiciones entre escenas
	CCTransitionCrossFade *transition=CCTransitionCrossFade::create(0.5, scene*/

	Director::getInstance()->replaceScene(scene);
}
void MenuPrincipal::ir_Pantalla_Opciones(Ref * pSender)
{
	auto scene = Opciones::createScene();
	Director::getInstance()->replaceScene(scene);
}
void MenuPrincipal::ir_Pantalla_Acerca(Ref * pSender)
{
	auto scene = Acerca::createScene();
	Director::getInstance()->replaceScene(scene);
}
void MenuPrincipal::ir_Pantalla_Ayuda(Ref * pSender){
	auto scene = Ayuda::createScene();
	Director::getInstance()->replaceScene(scene);
}
void MenuPrincipal::salir_Juego(Ref * pSender){
	exit(0) ;
}

// on "init" you need to initialize your instance
bool MenuPrincipal::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();

	//Cargamos el titulo del menu principal del juego
	auto menuTitle = MenuItemImage::create("images/MainMenuScreen/Game_Title.png","images/MainMenuScreen/Game_Title.png");

	//Cargamos el boton de jugar al menu principal
	auto jugar = MenuItemImage::create("images/jugar.fw.png","images/MainMenuScreen/Play_Button(Click).png",
											CC_CALLBACK_1(MenuPrincipal::ir_Pantalla_Game,this));
	//Cargamos el boton de opciones al menu principal
	auto opciones = MenuItemImage::create("images/opciones.png","images/MainMenuScreen/Play_Button(Click).png",
		CC_CALLBACK_1(MenuPrincipal::ir_Pantalla_Opciones, this));
	
	//Cargamos el boton de ayuda de al menu principal
	auto ayuda = MenuItemImage::create("images/ayuda.png","images/MainMenuScreen/Play_Button(Click).png",
		CC_CALLBACK_1(MenuPrincipal::ir_Pantalla_Ayuda, this));

	//Cargamos el boton de acerca de al menu principal
	auto acerca = MenuItemImage::create("images/acerca.png","images/MainMenuScreen/Play_Button(Click).png",
		CC_CALLBACK_1(MenuPrincipal::ir_Pantalla_Acerca, this));

	//Cargamos el boton de salir al menu principal
	auto salir = MenuItemImage::create("images/salir.png","images/salir.png",
		CC_CALLBACK_1(MenuPrincipal::salir_Juego, this));

	//Creamos el menu con los botones y el titulo del juego
	auto menu = Menu::create(menuTitle, jugar, opciones,ayuda,acerca, salir, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height /28);
	addChild(menu,1);

	/*PRUEBAS DE CAMBIO DE IMAGEN DEL CURSOR Y LUCES EN EL JUEGO */
	auto pp = Sprite::create("images/f1.jpg");
	LoadCursorFromFileA("images/f3.jpg");

	//Modificacion de la imagen de fondo de la escena, en la pantalla de menu
	auto background = Sprite::create("images/f1.jpg");
	background->setPosition(Point((visibleSize.width / 2),(visibleSize.height / 2)));
	addChild(background,0);
	//Fin de la modificación del tutorial
    return true;
}