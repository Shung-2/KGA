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

	_enemy.x = WINSIZEX / 2;
	_enemy.y = WINSIZEY / 2;
	_enemy.radius = 50;
	_enemy.angle = 0;



	

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

	_player.x = _ptMouse.x;
	_player.y = _ptMouse.y;

	_enemy.angle = getAngle(_enemy.x, _enemy.y, _player.x, _player.y);

	_enemy.x += cosf(_enemy.angle) * 3;
	_enemy.y += -sinf(_enemy.angle) * 3;

	
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	EllipseMakeCenter(backDC, _enemy.x, _enemy.y, 100, 100);
	EllipseMakeCenter(backDC, _player.x, _player.y, 100, 100);

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}
