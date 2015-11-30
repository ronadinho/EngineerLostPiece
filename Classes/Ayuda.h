#ifndef __AYUDA_H__
#define __AYUDA_H__

#include "cocos2d.h"

class Ayuda : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	void ir_Menu_Principal(Ref *pSender);

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Ayuda);
};

#endif // __AYUDA_H__

