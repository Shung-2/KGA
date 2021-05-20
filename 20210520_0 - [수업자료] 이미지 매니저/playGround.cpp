#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init();

	IMAGEMANAGER->addImage("하울", "img1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("석탄", "img2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("키키", "img3.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("포뇨", "img4.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공주", "img5.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_background = IMAGEMANAGER->findImage("포뇨");


	_player = new image;
	_player->init("myth_run.bmp", 1710, 268, 15, 2, true, RGB(255, 0, 255));

	_player->setX(WINSIZEX / 2 - 100);
	_player->setY(WINSIZEY / 2 - 100);

	_count = _index = 0;

	_state = RIGHT_IDLE;


	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();



}

//여기에다 연산하세요 제에발
void playGround::update()
{
	gameNode::update();

	if(KEYMANAGER->isOnceKeyDown(VK_F1)) _background = IMAGEMANAGER->findImage("하울");
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _background = IMAGEMANAGER->findImage("석탄");
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) _background = IMAGEMANAGER->findImage("키키");
	if (KEYMANAGER->isOnceKeyDown(VK_F4)) _background = IMAGEMANAGER->findImage("포뇨");
	if (KEYMANAGER->isOnceKeyDown(VK_F5)) _background = IMAGEMANAGER->findImage("공주");


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

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	
	_background->render(backDC, 0, 0);
	_player->frameRender(backDC, _player->getX(), _player->getY());



	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}
