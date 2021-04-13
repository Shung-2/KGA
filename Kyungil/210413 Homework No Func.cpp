#include <iostream>
#include <time.h>
using namespace std;

// ���� ����
int User_Val;				// ����� �� �Է�
int Bingo_Ary[25];			// 25���� �迭 ������ ����
int Bingo_Count = 0;		// ���� �� ���� ����
int dest, sour, temp;		// ���ÿ� ���� ���� ����
const int Marking = '#';	// ����� ���ڸ� �����ǿ� ��ŷ�Ҷ� ����ϴ� ���� ����

int main()
{
	// 25���� �迭 ������ �� ����
	for (int i = 0; i < 25; i++)
		Bingo_Ary[i] = i + 1;

	// ������ ����
	for (int i = 0; i < 25; i++)
	{
		// Shuffle
		dest = rand() % 25;
		sour = rand() % 25;

		temp = Bingo_Ary[dest];
		Bingo_Ary[dest] = Bingo_Ary[sour];
		Bingo_Ary[sour] = temp;
	}

	while (true)
	{
		// ������ ���
		system("cls");

		cout << "========== B I N G O ==========" << endl;
		// ���� ī���� ���
		cout << Bingo_Count << "�� ������!" << endl;
		for (int i = 0; i < 25; i++)
		{
			if (i % 5 == 0) cout << endl;			
			if (Bingo_Ary[i] == Marking)
				cout << (char)Bingo_Ary[i] << '\t';
			else
				cout << (int)Bingo_Ary[i] << '\t';
		}
		cout << endl << endl;

		// ����� �� �Է�
		cout << "���ڸ� �Է����ּ��� : ";
		cin >> User_Val;

		for (int i = 0; i < 25; i++)
		{
			if (Bingo_Ary[i] == User_Val)
			{
				Bingo_Ary[i] = Marking;
				break;
			}
		}

		// ����, ����, �밢�� �� �ϼ� üũ
		Bingo_Count = 0;

		for (int i = 0; i < 25; i++)
		{
			// ����
			if (Bingo_Ary[i * 5] == Marking && Bingo_Ary[i * 5 + 1] == Marking &&
				Bingo_Ary[i * 5 + 2] == Marking && Bingo_Ary[i * 5 + 3] == Marking &&
				Bingo_Ary[i * 5 + 4] == Marking
				)
				Bingo_Count++;


			// ����
			if (Bingo_Ary[i] == Marking && Bingo_Ary[i + 5 * 1] == Marking &&
				Bingo_Ary[i + 5 * 2] == Marking && Bingo_Ary[i + 5 * 3] == Marking &&
				Bingo_Ary[i + 5 * 4] == Marking
				)
				Bingo_Count++;

			// ������ �Ʒ� �밢�� (/)
			if (i == 0)
			{
				if (Bingo_Ary[0] == Marking && Bingo_Ary[6] == Marking &&
					Bingo_Ary[12] == Marking && Bingo_Ary[18] == Marking && Bingo_Ary[24] == Marking)
				{
					Bingo_Count++;
				}
			}

			if (i == 0)
			{
				// ���� �Ʒ� �밢�� (\) 
				if (Bingo_Ary[4] == Marking && Bingo_Ary[8] == Marking &&
					Bingo_Ary[12] == Marking && Bingo_Ary[16] == Marking && Bingo_Ary[20] == Marking)
				{
					Bingo_Count++;
				}
			}
		}
		if (Bingo_Count >= 5) break;
	}

	// ���� ����
	system("cls");

	cout << "========== B I N G O ==========" << endl;
	cout << Bingo_Count << "�� ������!" << endl;
	for (int i = 0; i < 25; i++)
	{
		if (i % 5 == 0) cout << endl;
		if (Bingo_Ary[i] == Marking)
			cout << (char)Bingo_Ary[i] << '\t';
		else
			cout << (int)Bingo_Ary[i] << '\t';
	}
	cout << "�¸�!" <<endl << endl;
}