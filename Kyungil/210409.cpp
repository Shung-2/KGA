#include <iostream>
#include <time.h> // 랜덤의 임의의 수를 뽑기 위해 사용한다.
using namespace std;

int main()
{
	// 연산자의 종류
	// 산술연산자
	// +	더하기
	// -	빼기
	// *	곱하기
	// /	나누기
	// %	나머지

	// Random 함수 출력
	// 하지만, rand()는 프로그램이 생성될때 값이 정해지기 때문에 여러번 실행시켜도 동일한 값이 나온다. 
	cout << "rand()의 값은? " << rand() << endl;
	cout << "rand()의 값은? " << rand() << endl;
	cout << "rand()의 값은? " << rand() << endl;
	cout << "rand()의 값은? " << rand() << endl;
	cout << "rand()의 값은? " << rand() << endl;
	cout << "rand()의 값은? " << rand() << endl;
	cout << "rand()의 값은? " << rand() << endl;
	cout << "rand()의 값은? " << rand() << endl << endl;
		
	srand(time(NULL));
	// 이럴떈 위와 같이 선언해주면 rand의 값이 계속 바뀌게 된다.
	int num1 = rand();
	int num2 = rand();

	cout << "num1의 값은? " << num1 << endl;
	cout << "num2의 값은? " << num2 << endl << endl;

	// 주사위
	cout << "랜덤 주사위 범위 출력!" << endl;
	int dice = rand() % 6 + 1;
	// 0 ~ 5의 범위가 나온다. 그렇지만 +1 하면 값의 범위는 1~6이 된다.
	cout << "앞으로 " << dice << " 칸 가세요!" << endl << endl;

	// 디아블로 활 드랍시 활의 데미지 범위가 2~7일 경우를 구하세요
	int bow = rand() % 6 + 2;
	// 0 ~ 5의 범위가 나오지만 +2를 하면 값의 범위는 2~7이 된다.

	// 관계 연산자
	// A > B		A는 B보다 크다
	// A >= B		A는 B보다 크거나 같다.
	// A < B		A는 B보다 작다
	// A <= B		A는 B보다 작거나 같다.
	// A == B		A는 B와 같다.
	// A != B		A와 B는 같지 않다.
	
	// 논리 연산자
	// A && B		A and B		A도 참이고 B도 참일때
	// A || B		A or  B		A랑 B 둘중 하나가 참일 때
	// !A			not A		A가 거짓일 때

	int A = 5, B = 5;
	bool Reslut;

	Reslut = A == B;
	cout << "A == B가 같니? " << Reslut << endl;

	int C = 5, D = 0;
	Reslut = A || B;
	cout << "A || B의 값은? " << Reslut << endl << endl;

	// 조건문
	// 해당 조건이 참일때만 실행이 된다.
	// if 문과, switch 문이 있다.
	// 사망연산자 X, - 삼항연산자 O.

	// if문 (만약 ~ 하면)
	int num = rand() % 10;
	cout << "나온 값 : " << num << endl;

	if (num < 2)
	{
		cout << "SSR이 떴다!" << endl << endl;
	}
	else if (num >= 2 && num < 5)
	{
		cout << "SR이 떴다!" << endl << endl;
	}
	else
	{
		cout << "또 속니 흑우야? 음머~" << endl << endl;
	}

	int LoveNum;
	cout << "케인 아저씨가 좋아하는 숫자를 입력하세요 : ";
	cin >> LoveNum;
	cout << "결과는 ? " << LoveNum << endl;

	if (LoveNum == 5)
	{
		cout << "아이고난1 아이고난2 어떻게 안거야?" << endl << endl;
	}
	else
	{
		cout << "틀렸답니다 뽈롱~" << endl << endl;
	}

	// switch 문
	int Select_Champion;

	cout << "챔프를 고르시오" << endl;
	cout << "1. 아칼리 2. 제드 3. 베인 4. 람머스" << endl;
	cin >> Select_Champion;

	// switch 문은 정수만 입력 가능 하다.
	// 정수 외 문자열, 실수 등은 입력이 되지 않는다.
	switch (Select_Champion)
	{
		case 1:
			cout << "아칼리를 골랐군요" << endl;
		break;

		case 2:		
			cout << "제드를 골랐군요" << endl;
		break;

		case 3:
			cout << "베인을 골랐군요" << endl;
		break;

		case 4:
			cout << "람머스를 골랐군요" << endl;
		break;

		default:
			cout << "지정된 범위 외 숫자를 입력했습니다. " << endl;
		break;
	}
	cout << endl;

	// cout, cin - c++
	// printf, scanf - C
	printf("C언어 출력! \n");
	printf("무야호~ \n\n");

	// 컴퓨터는 랜덤하게 0 ~ 2까지의 숫자를 받는다.
	// 0 바위, 1 가위, 2 보자기 라고 칩시다.
	// 나도 어떤 수를 입력(0~2) 받아서 승패를 출력해보자.

	// 변수 선언 & 사용자 입력
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
	cout << endl;

	// 반복문
	for (int i = 0; i < 5; i++)
	{
		cout << "콩나물 팍팍 무쳤니? " << i + 1 << endl;
	}
	cout << endl;
	
	// 구구단 (2단 출력)
	int GUGU = 2;
	
	for (int i = 1; i <= 9; i++)
	{
		cout << GUGU << " X " << i << " = " << GUGU * i << endl;
	}
	cout << endl;

	// 구구단 (2단 꺼꾸로 출력)
	for (int i = 9; i > 0; i--)
	{
		cout << GUGU << " X " << i << " = " << GUGU * i << endl;
	}
	cout << endl;

	// 구구단 (입력 출력)
	cout << "몇 단을 순서대로 출력할까요?  " << endl;
	int User_Dan = 0;
	cin >> User_Dan;

	for (int i = 1; i < 10; i++)
	{
		cout << User_Dan << " X " << i << " = " << User_Dan * i << endl;
	}
	cout << endl;

	// 구구단 (입력 꺼꾸로 출력)
	cout << "몇 단을 꺼꾸로 출력할까요? " << endl;
	int User_Dan2 = 0;
	cin >> User_Dan2;

	for (int i = 9; i >= 1; i--)
	{
		cout << User_Dan2 << " X " << i << " = " << User_Dan2 * i << endl;
	}
	cout << endl;

	// 구구단 (1~9단, 이중포문)
	cout << "1단부터 9단까지의 구구단 출력" << endl;
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " X " << j << " = " << i * j << endl;
		}
		cout << endl;
	}
	cout << endl;

	// 구구단 (9~1단, 이중포문, 역순)
	cout << "9단부터 1단까지의 구구단 출력" << endl;
	for (int i = 9; i > 0; i--)
	{
		for (int j = 9; j > 1; j--)
		{
			cout << i << " X " << j << " = " << i * j << endl;
		}
		cout << endl;
	}

	// 별찍기
	// *
	// **
	// ***
	// ****
	// *****
	cout << "별찍기!" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	// *****
	// ****
	// ***
	// **
	// *
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	//     *
	//    **
	//   ***
	//  ****
	// *****
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			cout << " ";
		}

		for (int k = 0; k < i + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	// *****
	//  ****
	//   ***
	//    **
	//     *
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		for (int k = 5; k > i; k--)
		{
			cout << "*";
		}
		cout << endl;
	}

	//    *
	//   ***
	//  *****
	// *******
	//*********
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 4; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < i * 2 + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	// *********
	//  *******
	//   *****
	//    ***
	//     *
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int k = i * 2; k < 4 * 2 + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// 반복문
	// 참일떄만 동작한다.
	// 무한루프가 기본
	//while (true)
	//{
	//	cout << "도와줘요" << endl;
	//}

	// 제어문
	// 1. return - 값을 반환하고 종료한다
	// 2. break - 연산을 중단하고 종료한다
	// 3. continue - 연산을 건너 뛴다.

	cout << "Continue, break 연습!" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (i == 3) continue;
		if (i == 5) break;
		cout << i;
	}
	cout << endl << endl;

	int me;
	int count = 9;

	while (true)
	{
		cout << "0. 바위, 1. 가위, 2. 보 골라라. " << endl;
		cin >> me;

		if (me < 0 || me > 2)
		{
			cout << "재 입력하세요 " << endl;
			continue;
		}

		cout << count << " 번의 기회가 남았습니다" << endl;
		count--;

		if (count < 0)
		{
			break;
		}
	}
	cout << endl;

	// 1. 컴퓨터가 0 ~ 999 숫자 중에 하나를 고른다
	// 2. 우리에겐 10번의 기회가 있다.
	// 3. 숫자를 입력하면 큰 지 작은 지 얘기해준다.
	cout << "스무고개 연습!" << endl;
	srand(time(NULL));
	int Computer_Random_Value = rand() % 1000;
	int Conut = 10;
	int User_Input_Value = 0;

	while (true)
	{
		cout << "기회는 " << Conut << "번 있습니다.";
		cout << "숫자를 입력하세요. " << endl;
		cin >> User_Input_Value;

		if (User_Input_Value < Computer_Random_Value)
		{
			cout << "컴퓨터의 숫자가 큽니다." << endl;
		}
		else if (User_Input_Value > Computer_Random_Value)
		{
			cout << "사용자의 숫자가 큽니다" << endl;
		}
		else
		{
			cout << "정답!" << endl;
			break;
		}
		
		Conut--;

		if (Conut == 0)
		{
			cout << "게임 종료" << endl;
			cout << "답은 : " << Computer_Random_Value << "입니다. ";
			break;
		}
	}
	return 0;
}