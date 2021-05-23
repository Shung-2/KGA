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
	RECT player;			/* RECT �ʱ�ȭ */
	float x, y;				/* X/Y �ʱ�ȭ */
	float _speed;			/* ���ǵ� �ʱ�ȭ */
	float _gravity;			/* �߷� �ʱ�ȭ */
	float _jumpPower;		/* ���� ���� �ʱ�ȭ */
	int _jumpCount;			/* ���� ī��Ʈ �ʱ�ȭ */
	bool _isJump;			/* ���� ���� �ʱ�ȭ */
	bool _isDownJump;		/* �ٿ� ���� ���� �ʱ�ȭ */
	bool _isGrap;			/* �� ���� ���� �ʱ�ȭ */
	bool _keyLock;			/* �� ���� ���¿��� ������ Ű ��� �ʱ�ȭ */
};

class playGround : public gameNode
{
private:

	image* _background;					// ���� ���ȭ�� �̹��� �ʱ�ȭ
	RECT _stage1_obj_land;				// �������� �� �ʱ�ȭ
	RECT _stage1_obj_bridge[3];			// �������� ��ֹ� �ʱ�ȭ
	image* _stage1_obj_bridge_img;		// �������� ��ֹ� �̹��� �ʱ�ȭ

	tagPlayer _player;					// �÷��̾� �ʱ�ȭ (PLAYER ����, �̹���, ���°�, �߷�����(����), ������, ������(INDEX))
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

	// �ʱ�ȭ(init)
	void set_Background();
	void set_Stage1_Land_Obj();
	void set_Player();

	// ����
	void get_Background();
	void get_Player_Key();

	// ����(update)
	void Player_Move();
	void Player_Frame();

	// �浹
	void On_Screen();
	void Above_Land_Obj();
	void Obj_Grap();

	// ���(render)
	void draw_BackGroud(HDC hdc);
	void draw_Stage1_Land_Obj(HDC hdc);
	void draw_Player(HDC hdc);
};