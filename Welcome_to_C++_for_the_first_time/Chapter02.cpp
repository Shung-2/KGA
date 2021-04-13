#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;

void Problem115_1()
{
	string a, b;

	cout << "첫 번째 문자열 : ";
	cin >> a;
	cout << "두 번째 문자열 : ";
	cin >> b;

	if (a == b)
		cout << "두 문자열을 같습니다. " << endl << endl;
	else
		cout << "두 문자열은 다릅니다. " << endl << endl;
}

void Problem115_2()
{
	int value;

	cout << "콜라, 물, 스프라이트, 주스, 커피 중에서 하나를 선택하세요 : ";
	cin >> value;

	switch (value)
	{
	case 1:
		cout << "콜라를 선택했습니다.";
		break;
	case 2:
		cout << "물을 선택했습니다.";
		break;
	case 3:
		cout << "스프라이트를 선택했습니다.";
		break;
	case 4:
		cout << "주스를 선택했습니다.";
		break;
	case 5:
		cout << "커피를 선택했습니다.";
		break;
	default:
		cout << "오류. 선택이 유효하지 않습니다. 돈을 반환합니다.";
		break;
	}	
}

void Problem115_3()
{
	int day[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 0; i < 12; i++)
	{
		cout << i + 1 << "월은 " << day[i] << "일 까지 있습니다." << endl;
	}
}

void Problem115_4()
{
	int userval;
	for (int i = 0; i < 5; i++)
	{
		cout << "정수를 입력하세요 : ";
		cin >> userval;

		if (userval == 5)
		{
			cout << "5를 입력하셨군요! 컴퓨터 승!";
			break;
		}
		
		if (i == 4)
			cout << "인내심이 강하군요. 사용자 승!";
	}
}

void Problem115_5()
{
	int user_val, result = 0;
	
	while (true)
	{
		cout << "정수를 입력하세요 : ";
		cin >> user_val;
		result += user_val;
		if (user_val == 0)
			break;
	}
	cout << "합계 : " << result;
}

void Problem115_6()
{
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << j + 1;
		}

		for (int k = 7; k > i; k--)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void Problem115_7()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			cout << i << " ";
	}
}

void Problem115_8()
{
	int val;
	cout << "정수를 입력하세요 : ";
	cin >> val;

	for (int i = 1; i <= val; i++)
		if (val % i == 0)
			cout << i << " ";
}

void Problem115_9()
{
	double c = 0;

	for (int i = 0; i <= 10; i++)
	{
		c = (i * 10 - 32.0) * 5.0 / 9.0;
		cout << i * 10 << "	" << c << endl;
	}
}

void Problem115_10()
{
	for (int a = 1; a < 100; a++)
		for (int b = 1; b < 100; b++)
			for (int c = 1; c < 100; c++)
				if (pow(a, 2) + pow(b, 2) == pow(c, 2))
					cout << a << " " << b << " " << c << endl;
}

void Problem115_11()
{
	int user_val, sum = 1;
	cout << "n의 값을 입력하시오 : ";
	cin >> user_val;
	
	for (int i = 1; i <= user_val; i++)
	{
		sum += i * i;
	}
	cout << "계산값은 : " << sum << "입니다.";
}

void Problem115_12()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			cout << "박수 ";
		else
			cout << i << " ";
	}
}

void Problem115_13()
{
	int input;
	int a = 0, b = 1;
	int temp;

	cout << "몇 항까지 구할까요 ? : ";
	cin >> input;

	cout << a << " " << b << " ";

	for (int i = 2; i < input; i++)
	{
		temp = b;
		b = a + b;
		a = temp;

		cout << b << " ";
	}
}

void Problem115_14()
{
	char op;
	int x, y, result;

	cout << "연산의 종류 : ";
	cin >> op;

	cout << "숫자를 입력하시오 : ";
	cin >> x >> y;

	switch (op)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		if (y == 0)
		{
			cout << "분모가 0입니다. 나눗셈을 할 수 없습니다." << endl;
			result = 0;
			break;
		}
		result = x / y;
	default:
		break;
	}

	cout << "계산의 결과 : " << result << endl;
}

void Problem115_15()
{
	int Computer_Random_Vlaue = rand() % 3;
	int User_Ball;
	cout << "어떤 수를 입력하시겠습니까?" << endl;
	cout << "1. 바위 2. 가위 3. 보" << endl;
	cin >> User_Ball;

	// switch 문을 이용한 결과 출력 :)
	switch (Computer_Random_Vlaue)
	{
	case 0:
		cout << "컴퓨터는 바위를 냈습니다" << endl;
		if (User_Ball == 1)
			cout << "비겼습니다." << endl;
		else if (User_Ball == 2)
			cout << "당신이 졌습니다" << endl;
		else
			cout << "당신이 이겼습니다" << endl;
		break;
	case 1:
		cout << "컴퓨터는 가위를 냈습니다" << endl;
		if (User_Ball == 1)
			cout << "당신이 이겼습니다." << endl;
		else if (User_Ball == 2)
			cout << "비겼습니다" << endl;
		else
			cout << "당신이 졌습니다" << endl;
		break;
	case 2:
		cout << "컴퓨터는 보를 냈습니다" << endl;
		if (User_Ball == 1)
			cout << "당신이 졌습니다." << endl;
		else if (User_Ball == 2)
			cout << "당신이 이겼습니다" << endl;
		else
			cout << "비겼습니다." << endl;
		break;
	default:
		cout << "범위 외 숫자를 입력했습니다." << endl;
	}
}

void Problem115_16()
{
	int cash = 50;
	const int goal = 250;

	int bets, win; // 각 시뮬레이션 당 베팅수, 이긴 횟수
	bool result; // 승/패 결과
	int wins = 0; // 1000번 시뮬레이션 중 이긴 횟수
	int total = 0; // 베팅한 횟수를 모두 더할 변수

	srand((unsigned int)time(NULL));

	cout << "초기 금액 $" << cash << endl;
	cout << "목표 금액 $" << goal << endl;

	// 승리확률을 알아보기 위한 1000번의 시뮬레이션
	for (int game = 0; game < 1000; game++)
	{
		cash = 50, bets = 0, win = 0; // 초기 설정 reset
		while (true)
		{
			bets++;
			if ((double)rand() / RAND_MAX < 0.5)
			{
				cash++;
				win++;
			}
			else
				cash--;

			if (cash <= 0)
			{
				result = false;
				break;
			}
			if (cash >= goal)
			{
				result = true;
				break;
			}
		}

		if (result == true)
			wins++; // 각 시뮬레이션당 승리 횟수 계산
		total += bets; // 각 시뮬레이션당 베팅 수 총합 계산
	}

	cout << "1000 중의 " << wins << "번 승리" << endl;
	cout << fixed; // 소수점 아래 자리 고정
	cout.precision(6); // 소수점 아래 6자리까지 지정
	cout << "이긴 확률=" << wins / 1000.0 * 100.0 << endl;
	cout << "평균 배팅 횟수 = " << total / 1000.0 << endl;
}

int main()
{
	// Problem115_1();
	// Problem115_2();
	// Problem115_3();
	// Problem115_4();
	// Problem115_5();
	// Problem115_6();
	// Problem115_7();
	// Problem115_8();
	// Problem115_9();
	// Problem115_10();
	// Problem115_11();
	// Problem115_12();
	// Problem115_13();
	// Problem115_14();
	// Problem115_15();
	// Problem115_16();
	return 0;
}