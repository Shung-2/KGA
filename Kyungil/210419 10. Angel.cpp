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
	cout << "평타 강화" << endl;
}

void Angel::WSkill()
{
	cout << "신의 축복" << endl;
}

void Angel::ESkill()
{
	cout << "정화" << endl;
}

void Angel::RSkill()
{
	cout << "구원" << endl;
}

void Angel::Output()
{
	cout << "기본 천사 체력 : " << _hp << endl;
	cout << "기본 천사 마력 : " << _mp << endl;
	cout << "기본 천사 물공 : " << _ad << endl;
	cout << "기본 천사 마공 : " << _ap << endl;
}