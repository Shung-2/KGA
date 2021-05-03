#pragma once
#include "gameNode.h"

#define BULLETMAX 30

struct tagBullet
{
	int x, y;		//�Ѿ� ������
	RECT rc;		//�Ѿ� ��Ʈ
	int speed;		//�Ѿ� ���ǵ�
	bool isFire;	//�߻� �ƴ�?
};

class playGround : public gameNode
{
private:
	RECT _player;
	RECT _player2;

	RECT _backGauge;
	RECT _frontGauge;
	int _r, _g;
	
	
	tagBullet _bullet[BULLETMAX];
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void bulletFire();	//�Ѿ� �߻��ϴ� �Լ�
	void bulletMove();	//�Ѿ� �����̴� �Լ�

	void setGauge();
};

