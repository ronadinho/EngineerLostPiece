#ifndef __OPCIONES_H__
#define __OPCIONES_H__

#include "cocos2d.h"

class Opciones : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	void ir_Menu_Principal(Ref *pSender);

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Opciones);
};

#endif // __OPCIONES_H__