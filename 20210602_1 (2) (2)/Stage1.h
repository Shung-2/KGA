#pragma once
#include "gameNode.h"
#include "Player.h"

class Player;

class Stage1 : public gameNode
{
private:
	Player* _Player;
	//Stage1* st;

	RECT _Stage1_Obj[4];
	RECT _Stage1_Rand[3];

public:
	Stage1();
	~Stage1();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayerAddressLink(Player* pl) { _Player = pl; }
	//RECT getRECT_Stage1_Rand() { return _Stage1_Rand[] }
};