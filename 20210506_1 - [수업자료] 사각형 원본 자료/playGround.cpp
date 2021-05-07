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

	_isCollision = false;

	_rectangle = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);


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

	_ellipse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 200, 200);
	
	if (isCollision(_ellipse, _rectangle)) _isCollision = true;
	else _isCollision = false;

}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	Rectangle(backDC, _rectangle);
	Ellipse(backDC, _ellipse);

	if (_isCollision)
	{
		TextOut(backDC, WINSIZEX / 2, WINSIZEY / 2, "��", 2);
	}
	
	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

bool playGround::isCollision(RECT& rc1, RECT& rc2)
{
	POINT pt;

	pt.x = (rc1.left + rc1.right) / 2;
	pt.y = (rc1.top + rc1.bottom) / 2;

	int radius = (rc1.right - rc1.left) / 2;
	//��
	if ((rc2.left <= pt.x && pt.x <= rc2.right) ||
		(rc2.top <= pt.y && pt.y <= rc2.bottom))
	{
		RECT rcTemp;

		rcTemp.left = rc2.left - radius;
		rcTemp.right = rc2.right + radius;
		rcTemp.top = rc2.top - radius;
		rcTemp.bottom = rc2.bottom + radius;

		if (PtInRect(&rcTemp, pt)) return true;

	}
	else //����
	{
		if (getDistance(rc1, rc2.left, rc2.top)) return true;
		if (getDistance(rc1, rc2.right, rc2.top)) return true;
		if (getDistance(rc1, rc2.left, rc2.bottom)) return true;
		if (getDistance(rc1, rc2.right, rc2.bottom)) return true;
	}

	return false;
}

//������ �浹�� �غ�� ���� (��)
bool playGround::getDistance(RECT& rc, float x, float y)
{
	float deltaX = x - ((rc.right + rc.left) / 2);
	float deltaY = y - ((rc.top + rc.bottom) / 2);

	//���������� �Ÿ���� �սô�
	float distance = sqrtf(deltaX * deltaX + deltaY * deltaY);
	float radius = (rc.right - rc.left) / 2;
	
	//�浹 X
	if (radius <= distance) return false;

	return true;
}

