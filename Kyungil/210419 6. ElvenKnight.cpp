#include "210419 6. ElvenKnight.h"

ElvenKnight::ElvenKnight()
{
	_hp = 150;
	_mp = 100;
	_ad = 15;
	_ap = 10;

	QSkill();
	WSkill();
	ESkill();
	RSkill();
}

ElvenKnight::~ElvenKnight()
{

}

void ElvenKnight::QSkill()
{
	cout << "�������� Q��ų : �������" << endl;
}

void ElvenKnight::WSkill()
{
	cout << "�������� W��ų : ���� ���̵�" << endl;

}

void ElvenKnight::ESkill()
{
	cout << "�������� E��ų : ���ɼ�ȯ" << endl;

}

void ElvenKnight::RSkill()
{
	cout << "�������� �ñر� : �ҵ���" << endl;
}

void ElvenKnight::Output()
{
	cout << "�������� ü�� : " << _hp << endl;
	cout << "�������� ���� : " << _mp << endl;
	cout << "�������� ���� : " << _ad << endl;
	cout << "�������� ���� : " << _ap << endl;
}