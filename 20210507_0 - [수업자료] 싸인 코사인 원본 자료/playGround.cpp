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

	_obj.x = WINSIZEX / 2;
	_obj.y = WINSIZEY / 2;
	_obj.radius = 50;
	_obj.angle = 0;

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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _obj.angle += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _obj.angle -= 0.04f;
	//                         ���ǵ� ��( R ��)
	_obj.x += cosf(_obj.angle) * 3;
	_obj.y += -sinf(_obj.angle) * 3;	
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	EllipseMakeCenter(backDC, _obj.x, _obj.y, _obj.radius * 2, _obj.radius * 2);

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}