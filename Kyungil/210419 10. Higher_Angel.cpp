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
	cout << "징벌" << endl;
}

void Higher_Angel::WSkill()
{
	cout << "상급 천사의 외침" << endl;
}

void Higher_Angel::ESkill()
{
	cout << "고급 정화" << endl;
}

void Higher_Angel::RSkill()
{
	cout << "소멸" << endl;
}

void Higher_Angel::Output()
{
	cout << "상급 천사 체력 : " << _hp << endl;
	cout << "상급 천사 마력 : " << _mp << endl;
	cout << "상급 천사 물공 : " << _ad << endl;
	cout << "상급 천사 마공 : " << _ap << endl;
}