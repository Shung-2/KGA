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
	weapon1.name = "�������� �����";
	weapon1.description = "���� ���. �ڼ��� �鿩�ٺ��� made in china�� �����ִ�";
	weapon1.ability = 999;
	weapon1.price = 10;
	_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.name = "�ÿ����� ��";
	weapon2.description = "���ϵ� ���� ��, ���۳��� ���� ����ִ� �δ��� ���� ���ǰ";
	weapon2.ability = 5;
	weapon2.price = 10;
	_vItem.push_back(weapon2);

	tagItemInfo weapon3;
	weapon3.itemKind = ITEM_WEAPON;
	weapon3.name = "������ K2";
	weapon3.description = "px���� ���Ű����ϴ�, �౺�Ҷ� ���ſ���";
	weapon3.ability = 20;
	weapon3.price = 4000;
	_vItem.push_back(weapon3);

	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.name = "�������� ������";
	armor1.description = "���� ���� �� ������ �� -�װ�-";
	armor1.ability = 0;
	armor1.price = 1000;
	_vItem.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemKind = ITEM_ARMOR;
	armor2.name = "�������� �۷���";
	armor2.description = "���ָ� ��ų�� ž��Ǿ� �ִ�, ���ε� �̴߰�";
	armor2.ability = 30;
	armor2.price = 100000;
	_vItem.push_back(armor2);

	tagItemInfo armor3;
	armor3.itemKind = ITEM_ARMOR;
	armor3.name = "�������� �¾簩��";
	armor3.description = "�¾縸�� ����θ� �ٴ� �� �ִ�";
	armor3.ability = 50;
	armor3.price = 5;
	_vItem.push_back(armor3);

	tagItemInfo acce1;
	acce1.itemKind = ITEM_ACCESORY;
	acce1.name = "������ �� ����";
	acce1.description = "�̻��ϴ�..�����ΰ��� �����־���..hoxy?";
	acce1.ability = 2;
	acce1.price = 10000;
	_vItem.push_back(acce1);

	tagItemInfo acce2;
	acce2.itemKind = ITEM_ACCESORY;
	acce2.name = "��ȭ�� �ð�";
	acce2.description = "����ħ�� ������. ���� ������ �� ���̴�";
	acce2.ability = 10;
	acce2.price = 5;
	_vItem.push_back(acce2);

	tagItemInfo potion1;
	potion1.itemKind = ITEM_POTION;
	potion1.name = "����� �ƾ�";
	potion1.description = "������ ������ �ɼ��ɶ������� feat.10��";
	potion1.ability = 2000;
	potion1.price = 2000;
	_vItem.push_back(potion1);

	tagItemInfo potion2;
	potion2.itemKind = ITEM_POTION;
	potion2.name = "�������� ����";
	potion2.description = "����� �������� (�װ� �������̾�)";
	potion2.ability = 500;
	potion2.price = 1000;
	_vItem.push_back(potion2);
}


void Shop::itemOutput(int itemNum)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->itemKind != itemNum) continue;

		cout << "=============== 28�� ��� ���� ==============" << endl;
		cout << "�� �� : " << _viItem->name << endl;
		cout << "�� �� : " << _viItem->ability << endl;
		cout << "�� �� : " << _viItem->price << endl;
		cout << "�� �� : " << _viItem->description << endl;
		cout << "=============================================" << endl << endl;
	}	
}