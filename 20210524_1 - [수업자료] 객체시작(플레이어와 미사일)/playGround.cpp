#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY,
		true, RGB(255, 0, 255));

	_ship = new spaceShip;
	_ship->init();
	

	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();

	SAFE_DELETE(_ship);

}


void playGround::update()
{
	gameNode::update();

	_ship->update();

}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	IMAGEMANAGER->findImage("���")->render(getMemDC(), 0, 0);

	_ship->render();



	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
