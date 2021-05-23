#pragma once
#include "gameNode.h"

enum MYTHSTATE
{
	RIGHT_IDLE,
	LEFT_IDLE,
	RIGHT_RUN,
	LEFT_RUN
};


class playGround : public gameNode
{
private:
	image* _background;
	image* _player;
	MYTHSTATE _state;

	int _count, _index;

	RECT _miniMap;
	RECT _miniPl;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	
	
};

