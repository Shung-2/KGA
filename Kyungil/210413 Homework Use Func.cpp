/* 
빙고게임 문제 사전조건 :
1. 빙고판에 1 ~ 25 숫자가 무작위로 화면에 나옵니다.
2. 빙고판에 있는 숫자를 사용자가 입력하면 빙고판에 # 마킹으로 변환이 됩니다.
3. 5줄 마킹으로 변한될 떄 빙고 카운트가 올라갑니다.
4. 빙고 카운트가 5일 경우 승리합니다.

심화과정 : if 조건을 넣어서 컴퓨터랑 1:1로 싸우고, else일 경우 1인용 빙고판.
*/

#include <iostream>
#include <time.h>
using namespace std;

// 변수 선언
int Ary[25];			// 빙고판에 1부터 ~ 25의 숫자를 담을 배열
int Bingo_Count = 0;		// 현재 빙고가 완성된 갯수
const int Marking = 'X';	// 사용자가 숫자를 입력했을 떄 마킹하는 변수

// 빙고 배열에 값 삽입
void Init()
{
	for (int i = 0; i < 25; i++)
		Ary[i] = i + 1;
}

// 빙고판 셔플
void Shuffle()
{
	// Shuffle 전용 변수 선언
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

// 빙고판 출력
void Show_Bingo_boder()
{
	system("cls");

	cout << "========== B I N G O ==========" << endl;
	cout << Bingo_Count << "개 빙고중!" << endl;
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

// 사용자 숫자 입력 
int Input_User_Val()
{
	// 사용자의 입력 받는 변수 선언
	int User_Val;			

	// 값 입력
	cout << "숫자를 입력해주세요 : ";
	cin >> User_Val;
	return User_Val;
}

// 마킹
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

// 가로, 세로, 대각선 줄 완성
void Bingo_Check()
{
	Bingo_Count = 0;		// 현재 빙고가 완성된 갯수

	for (int i = 0; i <= 1; i++)
	{
		// 가로
		if (Ary[i * 5]     == Marking && Ary[i * 5 + 1] == Marking &&
			Ary[i * 5 + 2] == Marking && Ary[i * 5 + 3] == Marking &&
			Ary[i * 5 + 4] == Marking
			)
			Bingo_Count++;


		// 세로
		if (Ary[i]         == Marking && Ary[i + 5 * 1] == Marking &&
			Ary[i + 5 * 2] == Marking && Ary[i + 5 * 3] == Marking &&
			Ary[i + 5 * 4] == Marking
			)
			Bingo_Count++;

		// 오른쪽 아래 대각선 (/)
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
			// 왼쪽 아래 대각선 (\) 
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

		// 승리
		if (Bingo_Count >= 5) break;
	}
	Show_Bingo_boder();
	cout << "승리!" << endl;
}