#include "210419 11. Middle_Devil.h"

Middle_Devil::Middle_Devil()
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

Middle_Devil::~Middle_Devil()
{

}

void Middle_Devil::QSkill()
{
	cout << "����" << endl;
}

void Middle_Devil::WSkill()
{
	cout << "����" << endl;
}

void Middle_Devil::ESkill()
{
	cout << "�Ǹ�" << endl;
}

void Middle_Devil::RSkill()
{
	cout << "����" << endl;
}

void Middle_Devil::Output()
{
	cout << "�߱� �Ǹ� ü�� : " << _hp << endl;
	cout << "�߱� �Ǹ� ���� : " << _mp << endl;
	cout << "�߱� �Ǹ� ���� : " << _ad << endl;
	cout << "�߱� �Ǹ� ���� : " << _ap << endl;
}