#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

HRESULT Player::init()
{
	_player._Player = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY / 2 + 360, 30, 65);
	_player._x = (_player._Player.right + _player._Player.left) / 2;
	_player._y = (_player._Player.bottom + _player._Player.top) / 2;
	_player._speed = 5;
	_player._jump_Count = 0;
	_player_gravity = false;
	_player._is_Down_Jump = false;

	//_Frame_Index = 0;
	//_state = RIGHT_IDLE;
	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player._x += _player._speed;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player._x -= _player._speed;
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_player._jump_Count++;
		_player._gravity = 0.5f;
		_player._jump_Power = 10.0f;
		_player._is_Jump = true;
	}

	if (_player._is_Jump)
	{
		_player._y -= _player._jump_Power;
		_player._jump_Power -= _player._gravity;
	}

	_player._Player = RectMakeCenter(_player._x, _player._y, 30, 65);
}

void Player::render()
{
	Rectangle(getMemDC(), _player._Player);
}