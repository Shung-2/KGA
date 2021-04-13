#include <iostream>
#include <time.h> // ������ ������ ���� �̱� ���� ����Ѵ�.
using namespace std;

int main()
{
	// �������� ����
	// ���������
	// +	���ϱ�
	// -	����
	// *	���ϱ�
	// /	������
	// %	������

	// Random �Լ� ���
	// ������, rand()�� ���α׷��� �����ɶ� ���� �������� ������ ������ ������ѵ� ������ ���� ���´�. 
	cout << "rand()�� ����? " << rand() << endl;
	cout << "rand()�� ����? " << rand() << endl;
	cout << "rand()�� ����? " << rand() << endl;
	cout << "rand()�� ����? " << rand() << endl;
	cout << "rand()�� ����? " << rand() << endl;
	cout << "rand()�� ����? " << rand() << endl;
	cout << "rand()�� ����? " << rand() << endl;
	cout << "rand()�� ����? " << rand() << endl << endl;
		
	srand(time(NULL));
	// �̷��� ���� ���� �������ָ� rand�� ���� ��� �ٲ�� �ȴ�.
	int num1 = rand();
	int num2 = rand();

	cout << "num1�� ����? " << num1 << endl;
	cout << "num2�� ����? " << num2 << endl << endl;

	// �ֻ���
	cout << "���� �ֻ��� ���� ���!" << endl;
	int dice = rand() % 6 + 1;
	// 0 ~ 5�� ������ ���´�. �׷����� +1 �ϸ� ���� ������ 1~6�� �ȴ�.
	cout << "������ " << dice << " ĭ ������!" << endl << endl;

	// ��ƺ�� Ȱ ����� Ȱ�� ������ ������ 2~7�� ��츦 ���ϼ���
	int bow = rand() % 6 + 2;
	// 0 ~ 5�� ������ �������� +2�� �ϸ� ���� ������ 2~7�� �ȴ�.

	// ���� ������
	// A > B		A�� B���� ũ��
	// A >= B		A�� B���� ũ�ų� ����.
	// A < B		A�� B���� �۴�
	// A <= B		A�� B���� �۰ų� ����.
	// A == B		A�� B�� ����.
	// A != B		A�� B�� ���� �ʴ�.
	
	// �� ������
	// A && B		A and B		A�� ���̰� B�� ���϶�
	// A || B		A or  B		A�� B ���� �ϳ��� ���� ��
	// !A			not A		A�� ������ ��

	int A = 5, B = 5;
	bool Reslut;

	Reslut = A == B;
	cout << "A == B�� ����? " << Reslut << endl;

	int C = 5, D = 0;
	Reslut = A || B;
	cout << "A || B�� ����? " << Reslut << endl << endl;

	// ���ǹ�
	// �ش� ������ ���϶��� ������ �ȴ�.
	// if ����, switch ���� �ִ�.
	// ��������� X, - ���׿����� O.

	// if�� (���� ~ �ϸ�)
	int num = rand() % 10;
	cout << "���� �� : " << num << endl;

	if (num < 2)
	{
		cout << "SSR�� ����!" << endl << endl;
	}
	else if (num >= 2 && num < 5)
	{
		cout << "SR�� ����!" << endl << endl;
	}
	else
	{
		cout << "�� �Ӵ� ����? ����~" << endl << endl;
	}

	int LoveNum;
	cout << "���� �������� �����ϴ� ���ڸ� �Է��ϼ��� : ";
	cin >> LoveNum;
	cout << "����� ? " << LoveNum << endl;

	if (LoveNum == 5)
	{
		cout << "���̰�1 ���̰�2 ��� �Ȱž�?" << endl << endl;
	}
	else
	{
		cout << "Ʋ�ȴ�ϴ� �ʷ�~" << endl << endl;
	}

	// switch ��
	int Select_Champion;

	cout << "è���� ���ÿ�" << endl;
	cout << "1. ��Į�� 2. ���� 3. ���� 4. ���ӽ�" << endl;
	cin >> Select_Champion;

	// switch ���� ������ �Է� ���� �ϴ�.
	// ���� �� ���ڿ�, �Ǽ� ���� �Է��� ���� �ʴ´�.
	switch (Select_Champion)
	{
		case 1:
			cout << "��Į���� �������" << endl;
		break;

		case 2:		
			cout << "���带 �������" << endl;
		break;

		case 3:
			cout << "������ �������" << endl;
		break;

		case 4:
			cout << "���ӽ��� �������" << endl;
		break;

		default:
			cout << "������ ���� �� ���ڸ� �Է��߽��ϴ�. " << endl;
		break;
	}
	cout << endl;

	// cout, cin - c++
	// printf, scanf - C
	printf("C��� ���! \n");
	printf("����ȣ~ \n\n");

	// ��ǻ�ʹ� �����ϰ� 0 ~ 2������ ���ڸ� �޴´�.
	// 0 ����, 1 ����, 2 ���ڱ� ��� Ĩ�ô�.
	// ���� � ���� �Է�(0~2) �޾Ƽ� ���и� ����غ���.

	// ���� ���� & ����� �Է�
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
	cout << endl;

	// �ݺ���
	for (int i = 0; i < 5; i++)
	{
		cout << "�ᳪ�� ���� ���ƴ�? " << i + 1 << endl;
	}
	cout << endl;
	
	// ������ (2�� ���)
	int GUGU = 2;
	
	for (int i = 1; i <= 9; i++)
	{
		cout << GUGU << " X " << i << " = " << GUGU * i << endl;
	}
	cout << endl;

	// ������ (2�� ���ٷ� ���)
	for (int i = 9; i > 0; i--)
	{
		cout << GUGU << " X " << i << " = " << GUGU * i << endl;
	}
	cout << endl;

	// ������ (�Է� ���)
	cout << "�� ���� ������� ����ұ��?  " << endl;
	int User_Dan = 0;
	cin >> User_Dan;

	for (int i = 1; i < 10; i++)
	{
		cout << User_Dan << " X " << i << " = " << User_Dan * i << endl;
	}
	cout << endl;

	// ������ (�Է� ���ٷ� ���)
	cout << "�� ���� ���ٷ� ����ұ��? " << endl;
	int User_Dan2 = 0;
	cin >> User_Dan2;

	for (int i = 9; i >= 1; i--)
	{
		cout << User_Dan2 << " X " << i << " = " << User_Dan2 * i << endl;
	}
	cout << endl;

	// ������ (1~9��, ��������)
	cout << "1�ܺ��� 9�ܱ����� ������ ���" << endl;
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " X " << j << " = " << i * j << endl;
		}
		cout << endl;
	}
	cout << endl;

	// ������ (9~1��, ��������, ����)
	cout << "9�ܺ��� 1�ܱ����� ������ ���" << endl;
	for (int i = 9; i > 0; i--)
	{
		for (int j = 9; j > 1; j--)
		{
			cout << i << " X " << j << " = " << i * j << endl;
		}
		cout << endl;
	}

	// �����
	// *
	// **
	// ***
	// ****
	// *****
	cout << "�����!" << endl;
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

	// �ݺ���
	// ���ϋ��� �����Ѵ�.
	// ���ѷ����� �⺻
	//while (true)
	//{
	//	cout << "�������" << endl;
	//}

	// ���
	// 1. return - ���� ��ȯ�ϰ� �����Ѵ�
	// 2. break - ������ �ߴ��ϰ� �����Ѵ�
	// 3. continue - ������ �ǳ� �ڴ�.

	cout << "Continue, break ����!" << endl;
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
		cout << "0. ����, 1. ����, 2. �� ����. " << endl;
		cin >> me;

		if (me < 0 || me > 2)
		{
			cout << "�� �Է��ϼ��� " << endl;
			continue;
		}

		cout << count << " ���� ��ȸ�� ���ҽ��ϴ�" << endl;
		count--;

		if (count < 0)
		{
			break;
		}
	}
	cout << endl;

	// 1. ��ǻ�Ͱ� 0 ~ 999 ���� �߿� �ϳ��� ����
	// 2. �츮���� 10���� ��ȸ�� �ִ�.
	// 3. ���ڸ� �Է��ϸ� ū �� ���� �� ������ش�.
	cout << "������ ����!" << endl;
	srand(time(NULL));
	int Computer_Random_Value = rand() % 1000;
	int Conut = 10;
	int User_Input_Value = 0;

	while (true)
	{
		cout << "��ȸ�� " << Conut << "�� �ֽ��ϴ�.";
		cout << "���ڸ� �Է��ϼ���. " << endl;
		cin >> User_Input_Value;

		if (User_Input_Value < Computer_Random_Value)
		{
			cout << "��ǻ���� ���ڰ� Ů�ϴ�." << endl;
		}
		else if (User_Input_Value > Computer_Random_Value)
		{
			cout << "������� ���ڰ� Ů�ϴ�" << endl;
		}
		else
		{
			cout << "����!" << endl;
			break;
		}
		
		Conut--;

		if (Conut == 0)
		{
			cout << "���� ����" << endl;
			cout << "���� : " << Computer_Random_Value << "�Դϴ�. ";
			break;
		}
	}
	return 0;
}