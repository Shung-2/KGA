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
	// Render�� ���� _rc��ġ �� ����
	_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
}

void enemy::draw()
{
	_imageName->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

// ���ʹ̰� �߻��ߴٰ� ��ȣ�� �ִ� �Լ�
bool enemy::bulletCountFire()
{
	// Update �Լ����� firecount�� ��� ����.
	_fireCount++;

	// �߻� ī��Ʈ�� ������ ���ڸ� �ޱ� ������ ���� ������ �� �¾� �������� �����Ѵ�
	if (_fireCount % _rndFireCount == 0)
	{
		// �ٽñ� �߻� ī��Ʈ�� �������� �ش�.
		_rndFireCount = RND->getFromIntTo(1, 800);
		// ���̾�ī��Ʈ�� 0���� �ٽ� �����Ѵ�
		_fireCount = 0;

		// ��� ���� ��ȯ�Ѵ�. (Ʈ�� ���� ��ȯ���� �� �߻簡 �Ǵ� ����)
		return true;
	}
	return false;
}