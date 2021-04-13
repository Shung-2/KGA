#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

// ��ó����
#define ZOMBIE_MAX 10000
#define CASHUSER

// ��ũ��
#define PI 3.14f
#define PI2 PI * 2
#define PLUS(x) x + x
// defind���� ����� ���� ������, ����Ŭ���� ���� �ʴ´�.

int main()
{
	// ����ȯ == casting
	float MoveSeppd = 3.3f;
	int distance = MoveSeppd * 3;
	
	// �Ǽ��� float�� ������ int�� ���� �Ǿ��� ������ ��µǴ� int�� ������ �Ҽ��� ǥ���� ���� �ʴ´�. �׷��� .9�� �α׸� ���ư���. 
	// �̷��� ���� ����ȯ �Ϸ��� �Ѱ� �ƴ����� ����ȯ ó���� �Ǿ���� ���� ������ ����ȯ�̶�� �Ѵ�.
	cout << "�̵��� �Ÿ� : " << distance << endl;

	// ���� ����ȯ�� ����������ν� ĳ���� �ϴ� ���� ����� ����ȯ�̶�� �Ѵ�.
	cout << "�̵��� �Ÿ� : " << (int)MoveSeppd << endl;

	int a = 65;
	cout << a << endl;
	// C��� Ȥ�� C#���� ���� ĳ����
	cout << (char)a << endl;

	// C++ Casting
	// 1. static_cast
	// C��Ÿ���� ����ȯ�� ����� ������ ����ȯ�� ���輺�� ����� �ѹ� ������ ���� ��ȯ�Ѵ�.
	cout << static_cast<char>(a) << endl;

	// 2. dynamic_cast
	// ��Ӱ��迡�� ������ ��Ӱ������� ��ĳ���� �Ǵ� �ٿ�ĳ���� �ҋ� ���� �ſ� ���ϴ�.
	// ���� : �ӵ��� ������.

	// reinterpret_cast
	// ���� ����ȯ

	// ��ó���⸦ �̿��� ����
	int zombie[ZOMBIE_MAX];
	int dest, sour, temp;

	for (int i = 0; i < ZOMBIE_MAX, i++)
		zombie[i] = i + 1;

	// �����ִ� Ƚ�� (���� �˰���)
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
	
	// ifdef�� ����.
#ifdef CASHUSER
	{
		cout << "�ɷ�ġ �����ϰ�" << endl;
	}
#else
	{
		cout << "�⺻������" << endl;
	}
#endif

	#define X(X) x*x
	// ������ ����
	// X(5 + 2)�� 49�� �ƴ϶� 17�̴�.
	// Ǯ�� X(5+2) 5 + 2 * 5 + 2 �̹Ƿ� 2 * 5 + 5 + 2�� �ȴ�. ��� 17.

	return 0;
}