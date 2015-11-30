#ifndef __ACERCA_H__
#define __ACERCA_H__

#include "cocos2d.h"

class Acerca : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	void ir_Menu_Principal(Ref *pSender);

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Acerca);
};

#endif // __ACERCA_H__
