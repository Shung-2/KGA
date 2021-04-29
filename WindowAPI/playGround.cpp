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

	// 210428 API 수업 1
	/*
	_rc = RectMakeCenter(RND->getFromIntTo(100, WINSIZEX - 100), WINSIZEY / 2, 100, 100);
	_speed = _isCrash = 0;
	*/

	// 210428 API 수업 2 (눈)
	/*
	_player = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 50, 70);

	for (int i = 0; i < SNOWMAX; i++)
	{
		_snow[i].rc = RectMakeCenter(20 + i * 25, 10, 10, 10);
		_snow[i].speed = RND->getFromIntTo(5, 10);
	}
	_isStart = false;
	*/

	// 210428 API 수업 3 (플래피버드)
	/*   주인공(박스) 생성
	_x = WINSIZEX / 2 - 200;
	_y = WINSIZEY / 2;
	_player = RectMakeCenter(_x, _y, 100, 100);

	_isStartSate = true;

	// 파이프 랜덤 생성
	for (int i = 0; i < PIPEMAX; i++)
	{
		_pipe1[i] = RectMake(350, 0, 100, RND->getFromIntTo(0, 400));
	}
	for (int i = 0; i < PIPEMAX; i++)
	{
		_pipe2[i] = RectMake(350, 600, 100, RND->getFromIntTo(0, 400));
	}
	for (int i = 0; i < PIPEMAX; i++)
	{
		_pipe3[i] = RectMake(0, 0, 0, 0);
	}

	_jumpPower = _gravity = _score = 0;
	_isJump = false;
	*/

	// 210429 API 수업 1
	_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);

	_count = 0;

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

	// 210428 API 수업 1
	/*
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_rc.left += 5;
		_rc.right += 5;
	}

	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_rc.left -= 15;
		_rc.right -= 15;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 2;
		_rc.right += 2;
	}

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		_rc.left -= 2;
		_rc.right -= 2;
	}
	*/

	// 210428 API 수업 2 (눈)
	/*
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (!_isStart) _isStart = true;
	}

	if (_isStart)
	{
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_player.left -= 5;
			_player.right -= 5;
		}
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_player.left += 5;
			_player.right += 5;
		}

		for (int i = 0; i < SNOWMAX; i++)
		{
			_snow[i].rc.top += _snow[i].speed;
			_snow[i].rc.bottom += _snow[i].speed;

			//만약에 눈 중에 화면밖으로 나갔으면
			if (_snow[i].rc.top > WINSIZEY)
			{
				_snow[i].rc = RectMakeCenter(20 + i * 25, 10, 10, 10);
				_snow[i].speed = RND->getFromIntTo(5, 10);
			}

			RECT temp;
			if (IntersectRect(&temp, &_player, &_snow[i].rc))
			{
				this->init();
			}
		}
	}
	*/

	// 210428 API 수업 3 (플래피버드)
	/*
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_gravity = 0.1f;
		_jumpPower = 4.0f;
		_isJump = true;
		_isStartSate = false;
		_score++;
	}

	if (_isJump)
	{
		_y -= _jumpPower;
		_jumpPower -= _gravity;

		for (int i = 0; i < PIPEMAX; i++)
		{
			_pipe1[i].left -= _speed;
			_pipe1[i].right -= _speed;

			RECT temp;
			if (IntersectRect(&temp, &_player, &_pipe1[i]))
			{
				this->init();
			}

			if (_pipe1[i].left < 200)
			{
				_pipe3[i] = RectMake(500, 0, 100, RND->getFromIntTo(0, 400));
			}
		}

		for (int i = 0; i < PIPEMAX; i++)
		{
			_pipe2[i].left -= _speed;
			_pipe2[i].right -= _speed;

			//만약에 눈 중에 화면밖으로 나갔으면
			if (_pipe2[i].left < 0)
			{
				_pipe2[i] = RectMake(600, 600, 100, RND->getFromIntTo(0, 400));
			}

			RECT temp;
			if (IntersectRect(&temp, &_player, &_pipe2[i]))
			{
				this->init();
			}
		}

		for (int i = 0; i < PIPEMAX; i++)
		{
			_pipe3[i].left -= _speed;
			_pipe3[i].right -= _speed;

			//만약에 눈 중에 화면밖으로 나갔으면
			if (_pipe1[i].left < 0)
			{
				_pipe1[i] = RectMake(600, 0, 100, RND->getFromIntTo(0, 400));
			}

			RECT temp;
			if (IntersectRect(&temp, &_player, &_pipe1[i]))
			{
				this->init();
			}
		}
		
	}
	_player = RectMakeCenter(_x, _y, 100, 100);
	*/

	// 210429 API 수업 1 (인터벌)
	_count++;
	
	if (_count % 50 == 0)
	{
		_rc.left += 10;
		_rc.right += 10;
	
		_count = 0;
	}
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	// 210428 API 수업 1
	/*
	Rectangle(hdc, _rc);
	*/

	// 210428 API 수업 2 (눈)
	/*
	Rectangle(hdc, _player);

	for (int i = 0; i < SNOWMAX; i++)
	{
		Ellipse(hdc,
			_snow[i].rc.left,
			_snow[i].rc.top,
			_snow[i].rc.right,
			_snow[i].rc.bottom);
	}
	*/

	// 210428 API 수업 3 (플래피버드)
	/*
	if (_isStartSate == true)
	{
		char str2[128];
		sprintf_s(str2, "=== 시작하려면 스페이스바를 누르세요. ===");
		TextOut(hdc, 200, 400, str2, strlen(str2));
	}

	char str[128];
	sprintf_s(str, "점수 : %d", _score);
	TextOut(hdc, 10, 10, str, strlen(str));

	Rectangle(hdc, _player);

	for (int i = 0; i < PIPEMAX; i++)
	{
		Rectangle(hdc, _pipe1[i]);
		Rectangle(hdc, _pipe2[i]);
		Rectangle(hdc, _pipe3[i]);
	}
	*/

	// 210429 API 수업 1
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================


	Rectangle(backDC, _rc);


	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}
