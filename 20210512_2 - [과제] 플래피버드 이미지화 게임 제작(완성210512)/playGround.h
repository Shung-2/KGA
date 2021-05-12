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
	// �ʱ�ȭ
	/* ���� �ý��� �ʱ�ȭ */
	bool _isGameStart;			// ���� ��ŸƮ ����
	bool _isGameOver;			// ���� ���� ����
	int _score1;				// ���� (���� �ڸ� ����)
	int _score10;				// ���� (���� �ڸ� ����)
	char _strNum[100];			// ���� �׸� �ʱ�ȭ �� �ʿ��� ���� ����
	image* _num[10];			// ���� �̹���
	image* _background;			// ��� �̹��� (��)
	image* _background_night;	// ��� �̹��� (��)
	bool _background_change;	// ��� �̹��� �ٲ� ����
	RECT _land;					// ��
	image* _landimg;			// �� �̹���

	// �÷��̾� �ʱ�ȭ
	RECT _player;				// �÷��̾�
	image* _playerimg;			// �÷��̾� �̹���
	float _x, _y;				// �÷��̾� X, Y ��
	float _jumpPower;			// �÷��̾� ���� ��
	float _gravity;				// �÷��̾� �߷�
	bool _isJump;				// �÷��̾� ���� ���� ����

	// ������ �ʱ�ȭ
	tagPipe _pipe[PIPEMAX];		// ������
	int _rndY;					// ������ ���� ����� ���� ���� ����
	image* _pipe_top_image;		// ������ �� �̹���
	image* _pipe_bottom_image;	// ������ �Ʒ� �̹���

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

};