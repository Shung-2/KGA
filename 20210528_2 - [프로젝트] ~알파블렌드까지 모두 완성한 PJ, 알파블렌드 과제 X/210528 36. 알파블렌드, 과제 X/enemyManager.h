#pragma once
#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>
// ## 210528 ufo move, boss ##
#include "boss.h"

// 상호 참조를 위한 클래스 전방선언
class spaceShip;

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

	// ## 210528 ufo move, boss ##
	int _MoveTick;
	int _ChangeMoveTick;
	int _stage;
	enemy* _boss;

	// 아직은 할당되지 않은 빈 포인터
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

	// 미니언을 제거하는 함수
	void removeMinion(int arrNum);
	void collision();

	// ## 210528 ufo move, boss ##
	void MoveMinion();
	void initBoss();
	void hitDamage(int _idx, float damage);

	// 단지 설정자인데 함수 이름이 그럴싸함 주의
	// 메모리 주소를 연결해주는 함수 (설정자). (spaceShip*를 매개변수로 넘겨줘서 넣어준다. 전방선언 된 빈 껍데기에)
	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _ship = ship; } 

	vector<enemy*> getVMinion() { return _vMinion; }
	vector<enemy*>::iterator getVIMinion() { return _viMinion; }
};