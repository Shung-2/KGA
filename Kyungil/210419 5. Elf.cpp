#include "210419 5. Elf.h"

Elf::Elf()
{
	_hp = 100;
	_mp = 50;
	_ad = 8;
	_ap = 7;
}

Elf::~Elf()
{

}

void Elf::QSkill()
{
	cout << "�⺻ ���� Q ��ų : Ȱ���" << endl;
}

void Elf::WSkill()
{
	cout << "�⺻ ���� W ��ų : �߻����� ����̱�" << endl;
}

void Elf::ESkill()
{
	cout << "�⺻ ���� E ��ų : ��ø�� ����" << endl;
}

void Elf::RSkill()
{
	cout << "�⺻ ���� �ñر� ��ų : ���߻�� " << endl;
}

void Elf::Output()
{
	 cout << "�⺻ ���� ü�� : " << _hp << endl;
	 cout << "�⺻ ���� ���� : " << _mp << endl;
	 cout << "�⺻ ���� ���� : " << _ad << endl;
	 cout << "�⺻ ���� ���� : " << _ap << endl;
}