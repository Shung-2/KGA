#include "210419 9. OrcWarlock.h"

OrcWarlock::OrcWarlock()
{
	_hp = 300;
	_mp = 500;
	_ad = 30;
	_ap = 50;

	QSkill();
	WSkill();
	ESkill();
	RSkill();
}

OrcWarlock::~OrcWarlock()
{

}

void OrcWarlock::QSkill()
{
	cout << "��ü ����" << endl;
}

void OrcWarlock::WSkill()
{
	cout << "�ּ����� �ֹ�" << endl;
}

void OrcWarlock::ESkill()
{
	cout << "���̾" << endl;
}

void OrcWarlock::RSkill()
{
	cout << "����ȭ" << endl;
}

void OrcWarlock::Output()
{
	cout << "��ũ ������ ü�� : " << _hp << endl;
	cout << "��ũ ������ ���� : " << _mp << endl;
	cout << "��ũ ������ ���� : " << _ad << endl;
	cout << "��ũ ������ ���� : " << _ap << endl;
}