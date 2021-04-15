/*
사전조건:
1. 0 ~ 24까지의 숫자가 5 * 5로 나타난다
2. 0은 항상 오른쪽 하단에 있는다.
3. 방향키 혹은 넘패드를 누르면 0이 움직인다.
4. 각 방향 끝에서는 더 옮겨지지 않는다.
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

// 변수 선언
int Ary[25];			// 24개의 배열 선언
int dest, sour, temp;	// 셔플용 전용 변수 선언
int user_move;
int zero = 24;

int main()
{
	// 배열안에 25개의 값 삽입
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
		cout << "= = = = = 0을 움직여라! = = = = =" << endl;
		cout << "= = = = = = = = = = = = = = = = =" << endl;

		for (int i = 0; i < 25; i++)
		{
			if (i % 5 == 0) cout << endl;
			cout << Ary[i] << '\t';
		}
		cout << endl << endl;
		cout << "4 : 왼쪽, 6 : 오른쪽, 8 : 위쪽, 2 : 아래쪽" << endl << endl;
		cout << "어느 방향으로 움직이시겠습니까? ";
	
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