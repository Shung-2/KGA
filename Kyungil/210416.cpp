#include <iostream>
#include "210416 1.mainGame.h"
#include "210416 2.CardGame.h"
#include "210416 3.BowlingGame.h"
// ���� ���̺귯���� < >�� ����ϰ�, ����ڰ� ���� ���̺귯���� " "�� ����Ѵ�.

using namespace std;

int main()
{
	// Ŭ���� == ��ü
	mainGame mg;

	// C++������ Ŭ������ ����ü�� ������
	// C++�� Ŭ������ �⺻ ������ private�̸�, ����ü�� public�̴�.
	// C#������ Ŭ������ ����ü�� ������

	// �����Ҵ� - �޸𸮰� ���� ������ ������
	// ������ �����ܰ迡������ �޸� ������ Ȯ���ϰ� ���´�.
	// ��Ÿ��(���൵��) �߿� ������ �Ұ����ϴ�
	// �������� �Ʒ��� ����.
	mainGame mg2;

	// �����Ҵ� - �޸𸮰� ��(heap) ������ ������.
	// ������ ���Ŀ� �޸� ������ �뿩�Ѵ�.
	// �׷��� ������ ��Ÿ�� �߿� ������ �����ϴ�.
	mainGame* mg3 = new mainGame;
	delete mg3;

	// �ǽ�
	int user_game_choice;
	cout << "1. ī����� 2. �������� " << endl;
	cout << "���� ������ �ϰ� �����Ű��� ? " << endl;
	cin >> user_game_choice;

	switch (user_game_choice)
	{
		// 1�� ī�����
		case 1:
		{
			CardGame CG;
			break;
		}

		// 2�� ��������
		case 2:
		{
			BowlingGame BG;
			break;
		}

		// �׿� 
		default:
		{
			cout << "�߸��Է��ϼ̽��ϴ�! " << endl;
			break;
		}
	}
}