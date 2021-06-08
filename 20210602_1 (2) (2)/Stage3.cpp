#include "stdafx.h"
#include "Stage3.h"

Stage3::Stage3()
{
}

Stage3::~Stage3()
{
}

HRESULT Stage3::init()
{
	IMAGEMANAGER->addImage("Stage 3 BG", "cnx/! stage/bg/final edit stg3.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_Stage3_Obj[0] = RectMake(0, WINSIZEY / 2 + 55, 439, 65);
	_Stage3_Obj[1] = RectMake(WINSIZEX / 2 + 360, WINSIZEY / 2 + 55, 439, 65);
	_Stage3_Obj[2] = RectMake(WINSIZEX / 2 - 78, WINSIZEY / 2 + 123, 155, 65);

	_Stage3_Rand = RectMake(0, WINSIZEY - 60, WINSIZEX, 75);

	_Player = new Player;
	_Player->init();

	return S_OK;
}

void Stage3::release()
{
	SAFE_DELETE(_Player);
}

void Stage3::update()
{
	_Player->update();
	
	/* STAGE2 RAND */

	/* STAGE2 OBJ */
	for (int i = 0; i < 3; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_Stage3_Obj[i], &_Player->getTagPlayer()->_Player))
		{
			// UP
			if (_Stage3_Obj[i].top > _Player->getTagPlayer()->_y &&
				_Stage3_Obj[i].left < _Player->getTagPlayer()->_x &&
				_Stage3_Obj[i].right > _Player->getTagPlayer()->_x)
			{
				_Player->getTagPlayer()->_jump_Count = 0.0f;
				_Player->getTagPlayer()->_jump_Power -= 0.01f;
				if (_Player->getTagPlayer()->_jump_Power >= 0) break;
				_Player->getTagPlayer()->_y = _Stage3_Obj[i].top - 30;
				_Player->getTagPlayer()->_is_Jump = false;
				_Player->getTagPlayer()->_jump_Power = 0.0f;
			}

			// DOWN JUMP
			if (_Stage3_Obj[i].top > _Player->getTagPlayer()->_y &&
				_Stage3_Obj[i].left < _Player->getTagPlayer()->_x &&
				_Stage3_Obj[i].right > _Player->getTagPlayer()->_x &&
				_Player->getTagPlayer()->_is_Down_Jump == true)
			{
				_Player->getTagPlayer()->_y = _Stage3_Obj[i].top + 10;
				_Player->getTagPlayer()->_is_Down_Jump = false;
			}
		}
	}
}

void Stage3::render()
{
	IMAGEMANAGER->findImage("Stage 3 BG")->render(getMemDC());

	/* STAGE3 OBJ ��� */
	for (int i = 0; i < 3; i++)
	{
		Rectangle(getMemDC(), _Stage3_Obj[i]);
	}

	/* STAGE3 RAND ��� */
	Rectangle(getMemDC(), _Stage3_Rand);

	_Player->render();
}
