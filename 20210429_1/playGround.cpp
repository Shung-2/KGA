#include "stdafx.h"
#include "playGround.h"
#include <Windows.h>

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
	
	// 시간
	time = 0;

	// 윗니
	for (int i = 0; i < 20; i++)
	{
		_box1[i].rc = RectMakeCenter(240 + i * 65, 400, 50, 50);
		_box1[i].isCheck = false;
		_box1[i].isJoker = false;

		// 아랫니
		if (i > 9)
		{
			_box1[i].rc = RectMakeCenter(220 + (i - 9.5) * 62, 500, 50, 50);
			_box1[i].isCheck = false;
			_box1[i].isJoker = false;
		}
	}

	// 이빨 중 조커 선언
	_box1[RND->getInt(20)].isJoker = true;

	// 얼굴 선언 (위, 왼쪽, 아래 순)
	Alligator_Mouse = RectMake(200, 375, 650, 200);
	Alligator_Face1 = RectMake(150, 325, 700, 50);
	Alligator_Face2 = RectMake(150, 325, 50, 250);
	Alligator_Face3 = RectMake(150, 525, 700, 50);

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

	//왼쪽클릭하면
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 20; i++)
		{
			if (PtInRect(&_box1[i].rc, _ptMouse))
			{
				_box1[i].isCheck = true;
			}
		}
	}

	for (int i = 0; i < 20; i++)
	{
		// 해당 카드가 조커이면
		if (_box1[i].isCheck && _box1[i].isJoker)
		{
			for (int i = 0; i < 10; i++)
			{
				// 윗니가 내려오고
				if (_box1[i].rc.bottom <= 450)
				{
					_box1[i].rc.top += 5;
					_box1[i].rc.bottom += 5;
				}

				// 윗입술이 내려온다
				if (Alligator_Face1.bottom <= 400)
				{
					Alligator_Face1.top += 5;
					Alligator_Face1.bottom += 5;
				}
			}

			time++;
			if (time > 100) this->init();
		}
	}
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	// 입 
	HBRUSH brush2 = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush2 = (HBRUSH)SelectObject(backDC, brush2);
	Rectangle(backDC, Alligator_Mouse);
	SelectObject(backDC, oldBrush2);
	DeleteObject(brush2);

	// 얼굴
	HBRUSH brush = CreateSolidBrush(RGB(0, 122, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);
	Rectangle(backDC, Alligator_Face1);
	Rectangle(backDC, Alligator_Face3);
	Rectangle(backDC, Alligator_Face2);
	SelectObject(backDC, oldBrush);
	DeleteObject(brush);

	// 눈
	EllipseMake(backDC, WINSIZEX / 2 - 400, 250, 100, 100);
	HBRUSH brush3 = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH oldBrush3 = (HBRUSH)SelectObject(backDC, brush3);
	EllipseMake(backDC, WINSIZEX / 2 - 380, 270, 63, 63);
	SelectObject(backDC, oldBrush3);
	DeleteObject(brush3);

	// 이
	for (int i = 0; i < 20; i++)
	{
		if (_box1[i].isCheck && !_box1[i].isJoker)
		{
			HBRUSH brush = CreateSolidBrush(RGB(5, 0, 238));
			HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);

			Rectangle(backDC, _box1[i].rc);
			SelectObject(backDC, oldBrush);
			DeleteObject(brush);
		}
		else if (_box1[i].isCheck && _box1[i].isJoker)
		{
			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
			Rectangle(backDC, _box1[i].rc);
			FillRect(backDC, &_box1[i].rc, brush);
			DeleteObject(brush);
		}
		else Rectangle(backDC, _box1[i].rc);
	}

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}
