#include <Windows.h>
#include <iostream>

using namespace std;

int num = 0;

//멀티 쓰레드 동기화는 크게 2가지 개념이 있음
//커널 영역 동기화
//비커널 영역 동기화

//커널 영역 동기화 특징
//뮤텍스, 세마포어 방식이 있음.
//기능이 많으나 그만큼 속도는 느리다고 함

//비커널 영역 동기화 특징
//크리티컬 섹션 방식이 있음 
//기능이 없으나 그만큼 속도는 빠름

CRITICAL_SECTION cs;

DWORD WINAPI threadFunc1(LPVOID lpParam)
{
	//크리티컬 섹션 초기화 하는 것임
	EnterCriticalSection(&cs);

	for (int i = 0; i < 10; i++)
	{
		num++;
		cout << "1번 쓰레드드드드드" << endl;
		cout << num << endl;
	}

	//얘가 데이터 넘겨줌
	LeaveCriticalSection(&cs);

	return 0;
}

DWORD WINAPI threadFunc2(LPVOID lpParam)
{
	//크리티컬 섹션 초기화 하는 것임
	EnterCriticalSection(&cs);

	for (int i = 0; i < 10; i++)
	{
		num++;
		cout << "2번 쓰레드드드드드" << endl;
		cout << num << endl;
	}

	//얘가 데이터 넘겨줌
	LeaveCriticalSection(&cs);

	return 0;
}

int main()
{
	HANDLE thread[2] = { NULL, NULL };


	DWORD dwThread1 = 0;
	DWORD dwThread2 = 1;

	//크리티컬 섹션을 이용한 멀티쓰레드 동기화를 하려면 초기화 필수
	InitializeCriticalSection(&cs);

	thread[0] = CreateThread(NULL, 0, threadFunc1, NULL, 0, &dwThread1);
	thread[1] = CreateThread(NULL, 0, threadFunc2, NULL, 0, &dwThread2);

	//1번째인자 : 기다려야할 오브젝트 수
	//2번째인자 : 쓰레드 포인터 주소값
	//3번째인자 : true : 쓰레드 등록된 전부를 기다림, false는 하나만
	//4번째인자 : 얼마나 기다릴껀지

	WaitForMultipleObjects(2, thread, TRUE, INFINITY);
	
	Sleep(1000);
}