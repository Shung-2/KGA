#pragma once
#include "gameNode.h"
#include "starScene.h"
#include "selectScene.h"
#include "knight.h"

class playGround : public gameNode
{
private:
	char* _str;
	int _test;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	
};

