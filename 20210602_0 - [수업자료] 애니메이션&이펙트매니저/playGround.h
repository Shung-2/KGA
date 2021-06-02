#pragma once
#include "gameNode.h"
#include "pixelCollision.h"
#include "animationTest.h"
#include "effectTest.h"

class playGround : public gameNode
{
private:
	animationTest* _at;
	effectTest* _et;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	
};

