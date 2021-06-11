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
	/* INIT */
	set_Player();

	_player._Player_img = new image;
	_player._Player_img = IMAGEMANAGER->findImage("PLAYER IDEL");

	_state = new IdelState();
	_state->enter(this);

	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	/* UPDATE */
	get_Player_Key();

	/* COLLISION */
	On_Screen();

	/* 상태 패턴 */
	InputHandle();
	_state->update(this);

	/* RE_RENDER 충돌렉트 & 이미지렉트 */
	_player._rc = RectMakeCenter(_player._x, _player._y, 30, 65);
	_player._rcimg = RectMakeCenter(_player._x, _player._y, 80, 190);
}

void Player::render()
{
	_player._Player_img->frameRender(getMemDC(), _player._rcimg.left, _player._rcimg.top);
	//Rectangle(getMemDC(), _player._rc);
}

void Player::set_Player()
{
	_player._rc = RectMakeCenter(WINSIZEX / 2 - 200, WINSIZEY / 2 + 260, 30, 65);
	_player._x = (_player._rc.right + _player._rc.left) / 2;
	_player._y = (_player._rc.bottom + _player._rc.top) / 2;
	_player._speed = 5;
	_player._jumpCount = 0;
	_player._grvity = 0.5f;

	_player._isJump = false;
	_player._isDownJump = false;
	_player._dir = true;
	_player._isLanding = false;

	/* PLAYER IMAGE */
	IMAGEMANAGER->addFrameImage("PLAYER IDEL", "cnx/! player/bmp/idel.bmp", 320, 264, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PLAYER RUN", "cnx/! player/bmp/run.bmp", 1188, 268, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PLAYER JUMP", "cnx/! player/bmp/jump.bmp", 500, 352, 5, 2, true, RGB(255, 0, 255));

}

void Player::get_Player_Key()
{
	/* DOWN JUMP */
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	//{
	//	if (KEYMANAGER->isOnceKeyDown(0x58) && !_player._is_Jump)
	//	{
	//		//_player._is_Jump = true;
	//		_player._is_Down_Jump = true;
	//		//_player._jump_Count = 0;
	//		//_player._jump_Power = 0.0f;
	//		_player._gravity = 0.5f;
	//		_player._jump_Count++;
	//	}
	//}

	// 땅에 닿지 않았을 떄 점프를 할 수 없다...........?????????????????
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
		_player._y -= _player._jumpPower;
	}
}
