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

	// 캐논 초기화
	_obj.angle = PI / 2;				// 캐논의 각도 설정
	_obj.length = 100;					// 캐논의 길이 설정
	_obj.radius = 100;					// 캐논의 반지름 설정
	_obj.center.x = WINSIZEX / 2;		// 캐논의 시작점 X 설정
	_obj.center.y = WINSIZEY;			// 캐논의 시작점 Y 설정

	// 미사일 초기화
	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].speed = 5;			// 총알 스피드 설정
		_bullet[i].radius = 20;			// 총알 반지름 설정
		_bullet[i].isFire = false;		// 총알 발사 여부 설정
	}

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

	// 대포의 끝점 X, Y 설정
	_obj.endPoint.x = cosf(_obj.angle) * _obj.length + _obj.center.x;
	_obj.endPoint.y = -sinf(_obj.angle) * _obj.length + _obj.center.y;

	// 왼쪽, 오른쪽, 발사 키보드를 누를 때
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _obj.angle <= 3.0)	// 누름 여부 및 각도 제한
		_obj.angle += 0.04f;

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _obj.angle > 0.15)	// 누름 여부 및 각도 제한
		_obj.angle -= 0.04f;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))						// 누름 여부
		bulletFire();												// 총알 발사
		
	// 총알 움직임
	bulletMove();
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================	

	EllipseMakeCenter(backDC, _obj.center.x, _obj.center.y, 100, 100);					// 대포 원 출력
	LineMake(backDC, _obj.center.x, _obj.center.y, _obj.endPoint.x, _obj.endPoint.y);	// 대포 포선 길이 출력

	// 총알 출력
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		EllipseMakeCenter(backDC, _bullet[i].x, _bullet[i].y, _bullet[i].radius * 2, _bullet[i].radius * 2);
	}

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

// 총알 발사 함수
void playGround::bulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet[i].isFire) continue;

		_bullet[i].isFire = true;
		_bullet[i].x = cosf(_obj.angle) * (_obj.length + 5) + _obj.center.x;
		_bullet[i].y = -sinf(_obj.angle) * (_obj.length + 5) + _obj.center.y;
		_bullet[i].angle = _obj.angle;
		break;
	}
}

// 총알 움직임 함수
void playGround::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;

		_bullet[i].x += cosf(_bullet[i].angle) * _bullet[i].speed;
		_bullet[i].y += -sinf(_bullet[i].angle) * _bullet[i].speed;

		// 화면 바깥으로 나갈 경우 나갈수 있는 총알 개수 초기화 (순서 : 상, 좌우(같이))
		if (_bullet[i].y + _bullet[i].radius < 0)
			_bullet[i].isFire = false;
		
		// 좌 OR 우
		if (_bullet[i].x + _bullet[i].radius < 0 || _bullet[i].x + _bullet[i].radius > WINSIZEX) 
			_bullet[i].isFire = false;
	}
}