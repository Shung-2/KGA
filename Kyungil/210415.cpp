#include <iostream>
#include <time.h>

using namespace std;

enum TEST
{
	ZERO,
	ONE,
	TWO
};

enum MARIOSTATE
{
	RIGHT_IDEL,
	LEFT_IDEL,
	RIGHT_RUN,
	LEFT_RUN,
	RIGHT_JUMP,
	LEFT_JUMP
};

int main()
{
	// enum == 열거형
	int number[3];

	number[ZERO] = 1;
	number[ONE] = 3;
	number[TWO] = 5;
	// 위 문장을 풀어서 이해하면 number[0] = 1, number[1] = 3, number[2] = 5과 같다.

	// 마리오를 이용한 예제
	MARIOSTATE marioState;

	marioState = RIGHT_IDEL;

	if (marioState == RIGHT_IDEL)
		marioState == RIGHT_RUN;

	/* 
	// 스위치 문에 enum문을 작성할때 Tab을 눌러주면 자동완성해준다!
	switch (marioState)
	{
	case RIGHT_IDEL:
		break;
	case LEFT_IDEL:
		break;
	case RIGHT_RUN:
		break;
	case LEFT_RUN:
		break;
	case RIGHT_JUMP:
		break;
	case LEFT_JUMP:
		break;
	default:
		break;
	}
	*/

	int num;
	cout << "1. 왼쪽서기, 2. 오른쪽 달리기 3. 왼쪽 달리기" << endl;
	cout << "마리오의 행동을 입력하세요 : ";
	cin >> num;

	// ERROR로 인한 주석처리
	marioState = num;
	// 해당 문장은 각각의 형이 맞지 않아 실행되지 않는다.
	// marioState는 enum 형태이므로 num 앞에 형을 명시해줘야한다.,
	// 고로 아래와 같이 사용해줘야 한다.
	marioState = (MARIOSTATE)num;

	// 그렇지만 꼭 ENUM을 0부터 사용하라는 법은 없다. 각각의 변수에 값을 대입해도 된다.
	// 이하 예)
	/*
	enum MARIOSTATE2
	{
		RIGHT_IDEL = 5,
		LEFT_IDEL = 3,
		RIGHT_RUN = 7,
		LEFT_RUN = 11,
		RIGHT_JUMP,
		LEFT_JUMP
	};
	*/
	// 각각의 변수에 정수형 값을 삽입할 수도 있으며 LEFT_RUN가 11이므로 RIGHT_JUMP의 값은 12가 된다.

	// enum과 enum class의 차이
	// -> https://unikys.tistory.com/376
	
	/* = = = 문 자 열 = = = */
	// 1. strlen()
	// 문자열의 길이를 반환해주는 함수
	char str[5] = "star";
	// str을 4로 설정하면 star 맨 끝에 있는 개행이 들어가지 못하므로 5로 설정해줘야 한다
	// 아래는 배열에 들어간 값이다.
	// star[0] = s
	// star[1] = t
	// star[2] = a
	// star[3] = r
	// star[4] = '/0'

	int size = strlen(str);
	cout << "문자열 길이는 : " << size << endl;
	// 문법적으로는 s, t, a, r, /0이라 5라고 생각할 수 있지만 /0을 제외한 4가 맞다.

	char str2[128] = "i kill you c++ SSIBAL";
	int size2 = strlen(str2);
	cout << "문자열 길이는 : " << size2 << endl;

	// 2. strcmp()
	// 문자열 비교 함수
	// 두 문자열을 비교하여 오른쪽이 크면 -1, 왼쪽이 크면 1
	// 두 문자열이 같으면 0을 반환한다.

	char str3[64] = "abc";
	char str4[64] = "abd";

	int result = strcmp(str3, str4);

	// 게임 내 정보를 세이브 파일로 불어올 때 예외처리할 떄 사용된다.
	cout << result << endl;

	// 3. strcat
	// 오른쪽 문자열을 왼쪽에 이어 붙여준다.
	// 왼쪽 문자열은 오른쪽 문자열을 포함할 버퍼값(배열크기)를 가지고 있어야 한다
	char str5[128] = "oh! ";
	char str6[64] = "i'm going home!";

	strcat_s(str5, str6);
	cout << str5 << endl;

	// 4. strcpy
	// 오른쪽의 문자열을 왼쪽으로 복사해준다.
	// 당연히 왼쪽 문자열 버퍼가 오른쪽 문자열 보다 크거나 같아야 한다
	char str7[6] = "apple";
	char str8[6];

	strcpy_s(str8, str7);
	cout << str7 << endl;
	
	// 문자열 뒤집기
	char str9[128];
	cin >> str9;

	// 바나나를 입력한다고 하자.
	// str[0] = 'b'	 str[0] = '\n'
	// str[1] = 'a'	 str[0] = 'a'
	// str[2] = 'n'	 str[0] = 'n'
	// str[3] = 'a'	 str[0] = 'a'
	// str[4] = 'n'	 str[0] = 'n'
	// str[5] = 'a'	 str[0] = 'a'
	// str[6] = '\n' str[0] = 'b'
	
	for (int i = strlen(str9) - 1; i >= 0; i--)
	{
		cout << str9[i];
	}

	// 문자열 짝수번쨰만 꺼꾸로 출력하기
	// 1. 문자열을 입력받아라
	// 2. 입력받은 문자열중 짝수번째 문자만 꺼구로 출력되게 하라
	// 예) a, b, c, d, e => a, d, c, b, e

	char str10[128];
	cin >> str10;

	// 서순 출력
	cout << "서순 출력 : ";
	for (int i = 0; i < strlen(str10); i++)
	{
		cout << str10[i];
	}
	cout << endl;

	// 짝수번째 문자만 거꾸로 출력 [선생님]
	cout << "짝수번째 문자만 거꾸로 출력 : ";
	for (int i = 0; i < strlen(str10); i++)
	{
		// 짝수번째 문자열이면 == 홀수번째 배열 인덱스
		if (i % 2 == 1)
		{
			if (strlen(str10) % 2 == 0)
			{
				// 5에서 뺴느냐
				cout << str10[strlen(str10) - i];
			}
			else
			{
				// 6에서 뺴느냐
				cout << str10[strlen(str10) - i - 1];
			}
		}
		// 홀수번째 문자열이면 == 짝수째 배열 인덱스
		else
		{
			cout << str10[i];
		}
	}

	// 짝수번째 문자만 거꾸로 출력 [선생님것 보고]
	cout << "짝수번째 문자만 거꾸로 출력 : ";
	for (int i = 0; i < strlen(str10); i++)
	{
		if (i % 2 == 1)
		{
			// strlen 참조 대상 배열이 짝수인 경우
			if (strlen(str10) % 2 == 0)
			{
				cout << str10[strlen(str10) - i];
			}
			// strlen 참조 대상 배열이 홀수인 경우
			else
			{
				cout << str10[strlen(str10) - i - 1];
			}
		}
		else
		{
			cout << str10[i];
		}
	}
	cout << endl;

	// 짝수번째 문자만 거꾸로 출력 [스스로]
	cout << "짝수번째 문자만 거꾸로 출력 : ";
	for (int i = 0; i < strlen(str10); i++)
	{
		if (i % 2 == 1)
		{
			if (strlen(str10) % 2 == 0)
			{
				cout << str10[strlen(str10) - i];
			}
			else
			{
				cout << str10[strlen(str10) - i - 1];
			}
		}
		else
		{
			cout << str10[i];
		}
	}

	// 삼항연산자
	// 항이 3개여서 삼항 연산자라고 한다
	// 문법 구조는
	// 조건 ? 참 : 거짓
	// 조건이 참일때 참 영역이 실행되고 아니면 거짓 영역이 실행됨
	cout << endl << endl;
	int luckynum = 7;
	luckynum == 7 ? cout << "yes" : cout << "no";
}