#include "stdafx.h"
#include "pixelCollision.h"

pixelCollision::pixelCollision()
{
}

pixelCollision::~pixelCollision()
{
}

HRESULT pixelCollision::init()
{
	IMAGEMANAGER->addImage("¾ð´ö", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_ball = IMAGEMANAGER->addImage("ball", "ball.bmp", 60, 60, true, RGB(255, 0, 255));

	_x = WINSIZEX / 2 - 150;
	_y = WINSIZEY / 2 + 80;
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
	_probeY = _y + _ball->getHeight() / 2;

	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _x -= 3;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _x += 3;
	_probeY = _y + _ball->getHeight() / 2;

	for (int i = _probeY - 50; i < _probeY + 50; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("¾ð´ö")->getMemDC(), _x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - _ball->getHeight() / 2;
			break;
		}
	}
	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());
	terrainBroke();
}

void pixelCollision::render()
{
	IMAGEMANAGER->findImage("¾ð´ö")->render(getMemDC());
	_ball->render(getMemDC(), _rc.left, _rc.top);
}

void pixelCollision::terrainBroke()
{
	HPEN pen = CreatePen(PS_DOT, 5, RGB(255, 0, 255));
	HPEN oldPen = (HPEN)SelectObject(IMAGEMANAGER->findImage("¾ð´ö")->getMemDC(), pen);
	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(IMAGEMANAGER->findImage("¾ð´ö")->getMemDC(), brush);

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		EllipseMakeCenter(IMAGEMANAGER->findImage("¾ð´ö")->getMemDC(), _ptMouse.x, _ptMouse.y, 50, 50);
	}

	DeleteObject(pen);
	DeleteObject(brush);
}