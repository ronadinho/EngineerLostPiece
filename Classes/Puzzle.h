#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include "cocos2d.h"

class Puzzle : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	bool _isMovingByMouse;
	Vec2 _podVector;
	/*asdfasdf*/
	void onMouseMove(Event *event);
	void onMouseDown(Event *event);
	/*asdfdsafas*/
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Puzzle);
};

#endif // __PUZZLE_H__
