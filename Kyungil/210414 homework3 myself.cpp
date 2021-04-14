#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));
	
	// ���� ����
	int user_money = 500000;	// ������� �ʱ� �ݾ��� 10�������� ����
	int card[52];				// 52���� ī�带 ���� �迭 ����
	int shape[3], number[3];	// ī���� ����� ���ڸ� ����ϱ� ���� �迭 ����
	int dest, sour, temp;		// ���ÿ� ���� ����
	int betting;				// ������ �ϱ� ���� ���� ����
	int turn = 2;				// ó���� ī�带 2�� ��� �����ϹǷ� 2�� �ΰ� ���� (�迭�� �ε����� -���� ���� ���� ����)

	// ī�忡 �� ����
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}

	// ����
	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = card[dest];
		card[dest] = card[sour];
		card[sour] = temp;
	}

	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			// ����� ��Ÿ����.
			shape[i] = card[i + turn - 2] / 13;
			// ���ڸ� ��Ÿ����.
			number[i] = card[i + turn - 2] % 13;
			// ����! card �迭 ���� �ƴ� �ε����� ������ �������

			if (i == 2) break;

			// ��� ���
			switch (shape[i])
			{
			case 0:
				cout << "�� ";
				break;
			case 1:
				cout << "�� ";
				break;
			case 2:
				cout << "�� ";
				break;
			case 3:
				cout << "�� ";
				break;
			}

			// ���� ���
			switch (number[i])
			{
			case 0:
				cout << "A ";
				break;
			case 11:
				cout << "J ";
				break;
			case 12:
				cout << "Q ";
				break;
			case 13:
				cout << "K ";
				break;
			default:
				cout << number[i] << "\t";
			}
			cout << endl << endl;
		}

		// ���� �ݾ� �Է�
		cout << "�� ������ : " << user_money << endl;
		cout << "���� (�ּұݾ� 100) : ";
		cin >> betting;

		// ���� ���� ����
		if (betting < 100)
		{
			cout << "�ݾ��� �ʹ� ����" << endl << endl;
			continue;
		}
		else if (user_money < betting)
		{
			cout << "������ �ִ� ������ �� ���� ������ �� ����" << endl << endl;
			continue;
		}

		// ���� ���ų�, �Ҵ� ����
		if (number[0] < number[2] && number[2] < number[1] ||
			number[1] < number[2] && number[2] < number[0])
		{
			user_money = betting * 2;
			cout << betting << " ���� ȹ��!" << endl << endl;
		}
		else
		{
			user_money -= betting;
			cout << betting << " ���� ����!" << endl << endl;
		}

		turn += 3;

		// �¸�����
		if (user_money > 300000)
		{
			cout << "�¸�" << endl;
			break;
		}

		// �й�����
		if (user_money < 1000)
		{
			cout << "���� �����ϴ�. �й�!" << endl;
			break;
		}
	}
}