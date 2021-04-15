#include <iostream>
#include <time.h>
using namespace std;

// ���� ����
int User_Val;				// ����� �� �Է�
int Ary[25];			// 25���� �迭 ������ ����
int Bingo_Count = 0;		// ���� �� ���� ����
int dest, sour, temp;		// ���ÿ� ���� ���� ����
const int Marking = '#';	// ����� ���ڸ� �����ǿ� ��ŷ�Ҷ� ����ϴ� ���� ����

int main()
{
	// 25���� �迭 ������ �� ����
	for (int i = 0; i < 25; i++)
		Ary[i] = i + 1;

	// ������ ����
	for (int i = 0; i < 25; i++)
	{
		// Shuffle
		dest = rand() % 25;
		sour = rand() % 25;

		temp = Ary[dest];
		Ary[dest] = Ary[sour];
		Ary[sour] = temp;
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
			if (Ary[i] == Marking)
				cout << (char)Ary[i] << '\t';
			else
				cout << (int)Ary[i] << '\t';
		}
		cout << endl << endl;

		// ����� �� �Է�
		cout << "���ڸ� �Է����ּ��� : ";
		cin >> User_Val;

		for (int i = 0; i < 25; i++)
		{
			if (Ary[i] == User_Val)
			{
				Ary[i] = Marking;
				break;
			}
		}

		// ����, ����, �밢�� �� �ϼ� üũ
		Bingo_Count = 0;

		for (int i = 0; i < 25; i++)
		{
			// ����
			if (Ary[i * 5] == Marking && Ary[i * 5 + 1] == Marking &&
				Ary[i * 5 + 2] == Marking && Ary[i * 5 + 3] == Marking &&
				Ary[i * 5 + 4] == Marking
				)
				Bingo_Count++;


			// ����
			if (Ary[i] == Marking && Ary[i + 5 * 1] == Marking &&
				Ary[i + 5 * 2] == Marking && Ary[i + 5 * 3] == Marking &&
				Ary[i + 5 * 4] == Marking
				)
				Bingo_Count++;

			// ������ �Ʒ� �밢�� (/)
			if (i == 0)
			{
				if (Ary[0] == Marking && Ary[6] == Marking &&
					Ary[12] == Marking && Ary[18] == Marking && Ary[24] == Marking)
				{
					Bingo_Count++;
				}
			}

			if (i == 0)
			{
				// ���� �Ʒ� �밢�� (\) 
				if (Ary[4] == Marking && Ary[8] == Marking &&
					Ary[12] == Marking && Ary[16] == Marking && Ary[20] == Marking)
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
		if (Ary[i] == Marking)
			cout << (char)Ary[i] << '\t';
		else
			cout << (int)Ary[i] << '\t';
	}
	cout << "�¸�!" <<endl << endl;
}