#pragma once
#include "enemy.h"

class boss : public enemy
{
	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void relase();
	virtual void update();
	virtual void render();
};

