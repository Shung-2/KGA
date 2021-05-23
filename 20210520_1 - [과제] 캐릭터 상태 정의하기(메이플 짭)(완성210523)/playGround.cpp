#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{
}

// 초기화
HRESULT playGround::init()
{
	gameNode::init();
	
	set_Background();			// 배경 선언 & 초기 배경 설정
	set_Stage1_Land_Obj();		// 땅 설정 & 스테이지 장애물 선언, RECT 위처 설정, 배경 설정
	set_Player();				// 플레이어 설정
	_count = 0;					// 프레임 설정
	return S_OK;
}

// 메모리 해제
void playGround::release()
{
	gameNode::release();
}

// 연산
void playGround::update()
{
	gameNode::update();

	get_Background(); 	/* 배경 변경 키 (F1, F2, F3) */
	get_Player_Key(); 	/* 플레이어 이동 키 */

	Player_Move();		/* 플레이어 이동 연산 */
	Player_Frame();		/* 플레이어 프레임 별 동작 상태 */

	/* 플레이어 위치 연산 */
	_player.player = RectMakeCenter(_player.x, _player.y, 110, 140);
}

// 출력
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================
	
	draw_BackGroud(backDC);			/* 배경 출력 */
	draw_Stage1_Land_Obj(backDC);	/* 땅, 장애물 출력 */
	draw_Player(backDC);			/* 주인공 출력 */

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

void playGround::set_Background()
{
	/* 스테이지 별 배경화면 설정 */ 
	IMAGEMANAGER->addImage("Stage1", "stgbg1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));						
	IMAGEMANAGER->addImage("Stage2", "stgbg2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage3", "stgbg3.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	/* 배경화면 초기 상태 출력 */
	_background = IMAGEMANAGER->findImage("Stage1");																
}

void playGround::set_Stage1_Land_Obj()
{
	/* 스테이지 1 땅 설정 */
	_stage1_obj_land = RectMake(0, WINSIZEY / 2 + 385, WINSIZEX, 75);												

	/* 스테이지 1 장애물 (다리) 이미지 상태 */
	IMAGEMANAGER->addImage("Stage1_bridge", "stage 1 object (bridge).bmp", 128, 71, true, RGB(255, 0, 255));		
	
	/* 스테이지 1 장애물 (다리) 설정 */
	_stage1_obj_bridge[0] = RectMake(400, 600, 128, 300);
	_stage1_obj_bridge[1] = RectMake(WINSIZEX / 2 + 200, 500, 128, 350);
	_stage1_obj_bridge[2] = RectMake(WINSIZEX / 2 + 500, 220, 128, 71);
	
	/* 스테이지 1 장애물 (다리) 초기 상태 출력 */
	_stage1_obj_bridge_img = IMAGEMANAGER->findImage("Stage1_bridge");
}

void playGround::set_Player()
{
	/* 플레이어 설정 (X,Y 좌표, 위치, 스피드, 점프 카운트, 중력 여부, 벽 잡은 상태 여부, 하단 점프 상태 여부) */
	_player.x = _player.player.right - _player.player.left;
	_player.y = _player.player.bottom - _player.player.top;
	_player.player = RectMakeCenter(_player.x, _player.y, 110, 140);
	_player._speed = 5;
	_player._jumpCount = 0;
	_player_gravity = false;
	_player._isGrap = false;
	_player._isDownJump = false;

	/* 플레이어 이미지 설정 (IDEL, JUMP, WALL CATCH, DOWN JUMP) */
	IMAGEMANAGER->addFrameImage("Player_Idel", "myth_run.bmp", 1710, 268, 15, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Player_Jump", "myth_jump.bmp", 550, 387, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Player_WallCatch", "myth_wallcatch.bmp", 1004, 309, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Player_DownJump", "myth_downJump.bmp", 224, 501, 3, 2, true, RGB(255, 0, 255));

	/* 플레이어 기타 설정 (인덱스, 초기 상태, 이미지, 초기 이미지 출력) */
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
	/* 오른쪽 이동상태 */
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !_player._keyLock)
	{
		_state = RIGHT_RUN;
		_player.x += _player._speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state = RIGHT_IDLE;
	}

	/* 왼쪽 이동상태 */
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !_player._keyLock)
	{
		_state = LEFT_RUN;
		_player.x -= _player._speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = LEFT_IDLE;
	}

	/* 점프 시 인덱스 값, 중력(점프) 설정 */
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

	/* 하단 점프 */
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
	/* 점프 상태 */
	if (_player._isJump || _player_gravity)
	{
		_player.y -= _player._jumpPower;
		_player._jumpPower -= _player._gravity;
	}

	/* 벽 잡은 상태 */
	if (_player._isGrap) 
	{
		_player._keyLock = true;
		_player._jumpPower = 0;
		_player._gravity = 0;
	}

	/* 플레이어 위치 연산 */
	_player.player = RectMakeCenter(_player.x, _player.y, 110, 140); 	

	/* 충돌 처리 */
	On_Screen();		/* 화면 내에서만 이동 */
	Above_Land_Obj();	/* 스테이지 땅 & 장애물 위에 있을 경우 처리 */
	Obj_Grap();			/* 스테이지 장애물 벽 잡기 */
}

void playGround::Player_Frame()
{
	_count++;

	if (_count % 9 == 0)
	{
		/* 오른쪽 기본 상태 */
		if (_state == RIGHT_IDLE)
		{
			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);
			_index++;

			if (_index >= 4) _index = 0;
		}

		/* 왼쪽 기본 상태 */
		if (_state == LEFT_IDLE)
		{
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);
			_index--;

			if (_index <= 10) _index = _player_img->getMaxFrameX();
		}

		/* 오른쪽 달리는 상태 */
		if (_state == RIGHT_RUN)
		{

			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);
			_index++;

			if (_index >= _player_img->getMaxFrameX()) _index = 6;
		}

		/* 왼쪽 달리는 상태 */
		if (_state == LEFT_RUN)
		{
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);
			_index--;

			if (_index <= 0) _index = 7;
		}

		/* 오른쪽 점프 상태 */
		if (_state == RIGHT_JUMP)
		{
			_player_img = IMAGEMANAGER->findImage("Player_Jump");
			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);

			if (_index >= 0) _index++;
		}

		/* 왼쪽 점프 상태 */
		if (_state == LEFT_JUMP)
		{
			_player_img = IMAGEMANAGER->findImage("Player_Jump");
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);

			if (_index > 0) _index--;
		}

		/* 오른쪽 벽 잡기 상태 */
		if (_state == RIGHT_WALLCATCH)
		{
			_player_img = IMAGEMANAGER->findImage("Player_WallCatch");
			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);
			_index++;

			if (_index >= _player_img->getMaxFrameX()) _index = 0;
		}

		/* 왼쪽 벽 잡기 상태 */
		if (_state == LEFT_WALLCATCH)
		{
			_player_img = IMAGEMANAGER->findImage("Player_WallCatch");
			_player_img->setFrameY(1);
			_player_img->setFrameX(_index);
			_index--;

			if (_index <= 0) _index = _player_img->getMaxFrameX();
		}

		/* 오른쪽 하단 점프 상태 */
		if (_state == RIGHT_DOWNJUMP)
		{
			_player_img = IMAGEMANAGER->findImage("Player_DownJump");
			_player_img->setFrameY(0);
			_player_img->setFrameX(_index);
			_index++;

			if (_index >= _player_img->getMaxFrameX()) _index = 0;
		}

		/* 왼쪽 하단 점프 상태 */
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
	/* 벽 못나가게 (순서 왼, 오) */
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
	/* 스테이지 땅 위에 있을 경우 처리 */
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

	/* 스테이지 장애물 위에 있을 경우 처리 */
	for (int i = 0; i < 3; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_stage1_obj_bridge[i], &_player.player))
		{
			if (i == 0)
			{
				_player._isDownJump = false;
			}

			// 벽 왼쪽 충돌
			if (_stage1_obj_bridge[i].left > _player.x)
			{
				_player.x = _stage1_obj_bridge[i].left - 55;
			}

			// 벽 오른쪽 충돌
			if (_stage1_obj_bridge[i].right < _player.x)
			{
				_player.x = _stage1_obj_bridge[i].right + 55;
			}

			// 벽 위 충돌
			if (_stage1_obj_bridge[i].top > _player.y &&
				_stage1_obj_bridge[i].left < _player.x && _stage1_obj_bridge[i].right > _player.x)
			{
				_player._jumpCount = 0;
				_player._jumpPower = 0.0f;
				_player.y = _stage1_obj_bridge[i].top - 70;
				_player._isJump = false;

				// 올라오고 난 후 IDEL 이미지 출력을 위한 호출 및 상태 정의
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

			// 하단 점프
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
	/* 스테이지 장애물 벽 잡기 */
	if (_player._jumpPower <= 0)
	{
		for (int i = 0; i < 3; i++)
		{
			// 왼쪽 모서리
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

			// 오른쪽 모서리
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

			// 그 외 (못잡은 상황)
			else
			{
				_player._isGrap = false;
			}
		}
	}
}

void playGround::draw_BackGroud(HDC hdc)
{
	/* 배경화면 출력 */
	IMAGEMANAGER->render("Stage1", hdc, 0, 0);
}

void playGround::draw_Stage1_Land_Obj(HDC hdc)
{
	/* 땅 출력 */
	Rectangle(hdc, _stage1_obj_land); 	

	/* 장애물 출력 */
	for (int i = 0; i < 3; i++)
	{
		Rectangle(hdc, _stage1_obj_bridge[i]);
		IMAGEMANAGER->render("Stage1_bridge", hdc, _stage1_obj_bridge[i].left, _stage1_obj_bridge[i].top);
	}
}

void playGround::draw_Player(HDC hdc)
{
	/* 플레이어 출력 */
	Rectangle(hdc, _player.player);
	_player_img->frameRender(hdc, _player.player.left, _player.player.top);
}