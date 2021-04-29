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

	for (int i = 0; i < 5; i++)
	{
		_box[i].rc = RectMakeCenter(100 + i * 200, 200, 100, 100);
		_box[i].isCheck = false;
		_box[i].isJoker = false;
	}

	_box[RND->getInt(5)].isJoker = true;


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
		for (int i = 0; i < 5; i++)
		{
			if (PtInRect(&_box[i].rc, _ptMouse))
			{
				_box[i].isCheck = true;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (_box[i].isCheck && _box[i].isJoker)
		{
			_box[i].rc.top += 5;
			_box[i].rc.bottom += 5;

			if (_box[i].rc.top > WINSIZEY) this->init();
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

	for (int i = 0; i < 5; i++)
	{
		if (_box[i].isCheck && !_box[i].isJoker)
		{
			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
			HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);

			Rectangle(backDC, _box[i].rc);

			SelectObject(backDC, oldBrush);
			DeleteObject(brush);
		}
		else if (_box[i].isCheck && _box[i].isJoker)
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
			Rectangle(backDC, _box[i].rc);
			FillRect(backDC, &_box[i].rc, brush);
			DeleteObject(brush);

		}
		else  Rectangle(backDC, _box[i].rc);



	}


	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}
