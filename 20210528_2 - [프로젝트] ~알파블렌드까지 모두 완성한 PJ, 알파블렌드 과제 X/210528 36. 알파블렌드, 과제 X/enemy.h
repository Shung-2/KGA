#pragma once
#include "gameNode.h"
// ## 210528 Unique progreessBar ##
#include "progressBar.h"

class enemy : public gameNode
{
protected:
	image* _imageName;		// 적 이미지
	RECT _rc;				// 적 렉트

	int _currentFrameX;		// 프레임번호로 사용할 변수 (X)
	int _currentFrameY;		// 프레임번호로 사용할 변수 (Y)

	int _count;				// 프레임 렌더링 용
	int _fireCount;			// 발사 카운트 용
	int _rndFireCount;		// 랜덤 발사 카운트 용

	// ## 210528 ufo move, boss ##
	int _x, _y;
	// ## 210528 Unique progreessBar ##
	progressBar* _hpBar;
	float _currentHP;
	float _maxHP;

public:
	enemy() {};
	~enemy() {};

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position, float hp);
	virtual void relase();
	virtual void update();
	virtual void render();

	void move(int MoveToX, int MoveToY);
	void draw();

	bool bulletCountFire();

	inline RECT getRect() { return _rc; }

	// ## 210528 Unique progreessBar ##
	float getHP() { return _currentHP; }
	void hitDamage(float damage);
};