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
using namespace std;

void main()
{
	srand(time(NULL));

	// 변수 선언
	int card[52];					// 52개의 카드를 담은 배열 선언
	int shape[3], number[3];		// 카드의 문양과 숫자를 출력하기 위한 2개의 카드 배열 선언
	int user_money = 100000;		// 사용자의 초기 금액은 10만원으라는 변수 선언
	int betting;					// 배팅을 하기 위한 변수 선언
	int dest, sour, temp;			// 셔플용 변수 선언
	int turn = 2;					// 처음에 카드를 2장 깔고 시작하므로.

	// 카드에 값 입력
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}

	// 셔플
	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = card[dest];
		card[dest] = card[sour];
		card[sour] = temp;
	}

	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			// 모양을 나타낸다.
			shape[i] = card[i + turn - 2] / 13; 
			// 숫자를 나타낸다
			number[i] = card[i + turn - 2] % 13;

			// card 배열 내부 값이 아닌 인덱스임을 명심하자.

			if (i == 2) break;

			// 모양 출력
			switch (shape[i])
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

			// 숫자 출력
			switch (number[i])
			{
			case 0:
				cout << "A \t";
				break;
			case 11:
				cout << "J \t";
				break;
			case 12:
				cout << "Q \t";
				break;
			case 13:
				cout << "K \t";
				break;
			default:
				cout << number[i] + 1 << "\t";
				break;
			}
		}

		// 배팅 금액 입력
		cout << "\n\n";
		cout << "총 소지금 : " << user_money << endl;
		cout << "배팅 (최소 금액 1000원) : ";
		cin >> betting;

		// 배팅 범위 지정
		if (betting < 1000)
		{
			cout << "금액이 너무 적습니다." << endl;
			continue;
		}
		else if (betting > user_money)
		{
			cout << "금액보다 많은 돈을 배팅할 수 없습니다. " << endl;
			continue;
		}
		
		// 돈을 획득하거나, 잃는 조건
		if ((number[0] < number[2] && number[2] < number[1]) ||
			(number[1] < number[2] && number[2] < number[0]))
		{
			user_money = betting * 2;
			cout << betting * 2 << "원 획득" << endl << endl;
		}
		else
		{
			user_money -= betting;
			cout << betting << "원 날림" << endl << endl;
		}		

		turn += 3;

		// 게임 승리 조건
		if (user_money > 300000)
		{
			cout << "승리!" << endl;
			break;
		}

		// 게임 패배 조건
		if (user_money < 1000)
		{
			cout << "패배!" << endl;
			break;
		}
	}
}