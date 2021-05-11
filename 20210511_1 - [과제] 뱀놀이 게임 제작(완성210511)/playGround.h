#pragma once
#include "gameNode.h"
#define SNAKEBODY 50

// 1�� ��ǰ
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

// 2�� ��ǰ (������ + ��)
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
	// 1�� ��ǰ
	/*
	tagSnack_HEAD _head;
	tagSnack_BODY _body[SNAKEBODY];
	*/

	// 2�� ��ǰ (������ + ��)
	tagSnake _snake[SNAKEBODY];

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	// 1�� ��ǰ
	/*
	void move();
	void crash();
	*/

	// 2�� ��ǰ (������ + ��)
	void snackMove();
};

