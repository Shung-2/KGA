#include "210419 10. Angel.h"

Angel::Angel()
{
	_hp = 1000;
	_mp = 1000;
	_ad = 500;
	_ap = 500;
}

Angel::~Angel()
{

}

void Angel::QSkill()
{
	cout << "��Ÿ ��ȭ" << endl;
}

void Angel::WSkill()
{
	cout << "���� �ູ" << endl;
}

void Angel::ESkill()
{
	cout << "��ȭ" << endl;
}

void Angel::RSkill()
{
	cout << "����" << endl;
}

void Angel::Output()
{
	cout << "�⺻ õ�� ü�� : " << _hp << endl;
	cout << "�⺻ õ�� ���� : " << _mp << endl;
	cout << "�⺻ õ�� ���� : " << _ad << endl;
	cout << "�⺻ õ�� ���� : " << _ap << endl;
}