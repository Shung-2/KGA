/*
��������:
1. 0 ~ 24������ ���ڰ� 5 * 5�� ��Ÿ����
2. 0�� �׻� ������ �ϴܿ� �ִ´�.
3. ����Ű Ȥ�� ���е带 ������ 0�� �����δ�.
4. �� ���� �������� �� �Ű����� �ʴ´�.
*/

#include <iostream>
#include <time.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

// ��������
int Array[25];			// 0 ~ 25���� ���� ����ϱ� ���� �迭 ����
int User_Move;			// ������� ������ ���� ����
int dest, sour, temp;	// Shuffle�� ���� ���� 
int Zero = 24;			// �迭�� ������ �ε����� ���� ���� ����

int main()
{
	// �迭�ȿ� 25���� �� ����
	for (int i = 0; i < 25; i++)
	{
		Array[i] = i + 1;
	}

	// Shuffle
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		dest = rand() % 25 + 1;
		sour = rand() % 25 + 1;

		temp = Array[dest];
		Array[dest] = Array[sour];
		Array[sour] = temp;
	}
	Array[24] = 0;

	// ȭ�� ���
	while (true)
	{
		system("cls");

		cout << "= = = = = = = = = = = = = = = = =" << endl;
		cout << "= = = = = 0�� ��������! = = = = =" << endl;
		cout << "= = = = = = = = = = = = = = = = =" << endl;

		for (int i = 0; i < 25; i++)
		{
			if (i % 5 == 0) cout << endl;
			cout << Array[i] << "\t";
		}
		cout << endl << endl;
		// ����� �Է� ���
		cout << "4 : ����, 6 : ������, 8 : ����, 2 : �Ʒ���" << endl << endl;
		cout << "��� �������� �����̽ðڽ��ϱ�? ";

		// ���͸� ġ�� �ʰ��� ������ �� �ְ�
		User_Move = _getch();

		// ������� �Է��� �޾� �����̴� �κ�
		switch (User_Move)
		{
		case UP:
			if (Zero < 5) break;
			temp = Array[Zero - 5];
			Array[Zero - 5] = Array[Zero];
			Array[Zero] = temp;
			Zero -= 5;
			break;

		case DOWN:
			if (Zero > 19) break;
			temp = Array[Zero + 5];
			Array[Zero + 5] = Array[Zero];
			Array[Zero] = temp;
			Zero += 5;
			break;

		case LEFT:
			if (Zero % 5 == 0) break;
			temp = Array[Zero - 1];
			Array[Zero - 1] = Array[Zero];
			Array[Zero] = temp;
			Zero--;
			break;

		case RIGHT:
			if (Zero % 5 == 4) break;
			temp = Array[Zero + 1];
			Array[Zero + 1] = Array[Zero];
			Array[Zero] = temp;
			Zero++;
			break;
		}
	}
}