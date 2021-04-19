#include "210419 5. Elf.h"

Elf::Elf()
{
	_hp = 100;
	_mp = 50;
	_ad = 8;
	_ap = 7;
}

Elf::~Elf()
{

}

void Elf::QSkill()
{
	cout << "기본 엘프 Q 스킬 : 활쏘기" << endl;
}

void Elf::WSkill()
{
	cout << "기본 엘프 W 스킬 : 야생동물 길들이기" << endl;
}

void Elf::ESkill()
{
	cout << "기본 엘프 E 스킬 : 민첩성 증가" << endl;
}

void Elf::RSkill()
{
	cout << "기본 엘프 궁극기 스킬 : 집중사격 " << endl;
}

void Elf::Output()
{
	 cout << "기본 엘프 체력 : " << _hp << endl;
	 cout << "기본 엘프 마력 : " << _mp << endl;
	 cout << "기본 엘프 물공 : " << _ad << endl;
	 cout << "기본 엘프 마공 : " << _ap << endl;
}