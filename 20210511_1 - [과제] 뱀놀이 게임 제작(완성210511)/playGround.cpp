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

	// 1�� ��ǰ ���ͳ� ����
	// ��ó : https://minpro-tech.tistory.com/18?category=859872
	/*
	// ����� X, Y, ������, ����, �ӵ� ����
	_head.x = 400;
	_head.y = 500;
	_head.radius = 30.f;
	_head.angle = PI / 2;
	_head.speed = 5.0f;

	// �ٵ��� �� �� [0]�� °�� ������, X, Y, ���� ����
	_body[0].radius = 30.f;
	_body[0].x = _head.x;
	_body[0].y = _head.y + _body[0].radius * 1.5f;
	_body[0].angle = PI / 2;

	// �ٵ��� ������ �κ� ����
	for (int i = 1; i < SNAKEBODY; ++i)
	{
		_body[i].x = _body[i - 1].x;
		_body[i].y = _body[i - 1].y + _body[0].radius * 1.5f;
		_body[i].angle = PI / 2;
	}
	*/

	// 2�� ��ǰ (������ + ��)
	for (int i = 0; i < SNAKEBODY; i++)
	{
		// ���� 0��°(�Ӹ�)�� �Ǵ� ģ���� ����, X, Y�� ���� �������� �־� �����Ѵ�.
		if (i == 0)
		{
			_snake[i].angle = RND->getFloat(PI2);
			_snake[i].x = RND->getFromFloatTo(100, WINSIZEX - 100);
			_snake[i].y = RND->getFromFloatTo(100, WINSIZEX - 100);
		}
		// �� �� ģ������ ��� ���� �Ӹ��� �Ǵ� ģ������ ���󰡰� �����Ѵ�.
		else
		{
			_snake[i].angle = _snake[i - 1].angle;
			_snake[i].x = _snake[i - 1].x - cosf(_snake[i].angle) * (_snake[i].radius * 2 + _snake[i - 1].radius * 2);
			_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius * 2 + _snake[i - 1].radius * 2));
		}

		// �������� �ӵ� ����
		_snake[i].radius = 20;
		_snake[i].speed = 5;
	}

	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();
}

//���⿡�� �����ϼ��� ������s
void playGround::update()
{
	gameNode::update();
	
	// 1�� ��ǰ
	/* 
	_head.x += cosf(_head.angle) * _head.speed;																	// _head�� x ��ǥ ����
	_head.y += -sinf(_head.angle) * _head.speed;																// _head�� y ��ǥ ����

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))																		// ����Ű�� ������ �� ���� ���
		_head.angle += 0.04;																					
																												
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))																	// ����Ű�� ������ �� ���� ���
		_head.angle -= 0.04;

	if (getDistance(_head.x, _head.y, _body[0].x, _body[0].y) > (_body[0].radius) + 25)							// Head�� Head�� ���󰡾��ϴ� Body�� ���������� �Ÿ��� Ư�� �Ÿ����� Ŀ����
		_body[0].angle = atan2(-1 * (_head.y - _body[0].y), (_head.x - _body[0].x));							// Body�� Head�� ������ �̾� ���� �ﰢ���� ������ ���ؼ� Body�� ������ �������ش�

	_body[0].x += cosf(_body[0].angle) * _head.speed;															// _head�� ���󰡴� _body[0]�� x ��ǥ ����
	_body[0].y += -sinf(_body[0].angle) * _head.speed;															// _head�� ���󰡴� _body[0]�� y ��ǥ ����

	for (int i = 1; i < SNAKEBODY; ++i)
	{
		if (getDistance(_body[i - 1].x, _body[i - 1].y, _body[i].x, _body[i].y) > (_body[0].radius) + 30)
		{
			_body[i].angle = atan2(-1 * (_body[i - 1].y - _body[i].y), (_body[i - 1].x - _body[i].x));			// ���� ���� ������� ������ Body�� ó��
		}
		_body[i].x += cosf(_body[i].angle) * _head.speed;														// ������ Body�� X ��ǥ ����
		_body[i].y += -sinf(_body[i].angle) * _head.speed;														// ������ Body�� Y ��ǥ ����
	}

	// �� �浹 ó��
	if (_head.x < WINSTARTX || _head.x + _head.radius > WINSIZEX)												// �¿� �� �浹ó��
		_head.angle = PI - _head.angle;
	if (_head.y < WINSTARTY || _head.y + _head.radius > WINSIZEY)												// ���� �� �浹ó��
		_head.angle *= -1;
	*/

	// 1�� ��ǰ �Լ�ȭ BY �ÿ�
	/* 
	move();
	crash();
	*/

	// 2�� ��ǰ (������ + ��)
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _snake[0].angle += 0.04f;		// Ű���带 �̿��Ͽ� ������ȯ (���� �� ����)
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _snake[0].angle -= 0.04f;		// Ű���带 �̿��Ͽ� ������ȯ (���� �� ����)

	snackMove();
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	// 1�� ��ǰ
	/*
	EllipseMakeCenter(backDC, _head.x, _head.y, _head.radius * 2, _head.radius * 2);
	EllipseMakeCenter(backDC, _body[0].x, _body[0].y, _body[0].radius * 2, _body[0].radius * 2);

	for (int i = 1; i < SNAKEBODY; ++i)
	{
		EllipseMakeCenter(backDC, _body[i].x, _body[i].y, _body[0].radius * 2, _body[0].radius * 2);
	}
	*/

	// 2�� ��ǰ (������ + ��)
	// ���� �׷��ش�.
	for (int i = 0; i < SNAKEBODY; i++)
	{
		EllipseMakeCenter(backDC, _snake[i].x, _snake[i].y, _snake[i].radius * 2, _snake[i].radius * 2);
	}

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

// 1�� ��ǰ
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

// 2�� ��ǰ (������ + ��)
void playGround::snackMove()
{
	for (int i = 0; i < SNAKEBODY; i++)
	{
		if (i == 0)
		{
			// ���� 0��°(�Ӹ�)�� �Ǵ� ģ���� X, Y ��ǥ ����
			_snake[0].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[0].y += -sinf(_snake[i].angle) * _snake[i].speed;

			// �� �浹 (��, ��)
			if (_snake[i].x + _snake[i].radius >= WINSIZEX || _snake[i].x - _snake[i].radius < 0)
				_snake[i].angle = PI - _snake[i].angle;
			
			// �� �浹 (��, ��)
			if (_snake[i].y + _snake[i].radius >= WINSIZEY || _snake[i].y - _snake[i].radius < 0)
				_snake[i].angle = PI2 - _snake[i].angle;
		}
		else
		{
			// [i]��°�� �� ������ �������� 2�谡 [i]��°�� ������ ���󰡾��ϴ� [i-1]�� �������̺��� �Ÿ��� Ŀ����
			if (_snake[i].radius * 2 <= getDistance(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y))
			{
				// [i]��°�� [i-1]�� ������ �̾� ���� �ﰢ���� ������ ���ؼ� [i]�� ������ �������ش�
				_snake[i].angle = getAngle(_snake[i].x, _snake[i].y, _snake[i - 1].x, _snake[i - 1].y);

				//���� ������ �ؼ� �̻ڰ� �ؾ��Ѵٸ�
				_snake[i].x = _snake[i - 1].x - (cosf(_snake[i].angle) * (_snake[i].radius + _snake[i - 1].radius));
				_snake[i].y = _snake[i - 1].y - (-sinf(_snake[i].angle) * (_snake[i].radius + _snake[i - 1].radius));
			}
			// ������ ģ������ X, Y ��ǥ ����
			_snake[i].x += cosf(_snake[i].angle) * _snake[i].speed;
			_snake[i].y += -sinf(_snake[i].angle) * _snake[i].speed;
		}
	}
}