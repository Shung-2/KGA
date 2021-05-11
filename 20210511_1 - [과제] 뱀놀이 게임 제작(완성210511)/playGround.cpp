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

	// 1번 작품 인터넷 참고
	// 출처 : https://minpro-tech.tistory.com/18?category=859872
	/*
	// 헤드의 X, Y, 반지름, 각도, 속도 설정
	_head.x = 400;
	_head.y = 500;
	_head.radius = 30.f;
	_head.angle = PI / 2;
	_head.speed = 5.0f;

	// 바디의 맨 앞 [0]번 째의 반지름, X, Y, 각도 설정
	_body[0].radius = 30.f;
	_body[0].x = _head.x;
	_body[0].y = _head.y + _body[0].radius * 1.5f;
	_body[0].angle = PI / 2;

	// 바디의 나머지 부분 설정
	for (int i = 1; i < SNAKEBODY; ++i)
	{
		_body[i].x = _body[i - 1].x;
		_body[i].y = _body[i - 1].y + _body[0].radius * 1.5f;
		_body[i].angle = PI / 2;
	}
	*/

	// 2번 작품 (선생님 + 나)
	for (int i = 0; i < SNAKEBODY; i++)
	{
		// 뱀의 0번째(머리)가 되는 친구의 각도, X, Y의 값을 랜덤으로 주어 시작한다.
		if (i == 0)
		{
			_snake[i].angle = RND->getFloat(PI2);
			_snake[i].x = RND->getFromFloatTo(100, WINSIZEX - 100);
			_snake[i].y = RND->getFromFloatTo(100, WINSIZEX - 100);
		}
		// 그 외 친구들은 모두 뱀의 머리가 되는 친구들을 따라가게 설정한다.
		else
		{
			_snake[i].angle = _snake[i - 1].angle;
			_snake[i].x = _snake[i - 1].x - cosf(_snake[i].angle) * (_snake[i].radius * 2 + _snake[i - 1].radius * 2);
			_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius * 2 + _snake[i - 1].radius * 2));
		}

		// 반지름과 속도 설정
		_snake[i].radius = 20;
		_snake[i].speed = 5;
	}

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();
}

//여기에다 연산하세요 제에발s
void playGround::update()
{
	gameNode::update();
	
	// 1번 작품
	/* 
	_head.x += cosf(_head.angle) * _head.speed;																	// _head의 x 좌표 갱신
	_head.y += -sinf(_head.angle) * _head.speed;																// _head의 y 좌표 갱신

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))																		// 방향키를 눌렀을 때 각도 계산
		_head.angle += 0.04;																					
																												
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))																	// 방향키를 눌렀을 때 각도 계산
		_head.angle -= 0.04;

	if (getDistance(_head.x, _head.y, _body[0].x, _body[0].y) > (_body[0].radius) + 25)							// Head와 Head를 따라가야하는 Body의 중점사이의 거리가 특정 거리보다 커지면
		_body[0].angle = atan2(-1 * (_head.y - _body[0].y), (_head.x - _body[0].x));							// Body와 Head의 중점을 이어 만든 삼각형의 각도를 구해서 Body의 각도에 대입해준다

	_body[0].x += cosf(_body[0].angle) * _head.speed;															// _head를 따라가는 _body[0]의 x 좌표 갱신
	_body[0].y += -sinf(_body[0].angle) * _head.speed;															// _head를 따라가는 _body[0]의 y 좌표 갱신

	for (int i = 1; i < SNAKEBODY; ++i)
	{
		if (getDistance(_body[i - 1].x, _body[i - 1].y, _body[i].x, _body[i].y) > (_body[0].radius) + 30)
		{
			_body[i].angle = atan2(-1 * (_body[i - 1].y - _body[i].y), (_body[i - 1].x - _body[i].x));			// 위와 같은 방식으로 나머지 Body를 처리
		}
		_body[i].x += cosf(_body[i].angle) * _head.speed;														// 나머지 Body의 X 좌표 갱신
		_body[i].y += -sinf(_body[i].angle) * _head.speed;														// 나머지 Body의 Y 좌표 갱신
	}

	// 벽 충돌 처리
	if (_head.x < WINSTARTX || _head.x + _head.radius > WINSIZEX)												// 좌우 벽 충돌처리
		_head.angle = PI - _head.angle;
	if (_head.y < WINSTARTY || _head.y + _head.radius > WINSIZEY)												// 상하 벽 충돌처리
		_head.angle *= -1;
	*/

	// 1번 작품 함수화 BY 시영
	/* 
	move();
	crash();
	*/

	// 2번 작품 (선생님 + 나)
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _snake[0].angle += 0.04f;		// 키보드를 이용하여 방향전환 (각도 값 감소)
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _snake[0].angle -= 0.04f;		// 키보드를 이용하여 방향전환 (각도 값 감소)

	snackMove();
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	// 1번 작품
	/*
	EllipseMakeCenter(backDC, _head.x, _head.y, _head.radius * 2, _head.radius * 2);
	EllipseMakeCenter(backDC, _body[0].x, _body[0].y, _body[0].radius * 2, _body[0].radius * 2);

	for (int i = 1; i < SNAKEBODY; ++i)
	{
		EllipseMakeCenter(backDC, _body[i].x, _body[i].y, _body[0].radius * 2, _body[0].radius * 2);
	}
	*/

	// 2번 작품 (선생님 + 나)
	// 뱀을 그려준다.
	for (int i = 0; i < SNAKEBODY; i++)
	{
		EllipseMakeCenter(backDC, _snake[i].x, _snake[i].y, _snake[i].radius * 2, _snake[i].radius * 2);
	}

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

// 1번 작품
/*
void playGround::move()
{
	_head.x += cosf(_head.angle) * _head.speed;
	_head.y += -sinf(_head.angle) * _head.speed;
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		_head.angle += 0.04;

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		_head.angle -= 0.04;

	if (getDistance(_head.x, _head.y, _body[0].x, _body[0].y) > (_body[0].radius) + 25)
		_body[0].angle = atan2(-1 * (_head.y - _body[0].y), (_head.x - _body[0].x));

	_body[0].x += cosf(_body[0].angle) * _head.speed;
	_body[0].y += -sinf(_body[0].angle) * _head.speed;

	for (int i = 1; i < SNAKEBODY; ++i)
	{
		if (getDistance(_body[i - 1].x, _body[i - 1].y, _body[i].x, _body[i].y) > (_body[0].radius) + 30)
		{
			_body[i].angle = atan2(-1 * (_body[i - 1].y - _body[i].y), (_body[i - 1].x - _body[i].x));
		}
		_body[i].x += cosf(_body[i].angle) * _head.speed;
		_body[i].y += -sinf(_body[i].angle) * _head.speed;
	}
}

void playGround::crash()
{
	if (_head.x < WINSTARTX || _head.x + _head.radius > WINSIZEX)
		_head.angle = PI - _head.angle;
	if (_head.y < WINSTARTY || _head.y + _head.radius > WINSIZEY)
		_head.angle *= -1;
}
*/

// 2번 작품 (선생님 + 나)
void playGround::snackMove()
{
	for (int i = 0; i < SNAKEBODY; i++)
	{
		if (i == 0)
		{
			// 뱀의 0번째(머리)가 되는 친구의 X, Y 좌표 갱신
			_snake[0].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[0].y += -sinf(_snake[i].angle) * _snake[i].speed;

			// 벽 충돌 (좌, 우)
			if (_snake[i].x + _snake[i].radius >= WINSIZEX || _snake[i].x - _snake[i].radius < 0)
				_snake[i].angle = PI - _snake[i].angle;
			
			// 벽 충돌 (상, 하)
			if (_snake[i].y + _snake[i].radius >= WINSIZEY || _snake[i].y - _snake[i].radius < 0)
				_snake[i].angle = PI2 - _snake[i].angle;
		}
		else
		{
			// [i]번째의 뱀 몸통의 반지름의 2배가 [i]번째의 몸통을 따라가야하는 [i-1]의 중점사이보다 거리가 커지면
			if (_snake[i].radius * 2 <= getDistance(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y))
			{
				// [i]번째와 [i-1]의 중점을 이어 만든 삼각형의 각도를 구해서 [i]에 각도에 대입해준다
				_snake[i].angle = getAngle(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y);

				//굳이 보정을 해서 이쁘게 해야한다면
				_snake[i].x = _snake[i - 1].x - (cosf(_snake[i].angle) * (_snake[i].radius + _snake[i - 1].radius));
				_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius + _snake[i - 1].radius));
			}
			// 나머지 친구들의 X, Y 좌표 갱신
			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;
		}
	}
}