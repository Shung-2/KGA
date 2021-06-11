#pragma once
#include "gameNode.h"
#include "State.h"

struct tagPlayer
{
	RECT _rc;
	RECT _rcimg;
	image* _Player_img;

	float _x, _y;
	float _speed;
	float _jumpPower;
	float _jumpCount;
	float _grvity;

	bool _isJump;
	bool _isFall;
	bool _isLanding;
	bool _isDownJump;
	bool _dir;

	/* 
	TRUE  = RIGHT
	FALSE = LEFT
	*/
};

class Player : public gameNode
{
private:
	tagPlayer _player;

public:

	//Stage1* _Stage1;

	void InputHandle();
	State* _state;

	Player();
	~Player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	tagPlayer* getTagPlayer() { return &_player; }	
	

	/* Init */
	void set_Player();

	/* Update */
	void get_Player_Key();

	/* Collision */
	void On_Screen();
};