#pragma once
#include "gameNode.h"

// BOARD
#define BOARDW	800
#define BOARDH	450
#define ERRORW	18
#define ERRORH	15
#define FRICT	0.15f
#define GOAL	222

// PLAYER
#define PSIZE	60
#define PSPEED	5

// BALL
#define BSIZE	40
#define BSPEED	PSPEED * 4

// SCORE
#define SCOREW	70
#define SCOREH	100

struct board
{
	image* img;
	RECT body;
	float x, y;
	float friction;
	float goalpost;
};

struct player
{
	image* img;
	RECT body;
	float x, y;
	float speed;
	int score;
};

struct ball
{
	image* img;
	RECT body;
	float x, y;
	float speed;
	float angle;
	bool onBoard;
};

enum user
{
	ALL,
	P1,
	P2
};

class playGround : public gameNode
{
private:

	/* ���� */
	board _board;

	/* �÷��̾� */
	player _player1;
	player _player2;

	/* �� */
	ball _ball;

	/* ���ھ� */
	image* _score1;
	image* _score2;

	/* ���� ���� */
	bool _isStart, _isEnd;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	/* �ʱ�ȭ */
	void setBoard();
	void setPlayer();
	void setBall();
	void setScore();

	/* ���� */
	void Player_Key(int player);

	/* �� */
	void makeBall();
	void MoveBall();
	void colWithBoard();
	bool colWithPlayer();

	/* ���� ���� */
	bool isEnd();

	/* �׸��� */
	void drawBoard(HDC hdc);
	void drawPlayer(HDC hdc);
	void drawBall(HDC hdc);
	void drawScore(HDC hdc);
	void drawResult(HDC hdc);

	/* ����ó�� */
	void onBoard(int player);

};