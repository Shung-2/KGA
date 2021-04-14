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
#include <Windows.h>
using namespace std;

enum Card_Shape
{
	Diamond,
	Spade,
	Heart,
	Clover
};

struct Card
{
	int Shape;
	int Number;
};

void Print_Game_Boder(Card cards)
{
	cout << "|";
	// ���� ���
	switch (cards.Shape)
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
	cout << "  |\n|    |\n|  ";

	// !(2~10) ���
	switch (cards.Number)
	{
	case 1:
		cout << " A";
		break;
	case 11:
		cout << " J";
		break;
	case 12:
		cout << " Q";
		break;
	case 13:
		cout << " K";
		break;
	// ���� ���
	default:
		if (cards.Number != 10)
			cout << " ";
		cout << cards.Number;
	}
	cout << "|" << endl << endl;
}

int main()
{
	srand(time(NULL));
	int User_Money = 100000;
	Card Cards[52];

	// ī�� ���̿� ��ȣ �Է�
	int Count = 0;

	for (int i = 0; i < 52; i++)
	{
		if (i != 0 && i % 13 == 0) Count++;

		switch (Count)
		{
		case 0:
			Cards[i].Shape = Diamond;
			break;
		case 1:
			Cards[i].Shape = Spade;
			break;
		case 2:
			Cards[i].Shape = Heart;
			break;
		case 3:
			Cards[i].Shape = Clover;
		}
		Cards[i].Number = i % 13 + 1;
	}

	// Shuffle ���� ���� ����
	int dest, sour;
	Card temp;

	// Shuffle
	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = Cards[dest];
		Cards[dest] = Cards[sour];
		Cards[sour] = temp;
	}

	int idx = 0;
	while (true)
	{
		system("cls");

		int betting_Money = 0;
		int Open_Card[2];
		int destIdx = idx + 2;
		int i = 0;

		cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
		cout << "= = = = = T R U M P - C A R D - B A T I N G - G A M E = = = = =" << endl;
		cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl << endl;
		cout << "A = 1, J = 11, Q = 12, K = 13 " << "\t \t    User_Money : " << User_Money << endl << endl;
		
		for (idx; idx < destIdx; idx++)
		{
			Open_Card[i++] = Cards[idx].Number;
			Print_Game_Boder(Cards[idx]);
		}

		// 0: ���� ��, 1: ū ���� �����Ͽ� ���� ���� �� �ְ� �Ѵ�.
		if (Open_Card[0] > Open_Card[1])
		{
			int temp;
			temp = Open_Card[0];
			Open_Card[0] = Open_Card[1];
			Open_Card[1] = temp;
		}

		while (true)
		{
			cout << "���� (�ּ� �ݾ� : 1,000) : ";
			cin >> betting_Money;

			if (1000 > betting_Money)
			{
				cout << " * ��� - �ּ� �ݾ� ���� �����ϴ�." << endl << endl;
				continue;
			}
			else if (betting_Money > User_Money)
			{
				cout << " * ��� - �����ݺ��� ���� �ݾ��� ������ �� �����ϴ�." << endl << endl;
				continue;
			}
			break;
		}

		cout << endl << "ī�带 �����մϴ�." << endl << endl;

		Card New_Open_Card
		{ 
			Cards[idx].Shape, Cards[idx++].Number
		};
		Print_Game_Boder(New_Open_Card);

		if (New_Open_Card.Number > Open_Card[0] && New_Open_Card.Number < Open_Card[1])
		{
			cout << "���� �ݾ��� 2���� " << betting_Money * 2 << "���� ȹ���߽��ϴ�! �����մϴ�! " << endl << endl;
			User_Money = betting_Money * 2;
		}
		else
		{
			cout << "���� �ݾ��� " << betting_Money << "���� �Ҿ����ϴ�." << endl << endl;
			User_Money -= betting_Money;
		}

		Sleep(3000);

		// �й�����
		if (User_Money <= 1000)
		{
			cout << "���� ��� �����̽��ϴ�. �� �̻� �÷��� �� �� �����ϴ�. " << endl << endl;
			break;
		}

		// �¸�����
		if (User_Money >= 300000)
		{
			cout << "�¸� �ڱ��� ��ҽ��ϴ�. �¸� !" << endl << endl;
			break;
		}

		// ī�带 ��� �� ����Ͽ��� ���
		if (idx >= 50)
		{
			cout << "ī�带 ���� �� ����Ͽ����ϴ�. " << endl;
			break;
		}
	}
	cout << "���� ����! ����� �������� : " << User_Money << "�� �Դϴ�!" << endl;
	return 0;
}