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
	// enum == ������
	int number[3];

	number[ZERO] = 1;
	number[ONE] = 3;
	number[TWO] = 5;
	// �� ������ Ǯ� �����ϸ� number[0] = 1, number[1] = 3, number[2] = 5�� ����.

	// �������� �̿��� ����
	MARIOSTATE marioState;

	marioState = RIGHT_IDEL;

	if (marioState == RIGHT_IDEL)
		marioState == RIGHT_RUN;

	/* 
	// ����ġ ���� enum���� �ۼ��Ҷ� Tab�� �����ָ� �ڵ��ϼ����ش�!
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
	cout << "1. ���ʼ���, 2. ������ �޸��� 3. ���� �޸���" << endl;
	cout << "�������� �ൿ�� �Է��ϼ��� : ";
	cin >> num;

	// ERROR�� ���� �ּ�ó��
	marioState = num;
	// �ش� ������ ������ ���� ���� �ʾ� ������� �ʴ´�.
	// marioState�� enum �����̹Ƿ� num �տ� ���� ���������Ѵ�.,
	// ��� �Ʒ��� ���� �������� �Ѵ�.
	marioState = (MARIOSTATE)num;

	// �׷����� �� ENUM�� 0���� ����϶�� ���� ����. ������ ������ ���� �����ص� �ȴ�.
	// ���� ��)
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
	// ������ ������ ������ ���� ������ ���� ������ LEFT_RUN�� 11�̹Ƿ� RIGHT_JUMP�� ���� 12�� �ȴ�.

	// enum�� enum class�� ����
	// -> https://unikys.tistory.com/376
	
	/* = = = �� �� �� = = = */
	// 1. strlen()
	// ���ڿ��� ���̸� ��ȯ���ִ� �Լ�
	char str[5] = "star";
	// str�� 4�� �����ϸ� star �� ���� �ִ� ������ ���� ���ϹǷ� 5�� ��������� �Ѵ�
	// �Ʒ��� �迭�� �� ���̴�.
	// star[0] = s
	// star[1] = t
	// star[2] = a
	// star[3] = r
	// star[4] = '/0'

	int size = strlen(str);
	cout << "���ڿ� ���̴� : " << size << endl;
	// ���������δ� s, t, a, r, /0�̶� 5��� ������ �� ������ /0�� ������ 4�� �´�.

	char str2[128] = "i kill you c++ SSIBAL";
	int size2 = strlen(str2);
	cout << "���ڿ� ���̴� : " << size2 << endl;

	// 2. strcmp()
	// ���ڿ� �� �Լ�
	// �� ���ڿ��� ���Ͽ� �������� ũ�� -1, ������ ũ�� 1
	// �� ���ڿ��� ������ 0�� ��ȯ�Ѵ�.

	char str3[64] = "abc";
	char str4[64] = "abd";

	int result = strcmp(str3, str4);

	// ���� �� ������ ���̺� ���Ϸ� �Ҿ�� �� ����ó���� �� ���ȴ�.
	cout << result << endl;

	// 3. strcat
	// ������ ���ڿ��� ���ʿ� �̾� �ٿ��ش�.
	// ���� ���ڿ��� ������ ���ڿ��� ������ ���۰�(�迭ũ��)�� ������ �־�� �Ѵ�
	char str5[128] = "oh! ";
	char str6[64] = "i'm going home!";

	strcat_s(str5, str6);
	cout << str5 << endl;

	// 4. strcpy
	// �������� ���ڿ��� �������� �������ش�.
	// �翬�� ���� ���ڿ� ���۰� ������ ���ڿ� ���� ũ�ų� ���ƾ� �Ѵ�
	char str7[6] = "apple";
	char str8[6];

	strcpy_s(str8, str7);
	cout << str7 << endl;
	
	// ���ڿ� ������
	char str9[128];
	cin >> str9;

	// �ٳ����� �Է��Ѵٰ� ����.
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

	// ���ڿ� ¦�������� ���ٷ� ����ϱ�
	// 1. ���ڿ��� �Է¹޾ƶ�
	// 2. �Է¹��� ���ڿ��� ¦����° ���ڸ� ������ ��µǰ� �϶�
	// ��) a, b, c, d, e => a, d, c, b, e

	char str10[128];
	cin >> str10;

	// ���� ���
	cout << "���� ��� : ";
	for (int i = 0; i < strlen(str10); i++)
	{
		cout << str10[i];
	}
	cout << endl;

	// ¦����° ���ڸ� �Ųٷ� ��� [������]
	cout << "¦����° ���ڸ� �Ųٷ� ��� : ";
	for (int i = 0; i < strlen(str10); i++)
	{
		// ¦����° ���ڿ��̸� == Ȧ����° �迭 �ε���
		if (i % 2 == 1)
		{
			if (strlen(str10) % 2 == 0)
			{
				// 5���� ������
				cout << str10[strlen(str10) - i];
			}
			else
			{
				// 6���� ������
				cout << str10[strlen(str10) - i - 1];
			}
		}
		// Ȧ����° ���ڿ��̸� == ¦��° �迭 �ε���
		else
		{
			cout << str10[i];
		}
	}

	// ¦����° ���ڸ� �Ųٷ� ��� [�����԰� ����]
	cout << "¦����° ���ڸ� �Ųٷ� ��� : ";
	for (int i = 0; i < strlen(str10); i++)
	{
		if (i % 2 == 1)
		{
			// strlen ���� ��� �迭�� ¦���� ���
			if (strlen(str10) % 2 == 0)
			{
				cout << str10[strlen(str10) - i];
			}
			// strlen ���� ��� �迭�� Ȧ���� ���
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

	// ¦����° ���ڸ� �Ųٷ� ��� [������]
	cout << "¦����° ���ڸ� �Ųٷ� ��� : ";
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

	// ���׿�����
	// ���� 3������ ���� �����ڶ�� �Ѵ�
	// ���� ������
	// ���� ? �� : ����
	// ������ ���϶� �� ������ ����ǰ� �ƴϸ� ���� ������ �����
	cout << endl << endl;
	int luckynum = 7;
	luckynum == 7 ? cout << "yes" : cout << "no";
}