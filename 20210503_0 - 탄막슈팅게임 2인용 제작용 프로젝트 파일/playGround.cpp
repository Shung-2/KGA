#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{
}

// �ʱ�ȭ
HRESULT playGround::init()
{
	gameNode::init();

	// ���� ���� �ʱ�ȭ & ����
	_isStart = false;
	_lockKey = false;
	_use4skile = false;
	_reverseKey = false;
	_mapchange = false;

	// �÷��̾� ���� ���� & ���� (���� - P1, P2)
	_player = RectMakeCenter(WINSIZEX / 2 - 350, WINSIZEY / 2, 100, 50);			// Player 1 ����
	for (int i = 0; i < PLAYER1_BULLETMAX; i++)										// Player 1 �Ѿ�
	{
		_player1_bullet[i].x = _player.right + 10;
		_player1_bullet[i].y = (_player.top + _player.bottom) / 2;
		_player1_bullet[i].rc = RectMakeCenter
		(
			_player1_bullet[i].x, _player1_bullet[i].y,
			20, 20
		);
		_player1_bullet[i].isFire = false;
		_player1_bullet[i].speed = 7;
	}
	_player1_backGauge = RectMakeCenter(WINSIZEX / 2 - 250, 100, 400, 50);			// Player 1 ������
	_player1_frontGauge = RectMakeCenter(WINSIZEX / 2 - 250, 100, 400, 50);
	_p1_r = 0;
	_p1_g = 240;
	_player1_map = RectMake(WINSIZEX / 2 - 450, WINSIZEY / 2 - 250,	400, 600);		// Player 1 ��
	_player1_mode = 1;																// Player 1 ���
	_player1_state = true;															// Player 1 ����

	//******************************************************************************

	_player2 = RectMakeCenter(WINSIZEX / 2 + 350, WINSIZEY / 2, 100, 50);			// Player 2 ����
	for (int i = 0; i < PLAYER2_BULLETMAX; i++)										// Player 2 �Ѿ�
	{
		_player2_bullet[i].x = _player2.left - 10;
		_player2_bullet[i].y = (_player2.top + _player2.bottom) / 2;
		_player2_bullet[i].rc = RectMakeCenter
		(
			_player2_bullet[i].x,
			_player2_bullet[i].y,
			20, 20
		);
		_player2_bullet[i].isFire = false;
		_player2_bullet[i].speed = 7;
	}
	_player2_backGauge = RectMakeCenter(WINSIZEX / 2 + 250, 100, 400, 50);			// Player 2 ������
	_player2_frontGauge = RectMakeCenter(WINSIZEX / 2 + 250, 100, 400, 50);
	_p2_r = 0;
	_p2_g = 240;
	_player2_map = RectMake (WINSIZEX / 2 + 50, WINSIZEY / 2 - 250,	400, 600);		// Player 2 ��
	_player2_mode = 1;																// Player 2 ���
	_player2_state = true;															// Player 2 ����

	//******************************************************************************

	// �� ���� ���� & ����
	_wall = RectMake(WINSIZEX / 2 - 15, WINSIZEY / 2 - 250, 30, 100);				// �� �ʱ�ȭ
	_wall_speed = 5.0f; 															// �� ���ǵ�
	_wall_change = false;															// �� ���� ��ȯ

	return S_OK;
}

// �޸� ����
void playGround::release()
{
	gameNode::release();
}

// ����
void playGround::update()
{
	gameNode::update();

	if (_isStart)
	{
		// Player 1 ������
		if (KEYMANAGER->isStayKeyDown('W') && _reverseKey == false)
		{
			_player.top -= 5;
			_player.bottom -= 5;
		}
		if (KEYMANAGER->isStayKeyDown('S') && _reverseKey == false)
		{
			_player.top += 5;
			_player.bottom += 5;
		}
		if (KEYMANAGER->isStayKeyDown('A') && _reverseKey == false)
		{
			_player.left -= 5;
			_player.right -= 5;
		}
		if (KEYMANAGER->isStayKeyDown('D') && _reverseKey == false)
		{
			_player.left += 5;
			_player.right += 5;
		}

		// Player 1 ������ (R)
		if (KEYMANAGER->isStayKeyDown('W') && _reverseKey == true)
		{
			_player.top += 5;
			_player.bottom += 5;
		}
		if (KEYMANAGER->isStayKeyDown('S') && _reverseKey == true)
		{
			_player.top -= 5;
			_player.bottom -= 5;
		}
		if (KEYMANAGER->isStayKeyDown('A') && _reverseKey == true)
		{
			_player.left += 5;
			_player.right += 5;
		}
		if (KEYMANAGER->isStayKeyDown('D') && _reverseKey == true)
		{
			_player.left -= 5;
			_player.right -= 5;
		}

		// Player 1 �� �浹 (���� - ��, ��, ��, �Ʒ�)
		if (_player1_map.left >= _player.left)
		{
			_player.left += 5;
			_player.right += 5;
		}
		if (_player1_map.right <= _player.right)
		{
			_player.left -= 5;
			_player.right -= 5;
		}
		if (_player1_map.top >= _player.top)
		{
			_player.top += 5;
			_player.bottom += 5;
		}
		if (_player1_map.bottom <= _player.bottom)
		{
			_player.top -= 5;
			_player.bottom -= 5;
		}

		// Player 1 �Ѿ� �߻�
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			if (_player1_mode == 1)
				bulletFire();

			if (_player1_mode == 2)
				player1_mode2();

			if (_player1_mode == 3)
				player1_mode3();

			if (_player1_mode == 4)
				player1_mode4();
		}

		// Player 1 ��� ����
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_player1_mode++;
			if (_player1_mode > 4)
			{
				_player1_mode = 1;
			}
		}

		// Player 2 ������ (���� - ��, ��, ��, �Ʒ�)
		if (KEYMANAGER->isStayKeyDown('U') && _lockKey == false)
		{
			_player2.top -= 5;
			_player2.bottom -= 5;
		}
		if (KEYMANAGER->isStayKeyDown('J') && _lockKey == false)
		{
			_player2.top += 5;
			_player2.bottom += 5;
		}
		if (KEYMANAGER->isStayKeyDown('H') && _lockKey == false)
		{
			_player2.left -= 5;
			_player2.right -= 5;
		}
		if (KEYMANAGER->isStayKeyDown('K') && _lockKey == false)
		{
			_player2.left += 5;
			_player2.right += 5;
		}

		// Player 2 �� �浹 
		if (_player2_map.left >= _player2.left)
		{
			_player2.left += 5;
			_player2.right += 5;
		}
		if (_player2_map.right <= _player2.right)
		{
			_player2.left -= 5;
			_player2.right -= 5;
		}
		if (_player2_map.top >= _player2.top)
		{
			_player2.top += 5;
			_player2.bottom += 5;
		}
		if (_player2_map.bottom <= _player2.bottom)
		{
			_player2.top -= 5;
			_player2.bottom -= 5;
		}

		// Player 2 �Ѿ� �߻�
		if (KEYMANAGER->isOnceKeyDown('N'))
		{
			if (_player2_mode == 1)
				bulletFire2();

			if (_player2_mode == 2)
				player2_mode2();

			if (_player2_mode == 3)
				player2_mode3();

			if (_player2_mode == 4)
				player2_mode4();
		}

		// Player 2 ��� ����
		if (KEYMANAGER->isOnceKeyDown('M'))
		{
			_player2_mode++;
			if (_player2_mode > 4)
			{
				_player2_mode = 1;
			}
		}

		// Wall ������
		if (_wall_change)
		{
			_wall.top -= _wall_speed;
			_wall.bottom -= _wall_speed;
		}
		else
		{
			_wall.top += _wall_speed;
			_wall.bottom += _wall_speed;
		}

		// Wall ���� ��ȯ �� �� ��� ���� ����, �ӵ� ���� ����
		if (_wall.bottom > _player2_map.bottom)
		{
			_wall = RectMake(WINSIZEX / 2 - 42, WINSIZEY / 2 + 250, RND->getFromIntTo(30, 85), 100);
			_wall_speed = RND->getFromIntTo(5, 15);
			_wall_change = true;
		}
		if (_wall.top < _player2_map.top)
		{
			_wall = RectMake(WINSIZEX / 2 + 15, WINSIZEY / 2 - 250, 30, RND->getFromIntTo(100, 400));
			_wall_speed = RND->getFromIntTo(5, 15);
			_wall_change = false;
		}

		// Wall �浹 ó�� (Player 1, 2 ��)
		RECT WALL_TEMP;
		for (int i = 0; i < WALL_BULLMAX; i++)
		{
			if (IntersectRect(&WALL_TEMP, &_wall, &_player1_bullet[i].rc))
			{
				_player1_bullet[i].isFire = false;
			}
			if (IntersectRect(&WALL_TEMP, &_wall, &_player2_bullet[i].rc))
			{
				_player2_bullet[i].isFire = false;
			}
		}

		// ��忡 ���� �߻� ���� ó��
		// Player 1
		if (_player1_mode >= 1)
		{
			bulletMove();
		}
		if (_player1_mode >= 2)
		{
			player1_mode2_Move();
		}
		if (_player1_mode >= 3)
		{
			player1_mode3_Move();
		}
		if (_player1_mode >= 4)
		{
			player1_mode4_Move();
		}
		
		// Player 2
		if (_player2_mode >= 1)
		{
			bulletMove2();
		}
		if (_player2_mode >= 2)
		{
			player2_mode2_Move();
		}
		if (_player2_mode >= 3)
		{
			player2_mode3_Move();
		}

		// �й� (P1, P2�� ���°� false �ϋ�)
		if (_player1_state == false)
		{
			this->init();
		}
		if (_player2_state == false)
		{
			this->init();
		}
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_isStart = true;
		}
	}
}

// ���
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	if (!_mapchange)
	{
		PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	}
	else
	{
		PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, DSTINVERT);
	}
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	// Player 1 �� ���
	Rectangle(backDC, _player1_map);

	// Player 2 �� & P1 4 SK �� ���
	Rectangle(backDC, _player2_map);
	HBRUSH brush3 = CreateSolidBrush(RGB(23, 0, 255));
	HBRUSH oldBrush3 = (HBRUSH)SelectObject(backDC, brush3);
	Rectangle(backDC, _lockWall);
	SelectObject(backDC, oldBrush3);
	DeleteObject(brush3);
	
	// Wall ���
	Rectangle(backDC, _wall);

	//******************************************************************************

	// ���� �ȳ� ����
	if (_isStart == false)
	{
		char str1[128];
		char str2[128];
		char str3[128];

		sprintf_s(str1, "= = = = = = = = = = = = = = = = = = = = = = = = =");
		sprintf_s(str2, "              �����Ϸ��� 'Enter'�� ��������");
		sprintf_s(str3, "= = = = = = = = = = = = = = = = = = = = = = = = =");

		TextOut(backDC, WINSIZEX / 2 - 150, WINSIZEY / 2 - 25, str1, strlen(str1));
		TextOut(backDC, WINSIZEX / 2 - 150, WINSIZEY / 2, str2, strlen(str2));
		TextOut(backDC, WINSIZEX / 2 - 150, WINSIZEY / 2 + 25, str3, strlen(str3));
	}

	//******************************************************************************

	// Player 1 ���
	Rectangle(backDC, _player);
	// Player 1 �Ѿ� ���
	for (int i = 0; i < PLAYER1_BULLETMAX; i++)
	{
		if (!_player1_bullet[i].isFire) continue;
		Ellipse(backDC, _player1_bullet[i].rc);
	}
	// Player 1 ��� ���
	char str[50];
	sprintf_s(str, "%d", _player1_mode);
	TextOut(backDC, _player.left, _player.top - 20, str, strlen(str));
	// Player 1 ������ ���
	Rectangle(backDC, _player1_backGauge);
	HBRUSH brush1 = CreateSolidBrush(RGB(_p1_r, _p1_g, 0));
	HBRUSH oldBrush1 = (HBRUSH)SelectObject(backDC, brush1);
	Rectangle(backDC, _player1_frontGauge);
	SelectObject(backDC, oldBrush1);
	DeleteObject(brush1);
	// P1 4 SK �ƺ��� ���
	Rectangle(backDC, _Arbiter);

	//******************************************************************************

	// Player 2 ���
	Rectangle(backDC, _player2);
	// Player 2 �Ѿ� ���
	for (int i = 0; i < PLAYER2_BULLETMAX; i++)
	{
		if (!_player2_bullet[i].isFire) continue;
		Ellipse(backDC, _player2_bullet[i].rc);
	}
	// Player 2 ��� ���
	char str2[50];
	sprintf_s(str2, "%d", _player2_mode);
	TextOut(backDC, _player2.right, _player2.top - 20, str2, strlen(str2));
	// Player 2 ������ ���
	Rectangle(backDC, _player2_backGauge);
	HBRUSH brush2 = CreateSolidBrush(RGB(_p2_r, _p2_g, 0));
	HBRUSH oldBrush2 = (HBRUSH)SelectObject(backDC, brush2);
	Rectangle(backDC, _player2_frontGauge);
	SelectObject(backDC, oldBrush2);
	DeleteObject(brush2);

	//******************************************************************************

	// ���۹� ���
	char str10[128];
	char str20[128];
	sprintf_s(str10, " �����¿� : WSAD   �߻� : Z   ��� ��ȯ : X ");
	sprintf_s(str20, " �����¿� : UJHK   �߻� : N   ��� ��ȯ : M ");
	TextOut(backDC, WINSIZEX / 2 - 425, WINSIZEY / 2 + 365, str10, strlen(str10));
	TextOut(backDC, WINSIZEX / 2 + 100, WINSIZEY / 2 + 365, str20, strlen(str20));

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

// �߻�� �Լ� (Player 1 - MODE 1)
void playGround::bulletFire()
{
	for (int i = 0; i < PLAYER1_BULLETMAX; i++)
	{
		if (_player1_bullet[i].isFire) continue;

		_player1_bullet[i].x = _player.right + 10;
		_player1_bullet[i].y = (_player.top + _player.bottom) / 2;
		_player1_bullet[i].rc = RectMakeCenter(_player1_bullet[i].x,
			_player1_bullet[i].y, 20, 20);
		_player1_bullet[i].isFire = true;
		break;
	}
}

// �߻�� �Լ� (Player 2 - MODE 1)
void playGround::bulletFire2()
{
	for (int i = 0; i < PLAYER2_BULLETMAX; i++)
	{
		if (_player2_bullet[i].isFire) continue;

		_player2_bullet[i].x = _player2.left - 10;
		_player2_bullet[i].y = (_player2.top + _player2.bottom) / 2;
		_player2_bullet[i].rc = RectMakeCenter(_player2_bullet[i].x,
			_player2_bullet[i].y, 20, 20);
		_player2_bullet[i].isFire = true;
		break;
	}
}

// �߻�� �Լ� (Player 1 - MODE 2)
void playGround::player1_mode2()
{
	for (int i = 0; i < PLAYER1_BULLETMAX; i += 5)
	{
		if (_player1_bullet[i].isFire) continue;

		_player1_bullet[i+0].x = _player.right + 10;
		_player1_bullet[i+0].y = (_player.top + _player.bottom) / 2;
		_player1_bullet[i+1].x = _player.right + 10;
		_player1_bullet[i+1].y = (_player.top + _player.bottom) / 2;
		_player1_bullet[i+2].x = _player.right + 10;
		_player1_bullet[i+2].y = (_player.top + _player.bottom) / 2; 
		_player1_bullet[i+3].x = _player.right + 10;
		_player1_bullet[i+3].y = (_player.top + _player.bottom) / 2;
		_player1_bullet[i+4].x = _player.right + 10;
		_player1_bullet[i+4].y = (_player.top + _player.bottom) / 2;
		
		_player1_bullet[i+0].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);
		_player1_bullet[i+1].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);
		_player1_bullet[i+2].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);
		_player1_bullet[i+3].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);
		_player1_bullet[i+4].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);

		_player1_bullet[i+0].isFire = true;
		_player1_bullet[i+1].isFire = true;
		_player1_bullet[i+2].isFire = true;
		_player1_bullet[i+3].isFire = true;
		_player1_bullet[i+4].isFire = true;
		break;
	}
}

// ��¿� �Լ� (Player 1 - MODE 2)
void playGround::player1_mode2_Move()
{
	for (int i = 0; i < PLAYER1_BULLETMAX; i += 5)
	{
		if (!_player1_bullet[i+0].isFire) continue;
		if (!_player1_bullet[i+1].isFire) continue;
		if (!_player1_bullet[i+2].isFire) continue;
		if (!_player1_bullet[i+3].isFire) continue;
		if (!_player1_bullet[i+4].isFire) continue;

		if (_player1_bullet[i+0].x > WINSIZEX + 50) _player1_bullet[i+0].isFire = false;
		if (_player1_bullet[i+1].x > WINSIZEX + 50) _player1_bullet[i+1].isFire = false;
		if (_player1_bullet[i+2].x > WINSIZEX + 50) _player1_bullet[i+2].isFire = false;
		if (_player1_bullet[i+3].x > WINSIZEX + 50) _player1_bullet[i+3].isFire = false;
		if (_player1_bullet[i+4].x > WINSIZEX + 50) _player1_bullet[i+4].isFire = false;

		_player1_bullet[i+0].x += _player1_bullet[i+0].speed;
		_player1_bullet[i+1].x += _player1_bullet[i+1].speed;
		_player1_bullet[i+2].x += _player1_bullet[i+2].speed;
		_player1_bullet[i+3].x += _player1_bullet[i+3].speed;
		_player1_bullet[i+4].x += _player1_bullet[i+4].speed;

		_player1_bullet[i + 0].rc = RectMakeCenter(_player1_bullet[i + 0].x, _player1_bullet[i + 0].y + RND->getFromIntTo(0, 100), 20, 20);
		_player1_bullet[i + 1].rc = RectMakeCenter(_player1_bullet[i + 1].x, _player1_bullet[i + 2].y + RND->getFromIntTo(0, 100), 20, 20);
		_player1_bullet[i + 2].rc = RectMakeCenter(_player1_bullet[i + 2].x, _player1_bullet[i + 3].y + RND->getFromIntTo(0, 100), 20, 20);
		_player1_bullet[i + 3].rc = RectMakeCenter(_player1_bullet[i + 3].x, _player1_bullet[i + 4].y + RND->getFromIntTo(0, 100), 20, 20);
		_player1_bullet[i + 4].rc = RectMakeCenter(_player1_bullet[i + 4].x, _player1_bullet[i + 5].y + RND->getFromIntTo(0, 100), 20, 20);

		RECT temp;
		if (IntersectRect(&temp, &_player2, &_player1_bullet[i].rc) && _player1_bullet[i].isFire)
		{
			setGauge();
			_player1_bullet[i + 0].isFire = false;
			_player1_bullet[i + 1].isFire = false;
			_player1_bullet[i + 2].isFire = false;
			_player1_bullet[i + 3].isFire = false;
			_player1_bullet[i + 4].isFire = false;
			break;
		}
	}
}

// �߻�� �Լ� (Player 2 - MODE 2)
void playGround::player2_mode2()
{
	for (int i = 0; i < PLAYER2_BULLETMAX; i += 5)
	{
		if (_player2_bullet[i].isFire) continue;

		_player2_bullet[i + 0].x = _player2.left - 10;
		_player2_bullet[i + 0].y = (_player2.top + _player2.bottom) / 2;
		_player2_bullet[i + 1].x = _player2.left - 10;
		_player2_bullet[i + 1].y = (_player2.top + _player2.bottom) / 2;
		_player2_bullet[i + 2].x = _player2.left - 10;
		_player2_bullet[i + 2].y = (_player2.top + _player2.bottom) / 2;
		_player2_bullet[i + 3].x = _player2.left - 10;
		_player2_bullet[i + 3].y = (_player2.top + _player2.bottom) / 2;
		_player2_bullet[i + 4].x = _player2.left - 10;
		_player2_bullet[i + 4].y = (_player2.top + _player2.bottom) / 2;

		_player2_bullet[i + 0].rc = RectMakeCenter(_player2_bullet[i].x, _player2_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);
		_player2_bullet[i + 1].rc = RectMakeCenter(_player2_bullet[i].x, _player2_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);
		_player2_bullet[i + 2].rc = RectMakeCenter(_player2_bullet[i].x, _player2_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);
		_player2_bullet[i + 3].rc = RectMakeCenter(_player2_bullet[i].x, _player2_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);
		_player2_bullet[i + 4].rc = RectMakeCenter(_player2_bullet[i].x, _player2_bullet[i].y + RND->getFromIntTo(0, 100), 20, 20);

		_player2_bullet[i + 0].isFire = true;
		_player2_bullet[i + 1].isFire = true;
		_player2_bullet[i + 2].isFire = true;
		_player2_bullet[i + 3].isFire = true;
		_player2_bullet[i + 4].isFire = true;
		break;
	}
}

// ��¿� �Լ� (Player 2 - MODE 2)
void playGround::player2_mode2_Move()
{
	for (int i = 0; i < PLAYER2_BULLETMAX; i += 5)
	{
		if (!_player2_bullet[i + 0].isFire) continue;
		if (!_player2_bullet[i + 1].isFire) continue;
		if (!_player2_bullet[i + 2].isFire) continue;
		if (!_player2_bullet[i + 3].isFire) continue;
		if (!_player2_bullet[i + 4].isFire) continue;

		if (_player2_bullet[i + 0].x > WINSIZEX + 50) _player2_bullet[i + 0].isFire = false;
		if (_player2_bullet[i + 1].x > WINSIZEX + 50) _player2_bullet[i + 1].isFire = false;
		if (_player2_bullet[i + 2].x > WINSIZEX + 50) _player2_bullet[i + 2].isFire = false;
		if (_player2_bullet[i + 3].x > WINSIZEX + 50) _player2_bullet[i + 3].isFire = false;
		if (_player2_bullet[i + 4].x > WINSIZEX + 50) _player2_bullet[i + 4].isFire = false;

		_player2_bullet[i + 0].x -= _player2_bullet[i + 0].speed;
		_player2_bullet[i + 1].x -= _player2_bullet[i + 1].speed;
		_player2_bullet[i + 2].x -= _player2_bullet[i + 2].speed;
		_player2_bullet[i + 3].x -= _player2_bullet[i + 3].speed;
		_player2_bullet[i + 4].x -= _player2_bullet[i + 4].speed;

		_player2_bullet[i + 0].rc = RectMakeCenter(_player2_bullet[i + 0].x, _player2_bullet[i + 0].y + RND->getFromIntTo(0, 100), 20, 20);
		_player2_bullet[i + 1].rc = RectMakeCenter(_player2_bullet[i + 1].x, _player2_bullet[i + 2].y + RND->getFromIntTo(0, 100), 20, 20);
		_player2_bullet[i + 2].rc = RectMakeCenter(_player2_bullet[i + 2].x, _player2_bullet[i + 3].y + RND->getFromIntTo(0, 100), 20, 20);
		_player2_bullet[i + 3].rc = RectMakeCenter(_player2_bullet[i + 3].x, _player2_bullet[i + 4].y + RND->getFromIntTo(0, 100), 20, 20);
		_player2_bullet[i + 4].rc = RectMakeCenter(_player2_bullet[i + 4].x, _player2_bullet[i + 5].y + RND->getFromIntTo(0, 100), 20, 20);

		RECT temp;
		if (IntersectRect(&temp, &_player, &_player2_bullet[i].rc) && _player2_bullet[i].isFire)
		{
			setGauge2();
			_player2_bullet[i + 0].isFire = false;
			_player2_bullet[i + 1].isFire = false;
			_player2_bullet[i + 2].isFire = false;
			_player2_bullet[i + 3].isFire = false;
			_player2_bullet[i + 4].isFire = false;
			break;
		}
	}
}

// �߻�� �Լ� (Player 1 - MODE 3)
void playGround::player1_mode3()
{
	for (int i = 0; i < PLAYER1_BULLETMAX; i++)
	{
		if (_player1_bullet[i].isFire) continue;

		_player1_bullet[i].x = _player.right + 10;
		_player1_bullet[i].y = (_player.top + _player.bottom) / 2;
		_player1_bullet[i].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y, 20, 20);
		_player1_bullet[i].isFire = true;
		break;
	}
}

// ��¿� �Լ� (Player 1 - MODE 3)
void playGround::player1_mode3_Move()
{
	for (int i = 0; i < PLAYER1_BULLETMAX; i++)
	{
		if (!_player1_bullet[i].isFire) continue;
		if (_player1_bullet[i].x > WINSIZEX + 50) _player1_bullet[i].isFire = false;
		_player1_bullet[i].x += _player1_bullet[i].speed;
		_player1_bullet[i].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y, 20, 20);

		if (_player1_bullet[i].rc.right > _player1_map.right)
		{
			// 1P�� �ٴ��ʿ��� ��� ���� 2P�� ���� ���� ��
			if (_player1_bullet[i].rc.top > _player2.top)
			{
				_player1_bullet[i].y -= 7.5;
				_player1_bullet[i].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y, 20, 20);
			}
			// 1P�� ���ʿ��� ��� ���� 2P�� �Ʒ��� ���� ��
			if (_player1_bullet[i].rc.bottom < _player2.bottom)
			{
				_player1_bullet[i].y += 7.5;
				_player1_bullet[i].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y, 20, 20);
			}
		}

		RECT temp;
		if (IntersectRect(&temp, &_player2, &_player1_bullet[i].rc) && _player1_bullet[i].isFire)
		{
			setGauge();
			_player1_bullet[i].isFire = false;
			break;
		}
	}
}

// �߻�� �Լ� (Player 2 - MODE 3)
void playGround::player2_mode3()
{
	for (int i = 0; i < PLAYER2_BULLETMAX; i++)
	{
		if (_player2_bullet[i].isFire) continue;

		_player2_bullet[i].x = _player2.left - 10;
		_player2_bullet[i].y = (_player2.top + _player2.bottom) / 2;
		_player2_bullet[i].rc = RectMakeCenter(_player2_bullet[i].x,
			_player2_bullet[i].y, 20, 20);
		_player2_bullet[i].isFire = true;
		break;
	}
}

// ��¿� �Լ� (Player 2 - MODE 3)
void playGround::player2_mode3_Move()
{
	for (int i = 0; i < PLAYER2_BULLETMAX; i++)
	{
		if (!_player2_bullet[i].isFire) continue;
		if (_player2_bullet[i].x > WINSIZEX + 50) _player2_bullet[i].isFire = false;
		_player2_bullet[i].x -= _player2_bullet[i].speed;
		_player2_bullet[i].rc = RectMakeCenter(_player2_bullet[i].x, _player2_bullet[i].y, 20, 20);

		if (_player2_bullet[i].rc.left < _player2_map.left)
		{
			//2 P�� �ٴ��ʿ��� ��� ���� 1P�� ���� ���� ��
			if (_player2_bullet[i].rc.top > _player.top)
			{
				_player2_bullet[i].y -= 7.5;
				_player2_bullet[i].rc = RectMakeCenter(_player2_bullet[i].x, _player2_bullet[i].y, 20, 20);
			}
			// 2P�� ���ʿ��� ��� ���� 1P�� �Ʒ��� ���� ��
			if (_player2_bullet[i].rc.bottom < _player.bottom)
			{		   
				_player2_bullet[i].y += 7.5;
				_player2_bullet[i].rc = RectMakeCenter(_player2_bullet[i].x, _player2_bullet[i].y, 20, 20);
			}
		}

		RECT temp;
		if (IntersectRect(&temp, &_player, &_player2_bullet[i].rc) && _player2_bullet[i].isFire)
		{
			setGauge2();
			_player2_bullet[i].isFire = false;
			break;
		}
	}
}

// �߻�� �Լ� (Player 1 - MODE 4)
void playGround::player1_mode4()
{
	if (!_use4skile)
	{
		_use4skile = true;
		_Arbiter = RectMakeCenter(0, WINSIZEY / 2 - 360, 70, 50);
	}
	else
	{

	}
}

// ��¿� �Լ� (Player 1 - MODE 4)
void playGround::player1_mode4_Move()
{
	_Arbiter.left += 5;
	_Arbiter.right += 5;
	
	if (_Arbiter.left >= (_player2_map.left + _player2_map.right) / 2)
	{
		_Arbiter = RectMakeCenter(800, WINSIZEY / 2 - 360, 70, 50);
		_lockWall = RectMake(_player2.left - 15, _player2.top - 15, 130, 80);
		_lockKey = true;
	}
}

// P2 4 SK �Լ�
void playGround::player2_mode4()
{
	_player1_map = RectMake( (WINSIZEX / 2 - 450) + 100, (WINSIZEY / 2 - 100), 400 / 2, 600 / 2);
	_reverseKey = true;
}

// �Ѿ� �����ӿ� (Player 1)
void playGround::bulletMove()
{
	for (int i = 0; i < PLAYER1_BULLETMAX; i++)
	{
		if (!_player1_bullet[i].isFire) continue;
		if (_player1_bullet[i].x > WINSIZEX + 50) _player1_bullet[i].isFire = false;
		_player1_bullet[i].x += _player1_bullet[i].speed;
		_player1_bullet[i].rc = RectMakeCenter(_player1_bullet[i].x, _player1_bullet[i].y , 20, 20);

		RECT temp;
		if (IntersectRect(&temp, &_player2, &_player1_bullet[i].rc) && _player1_bullet[i].isFire)
		{
			setGauge();
			_player1_bullet[i].isFire = false;
			break;
		}
	}
}

// �Ѿ� �����ӿ� (Player 2)
void playGround::bulletMove2()
{
	for (int i = 0; i < PLAYER2_BULLETMAX; i++)
	{
		if (!_player2_bullet[i].isFire) continue;
		if (_player2_bullet[i].x > WINSIZEX + 50) _player2_bullet[i].isFire = false;
		_player2_bullet[i].x -= _player2_bullet[i].speed;
		_player2_bullet[i].rc = RectMakeCenter(_player2_bullet[i].x,
			_player2_bullet[i].y, 20, 20);

		RECT temp;
		if (IntersectRect(&temp, &_player, &_player2_bullet[i].rc) && _player2_bullet[i].isFire)
		{
			setGauge2();
			_player2_bullet[i].isFire = false;
			break;
		}
	}
}

// �Ѿ� ���� ��� ���ϴ� ������ (Player 2)
void playGround::setGauge()
{
	_player2_frontGauge.left += 10;

	if (_player2_frontGauge.left >= _player2_backGauge.right)
	{
		_player2_state = false;
		_player2_frontGauge.left = _player2_backGauge.right;
	}
			   
	if (_player2_frontGauge.right - _player2_frontGauge.left < 275)
	{
		_p2_r = 255;
		_p2_g = 255;
	}
	
	if (_player2_frontGauge.right - _player2_frontGauge.left < 100)
	{
		_p2_r = 255;
		_p2_g = 0;
	}
}

// �Ѿ� ���� ��� ���ϴ� ������ (Player 1)
void playGround::setGauge2()
{
	_player1_frontGauge.right -= 10;

	if (_player1_frontGauge.left >= _player1_frontGauge.right)
	{
		_player1_state = false;
		_mapchange = true;
		_player1_frontGauge.left = _player1_frontGauge.right;
	}

	if (_player1_frontGauge.right - _player1_frontGauge.left < 275)
	{
		_p1_r = 255;
		_p1_g = 255;
	}

	if (_player1_frontGauge.right - _player1_frontGauge.left < 100)
	{
		_mapchange = true;
		_p1_r = 255;
		_p1_g = 0;
	}
}