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

	for (int i = 0; i < SNAKEBODY; i++)
	{
		if (i == 0)
		{
			_snake[i].angle = RND->getFloat(PI2);
			_snake[i].x = RND->getFromFloatTo(100, WINSIZEX - 100);
			_snake[i].y = RND->getFromFloatTo(100, WINSIZEY - 100);
		}
		else
		{
			_snake[i].angle = _snake[i - 1].angle;
			_snake[i].x = _snake[i - 1].x - cosf(_snake[i].angle) * (_snake[i].radius * 2 + _snake[i - 1].radius * 2);
			_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius * 2+ _snake[i - 1].radius * 2));
		}

		_snake[i].radius = 20;
		_snake[i].speed = 5;
	}

	_horse = new image;
	_horse->init("말.bmp", WINSIZEX, WINSIZEY);

	_bird = new image;
	_bird->init("레오.bmp", WINSIZEX, WINSIZEY);

	_mandarin = new image;
	_mandarin->init("귤.bmp", 50, 50, true, RGB(255, 0, 255));

	_background = _horse;
	

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

	if (KEYMANAGER->isOnceKeyDown(VK_F1)) _background = _bird;
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _background = _horse;

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _snake[0].angle += 0.08f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _snake[0].angle -= 0.08f;

	snakeMove();
	
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	_background->render(backDC, 0, 0);

	for (int i = 0; i < SNAKEBODY; i++)
	{
		_mandarin->render(backDC, _snake[i].x, _snake[i].y);
		// EllipseMakeCenter(backDC, _snake[i].x, _snake[i].y, _snake[i].radius * 2, _snake[i].radius * 2);
	}

	

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

void playGround::snakeMove()
{
	for (int i = 0; i < SNAKEBODY; i++)
	{
		if (i == 0)
		{
			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;

			if (_snake[i].x + _snake[i].radius >= WINSIZEX)
			{
				_snake[i].angle = PI - _snake[i].angle;
			}
			if (_snake[i].x - _snake[i].radius < 0)
			{
				_snake[i].angle = PI - _snake[i].angle;
			}
			if (_snake[i].y + _snake[i].radius >= WINSIZEY)
			{
				_snake[i].angle = PI2 - _snake[i].angle;
			}
			if (_snake[i].y - _snake[i].radius < 0)
			{
				_snake[i].angle = PI2 - _snake[i].angle;
			}
		}
		else
		{
			if (_snake[i].radius * 2 <= getDistance(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y))
			{
				_snake[i].angle = getAngle(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y);

				//굳이 보정을 해서 이쁘게 해야한다면
				_snake[i].x = _snake[i - 1].x - (cosf(_snake[i].angle) * (_snake[i].radius + _snake[i - 1].radius));
				_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius + _snake[i - 1].radius));
			}

			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;
		}
	}
}
