#pragma once
#include <iostream>
using namespace std;

class Player
{
private:
	int _hp;
	int _atk;

public:
	Player();
	~Player();

	// 접근자
	int getPlayerHP() { return _hp; }
	int getPlayerAtk() { return _atk; }

	// 설정자
	void setPlayerHP(int hp) { _hp = hp; }

	void output()
	{
		cout << "플레이어 체력 : " << _hp << endl;
	}
};

