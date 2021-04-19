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
	cout << "소매치기" << endl;
}

void HumanAssassin::WSkill()
{
	cout << "급습" << endl;
}

void HumanAssassin::ESkill()
{
	cout << "은신" << endl;
}

void HumanAssassin::RSkill()
{
	cout << "군중 사이로 스며들기" << endl;
}

void HumanAssassin::Output()
{
	cout << "인간 암살자 체력 : " << _hp << endl;
	cout << "인간 암살자 마력 : " << _mp << endl;
	cout << "인간 암살자 물공 : " << _ad << endl;
	cout << "인간 암살자 마공 : " << _ap << endl;
}