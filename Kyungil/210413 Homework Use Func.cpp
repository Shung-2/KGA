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
int Ary[25];			// �����ǿ� 1���� ~ 25�� ���ڸ� ���� �迭
int Bingo_Count = 0;		// ���� ���� �ϼ��� ����
const int Marking = 'X';	// ����ڰ� ���ڸ� �Է����� �� ��ŷ�ϴ� ����

// ���� �迭�� �� ����
void Init()
{
	for (int i = 0; i < 25; i++)
		Ary[i] = i + 1;
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
	
		temp = Ary[dest];
		Ary[dest] = Ary[sour];
		Ary[sour] = temp;
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
		if (Ary[i] == Marking) 
			cout << (char)Ary[i] << '\t';
		else 
			cout << (int) Ary[i] << '\t';
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
		if (Ary[i] == num)
		{
			Ary[i] = Marking;
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
		if (Ary[i * 5]     == Marking && Ary[i * 5 + 1] == Marking &&
			Ary[i * 5 + 2] == Marking && Ary[i * 5 + 3] == Marking &&
			Ary[i * 5 + 4] == Marking
			)
			Bingo_Count++;


		// ����
		if (Ary[i]         == Marking && Ary[i + 5 * 1] == Marking &&
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