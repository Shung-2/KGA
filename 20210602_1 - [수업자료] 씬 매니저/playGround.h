#pragma once
#include "gameNode.h"
#include "testScene.h"
#include "testScene2.h"


class playGround : public gameNode
{
private:


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	
};

