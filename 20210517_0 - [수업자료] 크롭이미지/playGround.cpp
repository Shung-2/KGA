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

	_leo = new image;
	_leo->init("레오.bmp", WINSIZEX, WINSIZEY);


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

	
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	_leo->render(backDC, 0, 0);
	//복사시작될 left, top좌표로부터 가로크기, 세로크기 만큼 오려서 0,0에 뿌렸다
	//_leo->render(backDC, 0, 0, 400, 300, 150, 150);

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}
