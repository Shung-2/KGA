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

	// 초기화
	_iscrash = false;															// 충돌여부
	_center_Ellipse = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 300, 300); 	// 중앙 원
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

	_user_Ellipse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 100);				// 사용자 원 초기화
	_user_radius = (_user_Ellipse.right - _user_Ellipse.left) / 2;					// 사용장 원 반지름

	_center_Ellipse_x = (_center_Ellipse.left + _center_Ellipse.right) / 2;			// 가운데 원 중점 X 좌표
	_center_Ellipse_y = (_center_Ellipse.top + _center_Ellipse.bottom) / 2;			// 가운데 원 중점 Y 좌표
	_center_Ellipse_radius = (_center_Ellipse.right - _center_Ellipse.left) / 2;	// 가운데 원 반지름

	_distance_x = _center_Ellipse_x - _ptMouse.x;									// 가운데 원 중점 X 좌표 - 사용자 원 중점 X 좌표 값
	_distance_y = _center_Ellipse_y - _ptMouse.y;									// 가운데 원 중점 Y 좌표 - 사용자 원 중점 Y 좌표 값
	_hypo = sqrt(_distance_x * _distance_x + _distance_y * _distance_y);			// 빗변
	
	/*
	-sqrt 함수가 하는일 : 매개변수 x로 들어온 숫자에 루트를 씌워서 계산한 값을 반환해주는 일을 합니다.
	즉, 루트 x를 구해주는 함수입니다.를 구해주는 함수입니다. (제곱근을 구해주는 함수)
	출처: https://blockdmask.tistory.com/307 [개발자 지망생]
	*/

	// 충돌여부 판정
	if ((_user_radius + _center_Ellipse_radius) >= _hypo)
	{
		_iscrash = true;
	}
	else
	{
		_iscrash = false;
	}
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================
	
	// 사용자 원과 중앙 원 그려주기
	Ellipse(backDC, _user_Ellipse);
	Ellipse(backDC, _center_Ellipse);

	// 충돌일 때 가운데 원 색칠
	if (_iscrash)
	{
		HBRUSH brush1 = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush1 = (HBRUSH)SelectObject(backDC, brush1);
		Ellipse(backDC, _center_Ellipse);
		SelectObject(backDC, oldBrush1);
		DeleteObject(brush1);
	}

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}
