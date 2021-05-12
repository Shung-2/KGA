#pragma once
#include "gameNode.h"

struct tagKirby
{
	image* img;
	RECT rc;
	float x, y;
	float jumpPower;
	float gravity;
	bool isJump;
};

class playGround : public gameNode
{
private:
	image* _background;
	tagKirby _kirby;
	
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};

