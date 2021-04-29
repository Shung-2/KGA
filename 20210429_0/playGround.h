#pragma once
#include "gameNode.h"
#define LANDMAX 3

struct tagland
{
	RECT left;
	RECT Middle;
	RECT right;
	RECT crush;
};

enum State
{
	Idel,
	Fly
};

class playGround : public gameNode
{
private:

	RECT _player; 	// 주인공 선언
	float _x, _y;
	int _rndX;

	tagland _land[LANDMAX]; // 땅 선언
	bool _isGameover;

	float _jumpPower;
	float _gravity;
	bool _isJump;

	int _jumpCount;
	bool _jumpcheck;
	

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};

