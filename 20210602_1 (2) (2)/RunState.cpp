#include "stdafx.h"
#include "Player.h"
#include "IdelState.h"
#include "RunState.h"

State* RunState::inputHandle(Player* player)
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		return new IdelState();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		return new IdelState();
	}
	return nullptr;
}

void RunState::update(Player* player)
{
}

void RunState::enter(Player* player)
{
	// �̹����� �ҷ�������~
	//player->img = IMAGEMANAGER->findImage("X");
	return;
}

void RunState::exit(Player* player)
{
}
