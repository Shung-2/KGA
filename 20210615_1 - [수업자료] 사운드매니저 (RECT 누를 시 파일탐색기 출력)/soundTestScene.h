#pragma once
#include "gameNode.h"
#include <commdlg.h>//OPENFILENAME

class soundTestScene : public gameNode
{
private:
	RECT _rc;

public:
	soundTestScene();
	~soundTestScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

