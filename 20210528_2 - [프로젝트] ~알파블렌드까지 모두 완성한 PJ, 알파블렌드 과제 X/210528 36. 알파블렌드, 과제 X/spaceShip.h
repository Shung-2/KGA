#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

// ## 210527 ���� ���� Save&Load, Loop Render ##
#pragma warning(disable:4996)

// 1. �����Ϸ� ���ѷ����� ���������� ����
// 2. ���� �ӵ��� ���̱� ����
// ��ȣ ������ ���� Ŭ���� ���� ����
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	hyunMoo* _hm;

	// �굵 ������ �� �����⿡ �Ұ��ϴ�.
	enemyManager* _em;

	progressBar* _hpBar;
	float _currentHP, _maxHP;

	// ## 210528 ���� ���� Alpha ���� ##
	int _alphaValue;

public:
	spaceShip();
	~spaceShip();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	// �浹�Լ�
	void collision();

	// �÷��̾� ������ ����ݽô�.
	void hitDamege(float damage);

	// ���� �������ε� �Լ� �̸��� �׷����� ����
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	// ������ ���� ������
	hyunMoo* getHyunMoo() { return _hm; }

	// �����̽��� �̹����� ���� �����ڸ� �Ѱ��ִ� ��
	image* getShipImage() { return _ship; }
};