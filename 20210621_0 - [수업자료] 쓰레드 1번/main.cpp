#include <windows.h>
#include <iostream>

using namespace std;

static int num = 0;

DWORD WINAPI threadFunc1(LPVOID lParam)
{
	while (true)
	{
		num++;
		cout << "���� : " << num << endl;
		cout << "������ 1��!!!!!!" << endl;
	}
}

DWORD WINAPI threadFunc2(LPVOID lParam)
{
	while (true)
	{
		num++;
		cout << "���� : " << num << endl;
		cout << "������ 2��!!!!!!" << endl;
	}
}


int main()
{
	HANDLE thread1 = NULL;
	HANDLE thread2 = NULL;

	DWORD dwThread1 = 0;
	DWORD dwThread2 = 1;

	thread1 = CreateThread(NULL, 0, threadFunc1, NULL, 0, &dwThread1);
	thread2 = CreateThread(NULL, 0, threadFunc2, NULL, 0, &dwThread2);

	//1. �������� ���ȼӼ� ����
	//�ڽ� �����찡 �ִ� ��쿡 �θ������쿡�� ������ ���μ��� �ڵ���
	//��ӵǾ� �ִ� ��쿡�� ����Ѵٰ� ��.

	//2. �������� ���ø޸� ũ�� ����
	//0���� �θ� ���ξ����� ���� ũ��� ����
	//���ÿ����÷� ���� ������ ���� ������ ���������ϰ� �Ǿ��ִٰ� ��.

	//3. ����� ������ �Լ� �̸�

	//4. ������ ���� �Ѱ��� ������ ����, ������ NULL�� �����Ѵ�.

	//5. 0�� ���� �����带 ��Ī�Ѵ�.
	//CREATE_SUSPENDED ��ɾ ����ϸ� �����尡 ���� ������� �ʴ´�.
	//�ٽ� �����ؾ��ϴ� ���� ResumeThread() �Լ��� �����ϸ� �ȴ�.

	//6. ������ ���� ID��ȣ
	//������ 7 ���ĺ��ʹ� NULL�� ����ϸ� ������ ������ �ȵȴ�
	//�׷��� �������� ����ؼ� DWORD�� ����Ѵٰ� ��.

	Sleep(1000);

	return 0;
}