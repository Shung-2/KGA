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
	cout << "체벌" << endl;
}

void Middle_Angel::WSkill()
{
	cout << "중급 천사의 외침" << endl;
}

void Middle_Angel::ESkill()
{
	cout << "중급 정화" << endl;
}

void Middle_Angel::RSkill()
{
	cout << "원죄" << endl;
}

void Middle_Angel::Output()
{
	cout << "중급 천사 체력 : " << _hp << endl;
	cout << "중급 천사 마력 : " << _mp << endl;
	cout << "중급 천사 물공 : " << _ad << endl;
	cout << "중급 천사 마공 : " << _ap << endl;
}