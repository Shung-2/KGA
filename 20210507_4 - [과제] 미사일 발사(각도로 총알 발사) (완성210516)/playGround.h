#pragma once
#include "gameNode.h"
#define PI 3.14156f
#define BULLETMAX 30

struct tagObj
{
	POINT center;	// ���� ���� ��ǥ �ʱ�ȭ
	POINT endPoint;	// ���� ���� ��ǥ �ʱ�ȭ
	int radius;		// ���� ������ �ʱ�ȭ
	int length;		// ���� ���� �ʱ�ȭ
	float angle;	// ���� ���� �ʱ�ȭ
};

struct tagBullet
{
	float x, y;		// �Ѿ� ���� ��ǥ �ʱ�ȸ
	float speed;	// �Ѿ� �ӵ� �ʱ�ȭ
	float angle;	// �Ѿ� ���� �ʱ�ȭ
	float radius;	// �Ѿ� ������ �ʱ�ȭ
	bool isFire;	// �Ѿ� �߻� ���� �ʱ�ȭ
};					   

class playGround : public gameNode
{
private:
	tagObj _obj;					// ������ ��ü��(obj)��� �������� ����
	tagBullet _bullet[BULLETMAX];	// �̻����� bullet��� �������� ����
	
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