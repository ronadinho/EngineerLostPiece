#ifndef __MENUPAUSA_H__
#define __MENUPAUSA_H__

#include "cocos2d.h"

class MenuPausa : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	void volver_a_Partida(Ref *pSender);
	void ir_Menu_Principal(Ref *pSender);
	void retryGameScene(Ref *pSender);

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MenuPausa);
};

#endif // __MENUPAUSA_H__
#pragma once
