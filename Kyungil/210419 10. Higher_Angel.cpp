#include "210419 10. Higher_Angel.h"

Higher_Angel::Higher_Angel()
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

Higher_Angel::~Higher_Angel()
{

}

void Higher_Angel::QSkill()
{
	cout << "¡��" << endl;
}

void Higher_Angel::WSkill()
{
	cout << "��� õ���� ��ħ" << endl;
}

void Higher_Angel::ESkill()
{
	cout << "��� ��ȭ" << endl;
}

void Higher_Angel::RSkill()
{
	cout << "�Ҹ�" << endl;
}

void Higher_Angel::Output()
{
	cout << "��� õ�� ü�� : " << _hp << endl;
	cout << "��� õ�� ���� : " << _mp << endl;
	cout << "��� õ�� ���� : " << _ad << endl;
	cout << "��� õ�� ���� : " << _ap << endl;
}