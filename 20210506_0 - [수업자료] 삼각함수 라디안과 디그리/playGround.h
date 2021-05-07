#pragma once
#include "gameNode.h"
#define PI 3.14156f

class playGround : public gameNode
{
private:

	float _radian;
	float _degree;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};