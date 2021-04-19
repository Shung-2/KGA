#include "210419 11. Devil.h"

Devil::Devil()
{
	_hp = 1000;
	_mp = 1000;
	_ad = 500;
	_ap = 500;
}

Devil::~Devil()
{

}

void Devil::QSkill()
{
	cout << "Å¸¶ô" << endl;
}

void Devil::WSkill()
{
	cout << "È¥µ·" << endl;
}

void Devil::ESkill()
{
	cout << "ÀúÁÖ" << endl;
}

void Devil::RSkill()
{
	cout << "¿µÈ¥ °­Å»" << endl;
}

void Devil::Output()
{
	cout << "±âº» ¾Ç¸¶ Ã¼·Â : " << _hp << endl;
	cout << "±âº» ¾Ç¸¶ ¸¶·Â : " << _mp << endl;
	cout << "±âº» ¾Ç¸¶ ¹°°ø : " << _ad << endl;
	cout << "±âº» ¾Ç¸¶ ¸¶°ø : " << _ap << endl;
}