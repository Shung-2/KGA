#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	// �迭�̶�?
	// ���� ����, �ڷ����� �������� ����	
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

	// 2���� �迭 ����
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

	/* ���� �߱� */
	// ���� �����
	srand(time(NULL));
	int Computer_Ball[3], User_Ball[3];
	int count = 10, Strike = 0, Ball = 0;

	// ��ǻ���� ���� ���� �Է�
	for (int i = 0; i < 3; i++)
	{
		// ���� ����
		Computer_Ball[i] = rand() % 9 + 1;		
		for (int j = 0; j < i; j++)
		{
			// �ߺ� ����
			if (Computer_Ball[i] == Computer_Ball[j] && i != j)
			{
				i--;
			}
		}
	}

	/* ��ǻ���� ���� ��¿�
	cout << "��ǻ���� ���ڴ� : ";
	for (int i = 0; i < 3; i++)
	{
		cout << Computer_Ball[i] << ' ';
	}
	cout << "�Դϴ�. " << endl;
	*/

	while (true)
	{
		// ��ȸ ���
		cout << "�� " << count << "���� ��ȸ�� �ֽ��ϴ�." << " ���ڸ� �Է��ϼ��� : ";
		// ����� ���� �Է� ����
		for (int i = 0; i < 3; i++)
		{
			cin >> User_Ball[i];
		}

		// ����� ���� ��¿�
		for (int i = 0; i < 3; i++)
		{
			cout << User_Ball[i] << ' ';
		}

		// Strike, Ball üũ
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

		// ��� ���
		if (Strike || Ball)
		{
			cout << "��Ʈ����ũ : " << Strike << " �� : " << Ball << endl;
		}
		else
		{
			cout << "��ġ�ϴ� ���� �����ϴ�." << endl;
		}

		// �¸� ����
		if (Strike == 3)
		{
			cout << "�¸�!" << endl;
			break;
		}
		// �й� ����
		if (count == 1)
		{
			cout << "�й�!" << endl;
			break;
		}

		// ī��Ʈ ���� �� ��Ʈ����ũ, �� �ʱ�ȭ
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

	// ����
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

	// ����ü == ��ü��� �Ѵ�.
	// ���� �ٸ� ������ ����ü
	// ����ü = struct

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