#include "210419 10. Middle_Angel.h"

Middle_Angel::Middle_Angel()
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

Middle_Angel::~Middle_Angel()
{

}

void Middle_Angel::QSkill()
{
	cout << "ü��" << endl;
}

void Middle_Angel::WSkill()
{
	cout << "�߱� õ���� ��ħ" << endl;
}

void Middle_Angel::ESkill()
{
	cout << "�߱� ��ȭ" << endl;
}

void Middle_Angel::RSkill()
{
	cout << "����" << endl;
}

void Middle_Angel::Output()
{
	cout << "�߱� õ�� ü�� : " << _hp << endl;
	cout << "�߱� õ�� ���� : " << _mp << endl;
	cout << "�߱� õ�� ���� : " << _ad << endl;
	cout << "�߱� õ�� ���� : " << _ap << endl;
}