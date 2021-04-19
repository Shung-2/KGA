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
	cout << "±Ã¼ö Q" << endl;
}

void ElfArcher::WSkill()
{
	cout << "±Ã¼ö W" << endl;
}

void ElfArcher::ESkill()
{
	cout << "±Ã¼ö E" << endl;
}

void ElfArcher::RSkill()
{
	cout << "±Ã¼ö R" << endl;
}

void ElfArcher::Output()
{
	cout << "¿¤ÇÁ±Ã¼ö Ã¼·Â : " << _hp << endl;
	cout << "¿¤ÇÁ±Ã¼ö ¸¶·Â : " << _mp << endl;
	cout << "¿¤ÇÁ±Ã¼ö ¹°°ø : " << _ad << endl;
	cout << "¿¤ÇÁ±Ã¼ö ¸¶°ø : " << _ap << endl;
}