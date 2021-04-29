#include "stdafx.h"
#include "playGround.h"
#include <Windows.h>

playGround::playGround()
{

}

playGround::~playGround()
{

}

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init();

	// 210428 API ���� 1
	/*
	_rc = RectMakeCenter(RND->getFromIntTo(100, WINSIZEX - 100), WINSIZEY / 2, 100, 100);
	_speed = _isCrash = 0;
	*/

	// 210428 API ���� 2 (��)
	/*
	_player = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 50, 70);

	for (int i = 0; i < SNOWMAX; i++)
	{
		_snow[i].rc = RectMakeCenter(20 + i * 25, 10, 10, 10);
		_snow[i].speed = RND->getFromIntTo(5, 10);
	}
	_isStart = false;
	*/

	// 210428 API ���� 3 (�÷��ǹ���)
	/*   ���ΰ�(�ڽ�) ����
	_x = WINSIZEX / 2 - 200;
	_y = WINSIZEY / 2;
	_player = RectMakeCenter(_x, _y, 100, 100);

	_isStartSate = true;

	// ������ ���� ����
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

	// 210429 API ���� 1
	_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);

	_count = 0;

	return S_OK;

}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();
}

//���⿡�� �����ϼ��� ������
void playGround::update()
{
	gameNode::update();

	// 210428 API ���� 1
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

	// 210428 API ���� 2 (��)
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

			//���࿡ �� �߿� ȭ������� ��������
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

	// 210428 API ���� 3 (�÷��ǹ���)
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

			//���࿡ �� �߿� ȭ������� ��������
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

			//���࿡ �� �߿� ȭ������� ��������
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

	// 210429 API ���� 1 (���͹�)
	_count++;
	
	if (_count % 50 == 0)
	{
		_rc.left += 10;
		_rc.right += 10;
	
		_count = 0;
	}
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	// 210428 API ���� 1
	/*
	Rectangle(hdc, _rc);
	*/

	// 210428 API ���� 2 (��)
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

	// 210428 API ���� 3 (�÷��ǹ���)
	/*
	if (_isStartSate == true)
	{
		char str2[128];
		sprintf_s(str2, "=== �����Ϸ��� �����̽��ٸ� ��������. ===");
		TextOut(hdc, 200, 400, str2, strlen(str2));
	}

	char str[128];
	sprintf_s(str, "���� : %d", _score);
	TextOut(hdc, 10, 10, str, strlen(str));

	Rectangle(hdc, _player);

	for (int i = 0; i < PIPEMAX; i++)
	{
		Rectangle(hdc, _pipe1[i]);
		Rectangle(hdc, _pipe2[i]);
		Rectangle(hdc, _pipe3[i]);
	}
	*/

	// 210429 API ���� 1
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================


	Rectangle(backDC, _rc);


	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}
