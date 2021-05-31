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

	// �ٸ� �ְ� �����Ҵ� �Ǵ� ����
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
	// MoveTick�� ������ �ٲ� ������ ��ȯ�ϱ� ���� �Լ�
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

	// �� �̴Ͼ��� �� ������ �ٽ� ��ȯ�ϴ� �Լ�
	//if (_vMinion.size() == 0) setMinion();
	
	// 2�� ��� (1�� ����� playGround Update�� �ִ�.)
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
		// � �̴Ͼ������� �𸣰����� ��¶�� �� �̴Ͼ��� ������ �ִ� bulletCountFire�� true�̸�
		if ((*_viMinion)->bulletCountFire() == true)
		{
			// �߻� ��ġ�� ����ֱ� ���� �� ��Ʈ�� �����Ѵ�.
			RECT rc = (*_viMinion)->getRect();
			
			// ���� �߻� 
			_bullet->fire((rc.left + rc.right) / 2, rc.bottom + 5, -(PI / 2), 7.0f);

			// ����ź
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
	// ���͸� �� ���� �� ���������� �ø���, �̴Ͼ�� ������ ��ȯ�ϴ� ��
	// ���� _vMinion.size()�� 0�̸� (�� ufo�� �� ���� ��)
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