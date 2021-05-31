#pragma once
#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>
// ## 210528 ufo move, boss ##
#include "boss.h"

// ��ȣ ������ ���� Ŭ���� ���漱��
class spaceShip;

class enemyManager : public gameNode
{
private:
	// �� ������ �̴Ͼ��� �ƴ� enemy�� ������?
	// �ؾ Ʋ�� enemy.
	// enemy�� ���� minion1, minion2, BOSS�� ���� �ȴ�.
	// �̵��� ���� �θ�� ��� �����ϱ� enemy * �� ����ϸ� ��θ� �� ������ �ֱ� ������ enemy*�� ����Ѵ�
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;
	bullet* _bullet;

	// ## 210528 ufo move, boss ##
	int _MoveTick;
	int _ChangeMoveTick;
	int _stage;
	enemy* _boss;

	// ������ �Ҵ���� ���� �� ������
	spaceShip* _ship;

public:
	enemyManager() {};
	~enemyManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setMinion();	
	void minionBulletFire();

	// �̴Ͼ��� �����ϴ� �Լ�
	void removeMinion(int arrNum);
	void collision();

	// ## 210528 ufo move, boss ##
	void MoveMinion();
	void initBoss();
	void hitDamage(int _idx, float damage);

	// ���� �������ε� �Լ� �̸��� �׷����� ����
	// �޸� �ּҸ� �������ִ� �Լ� (������). (spaceShip*�� �Ű������� �Ѱ��༭ �־��ش�. ���漱�� �� �� �����⿡)
	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _ship = ship; } 

	vector<enemy*> getVMinion() { return _vMinion; }
	vector<enemy*>::iterator getVIMinion() { return _viMinion; }
};