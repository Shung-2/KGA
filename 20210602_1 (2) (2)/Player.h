#pragma once
#include "gameNode.h"
//#include "Stage1.h"
#include "State.h"

//enum PLAYER_STATE
//{
//	/* IDEL */
//	RIGHT_IDLE,
//	LEFT_IDLE,
//
//	/* RUN */
//	RIGHT_RUN,
//	LEFT_RUN,
//
//	/* JUMP */
//	RIGHT_JUMP,
//	LEFT_JUMP,
//
//	/* DOWN JUMP */
//	RIGHT_DOWNJUMP,
//	LEFT_DOWNJUMP
//};

struct tagPlayer
{
	image* _Player_img;
	RECT _Player;
	RECT _Collision;
	float _x, _y;
	float _speed;
	float _gravity;
	float _jump_Power;
	int _jump_Count;

	bool _is_Jump;
	bool _is_Down_Jump;
};

class Player : public gameNode
{
private:
	tagPlayer _player;

	//PLAYER_STATE _state;

	bool _player_gravity;
	int _Frame_Count, _Frame_Index;

	//Stage1* _Stage1

public:
	void InputHandle();
	State* _state;

	Player();
	~Player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//void setStageAddressLink(Stage1* st1) { _Stage1 = st1; }
	tagPlayer* getTagPlayer() { return &_player; }
	
	/* Init */
	void set_Player();

	/* Update */
	void get_Player_Key();
	void get_Player_Move();

	/* Collision */
	void On_Screen();
};