#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include "cocos2d.h"

class Puzzle : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	bool _isMovingByMouse;
	/*Variables globales pruebas*/
	int _POS_INI_X=0;
	int _POS_INI_Y = 0;

	int _POS_FIN_X = 0;
	int _POS_FIN_Y = 0;


	void calcularDesplazamientoCursor();
	void onMouseUp(Event *event);
	void onMouseDown(Event *event);
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Puzzle);
};

#endif // __PUZZLE_H__
