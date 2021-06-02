#pragma once
#include "gameNode.h"
#include "pixelCollision.h"

class playGround : public gameNode
{
private:
	pixelCollision* _pc;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	
};

