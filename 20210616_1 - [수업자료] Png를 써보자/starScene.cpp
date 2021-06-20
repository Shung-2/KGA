#include "stdafx.h"
#include "starScene.h"
#include "battle.h"


starScene::starScene()
{
}


starScene::~starScene()
{
}

HRESULT starScene::init()
{
	_battle = new battle;
	_battle->init("battle", WINSIZEX / 2, WINSIZEY / 2);

	_graphics = new Graphics(getMemDC());
	_hornet = new Image(L"호넷.png");
	_heos = new Image(L"히오스.png");

	return S_OK;
}

void starScene::release()
{
}

void starScene::update()
{
	_battle->update();
}

void starScene::render()
{
	IMAGEMANAGER->findImage("바탕")->render(getMemDC());

	//drawPng(_hornet, 100, 100);
	drawPng(_hornet, 0, 0, _hornet->GetWidth(), _hornet->GetHeight());
	drawPng(_heos, 50, 50);
	_battle->render();
	_heos->RotateFlip(Rotate90FlipNone);
}

void starScene::drawPng(Image* img, int destX, int destY)
{
	Image* image = img;

	_graphics->DrawImage(image, destX, destY);

	image = NULL;

	delete image;

}

void starScene::drawPng(Image * img, int destX, int destY, int scaleWidth, int scaleHeight)
{
	Image* image = img;

	_graphics->DrawImage(image, destX, destY, scaleWidth, scaleHeight);

	image = NULL;

	delete image;
}
