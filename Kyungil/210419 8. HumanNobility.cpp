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
	cout << "병사 집결" << endl;
}

void HumanNobility::WSkill()
{
	cout << "자결" << endl;
}

void HumanNobility::ESkill()
{
	cout << "도망가기" << endl;
}

void HumanNobility::RSkill()
{
	cout << "눈속임하기" << endl;
}

void HumanNobility::Output()
{
	cout << "인간 귀족 체력 : " << _hp << endl;
	cout << "인간 귀족 마력 : " << _mp << endl;
	cout << "인간 귀족 물공 : " << _ad << endl;
	cout << "인간 귀족 마공 : " << _ap << endl;
}