#pragma once
#include "gameNode.h"

#define PI 3.14156f
#define BULLETMAX 30

struct tagBullet
{
	float x, y;		//���� ��ǥ
	float speed;	//�Ѿ� �ӵ�
	float angle;	//�Ѿ� ����
	float radius;	//�Ѿ� ������
	bool isFire;	//�߻��ߴ�?
};

struct tagCannon
{
	POINT center;		//���� ����
	POINT cannonEnd;	//���� ����
	int radius;			//���� ������
	int cannon;			//����(?)
	float angle;		//���� ����
};

class playGround : public gameNode
{
private:
	tagCannon _cannon;
	tagBullet _bullet[BULLETMAX];
		
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	
	void bulletFire();
	void bulletMove();
};