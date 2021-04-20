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

	// 접근자
	int getEnemyHP() { return _hp; }
	int getEnemyAtk() { return _atk; }

	// 설정자
	void setEnemyHp(int hp) { _hp = hp; }

	void output()
	{
		cout << "에너미 체력 : " << _hp << endl;
	}
};

