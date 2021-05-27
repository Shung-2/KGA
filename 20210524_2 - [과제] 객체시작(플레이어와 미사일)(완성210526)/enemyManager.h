#pragma once
#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>

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

public:
	enemyManager() {};
	~enemyManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setMinion();
	void minionBulletFire();
};