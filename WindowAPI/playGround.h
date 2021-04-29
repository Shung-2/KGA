#pragma once
#include "gameNode.h"

// 210428 API ���� 2 (��)
/*
#define SNOWMAX 40
*/

// 210428 API ���� 2 (��)
/* 
struct tagSnow
{
	RECT rc;
	int speed;
};
*/

// #define PIPEMAX 1

class playGround : public gameNode
{
private:
	// 210428 API ���� 1
	/*
	RECT _rc;
	float _speed;
	bool _isCrash;
	*/

	// 210428 API ���� 2 (��)
	/*
	RECT _player;
	tagSnow _snow[SNOWMAX];
	bool _isStart;
	*/

	// 210428 API ���� 3 (�÷��ǹ���)
	/* 
	RECT _player;
	RECT _pipe1;
	RECT _pipe2;
	RECT _pipe3;

	float _x, _y;

	float _jumpPower;			// ���� ����
	float _gravity;				// �߷�
	bool _isJump;				// ���� ����
	int _score;					// ���ھ�
	float _speed = 3;
	bool _isStartSate;
	*/

	// 210429 API ���� 1
	RECT _rc;
	int _count;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};

