#include "210419 6. ElfArcher.h"

ElfArcher::ElfArcher()
{
	_hp = 100;
	_mp = 150;
	_ad = 20;
	_ap = 5;

	QSkill();
	WSkill();
	ESkill();
	RSkill();
}

ElfArcher::~ElfArcher()
{

}

void ElfArcher::QSkill()
{
	cout << "�ü� Q" << endl;
}

void ElfArcher::WSkill()
{
	cout << "�ü� W" << endl;
}

void ElfArcher::ESkill()
{
	cout << "�ü� E" << endl;
}

void ElfArcher::RSkill()
{
	cout << "�ü� R" << endl;
}

void ElfArcher::Output()
{
	cout << "�����ü� ü�� : " << _hp << endl;
	cout << "�����ü� ���� : " << _mp << endl;
	cout << "�����ü� ���� : " << _ad << endl;
	cout << "�����ü� ���� : " << _ap << endl;
}