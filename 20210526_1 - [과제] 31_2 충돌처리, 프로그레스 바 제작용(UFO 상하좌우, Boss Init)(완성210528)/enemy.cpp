#include "stdafx.h"
#include "enemy.h"

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(const char* imageName, POINT position)
{
	_currentFrameX = _currentFrameY = 0;
	_count = _fireCount = 0;
	_rndFireCount = RND->getFromIntTo(1, 800);
	_imageName = IMAGEMANAGER->findImage(imageName);

	// ## 210528 ufo move, boss ##
	_x = position.x;
	_y = position.y;

	_rc = RectMakeCenter(_x, _y,
		_imageName->getFrameWidth(), _imageName->getFrameHeight());

	return S_OK;
}

void enemy::relase()
{
}

void enemy::update()
{
	_count++;
	if (_count % 2 == 0)
	{
		if (_currentFrameX >= _imageName->getMaxFrameX()) _currentFrameX = 0; _imageName->setFrameX(_currentFrameX);
		_currentFrameX++;

		_count = 0;
	}
}

void enemy::render()
{
	draw();
}

// ## 210528 ufo move, boss ##
void enemy::move(int MoveX, int MoveY)
{
	_x += MoveX;
	_y += MoveY;
	// Render를 통해 _rc위치 재 연산
	_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
}

void enemy::draw()
{
	_imageName->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

// 에너미가 발사했다고 신호만 주는 함수
bool enemy::bulletCountFire()
{
	// Update 함수에서 firecount가 계속 증가.
	_fireCount++;

	// 발사 카운트는 랜덤의 숫자를 받기 때문에 둘이 겹쳐질 때 맞아 떨어지면 실행한다
	if (_fireCount % _rndFireCount == 0)
	{
		// 다시금 발사 카운트를 랜덤으로 준다.
		_rndFireCount = RND->getFromIntTo(1, 800);
		// 파이어카운트도 0으로 다시 설정한다
		_fireCount = 0;

		// 결과 값을 반환한다. (트루 값을 반환받을 때 발사가 되는 것임)
		return true;
	}
	return false;
}