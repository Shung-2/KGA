#include <Windows.h>
#include <iostream>

using namespace std;

int num = 0;

//��Ƽ ������ ����ȭ�� ũ�� 2���� ������ ����
//Ŀ�� ���� ����ȭ
//��Ŀ�� ���� ����ȭ

//Ŀ�� ���� ����ȭ Ư¡
//���ؽ�, �������� ����� ����.
//����� ������ �׸�ŭ �ӵ��� �����ٰ� ��

//��Ŀ�� ���� ����ȭ Ư¡
//ũ��Ƽ�� ���� ����� ���� 
//����� ������ �׸�ŭ �ӵ��� ����

CRITICAL_SECTION cs;

DWORD WINAPI threadFunc1(LPVOID lpParam)
{
	//ũ��Ƽ�� ���� �ʱ�ȭ �ϴ� ����
	EnterCriticalSection(&cs);

	for (int i = 0; i < 10; i++)
	{
		num++;
		cout << "1�� ����������" << endl;
		cout << num << endl;
	}

	//�갡 ������ �Ѱ���
	LeaveCriticalSection(&cs);

	return 0;
}

DWORD WINAPI threadFunc2(LPVOID lpParam)
{
	//ũ��Ƽ�� ���� �ʱ�ȭ �ϴ� ����
	EnterCriticalSection(&cs);

	for (int i = 0; i < 10; i++)
	{
		num++;
		cout << "2�� ����������" << endl;
		cout << num << endl;
	}

	//�갡 ������ �Ѱ���
	LeaveCriticalSection(&cs);

	return 0;
}

int main()
{
	HANDLE thread[2] = { NULL, NULL };


	DWORD dwThread1 = 0;
	DWORD dwThread2 = 1;

	//ũ��Ƽ�� ������ �̿��� ��Ƽ������ ����ȭ�� �Ϸ��� �ʱ�ȭ �ʼ�
	InitializeCriticalSection(&cs);

	thread[0] = CreateThread(NULL, 0, threadFunc1, NULL, 0, &dwThread1);
	thread[1] = CreateThread(NULL, 0, threadFunc2, NULL, 0, &dwThread2);

	//1��°���� : ��ٷ����� ������Ʈ ��
	//2��°���� : ������ ������ �ּҰ�
	//3��°���� : true : ������ ��ϵ� ���θ� ��ٸ�, false�� �ϳ���
	//4��°���� : �󸶳� ��ٸ�����

	WaitForMultipleObjects(2, thread, TRUE, INFINITY);
	
	Sleep(1000);
}