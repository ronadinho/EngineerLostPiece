#ifndef __ACERTIJOS_H__
#define __ACERTIJOS_H__
#include "cocos2d.h"
#include <string.h>

using namespace std;
class Acertijos : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void buttonPressed(Ref* pSender,string s1);
	void volver_a_Partida(Ref *pSender);
	void fin_Partida(Ref *pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Acertijos);
};

#endif // __ACERTIJOS_H__

