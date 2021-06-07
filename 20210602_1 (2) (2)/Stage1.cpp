#include "stdafx.h"
#include "Stage1.h"

Stage1::Stage1()
{

}

Stage1::~Stage1()
{
}

HRESULT Stage1::init()
{
	IMAGEMANAGER->addImage("Stage 1 BG", "cnx/! stage/bg/stgb01.CNX.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_Stage1_Obj[0] = RectMake(110, 275, 580, 75);
	_Stage1_Obj[1] = RectMake(65, 555, 700, 75);
	_Stage1_Obj[2] = RectMake(900, 150, 650, 75);
	_Stage1_Obj[3] = RectMake(975, 430, 550, 75);

	_Stage1_Rand[0] = RectMake(0, WINSIZEY - 60, WINSIZEX, 75);
	
	_Player = new Player;
	_Player->init();

	return S_OK;
}

void Stage1::release()
{
	SAFE_DELETE(_Player);
}

void Stage1::update()
{
	_Player->update();



	if (_Player->getTagPlayer()->_Player.bottom >= _Stage1_Rand[0].top &&
		_Player->getTagPlayer()->_Player.top <= _Stage1_Rand[0].top)
	{
		_Player->getTagPlayer()->_is_Jump = false;
		_Player->getTagPlayer()->_jump_Count = 0;
		_Player->getTagPlayer()->_y = _Stage1_Rand[0].top - 30;
		//_Player->getTagPlayer()->_gravity = 0.0f;
		_Player->getTagPlayer()->_y = -350;
		//_Player->getTagPlayer()->_jump_Power = 0.0f;
		
	}
}

void Stage1::render()
{
	IMAGEMANAGER->findImage("Stage 1 BG")->render(getMemDC());

	for (int i = 0; i < 4; i++)
	{
		Rectangle(getMemDC(), _Stage1_Obj[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		Rectangle(getMemDC(), _Stage1_Rand[i]);
	}

	_Player->render();
}