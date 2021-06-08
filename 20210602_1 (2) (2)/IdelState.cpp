#include "stdafx.h"
#include "Player.h"
#include "IdelState.h"
#include "RunState.h"

State* IdelState::inputHandle(Player* player)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) || KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		return new RunState();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		return new RunState();
	}

	return nullptr;
}

void IdelState::update(Player* player)
{
	// 이미지 프레임, 이 상태에서 연산이 필요한 것들
	// player->getTagPlayer()->_player_img->frameRender(getMemDC(), _player._Player.left, _player._Player.top);
	// _player._player_img->frameRender(getMemDC(), _player._Player.left, _player._Player.top);
	
	frameCount++;
	if (frameCount >= 8)
	{
		frameCount = 0;
		if (player->getTagPlayer()->_Player_img->getFrameX() >=
			player->getTagPlayer()->_Player_img->getMaxFrameX())
		{
			player->getTagPlayer()->_Player_img->setFrameX(0);
		}
		player->getTagPlayer()->_Player_img->setFrameX(player->getTagPlayer()->_Player_img->getFrameX() + 1);
		player->getTagPlayer()->_Player_img->setFrameY(0);
	}




	//if (_state == RIGHT_IDLE)
	//{
	//	_player_img->setFrameY(0);
	//	_player_img->setFrameX(_index);
	//	_index++;
	//	if (_index >= 4) _index = 0;
	//}

	//if (!player->_direction) //플레이어에서 방향을 가져옴.
	//{
	//	frameCount++;
	//	if (frameCount >= 10) {
	//		frameCount = 0;
	//		if (player->img->getFrameX() >= player->img->getMaxFrameX()) {
	//			player->img->setFrameX(0);
	//		}
	//		player->img->setFrameX(player->img->getFrameX() + 1);
	//		player->img->setFrameY(0);
	//	}
	//}
}

void IdelState::enter(Player* player)
{
	player->getTagPlayer()->_Player_img = IMAGEMANAGER->findImage("PLAYER IDEL");
	return;
}

void IdelState::exit(Player* player)
{
}
