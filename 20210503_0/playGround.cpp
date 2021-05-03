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

	_player = RectMakeCenter(WINSIZEX / 2 - 350, WINSIZEY / 2, 100, 50);
	_player2 = RectMakeCenter(WINSIZEX / 2 + 350, WINSIZEY / 2, 100, 50);

	//�Ѿ��� �ִ밹����ŭ for���� ������
	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].x = _player.right + 10;
		_bullet[i].y = (_player.top + _player.bottom) / 2;
		_bullet[i].rc = RectMakeCenter(_bullet[i].x,
			_bullet[i].y, 20, 20);
		//ó������ ��� �Ѿ��� �߻�ȵƴٰ� ����
		_bullet[i].isFire = false;
		_bullet[i].speed = 7;
	}

	//�������� ǥ���غ���
	_backGauge = RectMakeCenter(WINSIZEX / 2 + 250, 100, 400, 50);
	_frontGauge = RectMakeCenter(WINSIZEX / 2 + 250, 100, 400, 50);
	_r = 0;
	_g = 240;
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

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_player.top -= 5;
		_player.bottom -= 5;
	}

	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_player.top += 5;
		_player.bottom += 5;
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		bulletFire();
	}

	
	bulletMove();
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	Rectangle(backDC, _player);
	Rectangle(backDC, _player2);

	//�Ѿ� �׷���
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		Ellipse(backDC, _bullet[i].rc);
	}


	Rectangle(backDC, _backGauge);

	HBRUSH brush = CreateSolidBrush(RGB(_r, _g, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);
	Rectangle(backDC, _frontGauge);
	SelectObject(backDC, oldBrush);
	DeleteObject(brush);

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

//�߻�� �Լ��ε�
void playGround::bulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (_bullet[i].isFire) continue;

		_bullet[i].x = _player.right + 10;
		_bullet[i].y = (_player.top + _player.bottom) / 2;
		_bullet[i].rc = RectMakeCenter(_bullet[i].x,
			_bullet[i].y, 20, 20);
		_bullet[i].isFire = true;
		break;
	}
}

//�Ѿ� �����ӿ�
void playGround::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		if (_bullet[i].x > WINSIZEX + 50) _bullet[i].isFire = false;
		_bullet[i].x += _bullet[i].speed;
		_bullet[i].rc = RectMakeCenter(_bullet[i].x,
			_bullet[i].y, 20, 20);

		RECT temp;
		if (IntersectRect(&temp, &_player2, &_bullet[i].rc) && _bullet[i].isFire)
		{
			setGauge();
			_bullet[i].isFire = false;
			break;
		}

	}
}

//������(?) ������ �Լ�
void playGround::setGauge()
{
	_frontGauge.left += 10;

	if (_frontGauge.left >= _backGauge.right) _frontGauge.left = _backGauge.right;

	if (_frontGauge.right - _frontGauge.left < 350)
	{
		_r = 255;
		_g = 255;
	}
	if (_frontGauge.right - _frontGauge.left < 100)
	{
		_r = 255;
		_g = 0;
	}

}
