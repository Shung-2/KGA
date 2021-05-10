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

	_cannon.angle = PI / 2;
	_cannon.cannon = 100;
	_cannon.radius = 100;
	_cannon.center.x = WINSIZEX / 2;
	_cannon.center.y = WINSIZEY;
	

	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].speed = 5;
		_bullet[i].radius = 20;
		_bullet[i].isFire = false;
		_bullet[i].gravity = 0;
	}	

	for (int i = 0; i < PREVIEWMAX; i++)
	{
		_preview[i].radius = 5;
	}

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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _cannon.angle <= 3.04) _cannon.angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _cannon.angle >= 0.08) _cannon.angle -= 0.04f;
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) bulletFire();
	//if (KEYMANAGER->isStayKeyDown('A')) _cannon.center.x -= 3;
	//if (KEYMANAGER->isStayKeyDown('D')) _cannon.center.x += 3;

	_cannon.cannonEnd.x = cosf(_cannon.angle) * _cannon.cannon + _cannon.center.x;
	_cannon.cannonEnd.y = -sinf(_cannon.angle) * _cannon.cannon + _cannon.center.y;

	//�뿵���� �˷��� 1�� (���� �̻�� 
	/*
	float deltaX = cosf(_cannon.angle) * _bullet[0].speed;
	float deltaY = -sinf(_cannon.angle) * _bullet[0].speed;

	_preview[0].x = cosf(_cannon.angle) * (_cannon.cannon + 3) + _cannon.center.x;
	_preview[0].y = -sinf(_cannon.angle) * (_cannon.cannon + 3) + _cannon.center.y;
	_preview[0].gravity = 0;

	for (int i = 1; i < PREVIEWMAX; i++)
	{
		_preview[i].gravity = _preview[i - 1].gravity + 0.05f;
		_preview[i].x = _preview[i - 1].x + deltaX;
		_preview[i].y = _preview[i - 1].y + deltaY + _preview[i].gravity;
	}
	*/

	// �뿵+�������� �˷��� 2�� (���� ���)
	/*
	float deltaX = cosf(_cannon.angle) * _bullet[0].speed;
	float deltaY = -sinf(_cannon.angle) * _bullet[0].speed;

	for (int i = 1; i < PREVIEWMAX; i++)
	{
		_preview[i].gravity = 0.05f;

		if (i % 10 == 0)
		{
			_preview[i].x = _cannon.cannonEnd.x + deltaX * i;
			_preview[i].y = _cannon.cannonEnd.y + deltaY * i + (_preview[i].gravity / 2) * i * i;
		}
	}
	*/

	// �Լ�ȭ by �ÿ�
	bulletPreview();
	bulletMove();
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================
	EllipseMakeCenter(backDC, _cannon.center.x, _cannon.center.y, 100, 100);
	LineMake(backDC, _cannon.center.x, _cannon.center.y, _cannon.cannonEnd.x, _cannon.cannonEnd.y);
	
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		EllipseMakeCenter(backDC, _bullet[i].x, _bullet[i].y, _bullet[i].radius * 2, _bullet[i].radius * 2);
	}

	for (int i = 0; i < PREVIEWMAX; i++)
	{
		EllipseMakeCenter(backDC, _preview[i].x, _preview[i].y, _preview[i].radius, _preview[i].radius);
	}

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

void playGround::bulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet[i].isFire) continue;

		_bullet[i].isFire = true;
		_bullet[i].x = cosf(_cannon.angle) * (_cannon.cannon + 3) + _cannon.center.x;
		_bullet[i].y = -sinf(_cannon.angle) * (_cannon.cannon + 3) + _cannon.center.y;
		_bullet[i].angle = _cannon.angle;
		break;
	}
}

void playGround::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		_bullet[i].gravity += 0.05f;
		_bullet[i].x += cosf(_bullet[i].angle) * _bullet[i].speed;
		_bullet[i].y += -sinf(_bullet[i].angle) * _bullet[i].speed + _bullet[i].gravity;

		//ȭ�� �������� ������
		if (_bullet[i].x - _bullet[i].radius < 0)
		{
			//_bullet[i].angle = PI - _bullet[i].angle;
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
			
		}
		//ȭ�� ���������� ������
		if (_bullet[i].x + _bullet[i].radius > WINSIZEX)
		{
			//_bullet[i].angle = PI - _bullet[i].angle;
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
			
		}
		//ȭ�� �������� ������
		if (_bullet[i].y - _bullet[i].radius < 0)
		{
			//_bullet[i].angle = PI * 2 - _bullet[i].angle;
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
			
		}
		//ȭ�� �Ʒ������� ������
		if (_bullet[i].y + _bullet[i].radius > WINSIZEY)
		{
			//_bullet[i].angle = PI * 2 - _bullet[i].angle;
			_bullet[i].isFire = false;
			_bullet[i].gravity = 0;
		
		}
	}
}

void playGround::bulletPreview()
{
	float deltaX = cosf(_cannon.angle) * _bullet[0].speed;
	float deltaY = -sinf(_cannon.angle) * _bullet[0].speed;

	for (int i = 1; i < PREVIEWMAX; i++)
	{
		_preview[i].gravity = 0.05f;

		if (i % 10 == 0)
		{
			_preview[i].x = _cannon.cannonEnd.x + deltaX * i;
			_preview[i].y = _cannon.cannonEnd.y + deltaY * i + (_preview[i].gravity / 2) * i * i;
		}
	}
}