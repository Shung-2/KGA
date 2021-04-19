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
	cout << "±ñÇÁÀü»ç Q½ºÅ³ : ³»·ÁÂï±â" << endl;
}

void ElvenKnight::WSkill()
{
	cout << "±ñÇÁÀü»ç W½ºÅ³ : µ¿¹° ¶óÀÌµù" << endl;

}

void ElvenKnight::ESkill()
{
	cout << "±ñÇÁÀü»ç E½ºÅ³ : Á¤·É¼ÒÈ¯" << endl;

}

void ElvenKnight::RSkill()
{
	cout << "±ñÇÁÀü»ç ±Ã±Ø±â : ¼Òµå´í½Ì" << endl;
}

void ElvenKnight::Output()
{
	cout << "±ñÇÁÀü»ç Ã¼·Â : " << _hp << endl;
	cout << "±ñÇÁÀü»ç ¸¶·Â : " << _mp << endl;
	cout << "±ñÇÁÀü»ç ¹°°ø : " << _ad << endl;
	cout << "±ñÇÁÀü»ç ¸¶°ø : " << _ap << endl;
}