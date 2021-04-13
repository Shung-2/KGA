#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	// ���� ����
	srand(time(NULL));
	int Computer_Ball[3], User_Ball[3];
	int Count = 1, Strike = 0, Ball = 0;

	// ��ǻ�� ���� ���� (�ߺ� ����)
	for (int i = 0; i < 3; i++)
	{
		Computer_Ball[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++)
		{
			if (Computer_Ball[i] == Computer_Ball[j] && i != j)
			{
				i--;
			}
		}
	}

	cout << "��ǻ���� ���ڴ� : ";
	for (int i = 0; i < 3; i++)
	{
		cout << Computer_Ball[i] << ' ';
	}
	cout << "�Դϴ�. " << endl;

	while (true)
	{
		// ī��Ʈ ���
		cout << Count << "��° ��ȸ�Դϴ� : ";
		// ����� ���� �Է�
		for (int i = 0; i < 3; i++)
		{
			cin >> User_Ball[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cout << User_Ball[i] << ' ';
		}

		// S, B üũ
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
			cout << "��Ʈ����ũ�� : " << Strike << " ���� : " << Ball << endl;
		}
		else
		{
			cout << "��ġ�ϴ� ���� �����ϴ�." << endl;
		}

		// �¸�����
		if (Strike == 3)
		{
			cout << "�¸� !" << endl;
			break;
		}
		// �й� ����
		if (Count == 10)
		{
			cout << "�ƿ� !" << endl;
			break;
		}
		Count++, Strike = 0, Ball = 0;
	}
	return 0;
}