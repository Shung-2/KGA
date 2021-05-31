#pragma once
#include "gameNode.h"
#include "spaceShip.h"
#include "enemyManager.h"
// ## 210527 ���� ���� Save&Load, Loop Render ##
#include "saveLoadTest.h"

class playGround : public gameNode
{
private:
	spaceShip* _ship;
	enemyManager* _em; 
	// ## 210527 ���� ���� Save&Load, Loop Render ##
	saveLoadTest* _slt;
	int _loopX, _loopY; 
	// ## 210528 ���� ���� Alpha ���� ##
	int _fadeIn, _fadeOut;
	bool _isChange;
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void collision();
};