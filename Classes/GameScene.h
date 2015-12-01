#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class GameScene : public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene();

	CCTMXTiledMap *map;

	void ir_Pausa(Ref *pSender);
	void ir_Fin_Juego(Ref *pSender);
	void ir_MiniJuego_Puzzle(Ref *pSender);
	void ir_MiniJuego_Acertijos(Ref *pSender);
	virtual bool init();
	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __GAMESCENE_SCENE_H__#pragma once
