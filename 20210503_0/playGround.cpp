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

	_player = RectMakeCenter(WINSIZEX / 2 - 350, WINSIZEY / 2, 100, 50);
	_player2 = RectMakeCenter(WINSIZEX / 2 + 350, WINSIZEY / 2, 100, 50);

	//총알의 최대갯수만큼 for문을 돌리자
	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].x = _player.right + 10;
		_bullet[i].y = (_player.top + _player.bottom) / 2;
		_bullet[i].rc = RectMakeCenter(_bullet[i].x,
			_bullet[i].y, 20, 20);
		//처음에는 모든 총알이 발사안됐다고 두자
		_bullet[i].isFire = false;
		_bullet[i].speed = 7;
	}

	//게이지를 표현해보자
	_backGauge = RectMakeCenter(WINSIZEX / 2 + 250, 100, 400, 50);
	_frontGauge = RectMakeCenter(WINSIZEX / 2 + 250, 100, 400, 50);
	_r = 0;
	_g = 240;
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

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_player.top -= 5;
		_player.bottom -= 5;
	}

	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_player.top += 5;
		_player.bottom += 5;
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		bulletFire();
	}

	
	bulletMove();
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	Rectangle(backDC, _player);
	Rectangle(backDC, _player2);

	//총알 그려줌
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		Ellipse(backDC, _bullet[i].rc);
	}


	Rectangle(backDC, _backGauge);

	HBRUSH brush = CreateSolidBrush(RGB(_r, _g, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);
	Rectangle(backDC, _frontGauge);
	SelectObject(backDC, oldBrush);
	DeleteObject(brush);

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

//발사용 함수인데
void playGround::bulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet[i].isFire) continue;

		_bullet[i].x = _player.right + 10;
		_bullet[i].y = (_player.top + _player.bottom) / 2;
		_bullet[i].rc = RectMakeCenter(_bullet[i].x,
			_bullet[i].y, 20, 20);
		_bullet[i].isFire = true;
		break;
	}
}

//총알 움직임용
void playGround::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		if (_bullet[i].x > WINSIZEX + 50) _bullet[i].isFire = false;
		_bullet[i].x += _bullet[i].speed;
		_bullet[i].rc = RectMakeCenter(_bullet[i].x,
			_bullet[i].y, 20, 20);

		RECT temp;
		if (IntersectRect(&temp, &_player2, &_bullet[i].rc) && _bullet[i].isFire)
		{
			setGauge();
			_bullet[i].isFire = false;
			break;
		}

	}
}

//게이지(?) 조절용 함수
void playGround::setGauge()
{
	_frontGauge.left += 10;

	if (_frontGauge.left >= _backGauge.right) _frontGauge.left = _backGauge.right;

	if (_frontGauge.right - _frontGauge.left < 350)
	{
		_r = 255;
		_g = 255;
	}
	if (_frontGauge.right - _frontGauge.left < 100)
	{
		_r = 255;
		_g = 0;
	}

}
