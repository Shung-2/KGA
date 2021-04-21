#pragma once
#include <iostream>
#include <vector>
#include <String>
using namespace std;

enum ITEM
{
	ITEM_WEAPON = 1,
	ITEM_ARMOR,
	ITEM_ACCESORY,
	ITEM_POTION,
	ITEM_END
};

struct tagItemInfo
{
	ITEM itemKind;				// ������ ����
	string name;				// ������ �̸�
	string description;			// ������ ����
	int ability;				// ������ �ɷ�
	int price;					// ������ ����
};

class Shop
{
private:
	vector <tagItemInfo>			_vItem;
	vector <tagItemInfo>::iterator	_viItem;

public:
	Shop();
	~Shop();

	void itemSetup();				// ������ ����
	void itemOutput(int itemNum);	// ������ ���

	vector<tagItemInfo> getVShopItem() { return _vItem; }
	vector<tagItemInfo>::iterator getVIShopItem() { return _viItem; }

	//vector<tagItemInfo> setVShopItem() { _vItem = _vItem; }
	//vector<tagItemInfo>::iterator getVIShopItem() { _viItem = _viItem; }
};

