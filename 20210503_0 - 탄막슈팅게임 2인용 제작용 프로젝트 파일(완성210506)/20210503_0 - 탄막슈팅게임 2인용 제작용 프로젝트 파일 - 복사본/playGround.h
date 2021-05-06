#pragma once
#include "gameNode.h"

#define PLAYER1_BULLETMAX 300
#define PLAYER2_BULLETMAX 300
#define WALL_BULLMAX 600

struct tagBullet
{
	int x, y;		// �Ѿ� ������
	RECT rc;		// �Ѿ� ��Ʈ
	int speed;		// �Ѿ� ���ǵ�
	bool isFire;	// �߻� �ƴ�?

	// 210506 �߰�
	int num;		// ���� ���� ����
};

class playGround : public gameNode
{
private:

	// ���� ���� �ʱ�ȭ & ����
	bool _isStart;									  // ��������
	bool _mapchange;								  // ���庯��

	// 210506 �߰�
	int _count;										  // ���� ���� ī��Ʈ

	// �÷��̾� ���� ���� & ����
	// Player 1										  
	RECT _player;									  // �÷��̾� 1 ����
	RECT _player1_backGauge;						  // �÷��̾� 1 ������
	RECT _player1_frontGauge;						  // �÷��̾� 1 ������
	int _p1_r, _p1_g;								  // �÷��̾� 1 ������ (RGB)
	tagBullet _player1_bullet[PLAYER1_BULLETMAX];	  // �÷��̾� 1 �Ѿ� 
	RECT _player1_map;								  // �÷��̾� 1 ��
	int _player1_mode;								  // �÷��̾� 1 ���
	bool _player1_state;							  // �÷��̾� 1 ����

	//******************************************************************************

	// Player 2
	RECT _player2;									  // �÷��̾� 2 ����
	RECT _player2_backGauge;						  // �÷��̾� 2 ������
	RECT _player2_frontGauge;						  // �÷��̾� 2 ������
	int _p2_r, _p2_g;								  // �÷��̾� 2 ������ (RGB)
	tagBullet _player2_bullet[PLAYER2_BULLETMAX];	  // �÷��̾� 2 �Ѿ� 
	RECT _player2_map;								  // �÷��̾� 2 ��
	int _player2_mode;								  // �÷��̾� 2 ���
	bool _player2_state;							  // �÷��̾� 2 ����

	//******************************************************************************

	// Wall
	RECT _wall;										  // �� ����
	float _wall_speed;								  // �� ���ǵ�
	bool _wall_change;								  // �� ���� ��ȯ

	//******************************************************************************

	// P1 4 SK
	RECT _Arbiter;									  // �ƺ���
	RECT _lockWall;									  // P2�� �ᱸ�� ��
	bool _lockKey;									  // �����̴� Ű ���°�
	bool _use4skile;								  // 1���� ������ �� �� �ִ� ���°�
	// P2 4 SK
	bool _reverseKey;								  // Ű �Ųٷ� �Է� ���°�


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void bulletFire();								  // �Ѿ� �߻��ϴ� �Լ� (P1)
	void bulletFire2();								  // �Ѿ� �߻��ϴ� �Լ� (P2)
	void bulletMove();								  // �Ѿ� �����̴� �Լ� (P1)
	void bulletMove2();								  // �Ѿ� �����̴� �Լ� (P2)
	void setGauge();								  // �Ѿ� ���� ��� ���ϴ� ������ (P2)
	void setGauge2();								  // �Ѿ� ���� ��� ���ϴ� ������ (P1)

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