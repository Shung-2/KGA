#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

// 전처리기
#define ZOMBIE_MAX 10000
#define CASHUSER

// 매크로
#define PI 3.14f
#define PI2 PI * 2
#define PLUS(x) x + x
// defind문은 디버깅 되지 않으며, 세미클론을 찍지 않는다.

int main()
{
	// 형변환 == casting
	float MoveSeppd = 3.3f;
	int distance = MoveSeppd * 3;
	
	// 실수형 float이 정수형 int에 대입 되었기 떄문에 출력되는 int형 변수는 소수점 표현이 되지 않는다. 그래서 .9가 싸그리 날아간다. 
	// 이렇게 내가 형변환 하려고 한건 아니지만 형변환 처리가 되어버린 것을 묵시적 형변환이라고 한다.
	cout << "이동한 거리 : " << distance << endl;

	// 내가 형변환을 명시해줌으로써 캐스팅 하는 것을 명시적 형변환이라고 한다.
	cout << "이동한 거리 : " << (int)MoveSeppd << endl;

	int a = 65;
	cout << a << endl;
	// C언어 혹은 C#에서 쓰는 캐스팅
	cout << (char)a << endl;

	// C++ Casting
	// 1. static_cast
	// C스타일의 형변환과 기능이 같지만 형변환의 위험성을 고려해 한번 점검한 다음 변환한다.
	cout << static_cast<char>(a) << endl;

	// 2. dynamic_cast
	// 상속관계에서 누구와 상속관계인지 업캐스팅 또는 다운캐스팅 할떄 쓰면 매우 편리하다.
	// 단점 : 속도가 느리다.

	// reinterpret_cast
	// 강제 형변환

	// 전처리기를 이용한 셔플
	int zombie[ZOMBIE_MAX];
	int dest, sour, temp;

	for (int i = 0; i < ZOMBIE_MAX, i++)
		zombie[i] = i + 1;

	// 섞어주는 횟수 (셔플 알고리즘)
	for (int i = 0; i < 100; i++)
	{
		dest = rand() % 10; // 8
		sour = rand() % 10; // 7

		temp = zombie[dest];
		zombie[dest] = zombie[sour];
		zombie[sour] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << zombie[i] << endl;
	}
	
	// ifdef의 예제.
#ifdef CASHUSER
	{
		cout << "능력치 빠빵하게" << endl;
	}
#else
	{
		cout << "기본적으로" << endl;
	}
#endif

	#define X(X) x*x
	// 공명의 함정
	// X(5 + 2)는 49가 아니라 17이다.
	// 풀이 X(5+2) 5 + 2 * 5 + 2 이므로 2 * 5 + 5 + 2가 된다. 고로 17.

	return 0;
}