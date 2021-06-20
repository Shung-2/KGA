#include "stdafx.h"
#include "soundTestScene.h"


soundTestScene::soundTestScene()
{
}


soundTestScene::~soundTestScene()
{
}

HRESULT soundTestScene::init()
{
	SOUNDMANAGER->addSound("BTS", "BTS-Butter.mp3", true, true);
	SOUNDMANAGER->addSound("BTS2", "BTS-Butter.mp3", true, true);
	SOUNDMANAGER->addSound("��Ż", "��Ż2�ͷ������.mp3", true, false);

	return S_OK;
}

void soundTestScene::release()
{
}

void soundTestScene::update()
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		SOUNDMANAGER->play("BTS", 1.0f);
	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		SOUNDMANAGER->stop("BTS");
	}
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		SOUNDMANAGER->pause("BTS");
	}
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		SOUNDMANAGER->resume("BTS");
	}

	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		SOUNDMANAGER->play("BTS2", 0.5f);
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		SOUNDMANAGER->stop("BTS2");
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		SOUNDMANAGER->pause("BTS2");
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		SOUNDMANAGER->resume("BTS2");
	}

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		SOUNDMANAGER->play("��Ż", 0.5f);
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		SOUNDMANAGER->stop("��Ż");
	}
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		SOUNDMANAGER->pause("��Ż");
	}
	if (KEYMANAGER->isOnceKeyDown('V'))
	{
		SOUNDMANAGER->resume("��Ż");
	}
}

void soundTestScene::render()
{
}
