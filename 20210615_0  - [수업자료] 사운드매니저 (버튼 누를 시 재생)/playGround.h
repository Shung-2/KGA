#pragma once
#include "gameNode.h"
#include "soundTestScene.h"

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

