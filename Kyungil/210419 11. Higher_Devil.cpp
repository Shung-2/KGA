#include "210419 11. Higher_Devil.h"

Higher_Devil::Higher_Devil()
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

Higher_Devil::~Higher_Devil()
{

}

void Higher_Devil::QSkill()
{
	cout << "Àý¸Á" << endl;
}

void Higher_Devil::WSkill()
{
	cout << "Ä§¹¬" << endl;
}

void Higher_Devil::ESkill()
{
	cout << "¸Á°¢" << endl;
}

void Higher_Devil::RSkill()
{
	cout << "¾Ç±Í" << endl;
}

void Higher_Devil::Output()
{
	cout << "»ó±Þ ¾Ç¸¶ Ã¼·Â : " << _hp << endl;
	cout << "»ó±Þ ¾Ç¸¶ ¸¶·Â : " << _mp << endl;
	cout << "»ó±Þ ¾Ç¸¶ ¹°°ø : " << _ad << endl;
	cout << "»ó±Þ ¾Ç¸¶ ¸¶°ø : " << _ap << endl;
}