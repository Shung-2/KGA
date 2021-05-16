#pragma once
#include "gameNode.h"

#define PI 3.14156f
#define BULLETMAX 30
#define PREVIEWMAX 300

struct tagBullet
{
	float x, y;		//���� ��ǥ
	float speed;	//�Ѿ� �ӵ�
	float angle;	//�Ѿ� ����
	float radius;	//�Ѿ� ������
	bool isFire;	//�߻��ߴ�?
	float gravity;
};

struct tagCannon
{
	POINT center;		//���� ����
	POINT cannonEnd;	//���� ����
	int radius;			//���� ������
	int cannon;			//����(?)
	float angle;		//���� ����
};

struct tagPreview
{
	float x, y;
	float radius;
	float gravity;
};

class playGround : public gameNode
{
private:
	tagCannon _cannon;
	tagBullet _bullet[BULLETMAX];
	tagPreview _preview[PREVIEWMAX];

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	
	void bulletFire();
	void bulletMove();

	void bulletPreview();
};

