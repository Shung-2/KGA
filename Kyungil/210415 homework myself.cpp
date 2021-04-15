/*
사전조건:
1. 0 ~ 24까지의 숫자가 5 * 5로 나타난다
2. 0은 항상 오른쪽 하단에 있는다.
3. 방향키 혹은 넘패드를 누르면 0이 움직인다.
4. 각 방향 끝에서는 더 옮겨지지 않는다.
*/

#include <iostream>
#include <time.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

int Array[25];
int User_Move;
int dest, sour, temp;
int Zero = 24;

int main()
{
	// 배열안에 25개의 값 삽입
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

	// 화면 출력
	while (true)
	{
		system("cls");

		cout << "= = = = = = = = = = = = = = = = =" << endl;
		cout << "= = = = = 0을 움직여라! = = = = =" << endl;
		cout << "= = = = = = = = = = = = = = = = =" << endl;

		for (int i = 0; i < 25; i++)
		{
			if (i % 5 == 0) cout << endl;
			cout << Array[i] << "\t";
		}
		cout << endl << endl;
		cout << "4 : 왼쪽, 6 : 오른쪽, 8 : 위쪽, 2 : 아래쪽" << endl << endl;
		cout << "어느 방향으로 움직이시겠습니까? ";

		User_Move = _getch();

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