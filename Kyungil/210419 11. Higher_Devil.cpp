#include "210419 11. Higher_Devil.h"

Higher_Devil::Higher_Devil()
{
	_hp = 3000;
	_mp = 3000;
	_ad = 5000;
	_ap = 3000;

	QSkill();
	WSkill();
	ESkill();
	RSkill();
}

Higher_Devil::~Higher_Devil()
{

}

void Higher_Devil::QSkill()
{
	cout << "����" << endl;
}

void Higher_Devil::WSkill()
{
	cout << "ħ��" << endl;
}

void Higher_Devil::ESkill()
{
	cout << "����" << endl;
}

void Higher_Devil::RSkill()
{
	cout << "�Ǳ�" << endl;
}

void Higher_Devil::Output()
{
	cout << "��� �Ǹ� ü�� : " << _hp << endl;
	cout << "��� �Ǹ� ���� : " << _mp << endl;
	cout << "��� �Ǹ� ���� : " << _ad << endl;
	cout << "��� �Ǹ� ���� : " << _ap << endl;
}