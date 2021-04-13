#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	// 배열이란?
	// 같은 변수, 자료형의 연속적인 나열	
	int num1[5];
						// sizeof(int) == 4
	num1[0] = 1;		// 1000 + 4 * 0
	num1[1] = 2;		// 1000 + 4 * 1
	num1[2] = 3;		// 1000 + 4 * 2
	num1[3] = 4;		// 1000 + 4 * 3
	num1[4] = 5;		// 1000 + 4 * 4

	int num2[30];
	for (int i = 0; i < 30; i++)
	{
		num2[i] = i + 1;
	}

	for (int i = 0; i < 30; i++)
	{
		cout << num2[i] << endl;
	}

	// 2차원 배열 선언
	int number1[3][3];
	number1[0][0];
	number1[0][1];
	number1[0][2];
	number1[1][0];
	number1[1][1];
	number1[1][2];
	number1[2][0];
	number1[2][1];
	number1[2][2];

	/* 숫자 야구 */
	// 변수 선언부
	srand(time(NULL));
	int Computer_Ball[3], User_Ball[3];
	int count = 10, Strike = 0, Ball = 0;

	// 컴퓨터의 랜덤 숫자 입력
	for (int i = 0; i < 3; i++)
	{
		// 범위 설정
		Computer_Ball[i] = rand() % 9 + 1;		
		for (int j = 0; j < i; j++)
		{
			// 중복 제거
			if (Computer_Ball[i] == Computer_Ball[j] && i != j)
			{
				i--;
			}
		}
	}

	/* 컴퓨터의 숫자 출력용
	cout << "컴퓨터의 숫자는 : ";
	for (int i = 0; i < 3; i++)
	{
		cout << Computer_Ball[i] << ' ';
	}
	cout << "입니다. " << endl;
	*/

	while (true)
	{
		// 기회 출력
		cout << "총 " << count << "번의 기회가 있습니다." << " 숫자를 입력하세요 : ";
		// 사용자 숫자 입력 받음
		for (int i = 0; i < 3; i++)
		{
			cin >> User_Ball[i];
		}

		// 사용자 숫자 출력용
		for (int i = 0; i < 3; i++)
		{
			cout << User_Ball[i] << ' ';
		}

		// Strike, Ball 체크
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Computer_Ball[i] == User_Ball[j])
				{
					if (i == j)
					{
						Strike++;
					}
					else
					{
						Ball++;
					}
				}
			}
		}

		// 결과 출력
		if (Strike || Ball)
		{
			cout << "스트라이크 : " << Strike << " 볼 : " << Ball << endl;
		}
		else
		{
			cout << "일치하는 것이 없습니다." << endl;
		}

		// 승리 조건
		if (Strike == 3)
		{
			cout << "승리!" << endl;
			break;
		}
		// 패배 조건
		if (count == 1)
		{
			cout << "패배!" << endl;
			break;
		}

		// 카운트 감소 및 스트라이크, 볼 초기화
		count--, Strike = 0, Ball = 0;
	}

	// swap
	int a = 3;
	int b = 7;
	int c;

	c = a;
	a = b;
	b = c;


	int number2[10];
	for (int i = 0; i < 10; i++)
	{
		number2[i] = i + 1;
	}

	// 셔플
	int dest, sour, temp;
	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 10; 
		sour = rand() % 10; 

		temp = number2[dest];
		number2[dest] = number2[sour];
		number2[sour] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << number2[i] << endl;
	}

	// 구조체 == 객체라고 한다.
	// 서로 다른 변수의 집합체
	// 구조체 = struct

	struct tagUnit
	{
		int hp, mp;
		float speed, criPer;
		bool isDead;
	};

	tagUnit corona;

	corona.hp = 400000;
	corona.mp = 0;
	corona.criPer = 50.0f;
	corona.speed = 32000.f;
	corona.isDead = true;

	tagUnit rabbit[3];

	for (int i = 0; i < 3; i++)
	{		
		rabbit[i].hp = rand() % 50 + 20;
	}

	return 0;
}