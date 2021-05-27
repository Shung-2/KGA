#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _imageName;		// �� �̹���
	RECT _rc;				// �� ��Ʈ

	int _currentFrameX;		// �����ӹ�ȣ�� ����� ���� (X)
	int _currentFrameY;		// �����ӹ�ȣ�� ����� ���� (Y)

	int _count;				// ������ ������ ��
	int _fireCount;			// �߻� ī��Ʈ ��
	int _rndFireCount;		// ���� �߻� ī��Ʈ ��

public:
	enemy() {};
	~enemy() {};

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void relase();
	virtual void update();
	virtual void render();

	void move();
	void draw();

	bool bulletCountFire();

	inline RECT getRect() { return _rc; }
};