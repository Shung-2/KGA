#pragma once
#include "gameNode.h"
#include "ship.h"

class battle;

class starScene : public gameNode
{
private:
	ship* _battle;

	Graphics* _graphics;
	Image* _hornet;
	Image* _heos;
	
public:
	starScene();
	~starScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void drawPng(Image* img, int destX, int destY);
	void drawPng(Image* img, int destX, int destY, int scaleWidth, int scaleHeight);
};

