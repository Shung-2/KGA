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

	// ������
	int getPlayerHP() { return _hp; }
	int getPlayerAtk() { return _atk; }

	// ������
	void setPlayerHP(int hp) { _hp = hp; }

	void output()
	{
		cout << "�÷��̾� ü�� : " << _hp << endl;
	}
};

