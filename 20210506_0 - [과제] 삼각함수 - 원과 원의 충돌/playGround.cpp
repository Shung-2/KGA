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

	// �ʱ�ȭ
	_iscrash = false;															// �浹����
	_center_Ellipse = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 300, 300); 	// �߾� ��
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

	_user_Ellipse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 100);				// ����� �� �ʱ�ȭ
	_user_radius = (_user_Ellipse.right - _user_Ellipse.left) / 2;					// ����� �� ������

	_center_Ellipse_x = (_center_Ellipse.left + _center_Ellipse.right) / 2;			// ��� �� ���� X ��ǥ
	_center_Ellipse_y = (_center_Ellipse.top + _center_Ellipse.bottom) / 2;			// ��� �� ���� Y ��ǥ
	_center_Ellipse_radius = (_center_Ellipse.right - _center_Ellipse.left) / 2;	// ��� �� ������

	_distance_x = _center_Ellipse_x - _ptMouse.x;									// ��� �� ���� X ��ǥ - ����� �� ���� X ��ǥ ��
	_distance_y = _center_Ellipse_y - _ptMouse.y;									// ��� �� ���� Y ��ǥ - ����� �� ���� Y ��ǥ ��
	_hypo = sqrt(_distance_x * _distance_x + _distance_y * _distance_y);			// ����
	
	/*
	-sqrt �Լ��� �ϴ��� : �Ű����� x�� ���� ���ڿ� ��Ʈ�� ������ ����� ���� ��ȯ���ִ� ���� �մϴ�.
	��, ��Ʈ x�� �����ִ� �Լ��Դϴ�.�� �����ִ� �Լ��Դϴ�. (�������� �����ִ� �Լ�)
	��ó: https://blockdmask.tistory.com/307 [������ ������]
	*/

	// �浹���� ����
	if ((_user_radius + _center_Ellipse_radius) >= _hypo)
	{
		_iscrash = true;
	}
	else
	{
		_iscrash = false;
	}
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================
	
	// ����� ���� �߾� �� �׷��ֱ�
	Ellipse(backDC, _user_Ellipse);
	Ellipse(backDC, _center_Ellipse);

	// �浹�� �� ��� �� ��ĥ
	if (_iscrash)
	{
		HBRUSH brush1 = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush1 = (HBRUSH)SelectObject(backDC, brush1);
		Ellipse(backDC, _center_Ellipse);
		SelectObject(backDC, oldBrush1);
		DeleteObject(brush1);
	}

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}
