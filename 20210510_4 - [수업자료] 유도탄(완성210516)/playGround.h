#pragma once
#include "gameNode.h"

#define PI 3.141592;

struct tagCircle
{
	float x, y;		// X���, Y��� ���� �ʱ�ȭ
	float angle;	// ���� �ʱ�ȭ
	float radius;	// ������ �ʱ�ȭ
	float speed;	// �ӵ� �ʱ�ȭ
};

class playGround : public gameNode
{
private:
	tagCircle _player;	// tagCircle�� �̿��ϴ� _player ����
	tagCircle _enemy;	// tagCircle�� �̿��ϴ� _enemy ����
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};