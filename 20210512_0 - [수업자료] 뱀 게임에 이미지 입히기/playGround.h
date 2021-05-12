#pragma once
#include "gameNode.h"

#define SNAKEBODY 50

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
	tagSnake _snake[SNAKEBODY];
	image* _background;
	image* _horse;
	image* _bird;
	image* _mandarin;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	
	void snakeMove();
};

