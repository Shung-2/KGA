/*
ī����� ��Ģ :
1. Ʈ���� ī�� ���(��, ��, ��, ��)�� ���� 52���� ī�带 �����ϰ�. �������� ���´�.
2. �� ���� ���� 13���� ������ A = 1, J = 11, Q = 12, K = 13 ���� ǥ���Ѵ�
3. �� ���� ī�带 ���� �̾� Ȯ���ϰ� ����° ī�带 �̴´�.
4. ����° ī�带 �̱� ���� ������ �Ǵ�. (�ּ� �ݾ��� �����Ѵ�.)
5. ����° ī�尡 �� ���� ī�� ���� ������ ���ڸ� ���� �ݾ��� 2�踦 ��´�.
6. �� ���� ī�� ������ ���ڰ� �ƴ϶�� ���� �ݾ׿��� ���� �ݾ��� �����Ѵ�.
��, �� ���� ī���� ���ڰ� ���ų� 1�ۿ� ���̰� �ȳ����� �ּ� ���ñݾ��� �ɾ�� �Ѵ�
*/

#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));

	// ���� ����
	int card[52];					// 52���� ī�带 ���� �迭 ����
	int shape[3], number[3];		// ī���� ����� ���ڸ� ����ϱ� ���� 2���� ī�� �迭 ����
	int user_money = 100000;		// ������� �ʱ� �ݾ��� 10��������� ���� ����
	int betting;					// ������ �ϱ� ���� ���� ����
	int dest, sour, temp;			// ���ÿ� ���� ����
	int turn = 2;					// ó���� ī�带 2�� ��� �����ϹǷ�.

	// ī�忡 �� �Է�
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
			// ���ڸ� ��Ÿ����
			number[i] = card[i + turn - 2] % 13;

			// card �迭 ���� ���� �ƴ� �ε������� �������.

			if (i == 2) break;

			// ��� ���
			switch (shape[i])
			{
			case 0:
				cout << "��";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			}

			// ���� ���
			switch (number[i])
			{
			case 0:
				cout << "A \t";
				break;
			case 11:
				cout << "J \t";
				break;
			case 12:
				cout << "Q \t";
				break;
			case 13:
				cout << "K \t";
				break;
			default:
				cout << number[i] + 1 << "\t";
				break;
			}
		}

		// ���� �ݾ� �Է�
		cout << "\n\n";
		cout << "�� ������ : " << user_money << endl;
		cout << "���� (�ּ� �ݾ� 1000��) : ";
		cin >> betting;

		// ���� ���� ����
		if (betting < 1000)
		{
			cout << "�ݾ��� �ʹ� �����ϴ�." << endl;
			continue;
		}
		else if (betting > user_money)
		{
			cout << "�ݾ׺��� ���� ���� ������ �� �����ϴ�. " << endl;
			continue;
		}
		
		// ���� ȹ���ϰų�, �Ҵ� ����
		if ((number[0] < number[2] && number[2] < number[1]) ||
			(number[1] < number[2] && number[2] < number[0]))
		{
			user_money = betting * 2;
			cout << betting * 2 << "�� ȹ��" << endl << endl;
		}
		else
		{
			user_money -= betting;
			cout << betting << "�� ����" << endl << endl;
		}		

		turn += 3;

		// ���� �¸� ����
		if (user_money > 300000)
		{
			cout << "�¸�!" << endl;
			break;
		}

		// ���� �й� ����
		if (user_money < 1000)
		{
			cout << "�й�!" << endl;
			break;
		}
	}
}