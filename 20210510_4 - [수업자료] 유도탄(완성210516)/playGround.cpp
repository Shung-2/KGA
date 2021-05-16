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

	_enemy.x = RND->getFromFloatTo(50, WINSIZEX - 50);	// enemy의 X축 설정 (랜덤)
	_enemy.y = RND->getFromFloatTo(50, WINSIZEY - 50);	// enemy의 Y축 설정 (랜덤)
	_enemy.radius = 30;									// enemy의 반지름 설정
	_enemy.angle = 0;									// enemy의 각도 설정 
	_enemy.speed = 3;									// enemy의 속도 설정

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
	// _ptMouseX, Y를 이용하여 플레이어의 X, Y축 설정
	_player.x = _ptMouse.x;
	_player.y = _ptMouse.y;

	// 적이 플레이어를 쫒아 오는 상황
	// enemy의 각도를 getAngle을 이용하여 연산
	//_enemy.angle = getAngle(_enemy.x, _enemy.y, _player.x, _player.y);

	// 플레이어가 적을 쫒아 가는 상황
	// enemy의 각도를 getAngle을 이용하여 연산 (인자 값 변경)
	_enemy.angle = getAngle(_player.x, _player.y, _enemy.x, _enemy.y);

	// enemy의 X, Y축 연산
	_enemy.x += cosf(_enemy.angle) * _enemy.speed;
	_enemy.y += -sinf(_enemy.angle) * _enemy.speed;

	gameNode::update();
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	EllipseMakeCenter(backDC, _player.x, _player.y, 100, 100);
	EllipseMakeCenter(backDC, _enemy.x, _enemy.y, 100, 100);

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}