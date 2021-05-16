#pragma once
#include "gameNode.h"

#define PI 3.141592;

struct tagCircle
{
	float x, y;		// X축용, Y축용 변수 초기화
	float angle;	// 각도 초기화
	float radius;	// 반지름 초기화
	float speed;	// 속도 초기화
};

class playGround : public gameNode
{
private:
	tagCircle _player;	// tagCircle을 이용하는 _player 생성
	tagCircle _enemy;	// tagCircle을 이용하는 _enemy 생성
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};