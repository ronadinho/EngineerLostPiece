#ifndef __MENU_PRINCIPAL_H__
#define __MENU_PRINCIPAL_H__

#include "cocos2d.h"

class MenuPrincipal : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

	void ir_Pantalla_Game(Ref *pSender);
	void ir_Pantalla_Opciones(Ref *pSender);
	void ir_Pantalla_Acerca(Ref *pSender);
	void ir_Pantalla_Ayuda(Ref *pSender);
	void salir_Juego(Ref *pSender);

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuPrincipal);
};

#endif // __MENU_PRINCIPAL_H__
