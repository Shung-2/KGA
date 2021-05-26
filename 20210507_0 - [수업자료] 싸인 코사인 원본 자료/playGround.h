#pragma once
#include "gameNode.h"

#define PI 3.14156f

struct tagObj
{
	float x, y;
	float angle;
	float radius;
	float speed;
};

class playGround : public gameNode
{
private:
	tagObj _obj;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};