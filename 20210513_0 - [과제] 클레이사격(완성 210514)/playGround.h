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
	// �ʱ�ȭ
	/* ���� �ý��� �ʱ�ȭ */
	bool _isGameStart;					// ���� ���� ����
	bool _isGameOver;					// ���� ���� ����
	int _gameOverCount;					// ���� ���� ī��Ʈ
	char _strNum[100];					// ���� �׸� �ʱ�ȭ �� �ʿ��� ���� ����
	int _score1;						// ���� (���� �ڸ� ����)
	int _score10;						// ���� (���� �ڸ� ����)
	image* _background;					// ���� ��� ȭ��
	image* _num[10];					// ���� �̹���

	// ��Ī�ӽ� & �� �ʱ�ȭ
	RECT _left_PitchingMachine;			// ���� ��Ī �ӽ�
	RECT _right_PitchingMachine;		// ������ ��Ī �ӽ�

	tagBall _ball[BALLMAX];				// ��
	image* _ballimg;					// �� �̹���
	int _ballRND;						// �� ��ġ ���� ����
	int _ballFireTimer;					// �� �߻� Ÿ�̸�

	// ��ݴ�
	RECT _launch_Pad;					// ��ݴ�
	image* _launch_Pad_img;				// ��ݴ� �̹���
	RECT _launch_Pad_Zone;				// ��ݴ� ����

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