#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("bullet", 30, 700);

	// ## 210528 ufo move, boss ##
	_MoveTick = 1;
	_ChangeMoveTick = 30;
	_stage = 1;

	// 다른 애가 동적할당 되는 거임
	// _ship = new spaceShip;

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	// ## 210528 ufo move, boss ##
	_ChangeMoveTick++;
	// MoveTick을 음수로 바꿔 방향을 전환하기 위한 함수
	if (_ChangeMoveTick == 100)
	{
		_MoveTick *= -1;
		_ChangeMoveTick = 0;
	}

	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	minionBulletFire();
	_bullet->update();

	// 적 미니언을 다 잡으면 다시 소환하는 함수
	//if (_vMinion.size() == 0) setMinion();
	
	// 2번 방식 (1번 방식은 playGround Update에 있다.)
	collision();

	// ## 210528 ufo move, boss ##
	MoveMinion();
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
			_bullet->fire((rc.left + rc.right) / 2, rc.bottom + 5, -(PI / 2), 7.0f);

			// 유도탄
			//_bullet->fire((rc.left + rc.right) / 2,
			//	rc.bottom + 5,
			//	getAngle((rc.left + rc.right) / 2, rc.bottom,
			//		_ship->getShipImage()->getCenterX(),
			//		_ship->getShipImage()->getCenterY()),
			//	7.0f);
		}
	}
}

void enemyManager::removeMinion(int arrNum)
{
	_vMinion.erase(_vMinion.begin() + arrNum);
	
	// ## 210528 ufo move, boss ##
	// 몬스터를 다 잡을 때 스테이지를 올리며, 미니언과 보스를 소환하는 곳
	// 만약 _vMinion.size()이 0이면 (적 ufo를 다 잡을 때)
	if (_vMinion.size() == 0) 	
	{
		if (_stage == 1)
		{
			setMinion();
		}
		_stage++;
		if (_stage == 3)
		{
			initBoss();
		}
	}
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

// ## 210528 ufo move, boss ##
void enemyManager::MoveMinion()
{
	int MoveX = 0, MoveY = 0;
	switch (_stage)
	{
	case 1:
		MoveX = 1;
		break;
	case 2:
		MoveY = 1;
		break;
	}
	for (int i = 0; i < _vMinion.size(); i++)
	{
		_vMinion[i]->move(MoveX * _MoveTick, MoveY * _MoveTick);
	}
}

// ## 210528 ufo move, boss ##
void enemyManager::initBoss()
{
	_boss = new boss();
	_boss->init("boss", PointMake(WINSIZEX / 2, -50));
	_vMinion.push_back(_boss);
}