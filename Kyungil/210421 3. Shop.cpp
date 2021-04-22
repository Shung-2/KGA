#include "210421 3. Shop.h"
#include <Windows.h>

Shop::Shop()
{

}

Shop::~Shop()
{

}

void Shop::itemSetup()
{
	tagItemInfo weapon1;
	weapon1.itemKind = ITEM_WEAPON;
	weapon1.name = "유정이의 듀란달";
	weapon1.description = "완전 쎄다. 자세히 들여다보면 made in china가 적혀있다";
	weapon1.ability = 999;
	weapon1.price = 10;
	_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.name = "시영이의 낫";
	weapon2.description = "흔하디 흔한 낫, 소작농의 한이 담겨있다 두덕리 마을 기념품";
	weapon2.ability = 5;
	weapon2.price = 10;
	_vItem.push_back(weapon2);

	tagItemInfo weapon3;
	weapon3.itemKind = ITEM_WEAPON;
	weapon3.name = "광수의 K2";
	weapon3.description = "px에서 구매가능하다, 행군할때 무거워짐";
	weapon3.ability = 20;
	weapon3.price = 4000;
	_vItem.push_back(weapon3);

	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.name = "영섭이의 스냅백";
	armor1.description = "나는 슬플 때 힙합을 춰 -네가-";
	armor1.ability = 0;
	armor1.price = 1000;
	_vItem.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemKind = ITEM_ARMOR;
	armor2.name = "유림이의 글러브";
	armor2.description = "불주먹 스킬이 탑재되어 있다, 본인도 뜨겁다";
	armor2.ability = 30;
	armor2.price = 100000;
	_vItem.push_back(armor2);

	tagItemInfo armor3;
	armor3.itemKind = ITEM_ARMOR;
	armor3.name = "정훈이의 태양갑옷";
	armor3.description = "태양만세 포즈로만 다닐 수 있다";
	armor3.ability = 50;
	armor3.price = 5;
	_vItem.push_back(armor3);

	tagItemInfo acce1;
	acce1.itemKind = ITEM_ACCESORY;
	acce1.name = "찬미의 은 반지";
	acce1.description = "이상하다..늑대인간이 끼고있었다..hoxy?";
	acce1.ability = 2;
	acce1.price = 10000;
	_vItem.push_back(acce1);

	tagItemInfo acce2;
	acce2.itemKind = ITEM_ACCESORY;
	acce2.name = "주화의 시계";
	acce2.description = "마취침이 나간다. 물론 방향은 내 쪽이다";
	acce2.ability = 10;
	acce2.price = 5;
	_vItem.push_back(acce2);

	tagItemInfo potion1;
	potion1.itemKind = ITEM_POTION;
	potion1.name = "양쌤의 아아";
	potion1.description = "선동과 날조가 능수능란해진다 feat.10분";
	potion1.ability = 2000;
	potion1.price = 2000;
	_vItem.push_back(potion1);

	tagItemInfo potion2;
	potion2.itemKind = ITEM_POTION;
	potion2.name = "종익이의 몬스터";
	potion2.description = "심장아 나대지마 (그거 부정맥이야)";
	potion2.ability = 500;
	potion2.price = 1000;
	_vItem.push_back(potion2);
}


void Shop::itemOutput(int itemNum)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->itemKind != itemNum) continue;

		cout << "=============== 28기 용사 상점 ==============" << endl;
		cout << "이 름 : " << _viItem->name << endl;
		cout << "성 능 : " << _viItem->ability << endl;
		cout << "설 명 : " << _viItem->price << endl;
		cout << "가 격 : " << _viItem->description << endl;
		cout << "=============================================" << endl << endl;
	}	
}