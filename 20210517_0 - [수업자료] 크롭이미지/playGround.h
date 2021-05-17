#pragma once
#include "gameNode.h"


class playGround : public gameNode
{
private:
	image* _leo;
	
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	
	void snakeMove();
};

