#include "210421 2. MainGame.h"

MainGame::MainGame()
{
	_shop = new Shop;
	_shop->itemSetup();
	
	_inven = new Inventory;

	_money = 500000;
	_selectNum = 0;

	// ó������ ���� ȭ���� �����ش�
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
	cout << "=============== 28�� ��� ���� ==============" << endl;
	cout << " 1. ����          2. �κ��丮" << endl;
	cout << "=============================================" << endl;
	cin >> _selectNum;
	
	system("cls");
	setLocation(_selectNum);
}

void MainGame::setShopPage()
{
	while (true)
	{
		cout << "=============== 28�� ��� ���� ==============" << endl;
		cout << " 1. ���ⱸ 2. �� 3. �Ǽ��縮 4. ����" << endl;
		cout << "=============================================" << endl;
		cout << "����ȭ������ ������ 0��" << endl;
		cin >> _selectNum;

		system("cls");
		if (_selectNum == 0)
		{
			setMainPage();
			break;
		}
		_shop->itemOutput(_selectNum);
		cout << "���Ŵ� 1, �ڷΰ����� �ƹ�Ű�� ��������" << endl;
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
		cout << "=============== ��� �κ��丮 ===============" << endl;
		// TODO - �κ��丮�� �ִ� ������ ���
		_inven->InvenOutput();
		cout << "=============================================" << endl;
		cout << "����ȭ������ ������ 0��" << endl;
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