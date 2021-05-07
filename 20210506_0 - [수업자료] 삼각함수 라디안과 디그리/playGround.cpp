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

	_radian = PI / 2;
	_degree = 45.0f;

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
	char strRadian[128];
	char strDegree[128];

	sprintf_s(strRadian, "%.2f 라디안 값은 %.2f 디그리와 같다",
		_radian, _radian * (180.0f / PI));
	TextOut(backDC, 100, 100, strRadian, strlen(strRadian));

	sprintf_s(strDegree, "%.2f 디그리 값은 %.2f 라디안와 같다",
		_degree, _degree * (PI / 180.0f));
	TextOut(backDC, 100, 200, strDegree, strlen(strDegree));

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}