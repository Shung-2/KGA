#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;

void Problem115_1()
{
	string a, b;

	cout << "ù ��° ���ڿ� : ";
	cin >> a;
	cout << "�� ��° ���ڿ� : ";
	cin >> b;

	if (a == b)
		cout << "�� ���ڿ��� �����ϴ�. " << endl << endl;
	else
		cout << "�� ���ڿ��� �ٸ��ϴ�. " << endl << endl;
}

void Problem115_2()
{
	int value;

	cout << "�ݶ�, ��, ��������Ʈ, �ֽ�, Ŀ�� �߿��� �ϳ��� �����ϼ��� : ";
	cin >> value;

	switch (value)
	{
	case 1:
		cout << "�ݶ� �����߽��ϴ�.";
		break;
	case 2:
		cout << "���� �����߽��ϴ�.";
		break;
	case 3:
		cout << "��������Ʈ�� �����߽��ϴ�.";
		break;
	case 4:
		cout << "�ֽ��� �����߽��ϴ�.";
		break;
	case 5:
		cout << "Ŀ�Ǹ� �����߽��ϴ�.";
		break;
	default:
		cout << "����. ������ ��ȿ���� �ʽ��ϴ�. ���� ��ȯ�մϴ�.";
		break;
	}	
}

void Problem115_3()
{
	int day[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 0; i < 12; i++)
	{
		cout << i + 1 << "���� " << day[i] << "�� ���� �ֽ��ϴ�." << endl;
	}
}

void Problem115_4()
{
	int userval;
	for (int i = 0; i < 5; i++)
	{
		cout << "������ �Է��ϼ��� : ";
		cin >> userval;

		if (userval == 5)
		{
			cout << "5�� �Է��ϼ̱���! ��ǻ�� ��!";
			break;
		}
		
		if (i == 4)
			cout << "�γ����� ���ϱ���. ����� ��!";
	}
}

void Problem115_5()
{
	int user_val, result = 0;
	
	while (true)
	{
		cout << "������ �Է��ϼ��� : ";
		cin >> user_val;
		result += user_val;
		if (user_val == 0)
			break;
	}
	cout << "�հ� : " << result;
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
	cout << "������ �Է��ϼ��� : ";
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
	cout << "n�� ���� �Է��Ͻÿ� : ";
	cin >> user_val;
	
	for (int i = 1; i <= user_val; i++)
	{
		sum += i * i;
	}
	cout << "��갪�� : " << sum << "�Դϴ�.";
}

void Problem115_12()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			cout << "�ڼ� ";
		else
			cout << i << " ";
	}
}

void Problem115_13()
{
	int input;
	int a = 0, b = 1;
	int temp;

	cout << "�� �ױ��� ���ұ�� ? : ";
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

	cout << "������ ���� : ";
	cin >> op;

	cout << "���ڸ� �Է��Ͻÿ� : ";
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
			cout << "�и� 0�Դϴ�. �������� �� �� �����ϴ�." << endl;
			result = 0;
			break;
		}
		result = x / y;
	default:
		break;
	}

	cout << "����� ��� : " << result << endl;
}

void Problem115_15()
{
	int Computer_Random_Vlaue = rand() % 3;
	int User_Ball;
	cout << "� ���� �Է��Ͻðڽ��ϱ�?" << endl;
	cout << "1. ���� 2. ���� 3. ��" << endl;
	cin >> User_Ball;

	// switch ���� �̿��� ��� ��� :)
	switch (Computer_Random_Vlaue)
	{
	case 0:
		cout << "��ǻ�ʹ� ������ �½��ϴ�" << endl;
		if (User_Ball == 1)
			cout << "�����ϴ�." << endl;
		else if (User_Ball == 2)
			cout << "����� �����ϴ�" << endl;
		else
			cout << "����� �̰���ϴ�" << endl;
		break;
	case 1:
		cout << "��ǻ�ʹ� ������ �½��ϴ�" << endl;
		if (User_Ball == 1)
			cout << "����� �̰���ϴ�." << endl;
		else if (User_Ball == 2)
			cout << "�����ϴ�" << endl;
		else
			cout << "����� �����ϴ�" << endl;
		break;
	case 2:
		cout << "��ǻ�ʹ� ���� �½��ϴ�" << endl;
		if (User_Ball == 1)
			cout << "����� �����ϴ�." << endl;
		else if (User_Ball == 2)
			cout << "����� �̰���ϴ�" << endl;
		else
			cout << "�����ϴ�." << endl;
		break;
	default:
		cout << "���� �� ���ڸ� �Է��߽��ϴ�." << endl;
	}
}

void Problem115_16()
{
	int cash = 50;
	const int goal = 250;

	int bets, win; // �� �ùķ��̼� �� ���ü�, �̱� Ƚ��
	bool result; // ��/�� ���
	int wins = 0; // 1000�� �ùķ��̼� �� �̱� Ƚ��
	int total = 0; // ������ Ƚ���� ��� ���� ����

	srand((unsigned int)time(NULL));

	cout << "�ʱ� �ݾ� $" << cash << endl;
	cout << "��ǥ �ݾ� $" << goal << endl;

	// �¸�Ȯ���� �˾ƺ��� ���� 1000���� �ùķ��̼�
	for (int game = 0; game < 1000; game++)
	{
		cash = 50, bets = 0, win = 0; // �ʱ� ���� reset
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
			wins++; // �� �ùķ��̼Ǵ� �¸� Ƚ�� ���
		total += bets; // �� �ùķ��̼Ǵ� ���� �� ���� ���
	}

	cout << "1000 ���� " << wins << "�� �¸�" << endl;
	cout << fixed; // �Ҽ��� �Ʒ� �ڸ� ����
	cout.precision(6); // �Ҽ��� �Ʒ� 6�ڸ����� ����
	cout << "�̱� Ȯ��=" << wins / 1000.0 * 100.0 << endl;
	cout << "��� ���� Ƚ�� = " << total / 1000.0 << endl;
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