#include "210419 8. HumanAssassin.h"

HumanAssassin::HumanAssassin()
{
	_hp = 50;
	_mp = 150;
	_ad = 30;
	_ap = 20;

	QSkill();
	WSkill();
	ESkill();
	RSkill();
}

HumanAssassin::~HumanAssassin()
{

}

void HumanAssassin::QSkill()
{
	cout << "�Ҹ�ġ��" << endl;
}

void HumanAssassin::WSkill()
{
	cout << "�޽�" << endl;
}

void HumanAssassin::ESkill()
{
	cout << "����" << endl;
}

void HumanAssassin::RSkill()
{
	cout << "���� ���̷� ������" << endl;
}

void HumanAssassin::Output()
{
	cout << "�ΰ� �ϻ��� ü�� : " << _hp << endl;
	cout << "�ΰ� �ϻ��� ���� : " << _mp << endl;
	cout << "�ΰ� �ϻ��� ���� : " << _ad << endl;
	cout << "�ΰ� �ϻ��� ���� : " << _ap << endl;
}