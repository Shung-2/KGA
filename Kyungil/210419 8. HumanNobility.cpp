#include "210419 8. HumanNobility.h"

HumanNobility::HumanNobility()
{
	_hp = 100;
	_mp = 50;
	_ad = 5;
	_ap = 5;

	QSkill();
	WSkill();
	ESkill();
	RSkill();
}

HumanNobility::~HumanNobility()
{

}

void HumanNobility::QSkill()
{
	cout << "���� ����" << endl;
}

void HumanNobility::WSkill()
{
	cout << "�ڰ�" << endl;
}

void HumanNobility::ESkill()
{
	cout << "��������" << endl;
}

void HumanNobility::RSkill()
{
	cout << "�������ϱ�" << endl;
}

void HumanNobility::Output()
{
	cout << "�ΰ� ���� ü�� : " << _hp << endl;
	cout << "�ΰ� ���� ���� : " << _mp << endl;
	cout << "�ΰ� ���� ���� : " << _ad << endl;
	cout << "�ΰ� ���� ���� : " << _ap << endl;
}