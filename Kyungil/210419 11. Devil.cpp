#include "210419 11. Devil.h"

Devil::Devil()
{
	_hp = 1000;
	_mp = 1000;
	_ad = 500;
	_ap = 500;
}

Devil::~Devil()
{

}

void Devil::QSkill()
{
	cout << "Ÿ��" << endl;
}

void Devil::WSkill()
{
	cout << "ȥ��" << endl;
}

void Devil::ESkill()
{
	cout << "����" << endl;
}

void Devil::RSkill()
{
	cout << "��ȥ ��Ż" << endl;
}

void Devil::Output()
{
	cout << "�⺻ �Ǹ� ü�� : " << _hp << endl;
	cout << "�⺻ �Ǹ� ���� : " << _mp << endl;
	cout << "�⺻ �Ǹ� ���� : " << _ad << endl;
	cout << "�⺻ �Ǹ� ���� : " << _ap << endl;
}