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
	
	set_Background();			// ��� ���� & �ʱ� ��� ����
	set_Stage1_Land_Obj();		// �� ���� & �������� ��ֹ� ����, RECT ��ó ����, ��� ����
	set_Player();				// �÷��̾� ����
	_count = 0;					// ������ ����
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

	get_Background(); 	/* ��� ���� Ű (F1, F2, F3) */
	get_Player_Key(); 	/* �÷��̾� �̵� Ű */

	Player_Move();		/* �÷��̾� �̵� ���� */
	Player_Frame();		/* �÷��̾� ������ �� ���� ���� */

	/* �÷��̾� ��ġ ���� */
	_player.player = RectMakeCenter(_player.x, _player.y, 110, 140);
}

// ���
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================
	
	draw_BackGroud(backDC);			/* ��� ��� */
	draw_Stage1_Land_Obj(backDC);	/* ��, ��ֹ� ��� */
	draw_Player(backDC);			/* ���ΰ� ��� */

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

void playGround::set_Background()
{
	/* �������� �� ���ȭ�� ���� */ 
	IMAGEMANAGER->addImage("Stage1", "stgbg1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));						
	IMAGEMANAGER->addImage("Stage2", "stgbg2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage3", "stgbg3.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	/* ���ȭ�� �ʱ� ���� ��� */
	_background = IMAGEMANAGER->findImage("Stage1");																
}

void playGround::set_Stage1_Land_Obj()
{
	/* �������� 1 �� ���� */
	_stage1_obj_land = RectMake(0, WINSIZEY / 2 + 385, WINSIZEX, 75);												

	/* �������� 1 ��ֹ� (�ٸ�) �̹��� ���� */
	IMAGEMANAGER->addImage("Stage1_bridge", "stage 1 object (bridge).bmp", 128, 71, true, RGB(255, 0, 255));		
	
	/* �������� 1 ��ֹ� (�ٸ�) ���� */
	_stage1_obj_bridge[0] = RectMake(400, 600, 128, 300);
	_stage1_obj_bridge[1] = RectMake(WINSIZEX / 2 + 200, 500, 128, 350);
	_stage1_obj_bridge[2] = RectMake(WINSIZEX / 2 + 500, 220, 128, 71);
	
	/* �������� 1 ��ֹ� (�ٸ�) �ʱ� ���� ��� */
	_stage1_obj_bridge_img = IMAGEMANAGER->findImage("Stage1_bridge");
}

void playGround::set_Player()
{
	/* �÷��̾� ���� (X,Y ��ǥ, ��ġ, ���ǵ�, ���� ī��Ʈ, �߷� ����, �� ���� ���� ����, �ϴ� ���� ���� ����) */
	_player.x = _player.player.right - _player.player.left;
	_player.y = _player.player.bottom - _player.player.top;
	_player.player = RectMakeCenter(_player.x, _player.y, 110, 140);
	_player._speed = 5;
	_player._jumpCount = 0;
	_player_gravity = false;
	_player._isGrap = false;
	_player._isDownJump = false;

	/* �÷��̾� �̹��� ���� (IDEL, JUMP, WALL CATCH, DOWN JUMP) */
	IMAGEMANAGER->addFrameImage("Player_Idel", "myth_run.bmp", 1710, 268, 15, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Player_Jump", "myth_jump.bmp", 550, 387, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Player_WallCatch", "myth_wallcatch.bmp", 1004, 309, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Player_DownJump", "myth_downJump.bmp", 224, 501, 3, 2, true, RGB(255, 0, 255));

	/* �÷��̾� ��Ÿ ���� (�ε���, �ʱ� ����, �̹���, �ʱ� �̹��� ���) */
	_index = 0;
	_state = LEFT_IDLE;
	_player_img = new image;
	_player_img = IMAGEMANAGER->findImage("Player_Idel");
}

void playGround::get_Background()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) _background = IMAGEMANAGER->findImage("Stage1");
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _background = IMAGEMANAGER->findImage("Stage2");
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) _background = IMAGEMANAGER->findImage("Stage3");
}

void playGround::get_Player_Key()
{
	/* ������ �̵����� */
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !_player._keyLock)
	{
		_state = RIGHT_RUN;
		_player.x += _player._speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state = RIGHT_IDLE;
	}

	/* ���� �̵����� */
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !_player._keyLock)
	{
		_state = LEFT_RUN;
		_player.x -= _player._speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = LEFT_IDLE;
	}

	/* ���� �� �ε��� ��, �߷�(����) ���� */
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		if (_state == LEFT_IDLE)
		{
			_state = LEFT_JUMP;
			_index = 4;
		}
		if (_state == RIGHT_IDLE)
		{
			_state = RIGHT_JUMP;
			_index = 0;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _player._jumpCount <= 1)
	{
		if (_state == LEFT_IDLE || _state == RIGHT_IDLE)
		{
			_player._keyLock = false;
			_player._jumpCount++;
			_player._gravity = 0.1f;
			_player._jumpPower = 7.5f;
			_player._isJump = true;
			_player_gravity = true;
		}
	}

	/* �ϴ� ���� */
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && !_player._isJump)
		{
			_player._isGrap = false;
			_player._isJump = true;
			_player._isDownJump = true;
			_player._jumpCount = 0;
			_player._jumpPower = 0;
			_player._gravity = 0.1f;

			if (_state % 2 == 0)
			{
				_player_img = IMAGEMANAGER->findImage("Player_DownJump");
				_state = RIGHT_DOWNJUMP;
				_index = 0;
			}
			else
			{
				_player_img = IMAGEMANAGER->findImage("Player_DownJump");
				_state = LEFT_DOWNJUMP;
				_index = 3;
			}
		}
	}
}

void playGround::Player_Move()
{
	/* ���� ���� */
	if (_player._isJump || _player_gravity)
	{
		_player.y -= _player._jumpPower;
		_player._jumpPower -= _player._gravity;
	}

	/* �� ���� ���� */
	if (_player._isGrap) 
	{
		_player._keyLock = true;
		_player._jumpPower = 0;
		_player._gravity = 0;
	}

	/* �÷��̾� ��ġ ���� */
	_player.player = RectMakeCenter(_player.x, _player.y, 110, 140); 	

	/* �浹 ó�� */
	On_Screen();		/* ȭ�� �������� �̵� */
	Above_Land_Obj();	/* �������� �� & ��ֹ� ���� ���� ��� ó�� */
	Obj_Grap();			/* �������� ��ֹ� �� ��� */
}

void playGround::Player_Frame()
{
	_count++;

	if (_count % 9 == 0)
	{
		/* ������ �⺻ ���� */
		if (_state == RIGHT_IDLE)
		{
			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);
			_index++;

			if (_index >= 4) _index = 0;
		}

		/* ���� �⺻ ���� */
		if (_state == LEFT_IDLE)
		{
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);
			_index--;

			if (_index <= 10) _index = _player_img->getMaxFrameX();
		}

		/* ������ �޸��� ���� */
		if (_state == RIGHT_RUN)
		{

			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);
			_index++;

			if (_index >= _player_img->getMaxFrameX()) _index = 6;
		}

		/* ���� �޸��� ���� */
		if (_state == LEFT_RUN)
		{
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);
			_index--;

			if (_index <= 0) _index = 7;
		}

		/* ������ ���� ���� */
		if (_state == RIGHT_JUMP)
		{
			_player_img = IMAGEMANAGER->findImage("Player_Jump");
			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);

			if (_index >= 0) _index++;
		}

		/* ���� ���� ���� */
		if (_state == LEFT_JUMP)
		{
			_player_img = IMAGEMANAGER->findImage("Player_Jump");
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);

			if (_index > 0) _index--;
		}

		/* ������ �� ��� ���� */
		if (_state == RIGHT_WALLCATCH)
		{
			_player_img = IMAGEMANAGER->findImage("Player_WallCatch");
			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);
			_index++;

			if (_index >= _player_img->getMaxFrameX()) _index = 0;
		}

		/* ���� �� ��� ���� */
		if (_state == LEFT_WALLCATCH)
		{
			_player_img = IMAGEMANAGER->findImage("Player_WallCatch");
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);
			_index--;

			if (_index <= 0) _index = _player_img->getMaxFrameX();
		}

		/* ������ �ϴ� ���� ���� */
		if (_state == RIGHT_DOWNJUMP)
		{
			_player_img = IMAGEMANAGER->findImage("Player_DownJump");
			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);
			_index++;

			if (_index >= _player_img->getMaxFrameX()) _index = 0;
		}

		/* ���� �ϴ� ���� ���� */
		if (_state == LEFT_DOWNJUMP)
		{
			_player_img = IMAGEMANAGER->findImage("Player_DownJump");
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);
			_index--;

			if (_index <= 0) _index = _player_img->getMaxFrameX();
		}
		_count = 0;
	}
}

void playGround::On_Screen()
{
	/* �� �������� (���� ��, ��) */
	if (_player.x - 60 < 0)
	{
		_player.x += _player._speed;
	}

	if (_player.x + 60 > WINSIZEX)
	{
		_player.x -= _player._speed;
	}
}

void playGround::Above_Land_Obj()
{
	/* �������� �� ���� ���� ��� ó�� */
	if (_player.player.bottom >= _stage1_obj_land.top && _player.player.top <= _stage1_obj_land.top)
	{
		_player._isJump = false;
		_player._jumpCount = 0;
		_player.y = _stage1_obj_land.top - 71;

		_player_img = IMAGEMANAGER->findImage("Player_Idel");
		if (_state == LEFT_JUMP)
			_state = LEFT_IDLE;
		if (_state == RIGHT_JUMP)
			_state = RIGHT_IDLE;
	}

	/* �������� ��ֹ� ���� ���� ��� ó�� */
	for (int i = 0; i < 3; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_stage1_obj_bridge[i], &_player.player))
		{
			if (i == 0)
			{
				_player._isDownJump = false;
			}

			// �� ���� �浹
			if (_stage1_obj_bridge[i].left > _player.x)
			{
				_player.x = _stage1_obj_bridge[i].left - 55;
			}

			// �� ������ �浹
			if (_stage1_obj_bridge[i].right < _player.x)
			{
				_player.x = _stage1_obj_bridge[i].right + 55;
			}

			// �� �� �浹
			if (_stage1_obj_bridge[i].top > _player.y &&
				_stage1_obj_bridge[i].left < _player.x && _stage1_obj_bridge[i].right > _player.x)
			{
				_player._jumpCount = 0;
				_player._jumpPower = 0.0f;
				_player.y = _stage1_obj_bridge[i].top - 70;
				_player._isJump = false;

				// �ö���� �� �� IDEL �̹��� ����� ���� ȣ�� �� ���� ����
				_player_img = IMAGEMANAGER->findImage("Player_Idel");
				if (_state == LEFT_JUMP)
				{
					_state = LEFT_IDLE;
				}
				if (_state == RIGHT_JUMP)
				{
					_state = RIGHT_IDLE;
				}
			}

			// �ϴ� ����
			if (_stage1_obj_bridge[i].top > _player.y && _stage1_obj_bridge[i].left < _player.x && _stage1_obj_bridge[i].right > _player.x && _player._isDownJump == true)
			{
				_player.y = _stage1_obj_bridge[i].bottom + 75;
				_player._isDownJump = false;
			}
		}
	}
}

void playGround::Obj_Grap()
{
	/* �������� ��ֹ� �� ��� */
	if (_player._jumpPower <= 0)
	{
		for (int i = 0; i < 3; i++)
		{
			// ���� �𼭸�
			if ((_stage1_obj_bridge[i].left - _player._speed	 <= _player.player.right && _player.player.right <= _stage1_obj_bridge[i].left + _player._speed) &&
				(_stage1_obj_bridge[i].top  + _player._jumpPower <= _player.player.top	 && _player.player.top	 <= _stage1_obj_bridge[i].top  - _player._jumpPower))
			{
				_state = LEFT_WALLCATCH;
				_player.x = _stage1_obj_bridge[i].left - 55;
				_player.y = _stage1_obj_bridge[i].top + 30;
				_player._jumpCount = 1;
				_player._isGrap = true;
				_player._isJump = false;
				break;
			}

			// ������ �𼭸�
			else if ((_stage1_obj_bridge[i].right - _player._speed		<= _player.player.left && _player.player.left <= _stage1_obj_bridge[i].right + _player._speed) &&
					 (_stage1_obj_bridge[i].top   + _player._jumpPower	<= _player.player.top  && _player.player.top  <= _stage1_obj_bridge[i].top   - _player._jumpPower))
			{
				_state = RIGHT_WALLCATCH;
				_player_img = IMAGEMANAGER->findImage("Player_WallCatch");
				_player.x = _stage1_obj_bridge[i].right + 55;
				_player.y = _stage1_obj_bridge[i].top + 30;
				_player._jumpCount = 1;
				_player._isGrap = true;
				_player._isJump = false;
				break;
			}

			// �� �� (������ ��Ȳ)
			else
			{
				_player._isGrap = false;
			}
		}
	}
}

void playGround::draw_BackGroud(HDC hdc)
{
	/* ���ȭ�� ��� */
	IMAGEMANAGER->render("Stage1", hdc, 0, 0);
}

void playGround::draw_Stage1_Land_Obj(HDC hdc)
{
	/* �� ��� */
	Rectangle(hdc, _stage1_obj_land); 	

	/* ��ֹ� ��� */
	for (int i = 0; i < 3; i++)
	{
		Rectangle(hdc, _stage1_obj_bridge[i]);
		IMAGEMANAGER->render("Stage1_bridge", hdc, _stage1_obj_bridge[i].left, _stage1_obj_bridge[i].top);
	}
}

void playGround::draw_Player(HDC hdc)
{
	/* �÷��̾� ��� */
	Rectangle(hdc, _player.player);
	_player_img->frameRender(hdc, _player.player.left, _player.player.top);
}