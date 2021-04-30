#pragma once
#include "gameNode.h"

struct tagBox
{
	RECT rc;
	bool isJoker;
	bool isCheck;
};

class playGround : public gameNode
{
private:
	// ÀÌ
	tagBox _box1[20];
	
	// ¾ó±¼
	RECT Alligator_Mouse;
	RECT Alligator_Face1;
	RECT Alligator_Face2;
	RECT Alligator_Face3;
	
	// ½Ã°£
	int time;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};

