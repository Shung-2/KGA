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
	gameNode::init();

	_obj.x = WINSIZEX / 2;
	_obj.y = WINSIZEY / 2;
	_obj.radius = 50;
	_obj.angle = 0;

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();
}

//여기에다 연산하세요 제에발
void playGround::update()
{
	gameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _obj.angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _obj.angle -= 0.04f;
	//                         스피드 값( R 값)
	_obj.x += cosf(_obj.angle) * 3;
	_obj.y += -sinf(_obj.angle) * 3;	
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	EllipseMakeCenter(backDC, _obj.x, _obj.y, _obj.radius * 2, _obj.radius * 2);

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}