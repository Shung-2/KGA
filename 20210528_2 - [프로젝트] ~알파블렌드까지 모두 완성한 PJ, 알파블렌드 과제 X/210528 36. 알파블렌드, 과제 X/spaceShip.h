#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

// ## 210527 수업 내용 Save&Load, Loop Render ##
#pragma warning(disable:4996)

// 1. 컴파일러 무한루프를 빠져나오기 위해
// 2. 빌드 속도를 높이기 위해
// 상호 참조를 위한 클래스 전방 선언
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	hyunMoo* _hm;

	// 얘도 지금은 빈 껍데기에 불과하다.
	enemyManager* _em;

	progressBar* _hpBar;
	float _currentHP, _maxHP;

	// ## 210528 수업 내용 Alpha 블렌드 ##
	int _alphaValue;

public:
	spaceShip();
	~spaceShip();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	// 충돌함수
	void collision();

	// 플레이어 피통을 깍아줍시다.
	void hitDamege(float damage);

	// 단지 설정자인데 함수 이름이 그럴싸함 주의
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	// 현무에 대한 접근자
	hyunMoo* getHyunMoo() { return _hm; }

	// 스페이스쉽 이미지에 대한 접근자를 넘겨주는 것
	image* getShipImage() { return _ship; }
};