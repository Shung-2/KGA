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

	_isCollision = false;

	_rectangle = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);


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

	_ellipse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 200, 200);
	
	if (isCollision(_ellipse, _rectangle)) _isCollision = true;
	else _isCollision = false;

}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	Rectangle(backDC, _rectangle);
	Ellipse(backDC, _ellipse);

	if (_isCollision)
	{
		TextOut(backDC, WINSIZEX / 2, WINSIZEY / 2, "꺄", 2);
	}
	
	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

bool playGround::isCollision(RECT& rc1, RECT& rc2)
{
	POINT pt;

	pt.x = (rc1.left + rc1.right) / 2;
	pt.y = (rc1.top + rc1.bottom) / 2;

	int radius = (rc1.right - rc1.left) / 2;
	//면
	if ((rc2.left <= pt.x && pt.x <= rc2.right) ||
		(rc2.top <= pt.y && pt.y <= rc2.bottom))
	{
		RECT rcTemp;

		rcTemp.left = rc2.left - radius;
		rcTemp.right = rc2.right + radius;
		rcTemp.top = rc2.top - radius;
		rcTemp.bottom = rc2.bottom + radius;

		if (PtInRect(&rcTemp, pt)) return true;

	}
	else //꼭지
	{
		if (getDistance(rc1, rc2.left, rc2.top)) return true;
		if (getDistance(rc1, rc2.right, rc2.top)) return true;
		if (getDistance(rc1, rc2.left, rc2.bottom)) return true;
		if (getDistance(rc1, rc2.right, rc2.bottom)) return true;
	}

	return false;
}

//꼭지점 충돌할 준비는 끄읏 (끝)
bool playGround::getDistance(RECT& rc, float x, float y)
{
	float deltaX = x - ((rc.right + rc.left) / 2);
	float deltaY = y - ((rc.top + rc.bottom) / 2);

	//빗변이지만 거리라고 합시다
	float distance = sqrtf(deltaX * deltaX + deltaY * deltaY);
	float radius = (rc.right - rc.left) / 2;
	
	//충돌 X
	if (radius <= distance) return false;

	return true;
}

