#include "210419 9. OrcKing.h"

OrcKing::OrcKing()
{
	_hp = 500;
	_mp = 300;
	_ad = 50;
	_ap = 30;

	QSkill();
	WSkill();
	ESkill();
	RSkill();
}

OrcKing::~OrcKing()
{

}

void OrcKing::QSkill()
{
	cout << "뿔피리 불기" << endl;
}

void OrcKing::WSkill()
{
	cout << "왕의 버프" << endl;
}

void OrcKing::ESkill()
{
	cout << "무자비" << endl;
}

void OrcKing::RSkill()
{
	cout << "뛰쳐매기" << endl;
}

void OrcKing::Output()
{
	cout << "오크 킹 체력 : " << _hp << endl;
	cout << "오크 킹 마력 : " << _mp << endl;
	cout << "오크 킹 물공 : " << _ad << endl;
	cout << "오크 킹 마공 : " << _ap << endl;
}