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
	IMAGEMANAGER->addImage("Stage 1 BG", "cnx/! stage/bg/final edit stg1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_Stage1_Obj[0] = RectMake(118, 295, 565, 65);
	_Stage1_Obj[1] = RectMake(78, 570, 720, 65);
	_Stage1_Obj[2] = RectMake(880, 140, 675, 65);
	_Stage1_Obj[3] = RectMake(965, 420, 550, 65);

	//_Stage1_Rand[0] = RectMake(0, WINSIZEY - 60, WINSIZEX, 75);
	
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

	/* STAGE1 RAND */
	//if (_Player->getTagPlayer()->_Player.bottom >= _Stage1_Rand[0].top &&
	//	_Player->getTagPlayer()->_Player.top <= _Stage1_Rand[0].top)
	//{
	//	_Player->getTagPlayer()->_is_Jump = false;
	//	_Player->getTagPlayer()->_jump_Count = 0.0f;
	//	_Player->getTagPlayer()->_jump_Power = 0.0f;
	//	_Player->getTagPlayer()->_y = _Stage1_Rand[0].top - 30;
	//}

	/* STAGE1 OBJ*/
	for (int i = 0; i < 4; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_Stage1_Obj[i], &_Player->getTagPlayer()->_Player))
		{
			//if (i == 0)
			//{
			//	_Player->getTagPlayer()->_is_Down_Jump = false;
			//}
			//
			// lEFT
			//if (_Stage1_Obj[i].left > _Player->getTagPlayer()->_x)
			//{
			//	_Player->getTagPlayer()->_x = _Stage1_Obj[i].left - 20;
			//}
			//
			// RIGHT
			//if (_Stage1_Obj[i].right < _Player->getTagPlayer()->_x)
			//{
			//	_Player->getTagPlayer()->_x = _Stage1_Obj[i].right + 20;
			//}

			// UP
			if (_Stage1_Obj[i].top > _Player->getTagPlayer()->_y &&
				_Stage1_Obj[i].left < _Player->getTagPlayer()->_x &&
				_Stage1_Obj[i].right > _Player->getTagPlayer()->_x)
			{
				_Player->getTagPlayer()->_jump_Count = 0.0f;
				_Player->getTagPlayer()->_jump_Power -= 0.01f;
				if (_Player->getTagPlayer()->_jump_Power >= 0) break;
				_Player->getTagPlayer()->_y = _Stage1_Obj[i].top - 30;
				_Player->getTagPlayer()->_is_Jump = false;
				_Player->getTagPlayer()->_jump_Power = 0.0f;
			}

			// DOWN JUMP
			if (_Stage1_Obj[i].top > _Player->getTagPlayer()->_y &&
				_Stage1_Obj[i].left < _Player->getTagPlayer()->_x &&
				_Stage1_Obj[i].right > _Player->getTagPlayer()->_x &&
				_Player->getTagPlayer()->_is_Down_Jump == true)
			{
				_Player->getTagPlayer()->_y = _Stage1_Obj[i].top + 10;
				_Player->getTagPlayer()->_is_Down_Jump = false;
			}
		}		
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