#include "stdafx.h"
#include "enemyManager.h"

HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("bullet", 30, 700);

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}
	minionBulletFire();
	_bullet->update();
}

void enemyManager::render()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
	_bullet->render();
}

void enemyManager::setMinion()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("enemy", PointMake(80 + j * 80, 80 + i * 100));

			_vMinion.push_back(ufo);
		}
	}
}

void enemyManager::minionBulletFire()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		// 어떤 미니언인지는 모르겠지만 어쨋든 저 미니언이 가지고 있는 bulletCountFire가 true이면
		if ((*_viMinion)->bulletCountFire() == true)
		{
			// 발사 위치를 잡아주기 위해 빈 렉트를 선언한다.
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire((rc.left + rc.right) / 2, rc.bottom + 5, -(PI / 2), 7.0f);
		}
	}
}