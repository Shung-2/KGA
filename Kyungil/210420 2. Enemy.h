#pragma once
#include <iostream>
using namespace std;

class Enemy
{
private:
	int _hp;
	int _atk;

public:
	Enemy();
	~Enemy();

	// ������
	int getEnemyHP() { return _hp; }
	int getEnemyAtk() { return _atk; }

	// ������
	void setEnemyHp(int hp) { _hp = hp; }

	void output()
	{
		cout << "���ʹ� ü�� : " << _hp << endl;
	}
};

