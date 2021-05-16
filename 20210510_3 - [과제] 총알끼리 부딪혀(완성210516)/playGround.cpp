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

	// ĳ�� �ʱ�ȭ
	_obj.angle = PI / 2;				// ĳ���� ���� ����
	_obj.length = 100;					// ĳ���� ���� ����
	_obj.radius = 100;					// ĳ���� ������ ����
	_obj.center.x = WINSIZEX / 2;		// ĳ���� ������ X ����
	_obj.center.y = WINSIZEY;			// ĳ���� ������ Y ����

	// �̻��� �ʱ�ȭ
	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].speed = 5;			// �Ѿ� ���ǵ� ����
		_bullet[i].radius = 20;			// �Ѿ� ������ ����
		_bullet[i].isFire = false;		// �Ѿ� �߻� ���� ����
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

	// ������ ���� X, Y ����
	_obj.endPoint.x = cosf(_obj.angle) * _obj.length + _obj.center.x;
	_obj.endPoint.y = -sinf(_obj.angle) * _obj.length + _obj.center.y;

	// ����, ������, �߻� Ű���带 ���� ��
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _obj.angle <= 3.0)	// ���� ���� �� ���� ����
		_obj.angle += 0.04f;

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _obj.angle > 0.15)	// ���� ���� �� ���� ����
		_obj.angle -= 0.04f;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))						// ���� ����
		bulletFire();												// �Ѿ� �߻�

	// �Ѿ� ������ & �� �浹 ����
	bulletMove();

	// �Ѿ� �� �浹����
	bulletCollision();
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================	

	EllipseMakeCenter(backDC, _obj.center.x, _obj.center.y, 100, 100);					// ���� �� ���
	LineMake(backDC, _obj.center.x, _obj.center.y, _obj.endPoint.x, _obj.endPoint.y);	// ���� ���� ���� ���

	// �Ѿ� ���
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
		EllipseMakeCenter(backDC, _bullet[i].x, _bullet[i].y, _bullet[i].radius * 2, _bullet[i].radius * 2);
	}

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

// �Ѿ� �߻� �Լ�
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

// �Ѿ� ������ �Լ�
void playGround::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;

		_bullet[i].x += cosf(_bullet[i].angle) * _bullet[i].speed;
		_bullet[i].y += -sinf(_bullet[i].angle) * _bullet[i].speed;

		// ���� ȭ�� �ٱ����� �������� �����ϴ� ��(���� : �����¿�)
		// ��
		if (_bullet[i].y - _bullet[i].radius < 0)
		{
			_bullet[i].angle = PI * 2- _bullet[i].angle;
			_bullet[i].y = _bullet[i].radius;
		}

		// ��
		if (_bullet[i].y + _bullet[i].radius > WINSIZEY)
		{
			_bullet[i].angle = PI * 2 - _bullet[i].angle;
			_bullet[i].y = WINSIZEY - _bullet[i].radius;
		}

		// ��
		if (_bullet[i].x + _bullet[i].radius < 0)
		{
			_bullet[i].angle = PI - _bullet[i].angle;
			_bullet[i].x = _bullet[i].radius;
		}

		// ��
		if (_bullet[i].x + _bullet[i].radius > WINSIZEX)
		{
			_bullet[i].angle = PI - _bullet[i].angle;
			_bullet[i].x = WINSIZEX - _bullet[i].radius;
		}
	}
}

// �Ѿ� �� �浹����
void playGround::bulletCollision()
{
	// TODO - �Ѿ˰� �Ѿ� �� �浹 ���� 
	for (int i = 0; i < BULLETMAX; i++)
	{
		for (int j = i + 1; j < BULLETMAX; j++)
		{
			if (_bullet[i].radius * 2 < getDistance(_bullet[i].x, _bullet[i].y, _bullet[j].x, _bullet[j].y)) continue;

			// �浹�� ���� ���� ����
			// getAngle���� ���Լ��� ���ϴ� ����� ���ִ�. �ش� ����� �̿��Ͽ� �浹 �� Y�� ���� ������ ���� �ޱ� ���� �������ش�.
			// ���� ����Ʈ : http://eirenehue.egloos.com/967214
			// ���� ����Ʈ : https://salix97.tistory.com/278
			// ���� ����Ʈ : https://ehpub.co.kr/acos-acosfacosl-%ED%95%A8%EC%88%98/
			_bullet[i].angle = getAngle(_bullet[j].x, _bullet[j].y, _bullet[i].x, _bullet[i].y);
			_bullet[j].angle = getAngle(_bullet[i].x, _bullet[i].y, _bullet[j].x, _bullet[j].y);
		}
	}
}