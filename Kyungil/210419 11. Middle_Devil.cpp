#include "210419 11. Middle_Devil.h"

Middle_Devil::Middle_Devil()
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

Middle_Devil::~Middle_Devil()
{

}

void Middle_Devil::QSkill()
{
	cout << "±³¸¸" << endl;
}

void Middle_Devil::WSkill()
{
	cout << "³ªÅÂ" << endl;
}

void Middle_Devil::ESkill()
{
	cout << "¾Ç¸ù" << endl;
}

void Middle_Devil::RSkill()
{
	cout << "¼ÓÁË" << endl;
}

void Middle_Devil::Output()
{
	cout << "Áß±Þ ¾Ç¸¶ Ã¼·Â : " << _hp << endl;
	cout << "Áß±Þ ¾Ç¸¶ ¸¶·Â : " << _mp << endl;
	cout << "Áß±Þ ¾Ç¸¶ ¹°°ø : " << _ad << endl;
	cout << "Áß±Þ ¾Ç¸¶ ¸¶°ø : " << _ap << endl;
}