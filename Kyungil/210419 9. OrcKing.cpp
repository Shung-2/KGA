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
	cout << "���Ǹ� �ұ�" << endl;
}

void OrcKing::WSkill()
{
	cout << "���� ����" << endl;
}

void OrcKing::ESkill()
{
	cout << "���ں�" << endl;
}

void OrcKing::RSkill()
{
	cout << "���ĸű�" << endl;
}

void OrcKing::Output()
{
	cout << "��ũ ŷ ü�� : " << _hp << endl;
	cout << "��ũ ŷ ���� : " << _mp << endl;
	cout << "��ũ ŷ ���� : " << _ad << endl;
	cout << "��ũ ŷ ���� : " << _ap << endl;
}