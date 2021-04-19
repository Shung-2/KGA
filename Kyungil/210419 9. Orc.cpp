#include "210419 9. Orc.h"

Orc::Orc()
{
	_hp = 100;
	_mp = 50;
	_ad = 5;
	_ap = 5;
}

Orc::~Orc()
{

}

void Orc::QSkill()
{
	cout << "소리치기" << endl;
}

void Orc::WSkill()
{
	cout << "도망가기" << endl;
}

void Orc::ESkill()
{
	cout << "숨기" << endl;
}

void Orc::RSkill()
{
	cout << "싸우기" << endl;
}

void Orc::Output()
{
	cout << "기본 오크 체력 : " << _hp << endl;
	cout << "기본 오크 마력 : " << _mp << endl;
	cout << "기본 오크 물공 : " << _ad << endl;
	cout << "기본 오크 마공 : " << _ap << endl;
}