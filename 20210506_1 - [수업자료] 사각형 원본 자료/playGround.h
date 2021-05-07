#pragma once
#include "gameNode.h"

#define PI 3.14156f

class playGround : public gameNode
{
private:
	RECT _rectangle;
	RECT _ellipse;

	bool _isCollision;	//�浹�ƴ� ó���ϰ�
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	bool isCollision(RECT &rc1, RECT& rc2);
	//��Ʈ �������̶� Ư�� �������� �Ÿ� (h) ���ϴ� ��
	bool getDistance(RECT& rc, float x, float y);

	
	
};

