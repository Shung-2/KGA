#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));
	
	// 변수 선언
	int user_money = 500000;	// 사용자의 초기 금액을 10만원으로 설정
	int card[52];				// 52개의 카드를 담을 배열 선언
	int shape[3], number[3];	// 카드의 문양과 숫자를 출력하기 위한 배열 선언
	int dest, sour, temp;		// 셔플용 변수 선언
	int betting;				// 배팅을 하기 위한 변수 선언
	int turn = 2;				// 처음에 카드를 2장 깔고 시작하므로 2를 두고 설정 (배열의 인덱스의 -값이 들어가는 것을 방지)

	// 카드에 값 삽입
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
			// 숫자를 나타낸다.
			number[i] = card[i + turn - 2] % 13;
			// 주의! card 배열 값이 아닌 인덱스의 값임을 명심하자

			if (i == 2) break;

			// 모양 출력
			switch (shape[i])
			{
			case 0:
				cout << "◆ ";
				break;
			case 1:
				cout << "♠ ";
				break;
			case 2:
				cout << "♥ ";
				break;
			case 3:
				cout << "♣ ";
				break;
			}

			// 숫자 출력
			switch (number[i])
			{
			case 0:
				cout << "A ";
				break;
			case 11:
				cout << "J ";
				break;
			case 12:
				cout << "Q ";
				break;
			case 13:
				cout << "K ";
				break;
			default:
				cout << number[i] << "\t";
			}
			cout << endl << endl;
		}

		// 배팅 금액 입력
		cout << "총 소지금 : " << user_money << endl;
		cout << "배팅 (최소금액 100) : ";
		cin >> betting;

		// 배팅 범위 지정
		if (betting < 100)
		{
			cout << "금액이 너무 적다" << endl << endl;
			continue;
		}
		else if (user_money < betting)
		{
			cout << "가지고 있는 돈보다 더 많이 배팅할 순 없다" << endl << endl;
			continue;
		}

		// 돈을 따거나, 잃는 조건
		if (number[0] < number[2] && number[2] < number[1] ||
			number[1] < number[2] && number[2] < number[0])
		{
			user_money = betting * 2;
			cout << betting << " 원을 획득!" << endl << endl;
		}
		else
		{
			user_money -= betting;
			cout << betting << " 원을 잃음!" << endl << endl;
		}

		turn += 3;

		// 승리조건
		if (user_money > 300000)
		{
			cout << "승리" << endl;
			break;
		}

		// 패배조건
		if (user_money < 1000)
		{
			cout << "돈이 없습니다. 패배!" << endl;
			break;
		}
	}
}