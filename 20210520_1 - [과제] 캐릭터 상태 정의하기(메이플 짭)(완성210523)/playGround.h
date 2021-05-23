#pragma once
#include "gameNode.h"

enum MYTHSTATE
{
	/* IDEL */
	RIGHT_IDLE,
	LEFT_IDLE,

	/* RUN */
	RIGHT_RUN,
	LEFT_RUN,

	/* JUMP */
	RIGHT_JUMP,
	LEFT_JUMP,	

	/* WALL_GRAP */
	RIGHT_WALLCATCH,
	LEFT_WALLCATCH,

	/* DOWN JUMP */
	RIGHT_DOWNJUMP,
	LEFT_DOWNJUMP
};

struct tagPlayer
{
	RECT player;			/* RECT 초기화 */
	float x, y;				/* X/Y 초기화 */
	float _speed;			/* 스피드 초기화 */
	float _gravity;			/* 중력 초기화 */
	float _jumpPower;		/* 점프 세기 초기화 */
	int _jumpCount;			/* 점프 카운트 초기화 */
	bool _isJump;			/* 점프 유무 초기화 */
	bool _isDownJump;		/* 다운 점프 상태 초기화 */
	bool _isGrap;			/* 벽 잡은 상태 초기화 */
	bool _keyLock;			/* 벽 잡은 상태에서 움직임 키 잠금 초기화 */
};

class playGround : public gameNode
{
private:

	image* _background;					// 게임 배경화면 이미지 초기화
	RECT _stage1_obj_land;				// 스테이지 땅 초기화
	RECT _stage1_obj_bridge[3];			// 스테이지 장애물 초기화
	image* _stage1_obj_bridge_img;		// 스테이지 장애물 이미지 초기화

	tagPlayer _player;					// 플레이어 초기화 (PLAYER 선언, 이미지, 상태값, 중력유무(춘춘), 프레임, 프레임(INDEX))
	image* _player_img;
	MYTHSTATE _state;
	bool _player_gravity;
	int _count, _index;

	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	// 초기화(init)
	void set_Background();
	void set_Stage1_Land_Obj();
	void set_Player();

	// 조작
	void get_Background();
	void get_Player_Key();

	// 연산(update)
	void Player_Move();
	void Player_Frame();

	// 충돌
	void On_Screen();
	void Above_Land_Obj();
	void Obj_Grap();

	// 출력(render)
	void draw_BackGroud(HDC hdc);
	void draw_Stage1_Land_Obj(HDC hdc);
	void draw_Player(HDC hdc);
};