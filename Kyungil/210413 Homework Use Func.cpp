/* 
������� ���� �������� :
1. �����ǿ� 1 ~ 25 ���ڰ� �������� ȭ�鿡 ���ɴϴ�.
2. �����ǿ� �ִ� ���ڸ� ����ڰ� �Է��ϸ� �����ǿ� # ��ŷ���� ��ȯ�� �˴ϴ�.
3. 5�� ��ŷ���� ���ѵ� �� ���� ī��Ʈ�� �ö󰩴ϴ�.
4. ���� ī��Ʈ�� 5�� ��� �¸��մϴ�.

��ȭ���� : if ������ �־ ��ǻ�Ͷ� 1:1�� �ο��, else�� ��� 1�ο� ������.
*/

#include <iostream>
#include <time.h>
using namespace std;

// ���� ����
int Bingo_Ary[25];			// �����ǿ� 1���� ~ 25�� ���ڸ� ���� �迭
int Bingo_Count = 0;		// ���� ���� �ϼ��� ����
const int Marking = 'X';	// ����ڰ� ���ڸ� �Է����� �� ��ŷ�ϴ� ����

// ���� �迭�� �� ����
void Init()
{
	for (int i = 0; i < 25; i++)
		Bingo_Ary[i] = i + 1;
}

// ������ ����
void Shuffle()
{
	// Shuffle ���� ���� ����
	int dest, sour, temp;	

	// Shuffle
	for (int i = 0; i < 25; i++)
	{
		dest = rand() % 25;
		sour = rand() % 25;
	
		temp = Bingo_Ary[dest];
		Bingo_Ary[dest] = Bingo_Ary[sour];
		Bingo_Ary[sour] = temp;
	}
}

// ������ ���
void Show_Bingo_boder()
{
	system("cls");

	cout << "========== B I N G O ==========" << endl;
	cout << Bingo_Count << "�� ������!" << endl;
	for (int i = 0; i < 25; i++)
	{
		if (i % 5 == 0) cout << endl;
		if (Bingo_Ary[i] == Marking) 
			cout << (char)Bingo_Ary[i] << '\t';
		else 
			cout << (int) Bingo_Ary[i] << '\t';
	}
	cout << endl << endl;
}

// ����� ���� �Է� 
int Input_User_Val()
{
	// ������� �Է� �޴� ���� ����
	int User_Val;			

	// �� �Է�
	cout << "���ڸ� �Է����ּ��� : ";
	cin >> User_Val;
	return User_Val;
}

// ��ŷ
void SetMarking(int num)
{
	for (int i = 0; i < 25; i++)
	{
		if (Bingo_Ary[i] == num)
		{
			Bingo_Ary[i] = Marking;
			break;
		}
	}
}

// ����, ����, �밢�� �� �ϼ�
void Bingo_Check()
{
	Bingo_Count = 0;		// ���� ���� �ϼ��� ����

	for (int i = 0; i <= 1; i++)
	{
		// ����
		if (Bingo_Ary[i * 5]     == Marking && Bingo_Ary[i * 5 + 1] == Marking &&
			Bingo_Ary[i * 5 + 2] == Marking && Bingo_Ary[i * 5 + 3] == Marking &&
			Bingo_Ary[i * 5 + 4] == Marking
			)
			Bingo_Count++;


		// ����
		if (Bingo_Ary[i]         == Marking && Bingo_Ary[i + 5 * 1] == Marking &&
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
}

int main()
{
	Init();
	Shuffle();

	while (true)
	{		
		Show_Bingo_boder();		
		SetMarking(Input_User_Val());
		Bingo_Check();

		// �¸�
		if (Bingo_Count >= 5) break;
	}
	Show_Bingo_boder();
	cout << "�¸�!" << endl;
}