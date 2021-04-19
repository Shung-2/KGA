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
	cout << "시체 폭발" << endl;
}

void OrcWarlock::WSkill()
{
	cout << "주술사의 주문" << endl;
}

void OrcWarlock::ESkill()
{
	cout << "파이어볼" << endl;
}

void OrcWarlock::RSkill()
{
	cout << "광폭화" << endl;
}

void OrcWarlock::Output()
{
	cout << "오크 마법사 체력 : " << _hp << endl;
	cout << "오크 마법사 마력 : " << _mp << endl;
	cout << "오크 마법사 물공 : " << _ad << endl;
	cout << "오크 마법사 마공 : " << _ap << endl;
}