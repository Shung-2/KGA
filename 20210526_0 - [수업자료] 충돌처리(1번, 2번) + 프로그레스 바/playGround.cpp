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
	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemy", "ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));

	//스페이스 쉽 동적할당
	_ship = new spaceShip;
	_ship->init();

	//에너미매니저 동적할당
	_em = new enemyManager;
	_em->init();
	_em->setMinion();

	//전방선언된 에너미매니저에 스페이스쉽에 실제 주소지를 링크시켜줌
	_em->setSpaceShipMemoryAddressLink(_ship);
	_ship->setEmMemoryAddressLink(_em);
		

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();

	SAFE_DELETE(_ship);

}


void playGround::update()
{
	gameNode::update();

	_ship->update();
	_em->update();
	//collision();
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	IMAGEMANAGER->findImage("배경")->render(getMemDC(), 0, 0);

	_ship->render();
	_em->render();


	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
