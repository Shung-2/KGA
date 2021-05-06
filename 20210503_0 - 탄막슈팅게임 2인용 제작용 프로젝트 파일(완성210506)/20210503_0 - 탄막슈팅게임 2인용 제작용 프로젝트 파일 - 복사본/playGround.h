#pragma once
#include "gameNode.h"

#define PLAYER1_BULLETMAX 300
#define PLAYER2_BULLETMAX 300
#define WALL_BULLMAX 600

struct tagBullet
{
	int x, y;		// 총알 중점용
	RECT rc;		// 총알 렉트
	int speed;		// 총알 스피드
	bool isFire;	// 발사 됐누?

	// 210506 추가
	int num;		// 샷건 전용 변수
};

class playGround : public gameNode
{
private:

	// 게임 로직 초기화 & 선언
	bool _isStart;									  // 시작유무
	bool _mapchange;								  // 전장변경

	// 210506 추가
	int _count;										  // 샷건 전용 카운트

	// 플레이어 관련 변수 & 선언
	// Player 1										  
	RECT _player;									  // 플레이어 1 생성
	RECT _player1_backGauge;						  // 플레이어 1 게이지
	RECT _player1_frontGauge;						  // 플레이어 1 게이지
	int _p1_r, _p1_g;								  // 플레이어 1 게이지 (RGB)
	tagBullet _player1_bullet[PLAYER1_BULLETMAX];	  // 플레이어 1 총알 
	RECT _player1_map;								  // 플레이어 1 맵
	int _player1_mode;								  // 플레이어 1 모드
	bool _player1_state;							  // 플레이어 1 상태

	//******************************************************************************

	// Player 2
	RECT _player2;									  // 플레이어 2 생성
	RECT _player2_backGauge;						  // 플레이어 2 게이지
	RECT _player2_frontGauge;						  // 플레이어 2 게이지
	int _p2_r, _p2_g;								  // 플레이어 2 게이지 (RGB)
	tagBullet _player2_bullet[PLAYER2_BULLETMAX];	  // 플레이어 2 총알 
	RECT _player2_map;								  // 플레이어 2 맵
	int _player2_mode;								  // 플레이어 2 모드
	bool _player2_state;							  // 플레이어 2 상태

	//******************************************************************************

	// Wall
	RECT _wall;										  // 벽 생성
	float _wall_speed;								  // 벽 스피드
	bool _wall_change;								  // 벽 방향 전환

	//******************************************************************************

	// P1 4 SK
	RECT _Arbiter;									  // 아비터
	RECT _lockWall;									  // P2를 잠구는 맵
	bool _lockKey;									  // 움직이는 키 상태값
	bool _use4skile;								  // 1번만 나오게 할 수 있는 상태값
	// P2 4 SK
	bool _reverseKey;								  // 키 거꾸로 입력 상태값


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void bulletFire();								  // 총알 발사하는 함수 (P1)
	void bulletFire2();								  // 총알 발사하는 함수 (P2)
	void bulletMove();								  // 총알 움직이는 함수 (P1)
	void bulletMove2();								  // 총알 움직이는 함수 (P2)
	void setGauge();								  // 총알 맞은 경우 변하는 게이지 (P2)
	void setGauge2();								  // 총알 맞은 경우 변하는 게이지 (P1)

	void player1_mode2();							  // Player 1 MODE 2
	void player1_mode2_Move();						  // Player 1 MODE 2 MOVE
	void player2_mode2();							  // Player 2 MODE 2
	void player2_mode2_Move();						  // Player 2 MODE 2 MOVE
	void player1_mode3();							  // Player 1 MODE 3
	void player1_mode3_Move();						  // Player 1 MODE 3 MOVE
	void player2_mode3();							  // Player 2 MODE 3
	void player2_mode3_Move();						  // Player 2 MODE 3 MOVE
	void player1_mode4();							  // Player 1 MODE 4
	void player1_mode4_Move();						  // Player 1 MODE 4 MOVE
	void player2_mode4();							  // Player 2 MODE 4
};