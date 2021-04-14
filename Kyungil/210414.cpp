#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

void output()
{
	cout << "12�� �ڸ� ���� �ð�" << endl << endl;
}

void gugudan(int num)
{
	for (int i = 1; i < 10; i++)
	{
		cout << num << " X " << i << " = " << num * i << endl;
	}
	cout << endl;
}

// ��ȯ���� int���� attack �̸��� ���� �Լ�
int attack(int hp, int atk)
{
	hp -= atk;

	cout << atk << "�� ���ظ� �Ծ� " << hp << "�� ü���� ���� �ֽ��ϴ�." << endl;

	return hp;
}

int heal(int hp, int healRate)
{
	hp += healRate;

	cout << "ȸ��! " << healRate << "��ŭ ȸ���� �Ͽ� " << hp << "�� �Ǿ����ϴ�." << endl << endl;

	return hp;
}

// �Լ� ���� ����
void output2();

// call-by-value Ÿ��
void damaged(int hp, int atk)
{
	hp -= atk;
	cout << "���� ü�� : " << hp << endl;
}

// call-by-reference Ÿ��
void damaged(int& hp, int atk)
{
	hp -= atk;
	cout << "���� ü�� : " << hp << endl;
}

// call-by-reference Ÿ���� �̿��� ��
struct tagUnit
{
	const char* name;
	int hp;
	int atk;
};

void damaged(const char* name, int* hp, const char* name2, int atk)
{
	*hp -= atk;
	cout << name << "��(��) " << name2 << "���� " << atk << "��ŭ�� �������� �Ծ� ü���� " << *hp << " �Ǿ����ϴ�." << endl;
}

int main()
{
	// �Լ�.

	// �Լ��� ������ �Ʒ��� ����.
	// ��ȯ�� �Լ� �̸� (�Ű� ����)
	// ��) void Test ()
	// ��) int gugudan (int num)

	// output �Լ� ����
	output();

	// ������ �Լ� ����
	gugudan(8);
	gugudan(2);

	// ���� ������ �ο�
	int dogHp = 100;
	int dogAtk = 10;

	int duckHp = 80;
	int duckAtk = 15;

	duckHp = attack(duckHp, dogAtk);
	dogHp = attack(dogHp, duckAtk);

	duckHp = attack(duckHp, dogAtk);
	dogHp = attack(dogHp, duckAtk);

	duckHp = attack(duckHp, dogAtk);
	dogHp = attack(dogHp, duckAtk);
	cout << endl;

	// ��������
	int healthPotion = 20;
	duckHp = heal(duckHp, healthPotion);

	// �Լ� ���漱��
	// �ϴ� �����غ�~ �����ϱ�!
	output2();

	// call-by-value
	// ���� ���� �ǵ帮�� �ʴ´�
	// �Ű� ������ �Լ� ���ο��� �����ؼ� ����ϴ� ������ ��ġ�� ������ ���������� ������.

	// call-by-reference
	// �Ű������� �Լ� ���ο��� ����Ǵ� ���� ���� ���� ���� �ٲٱ� ������ �����ϴ�.

	// call-by-value, reference�� ����
	int orcHp = 100;
	int orcHtk = 10;

	int gganfHp = 80;
	int gganfAtk = 8;
	
	// �����ε�� ���� �ּ�ó��
	// damaged(orcHp, gganfAtk);

	// ������, == ����Ű�� ��
	int a = 3;
	int b = 7;
	int* c;

	cout << "b�� ���� : " << b << endl;
	c = &b;

	cout << "b�� ���� : " << b << endl;
	*c = 9;

	cout << "b�� ���� : " << b << endl << endl;

	// �����͸� �̿��� �����
	const char* star = "*****";

	for (int i = 0; i < 5; i++)
		cout << star + i << endl;
	cout << endl;

	for (int i = 0; i < 5; i++)
		cout << star + 4 - i << endl;
	cout << endl;

	// call-by-reference Ÿ���� �̿��� ��
	tagUnit human;
	human.name = "�켭";
	human.hp = 100;
	human.atk = 10;

	tagUnit orc;
	orc.name = "����";
	orc.hp = 150;
	orc.atk = 10;

	damaged(orc.name, &orc.hp, human.name, human.atk);
	damaged(human.name, &human.hp, orc.name, orc.atk);

	damaged(orc.name, &orc.hp, human.name, human.atk);
	damaged(human.name, &human.hp, orc.name, orc.atk);

	damaged(orc.name, &orc.hp, human.name, human.atk);
	damaged(human.name, &human.hp, orc.name, orc.atk);
}

void output2()
{
	cout << "���� ����~!! ���� ����!" << endl << endl;
}