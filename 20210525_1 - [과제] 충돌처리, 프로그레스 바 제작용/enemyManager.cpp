#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("bullet", 30, 700);

	// 다른 애가 동적할당 되는 거임
	// _ship = new spaceShip;

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

	// 적 미니언을 다 잡으면 다시 소환하는 함수
	// if (_vMinion.size() == 0) setMinion();
	
	// 2번 방식 (1번 방식은 playGround Update에 있다.)
	collision();
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
			
			// 수직 발사 
			// _bullet->fire((rc.left + rc.right) / 2, rc.bottom + 5, -(PI / 2), 7.0f);

			// 유도탄
			_bullet->fire((rc.left + rc.right) / 2,
				rc.bottom + 5,
				getAngle((rc.left + rc.right) / 2, rc.bottom,
					_ship->getShipImage()->getCenterX(),
					_ship->getShipImage()->getCenterY()),
				7.0f);
		}
	}
}

void enemyManager::removeMinion(int arrNum)
{
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void enemyManager::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		RECT temp;
		RECT rc = RectMake(_ship->getShipImage()->getX(), _ship->getShipImage()->getY(),
			_ship->getShipImage()->getWidth(), _ship->getShipImage()->getHeight());

		if (IntersectRect(&temp, &_bullet->getVBullet()[i].rc, &rc))
		{
			_ship->hitDamege(10.0f);
			_bullet->removeBullet(i);
			break;
		}
	}
}