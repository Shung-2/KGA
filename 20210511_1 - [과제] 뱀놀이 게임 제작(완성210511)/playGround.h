#pragma once
#include "gameNode.h"
#define SNAKEBODY 50

// 1번 작품
/*
struct tagSnack_HEAD
{
	float x, y;
	float radius;
	float angle;
	float speed;
};
struct tagSnack_BODY
{
	float x, y;
	float radius;
	float angle;
};
*/

// 2번 작품 (선생님 + 나)
struct tagSnake
{
	float x, y;
	float angle;
	float radius;
	float speed;
};

class playGround : public gameNode
{
private:
	// 1번 작품
	/*
	tagSnack_HEAD _head;
	tagSnack_BODY _body[SNAKEBODY];
	*/

	// 2번 작품 (선생님 + 나)
	tagSnake _snake[SNAKEBODY];

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	// 1번 작품
	/*
	void move();
	void crash();
	*/

	// 2번 작품 (선생님 + 나)
	void snackMove();
};

