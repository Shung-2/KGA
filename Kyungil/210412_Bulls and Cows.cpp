#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	// 변수 선언
	srand(time(NULL));
	int Computer_Ball[3], User_Ball[3];
	int Count = 1, Strike = 0, Ball = 0;

	// 컴퓨터 범위 설정 (중복 제거)
	for (int i = 0; i < 3; i++)
	{
		Computer_Ball[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++)
		{
			if (Computer_Ball[i] == Computer_Ball[j] && i != j)
			{
				i--;
			}
		}
	}

	cout << "컴퓨터의 숫자는 : ";
	for (int i = 0; i < 3; i++)
	{
		cout << Computer_Ball[i] << ' ';
	}
	cout << "입니다. " << endl;

	while (true)
	{
		// 카운트 출력
		cout << Count << "번째 기회입니다 : ";
		// 사용자 숫자 입력
		for (int i = 0; i < 3; i++)
		{
			cin >> User_Ball[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cout << User_Ball[i] << ' ';
		}

		// S, B 체크
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
			cout << "스트라이크는 : " << Strike << " 볼은 : " << Ball << endl;
		}
		else
		{
			cout << "일치하는 것이 없습니다." << endl;
		}

		// 승리조건
		if (Strike == 3)
		{
			cout << "승리 !" << endl;
			break;
		}
		// 패배 조건
		if (Count == 10)
		{
			cout << "아웃 !" << endl;
			break;
		}
		Count++, Strike = 0, Ball = 0;
	}
	return 0;
}