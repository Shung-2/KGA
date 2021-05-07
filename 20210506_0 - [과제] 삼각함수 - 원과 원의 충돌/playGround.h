#pragma once
#include "gameNode.h"

class playGround : public gameNode
{
private:
	
	// �ʱ�ȭ
	RECT _user_Ellipse;				// ����� ��
	float _user_radius;				// ����� �� ������

	RECT _center_Ellipse;			// ��� ��
	float _center_Ellipse_x;		// ��� �� X�� ���� ��ǥ
	float _center_Ellipse_y;		// ��� �� Y�� ���� ��ǥ
	float _center_Ellipse_radius;	// ��� �� ������

	float _distance_x;				// ��� �� ���� X ��ǥ - ����� �� ���� X ��ǥ ��
	float _distance_y;				// ��� �� ���� Y ��ǥ - ����� �� ���� Y ��ǥ ��
	float _hypo;					// ����

	bool _iscrash;					// �浹����

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};