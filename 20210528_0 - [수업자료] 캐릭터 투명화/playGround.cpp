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
	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemy", "ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));

	//�����̽� �� �����Ҵ�
	_ship = new spaceShip;
	_ship->init();

	//���ʹ̸Ŵ��� �����Ҵ�
	_em = new enemyManager;
	_em->init();
	_em->setMinion();

	//���漱��� ���ʹ̸Ŵ����� �����̽����� ���� �ּ����� ��ũ������
	_em->setSpaceShipMemoryAddressLink(_ship);
	_ship->setEmMemoryAddressLink(_em);
		
	_slt = new saveLoadTest;


	_loopX = _loopY = 0;
	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();

	SAFE_DELETE(_ship);
	SAFE_DELETE(_em);
	SAFE_DELETE(_slt);
}


void playGround::update()
{
	gameNode::update();

	_ship->update();
	_em->update();
	//collision();
	//_slt->update();

	_loopY -= 5;
	//_loopX += 5;
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	RECT rc = RectMake(0, 0, WINSIZEX, 300);
	IMAGEMANAGER->findImage("���")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("���")->loopRender(getMemDC(), &rc, _loopX, _loopY);

	_ship->render();
	_em->render();


	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
