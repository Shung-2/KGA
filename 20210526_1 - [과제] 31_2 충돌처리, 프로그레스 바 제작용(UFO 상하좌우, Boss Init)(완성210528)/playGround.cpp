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

	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemy", "ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));
	// ## 210528 ufo move, boss ##
	IMAGEMANAGER->addFrameImage("boss", "ufo.bmp", 0, 0, 2120, 128, 10, 1, true, RGB(255, 0, 255));

	// �����̽� �� �����Ҵ�
	_ship = new spaceShip;
	_ship->init();
	
	// ���ʹ� �޴��� �����Ҵ�
	_em = new enemyManager;
	_em->init();
	_em->setMinion();

	// �����ڸ� �־��ش�.
	// _ship�� �����Ҵ�Ǽ� ����ָ� �Ű������� �Ѱ��༭
	// setSpaceShipMemoryAddressLink�� �Ķ���͸� ���� �����Ҵ� �� �޸𸮸� �Ѱܹ޾� �� �����Ϳ� �������ش�.
	// ���. ���漱��� ���ʹ̸Ŵ����� �����̽����� ���� �ּ����� ��ũ�����ش�
	_em->setSpaceShipMemoryAddressLink(_ship);
	// ��
	_ship->setEmMemoryAddressLink(_em);

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
	_em->update();
	
	// 1�� ��� �浹 (2�� ����� enemyManager Update�� �ִ�.)
	// collision();
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	IMAGEMANAGER->findImage("���")->render(getMemDC(), 0, 0);

	_ship->render();
	_em->render();

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
