#include "210421 2. MainGame.h"

MainGame::MainGame()
{
	_shop = new Shop;
	_shop->itemSetup();
	
	_inven = new Inventory;

	_money = 500000;
	_selectNum = 0;

	// 처음에는 메인 화면을 보여준다
	setMainPage();
}

MainGame::~MainGame()
{
	delete _shop;
	delete _inven;
}

void MainGame::setLocation(int number)
{
	switch (number)
	{
	case LOCATION_SHOP:
		setShopPage();
		break;

	case LOCATION_INVEN:
		setInvenPage();
		break;

	default:
		setMainPage();
		break;
	}
}

void MainGame::setMainPage()
{
	cout << "=============== 28기 용사 상점 ==============" << endl;
	cout << " 1. 상점          2. 인벤토리" << endl;
	cout << "=============================================" << endl;
	cin >> _selectNum;
	
	system("cls");
	setLocation(_selectNum);
}

void MainGame::setShopPage()
{
	while (true)
	{
		cout << "=============== 28기 용사 상점 ==============" << endl;
		cout << " 1. 무기구 2. 방어구 3. 악세사리 4. 포션" << endl;
		cout << "=============================================" << endl;
		cout << "메인화면으로 가려면 0번" << endl;
		cin >> _selectNum;

		system("cls");
		if (_selectNum == 0)
		{
			setMainPage();
			break;
		}
		_shop->itemOutput(_selectNum);
		cout << "구매는 1, 뒤로가려면 아무키나 누르세요" << endl;
		cin >> _selectNum;
		if (_selectNum == 1)
		{
			buy_item();
		}
		else { }
		system("cls");
	}
}

void MainGame::setInvenPage()
{
	while (true)
	{
		cout << "=============== 용사 인벤토리 ===============" << endl;
		// TODO - 인벤토리에 있는 아이템 출력
		_inven->InvenOutput();
		cout << "=============================================" << endl;
		cout << "메인화면으로 가려면 0번" << endl;
		cin >> _selectNum;

		system("cls");
		if (_selectNum == 0)
		{
			setMainPage();
			break;
		}
	}
}

void MainGame::buy_item()
{
	cout << "test" << endl;
}