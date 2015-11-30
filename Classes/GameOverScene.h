#ifndef __GAMEOVERSCENE_SCENE_H__
#define __GAMEOVERSCENE_SCENE_H__

#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	void goToMainMenuScene(Ref *pSender);
	void goToGameScene(Ref *pSender);

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameOverScene);
};

#endif // __GAMEOVERSCENE_SCENE_H__
#pragma once
