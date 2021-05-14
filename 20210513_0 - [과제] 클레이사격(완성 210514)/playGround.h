#pragma once
#include "gameNode.h"

#define BALLMAX 10
#define GAMEOVER_VALUE 5

struct tagBall
{
	float x, y;
	float angle;
	float radius;
	float speed;
	float gravity;
	bool isFire;
};

class playGround : public gameNode
{
private:
	// 초기화
	/* 게임 시스템 초기화 */
	bool _isGameStart;					// 게임 시작 유무
	bool _isGameOver;					// 게임 종료 유무
	int _gameOverCount;					// 게임 오버 카운트
	char _strNum[100];					// 점수 그림 초기화 시 필요한 변수 선언
	int _score1;						// 점수 (일의 자리 숫자)
	int _score10;						// 점수 (십의 자리 숫자)
	image* _background;					// 게임 배경 화면
	image* _num[10];					// 숫자 이미지

	// 피칭머신 & 공 초기화
	RECT _left_PitchingMachine;			// 왼쪽 피칭 머신
	RECT _right_PitchingMachine;		// 오른쪽 피칭 머신

	tagBall _ball[BALLMAX];				// 공
	image* _ballimg;					// 공 이미지
	int _ballRND;						// 공 위치 랜덤 변수
	int _ballFireTimer;					// 공 발사 타이머

	// 사격대
	RECT _launch_Pad;					// 사격대
	image* _launch_Pad_img;				// 사격대 이미지
	RECT _launch_Pad_Zone;				// 사격대 구역

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void ballFire();
	void ballMove();
};