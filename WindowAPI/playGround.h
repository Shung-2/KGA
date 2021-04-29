#pragma once
#include "gameNode.h"

// 210428 API 수업 2 (눈)
/*
#define SNOWMAX 40
*/

// 210428 API 수업 2 (눈)
/* 
struct tagSnow
{
	RECT rc;
	int speed;
};
*/

// #define PIPEMAX 1

class playGround : public gameNode
{
private:
	// 210428 API 수업 1
	/*
	RECT _rc;
	float _speed;
	bool _isCrash;
	*/

	// 210428 API 수업 2 (눈)
	/*
	RECT _player;
	tagSnow _snow[SNOWMAX];
	bool _isStart;
	*/

	// 210428 API 수업 3 (플래피버드)
	/* 
	RECT _player;
	RECT _pipe1;
	RECT _pipe2;
	RECT _pipe3;

	float _x, _y;

	float _jumpPower;			// 점프 강도
	float _gravity;				// 중력
	bool _isJump;				// 점프 상태
	int _score;					// 스코어
	float _speed = 3;
	bool _isStartSate;
	*/

	// 210429 API 수업 1
	RECT _rc;
	int _count;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};

