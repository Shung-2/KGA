#include <iostream>
#include <time.h>
using namespace std;

// 변수 선언
int User_Val;				// 사용자 값 입력
int Bingo_Ary[25];			// 25개의 배열 빙고판 선언
int Bingo_Count = 0;		// 빙고가 된 변수 선언
int dest, sour, temp;		// 셔플용 전용 변수 선언
const int Marking = '#';	// 사용자 숫자를 빙고판에 마킹할때 사용하는 변수 선언

int main()
{
	// 25개의 배열 빙고판 값 삽입
	for (int i = 0; i < 25; i++)
		Bingo_Ary[i] = i + 1;

	// 빙고판 셔플
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
		// 빙고판 출력
		system("cls");

		cout << "========== B I N G O ==========" << endl;
		// 빙고 카운터 출력
		cout << Bingo_Count << "개 빙고중!" << endl;
		for (int i = 0; i < 25; i++)
		{
			if (i % 5 == 0) cout << endl;			
			if (Bingo_Ary[i] == Marking)
				cout << (char)Bingo_Ary[i] << '\t';
			else
				cout << (int)Bingo_Ary[i] << '\t';
		}
		cout << endl << endl;

		// 사용자 값 입력
		cout << "숫자를 입력해주세요 : ";
		cin >> User_Val;

		for (int i = 0; i < 25; i++)
		{
			if (Bingo_Ary[i] == User_Val)
			{
				Bingo_Ary[i] = Marking;
				break;
			}
		}

		// 가로, 세로, 대각선 줄 완성 체크
		Bingo_Count = 0;

		for (int i = 0; i < 25; i++)
		{
			// 가로
			if (Bingo_Ary[i * 5] == Marking && Bingo_Ary[i * 5 + 1] == Marking &&
				Bingo_Ary[i * 5 + 2] == Marking && Bingo_Ary[i * 5 + 3] == Marking &&
				Bingo_Ary[i * 5 + 4] == Marking
				)
				Bingo_Count++;


			// 세로
			if (Bingo_Ary[i] == Marking && Bingo_Ary[i + 5 * 1] == Marking &&
				Bingo_Ary[i + 5 * 2] == Marking && Bingo_Ary[i + 5 * 3] == Marking &&
				Bingo_Ary[i + 5 * 4] == Marking
				)
				Bingo_Count++;

			// 오른쪽 아래 대각선 (/)
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
				// 왼쪽 아래 대각선 (\) 
				if (Bingo_Ary[4] == Marking && Bingo_Ary[8] == Marking &&
					Bingo_Ary[12] == Marking && Bingo_Ary[16] == Marking && Bingo_Ary[20] == Marking)
				{
					Bingo_Count++;
				}
			}
		}
		if (Bingo_Count >= 5) break;
	}

	// 게임 종료
	system("cls");

	cout << "========== B I N G O ==========" << endl;
	cout << Bingo_Count << "개 빙고중!" << endl;
	for (int i = 0; i < 25; i++)
	{
		if (i % 5 == 0) cout << endl;
		if (Bingo_Ary[i] == Marking)
			cout << (char)Bingo_Ary[i] << '\t';
		else
			cout << (int)Bingo_Ary[i] << '\t';
	}
	cout << "승리!" <<endl << endl;
}