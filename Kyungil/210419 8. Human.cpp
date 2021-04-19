#include "210419 8. Human.h"

Human::Human()
{
	_hp = 100;
	_mp = 50;
	_ad = 5;
	_ap = 5;
}

Human::~Human()
{

}

void Human::QSkill()
{
	cout << "소리치기" << endl;
}

void Human::WSkill()
{
	cout << "도망가기" << endl;
}

void Human::ESkill()
{
	cout << "숨기" << endl;
}

void Human::RSkill()
{
	cout << "싸우기" << endl;
}

void Human::Output()
{
	cout << "기본 인간 체력 : " << _hp << endl;
	cout << "기본 인간 마력 : " << _mp << endl;
	cout << "기본 인간 물공 : " << _ad << endl;
	cout << "기본 인간 마공 : " << _ap << endl;
}