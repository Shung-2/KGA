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

	for (int i = 0; i < SNAKEBODY; i++)
	{
		if (i == 0)
		{
			_snake[i].angle = RND->getFloat(PI2);
			_snake[i].x = RND->getFromFloatTo(100, WINSIZEX - 100);
			_snake[i].y = RND->getFromFloatTo(100, WINSIZEY - 100);
		}
		else
		{
			_snake[i].angle = _snake[i - 1].angle;
			_snake[i].x = _snake[i - 1].x - cosf(_snake[i].angle) * (_snake[i].radius * 2 + _snake[i - 1].radius * 2);
			_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius * 2+ _snake[i - 1].radius * 2));
		}

		_snake[i].radius = 20;
		_snake[i].speed = 5;
	}

	_horse = new image;
	_horse->init("��.bmp", WINSIZEX, WINSIZEY);

	_bird = new image;
	_bird->init("����.bmp", WINSIZEX, WINSIZEY);

	_mandarin = new image;
	_mandarin->init("��.bmp", 50, 50, true, RGB(255, 0, 255));

	_background = _horse;
	

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

	if (KEYMANAGER->isOnceKeyDown(VK_F1)) _background = _bird;
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) _background = _horse;

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _snake[0].angle += 0.08f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _snake[0].angle -= 0.08f;

	snakeMove();
	
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	_background->render(backDC, 0, 0);

	for (int i = 0; i < SNAKEBODY; i++)
	{
		_mandarin->render(backDC, _snake[i].x, _snake[i].y);
		// EllipseMakeCenter(backDC, _snake[i].x, _snake[i].y, _snake[i].radius * 2, _snake[i].radius * 2);
	}

	

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

void playGround::snakeMove()
{
	for (int i = 0; i < SNAKEBODY; i++)
	{
		if (i == 0)
		{
			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;

			if (_snake[i].x + _snake[i].radius >= WINSIZEX)
			{
				_snake[i].angle = PI - _snake[i].angle;
			}
			if (_snake[i].x - _snake[i].radius < 0)
			{
				_snake[i].angle = PI - _snake[i].angle;
			}
			if (_snake[i].y + _snake[i].radius >= WINSIZEY)
			{
				_snake[i].angle = PI2 - _snake[i].angle;
			}
			if (_snake[i].y - _snake[i].radius < 0)
			{
				_snake[i].angle = PI2 - _snake[i].angle;
			}
		}
		else
		{
			if (_snake[i].radius * 2 <= getDistance(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y))
			{
				_snake[i].angle = getAngle(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y);

				//���� ������ �ؼ� �̻ڰ� �ؾ��Ѵٸ�
				_snake[i].x = _snake[i - 1].x - (cosf(_snake[i].angle) * (_snake[i].radius + _snake[i - 1].radius));
				_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius + _snake[i - 1].radius));
			}

			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;
		}
	}
}
