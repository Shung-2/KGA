#pragma once
#include "gameNode.h"
// ## 210528 Unique progreessBar ##
#include "progressBar.h"

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

	// ## 210528 ufo move, boss ##
	int _x, _y;
	// ## 210528 Unique progreessBar ##
	progressBar* _hpBar;
	float _currentHP;
	float _maxHP;

public:
	enemy() {};
	~enemy() {};

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position, float hp);
	virtual void relase();
	virtual void update();
	virtual void render();

	void move(int MoveToX, int MoveToY);
	void draw();

	bool bulletCountFire();

	inline RECT getRect() { return _rc; }

	// ## 210528 Unique progreessBar ##
	float getHP() { return _currentHP; }
	void hitDamage(float damage);
};