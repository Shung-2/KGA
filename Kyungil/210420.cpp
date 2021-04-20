#include <iostream>
#include "210420 1. Player.h"
#include "210420 2. Enemy.h"
#include "210420 3. mainGame5.h"
#include "210420 4. VectorTest.h"
#include "210420 5. ArraySample.h"

int main()
{
	// ����Ϸ��� �����Ҵ�
	Player* pl = new Player;
	Enemy* em = new Enemy;

	// ������, �����ڸ� ���� ����
	int tempHp = pl->getPlayerHP();
	// tempHp���� getPlayerHp ������ return hp�� ���� tempHp�� 100�� �ȴ�.
	int tempAtk = em->getEnemyAtk();
	// tempAtk���� getEnemyAtk ������ return Atk�� ���� tempAtk�� 10�� �ȴ�.

	pl->output();
	// pl�� output�� pl�� ü���� ����Ѵ�. tempHp�� ü���� ����ϴ� ���� �ƴϴ�.
	pl->setPlayerHP(tempHp - tempAtk);
	// pl�� setPlayerHp �����ڸ� ���� ���� ���������� �Ű����� (tempHp - tempAtk) = (100 - 10)�� ���� 90�� setPlayerHp�� ��ȯ�ȴ� 
	pl->output();
	// pl�� ü���� 21���� �ڵ�� ���� 90�� �ȴ�.
	
	pl->setPlayerHP(pl->getPlayerHP() - em->getEnemyAtk());
	pl->output();
	em->setEnemyHp(em->getEnemyHP() - pl->getPlayerAtk());
	em->output();
	// ���Ͱ��� ����ص� �����ϴ�. �ڼ��� ������ �����Ѵ�. (©)

	// �� ��������� ����
	delete pl;
	delete em;

	// STL
	cout << endl;
	mainGame5 mg;
	/*
	template<typename T>
	inline void mainGame::output(T t)
	output(T t)�� ���� mg.output�� ������ Ÿ���� ������ �͵� �� ����� �����ϴ�!
	*/
	mg.output(7);
	mg.output(3.14f);
	mg.output("���� ������?");

	// STL �����̳��� ����
	// ����, ť, ����Ʈ, ����, �� ���!

	// ����
	VectorTest vT;

	// �迭�� ���� ������.
	cout << endl;
	arraySample<int> arrInt;

	arrInt.pushBack(10);

	for (int i = 0; i < 10; i++)
	{
		arrInt.pushBack(i * 100);
	}

	for (int i = 0; i < arrInt.GetSize(); i++)
	{
		cout << arrInt[i] << endl;
	}
	cout << endl;

	arraySample<float> arrFloat;

	arrFloat.pushBack(3.14f);
	arrFloat.pushBack(181.9f);
	arrFloat.pushBack(150.33f);

	for (int i = 0; i < arrFloat.GetSize(); i++)
	{
		cout << arrFloat[i] << endl;
	}
	cout << endl;

	arraySample<const char*> arrStr;
	arrStr.pushBack("���� ����");
	arrStr.pushBack("�����ҹ�");
	arrStr.pushBack("���");
	arrStr.pushBack("���ö�");
	arrStr.pushBack("4�������ŷ");

	for (int i = 0; i < arrStr.GetSize(); i++)
	{
		cout << arrStr[i] << endl;
	}
}