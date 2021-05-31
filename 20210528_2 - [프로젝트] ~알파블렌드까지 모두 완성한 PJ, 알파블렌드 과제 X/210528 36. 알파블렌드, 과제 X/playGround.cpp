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
	// ## 210528 ���� ���� Alpha ���� ##
	IMAGEMANAGER->addImage("��", "��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "����.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

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

	// ## 210527 ���� ���� Save&Load, Loop Render ##
	_slt = new saveLoadTest;
	_loopX = _loopY = 0;
	
	// ## 210528 ���� ���� Alpha ���� ##
	_fadeIn = 0;
	_fadeOut = 255;
	_isChange = false;

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
	
	// 1�� ��� �浹 (2�� ����� enemyManager Update�� �ִ�.)
	// collision();

	// ## 210527 ���� ���� Save&Load, Loop Render ##
	//_slt->update();
	//_loopY -= 5;
	//_loopX += 5;

	// ## 210528 ���� ���� Alpha ���� ##
	// ������������ ��� ��ȯ, �ǰݴ��� �� �����Ÿ��� ����ϸ� ����
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isChange = true;
	}

	if (_isChange)
	{
		_fadeIn++;
		_fadeOut--;

		if (_fadeIn >= 255) _isChange = false;
	}
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	IMAGEMANAGER->findImage("���")->render(getMemDC(), 0, 0);
	// ## 210527 ���� ���� Save&Load, Loop Render ##
	// IMAGEMANAGER->findImage("���")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _loopX, _loopY);

	// ���� �� ���� ������ �����ϴ�.
	//IMAGEMANAGER->findImage("���")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, 300),
	//	_loopX, _loopY);

	_ship->render();
	_em->render();

	// ## 210528 ���� ���� Alpha ���� ##
	//IMAGEMANAGER->findImage("����")->alphaRender(getMemDC(), _fadeOut);
	//IMAGEMANAGER->findImage("��")->alphaRender(getMemDC(), _fadeIn);

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
