#pragma once
#include "gameNode.h"

class soundTestScene : public gameNode
{
public:
	soundTestScene();
	~soundTestScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

