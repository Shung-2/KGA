#include "stdafx.h"
#include "Player.h"
#include "IdelState.h"

void Player::InputHandle()
{
	State* newState = _state->inputHandle(this);
	if (newState != nullptr)
	{
		SAFE_DELETE(_state);
		_state = newState;
		_state->enter(this);
	}
}

Player::Player()
{
}

Player::~Player()
{
}

HRESULT Player::init()
{
	_state = new IdelState();
	_state->enter(this);
	
	/* INIT */
	set_Player();

	_player._Player_img = new image;
	_player._Player_img = IMAGEMANAGER->findImage("PLAYER IDEL");

	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	InputHandle();
	_state->update(this);

	/* UPDATE */
	get_Player_Key();
	get_Player_Move();
	
	/* COLLISION */
	On_Screen();

	/* RE_RENDER */
	_player._Player = RectMakeCenter(_player._x, _player._y, 30, 65);
}

void Player::render()
{
	_player._Player_img->frameRender(getMemDC(), _player._Player.left, _player._Player.top);
	//Rectangle(getMemDC(), _player._Player);
}

void Player::set_Player()
{
	_player._Player = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY / 2 + 360, 30, 65);
	_player._x = (_player._Player.right + _player._Player.left) / 2;
	_player._y = (_player._Player.bottom + _player._Player.top) / 2;
	_player._speed = 5;
	_player._jump_Count = 0;
	_player_gravity = false;
	_player._is_Down_Jump = false;

	_Frame_Index = 0;

	/* PLAYER IMAGE */
	IMAGEMANAGER->addFrameImage("PLAYER IDEL", "cnx/! player/bmp/idel.bmp", 160, 132, 4, 2, true, RGB(255, 0, 255));

}

void Player::get_Player_Key()
{
	/* RIGHT MOVE */
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player._x += _player._speed;
	}

	/* LEFT MOVE */
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player._x -= _player._speed;
	}

	/* DOWN JUMP */
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (KEYMANAGER->isOnceKeyDown(0x58) && !_player._is_Jump)
		{
			_player._is_Jump = true;
			_player._is_Down_Jump = true;
			_player._jump_Count = 0.0f;
			_player._jump_Power = 0.0f;
			_player._gravity = 0.5f;
		}
	}

	/* JUMP */
	if (KEYMANAGER->isOnceKeyDown(0x58) && _player._jump_Count <= 0)
	{
		_player._jump_Count++;
		_player._gravity = 0.5f;
		_player._jump_Power = 20.0f;
		_player._is_Jump = true;
		_player_gravity = true;
	}
}

void Player::get_Player_Move()
{
	/* JUMP-ING STAGE*/
	if (_player._is_Jump || _player_gravity)
	{
		_player._y -= _player._jump_Power;
		_player._jump_Power -= _player._gravity;
	}
}

void Player::On_Screen()
{	
	/* SCREEN LOCK */
	/* LEFT */
	if (_player._x < 0)
	{
		_player._x += _player._speed;
	}

	/* RIGHT */
	if (_player._x > WINSIZEX)
	{
		_player._x -= _player._speed;
	}

	/* UP */
	if (_player._y < 0)
	{
		_player._y -= _player._jump_Power;
	}
}
