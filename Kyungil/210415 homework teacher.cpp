/*
��������:
1. 0 ~ 24������ ���ڰ� 5 * 5�� ��Ÿ����
2. 0�� �׻� ������ �ϴܿ� �ִ´�.
3. ����Ű Ȥ�� ���е带 ������ 0�� �����δ�.
4. �� ���� �������� �� �Ű����� �ʴ´�.
*/

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

// ���� ����
int Ary[25];			// 24���� �迭 ����
int dest, sour, temp;	// ���ÿ� ���� ���� ����
int user_move;
int zero = 24;

int main()
{
	// �迭�ȿ� 25���� �� ����
	for (int i = 0; i < 25; i++)
	{
		Ary[i] = i + 1;
	}

	// Shuffle
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		dest = rand() % 25 + 1;
		sour = rand() % 25 + 1;

		temp = Ary[dest];
		Ary[dest] = Ary[sour];
		Ary[sour] = temp;
	}
	cout << "T";
	Ary[24] = 0;

	while (true)
	{
		system("cls");

		cout << "= = = = = = = = = = = = = = = = =" << endl;
		cout << "= = = = = 0�� ��������! = = = = =" << endl;
		cout << "= = = = = = = = = = = = = = = = =" << endl;

		for (int i = 0; i < 25; i++)
		{
			if (i % 5 == 0) cout << endl;
			cout << Ary[i] << '\t';
		}
		cout << endl << endl;
		cout << "4 : ����, 6 : ������, 8 : ����, 2 : �Ʒ���" << endl << endl;
		cout << "��� �������� �����̽ðڽ��ϱ�? ";
	
		user_move = _getch();

		switch (user_move)
		{
		case LEFT:
			if (zero % 5 == 0) break;
			temp = Ary[zero - 1];
			Ary[zero - 1] = Ary[zero];
			Ary[zero] = temp;
			zero--;
			break;

		case RIGHT:
			if (zero % 5 == 4) break;
			temp = Ary[zero + 1];
			Ary[zero + 1] = Ary[zero];
			Ary[zero] = temp;
			zero++;
			break;

		case UP:
			if (zero < 5 ) break;
			temp = Ary[zero - 5];
			Ary[zero - 5] = Ary[zero];
			Ary[zero] = temp;
			zero -= 5;
			break;

		case DOWN:
			if (zero > 19) break;
			temp = Ary[zero + 5];
			Ary[zero + 5] = Ary[zero];
			Ary[zero] = temp;
			zero += 5;
			break;
		}	
	}
}