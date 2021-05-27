#pragma once
#include "gameNode.h"
#include "spaceShip.h"
#include "enemyManager.h"

class playGround : public gameNode
{
private:
	spaceShip* _ship;
	enemyManager* _em; 
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};