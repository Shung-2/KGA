#pragma once
#include "210421 3. Shop.h"
#include "210421 4. Inventory.h"
using namespace std;

enum LOCATION
{
	LOCATION_SHOP = 1,
	LOCATION_INVEN
};

class MainGame
{
private:
	Shop* _shop;
	Inventory* _inven;
	LOCATION _location;

	int _money;			// ������
	int _selectNum;		// ���ú���

public :
	MainGame();
	~MainGame();

	void setLocation(int number);
	void setMainPage();
	void setShopPage();
	void setInvenPage();
	void buy_item();
};

