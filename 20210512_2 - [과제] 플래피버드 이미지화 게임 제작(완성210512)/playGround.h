#pragma once
#include "gameNode.h"
#define PIPEMAX 3

struct tagPipe
{
	RECT top;
	RECT bottom;
	RECT score;
	bool _isCrash;
};

class playGround : public gameNode
{
private:
	// 초기화
	/* 게임 시스템 초기화 */
	bool _isGameStart;			// 게임 스타트 여부
	bool _isGameOver;			// 게임 종료 여부
	int _score1;				// 점수 (일의 자리 숫자)
	int _score10;				// 점수 (십의 자리 숫자)
	char _strNum[100];			// 점수 그림 초기화 시 필요한 변수 선언
	image* _num[10];			// 숫자 이미지
	image* _background;			// 배경 이미지 (낮)
	image* _background_night;	// 배경 이미지 (밤)
	bool _background_change;	// 배경 이미지 바뀜 설정
	RECT _land;					// 땅
	image* _landimg;			// 땅 이미지

	// 플레이어 초기화
	RECT _player;				// 플레이어
	image* _playerimg;			// 플레이어 이미지
	float _x, _y;				// 플레이어 X, Y 값
	float _jumpPower;			// 플레이어 점프 힘
	float _gravity;				// 플레이어 중력
	bool _isJump;				// 플레이어 점프 유무 상태

	// 파이프 초기화
	tagPipe _pipe[PIPEMAX];		// 파이프
	int _rndY;					// 파이프 랜덤 출력을 위한 변수 선언
	image* _pipe_top_image;		// 파이프 위 이미지
	image* _pipe_bottom_image;	// 파이프 아래 이미지

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

};