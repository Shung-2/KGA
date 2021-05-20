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
	gameNode::init();

	IMAGEMANAGER->addImage("�Ͽ�", "img1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ź", "img2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ŰŰ", "img3.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "img4.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "img5.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_background = IMAGEMANAGER->findImage("����");


	_player = new image;
	_player->init("myth_run.bmp", 1710, 268, 15, 2, true, RGB(255, 0, 255));

	_player->setX(WINSIZEX / 2 - 100);
	_player->setY(WINSIZEY / 2 - 100);

	_count = _index = 0;

	_state = RIGHT_IDLE;


	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();



}

//���⿡�� �����ϼ��� ������
void playGround::update()
{
	gameNode::update();

	if(KEYMANAGER->isOnceKeyDown(VK_F1)) _background = IMAGEMANAGER->findImage("�Ͽ�");
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _background = IMAGEMANAGER->findImage("��ź");
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) _background = IMAGEMANAGER->findImage("ŰŰ");
	if (KEYMANAGER->isOnceKeyDown(VK_F4)) _background = IMAGEMANAGER->findImage("����");
	if (KEYMANAGER->isOnceKeyDown(VK_F5)) _background = IMAGEMANAGER->findImage("����");


	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_state = RIGHT_RUN;
		_player->setX(_player->getX() + 5);
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state = RIGHT_IDLE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_state = LEFT_RUN;
		_player->setX(_player->getX() - 5);
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = LEFT_IDLE;
	}



	_count++;

	if (_count % 10 == 0)
	{
		if (_state == RIGHT_IDLE)
		{
			_player->setFrameY(0);
			_player->setFrameX(_index);
			_index++;

			if (_index >= 4) _index = 0;
		}
		if (_state == LEFT_IDLE)
		{
			_player->setFrameY(1);
			_player->setFrameX(_index);
			_index--;

			if (_index <= 10) _index = _player->getMaxFrameX();
		}
		if (_state == RIGHT_RUN)
		{
			_player->setFrameY(0);
			_player->setFrameX(_index);
			_index++;

			if (_index >= _player->getMaxFrameX()) _index = 6;
		}
		if (_state == LEFT_RUN)
		{
			_player->setFrameY(1);
			_player->setFrameX(_index);
			_index--;

			if (_index <= 0) _index = 7;
		}
		
		
		_count = 0;
	}
	
	

}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	
	_background->render(backDC, 0, 0);
	_player->frameRender(backDC, _player->getX(), _player->getY());



	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}
