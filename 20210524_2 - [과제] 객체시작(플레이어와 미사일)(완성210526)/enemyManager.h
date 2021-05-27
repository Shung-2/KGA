#pragma once
#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>

class enemyManager : public gameNode
{
private:
	// 왜 벡터의 미니언이 아닌 enemy를 넣을까?
	// 붕어빵 틀은 enemy.
	// enemy를 통해 minion1, minion2, BOSS를 찍어내도 된다.
	// 이들은 같은 부모로 찍어 냈으니까 enemy * 를 사용하면 모두를 다 담을수 있기 때문에 enemy*을 사용한다
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