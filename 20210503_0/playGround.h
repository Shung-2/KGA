#pragma once
#include "gameNode.h"

#define BULLETMAX 30

struct tagBullet
{
	int x, y;		//총알 중점용
	RECT rc;		//총알 렉트
	int speed;		//총알 스피드
	bool isFire;	//발사 됐누?
};

class playGround : public gameNode
{
private:
	RECT _player;
	RECT _player2;

	RECT _backGauge;
	RECT _frontGauge;
	int _r, _g;
	
	
	tagBullet _bullet[BULLETMAX];
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void bulletFire();	//총알 발사하는 함수
	void bulletMove();	//총알 움직이는 함수

	void setGauge();
};

