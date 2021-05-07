#pragma once
#include "gameNode.h"

#define PI 3.14156f

class playGround : public gameNode
{
private:
	RECT _rectangle;
	RECT _ellipse;

	bool _isCollision;	//충돌됐다 처리하게
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	bool isCollision(RECT &rc1, RECT& rc2);
	//렉트 꼭지점이랑 특정 중점과의 거리 (h) 구하는 용
	bool getDistance(RECT& rc, float x, float y);

	
	
};

