#include "210419 9. Orc.h"

Orc::Orc()
{
	_hp = 100;
	_mp = 50;
	_ad = 5;
	_ap = 5;
}

Orc::~Orc()
{

}

void Orc::QSkill()
{
	cout << "�Ҹ�ġ��" << endl;
}

void Orc::WSkill()
{
	cout << "��������" << endl;
}

void Orc::ESkill()
{
	cout << "����" << endl;
}

void Orc::RSkill()
{
	cout << "�ο��" << endl;
}

void Orc::Output()
{
	cout << "�⺻ ��ũ ü�� : " << _hp << endl;
	cout << "�⺻ ��ũ ���� : " << _mp << endl;
	cout << "�⺻ ��ũ ���� : " << _ad << endl;
	cout << "�⺻ ��ũ ���� : " << _ap << endl;
}