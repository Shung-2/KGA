#include "210419 8. Human.h"

Human::Human()
{
	_hp = 100;
	_mp = 50;
	_ad = 5;
	_ap = 5;
}

Human::~Human()
{

}

void Human::QSkill()
{
	cout << "�Ҹ�ġ��" << endl;
}

void Human::WSkill()
{
	cout << "��������" << endl;
}

void Human::ESkill()
{
	cout << "����" << endl;
}

void Human::RSkill()
{
	cout << "�ο��" << endl;
}

void Human::Output()
{
	cout << "�⺻ �ΰ� ü�� : " << _hp << endl;
	cout << "�⺻ �ΰ� ���� : " << _mp << endl;
	cout << "�⺻ �ΰ� ���� : " << _ad << endl;
	cout << "�⺻ �ΰ� ���� : " << _ap << endl;
}