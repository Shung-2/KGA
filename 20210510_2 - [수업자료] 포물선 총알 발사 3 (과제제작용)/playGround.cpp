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

	_cannon.angle = PI / 2;
	_cannon.cannon = 100;
	_cannon.radius = 100;
	_cannon.center.x = WINSIZEX / 2;
	_cannon.center.y = WINSIZEY;

	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].speed = 5;
		_bullet[i].radius = 20;
		_bullet[i].isFire = false;
		_bullet[i].gravity = 0;
	}

	

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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _cannon.angle <= 3.04) _cannon.angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _cannon.angle >= 0.08) _cannon.angle -= 0.04f;
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) bulletFire();
	//if (KEYMANAGER->isStayKeyDown('A')) _cannon.center.x -= 3;
	//if (KEYMANAGER->isStayKeyDown('D')) _cannon.center.x += 3;

	_cannon.cannonEnd.x = cosf(_cannon.angle) * _cannon.cannon + _cannon.center.x;
	_cannon.cannonEnd.y = -sinf(_cannon.angle) * _cannon.cannon + _cannon.center.y;
	
	bulletMove();
	
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	EllipseMakeCenter(backDC, _cannon.center.x, _cannon.center.y, 100, 100);
	LineMake(backDC, _cannon.center.x, _cannon.center.y, _cannon.cannonEnd.x, _cannon.cannonEnd.y);
	
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		EllipseMakeCenter(backDC, _bullet[i].x, _bullet[i].y, _bullet[i].radius * 2, _bullet[i].radius * 2);
	}

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

void playGround::bulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet[i].isFire) continue;

		_bullet[i].isFire = true;
		_bullet[i].x = cosf(_cannon.angle) * (_cannon.cannon + 3) + _cannon.center.x;
		_bullet[i].y = -sinf(_cannon.angle) * (_cannon.cannon + 3) + _cannon.center.y;
		_bullet[i].angle = _cannon.angle;
		break;
	}
}

void playGround::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		_bullet[i].gravity += 0.05f;
		_bullet[i].x += cosf(_bullet[i].angle) * _bullet[i].speed;
		_bullet[i].y += -sinf(_bullet[i].angle) * _bullet[i].speed + _bullet[i].gravity;

		//화면 왼쪽으로 나가면
		if (_bullet[i].x - _bullet[i].radius < 0)
		{
			//_bullet[i].angle = PI - _bullet[i].angle;
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
			
		}
		//화면 오른쪽으로 나가면
		if (_bullet[i].x + _bullet[i].radius > WINSIZEX)
		{
			//_bullet[i].angle = PI - _bullet[i].angle;
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
			
		}
		//화면 위쪽으로 나가면
		if (_bullet[i].y - _bullet[i].radius < 0)
		{
			//_bullet[i].angle = PI * 2 - _bullet[i].angle;
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
			
		}
		//화면 아래쪽으로 나가면
		if (_bullet[i].y + _bullet[i].radius > WINSIZEY)
		{
			//_bullet[i].angle = PI * 2 - _bullet[i].angle;
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
		
		}
	}
}
