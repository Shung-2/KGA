#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("배경", "background.bmp", WINSIZEX, WINSIZEY,
		true, RGB(255, 0, 255));
	
	SCENEMANAGER->addScene("INTRO", new testScene);
	SCENEMANAGER->addScene("OPTION", new testScene2);
	SCENEMANAGER->addScene("STAGE 1", new Stage1);
	SCENEMANAGER->changeScene("INTRO");

	st = new Stage1;
	st->setPlayerAddressLink(pl);

	//pl = new Player;


	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();
}

void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();	
}

void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	IMAGEMANAGER->findImage("배경")->render(getMemDC(), 0, 0);	
	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
