/*
카드게임 규칙 : 
1. 트럼프 카드 모양(◆, ♠, ♥, ♣)을 가진 52개의 카드를 생성하고. 무작위로 섞는다.
2. 각 모양당 각각 13장이 있으며 A = 1, J = 11, Q = 12, K = 13 으로 표시한다
3. 두 장의 카드를 먼저 뽑아 확인하고 세번째 카드를 뽑는다. 
4. 세번째 카드를 뽑기 전에 배팅을 건다. (최소 금액이 존재한다.)
5. 세번째 카드가 두 장의 카드 범위 사이의 숫자면 배팅 금액의 2배를 얻는다.
6. 두 장의 카드 사이의 숫자가 아니라면 현재 금액에서 배팅 금액을 차감한다.
단, 두 장의 카드의 숫자가 같거나 1밖에 차이가 안나더라도 최소 배팅금액은 걸어야 한다
*/

#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

enum Card_Shape
{
	Diamond,
	Spade,
	Heart,
	Clover
};

struct Card
{
	int Shape;
	int Number;
};

void Print_Game_Boder(Card cards)
{
	cout << "|";
	// 문양 출력
	switch (cards.Shape)
	{
	case 0:
		cout << "◆";
		break;
	case 1:
		cout << "♠";
		break;
	case 2:
		cout << "♥";
		break;
	case 3:
		cout << "♣";
		break;
	}
	cout << "  |\n|    |\n|  ";

	// !(2~10) 출력
	switch (cards.Number)
	{
	case 1:
		cout << " A";
		break;
	case 11:
		cout << " J";
		break;
	case 12:
		cout << " Q";
		break;
	case 13:
		cout << " K";
		break;
	// 숫자 출력
	default:
		if (cards.Number != 10)
			cout << " ";
		cout << cards.Number;
	}
	cout << "|" << endl << endl;
}

int main()
{
	srand(time(NULL));
	int User_Money = 100000;
	Card Cards[52];

	// 카드 무늬와 번호 입력
	int Count = 0;

	for (int i = 0; i < 52; i++)
	{
		if (i != 0 && i % 13 == 0) Count++;

		switch (Count)
		{
		case 0:
			Cards[i].Shape = Diamond;
			break;
		case 1:
			Cards[i].Shape = Spade;
			break;
		case 2:
			Cards[i].Shape = Heart;
			break;
		case 3:
			Cards[i].Shape = Clover;
		}
		Cards[i].Number = i % 13 + 1;
	}

	// Shuffle 전용 변수 선언
	int dest, sour;
	Card temp;

	// Shuffle
	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = Cards[dest];
		Cards[dest] = Cards[sour];
		Cards[sour] = temp;
	}

	int idx = 0;
	while (true)
	{
		system("cls");

		int betting_Money = 0;
		int Open_Card[2];
		int destIdx = idx + 2;
		int i = 0;

		cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
		cout << "= = = = = T R U M P - C A R D - B A T I N G - G A M E = = = = =" << endl;
		cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl << endl;
		cout << "A = 1, J = 11, Q = 12, K = 13 " << "\t \t    User_Money : " << User_Money << endl << endl;
		
		for (idx; idx < destIdx; idx++)
		{
			Open_Card[i++] = Cards[idx].Number;
			Print_Game_Boder(Cards[idx]);
		}

		// 0: 작은 수, 1: 큰 수로 정렬하여 쉽게 비교할 수 있게 한다.
		if (Open_Card[0] > Open_Card[1])
		{
			int temp;
			temp = Open_Card[0];
			Open_Card[0] = Open_Card[1];
			Open_Card[1] = temp;
		}

		while (true)
		{
			cout << "배팅 (최소 금액 : 1,000) : ";
			cin >> betting_Money;

			if (1000 > betting_Money)
			{
				cout << " * 경고 - 최소 금액 보다 적습니다." << endl << endl;
				continue;
			}
			else if (betting_Money > User_Money)
			{
				cout << " * 경고 - 소지금보다 많은 금액을 배팅할 수 없습니다." << endl << endl;
				continue;
			}
			break;
		}

		cout << endl << "카드를 오픈합니다." << endl << endl;

		Card New_Open_Card
		{ 
			Cards[idx].Shape, Cards[idx++].Number
		};
		Print_Game_Boder(New_Open_Card);

		if (New_Open_Card.Number > Open_Card[0] && New_Open_Card.Number < Open_Card[1])
		{
			cout << "배팅 금액의 2배인 " << betting_Money * 2 << "원을 획득했습니다! 축하합니다! " << endl << endl;
			User_Money = betting_Money * 2;
		}
		else
		{
			cout << "배팅 금액인 " << betting_Money << "원을 잃었습니다." << endl << endl;
			User_Money -= betting_Money;
		}

		Sleep(3000);

		// 패배조건
		if (User_Money <= 1000)
		{
			cout << "돈을 모두 잃으셨습니다. 더 이상 플레이 할 수 없습니다. " << endl << endl;
			break;
		}

		// 승리조건
		if (User_Money >= 300000)
		{
			cout << "승리 자금을 모았습니다. 승리 !" << endl << endl;
			break;
		}

		// 카드를 모두 다 사용하였을 경우
		if (idx >= 50)
		{
			cout << "카드를 전부 다 사용하였습니다. " << endl;
			break;
		}
	}
	cout << "게임 종료! 당신의 소지금은 : " << User_Money << "원 입니다!" << endl;
	return 0;
}