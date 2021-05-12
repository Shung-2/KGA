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

	_background = new image;
	_background->init("�׸���.bmp", 2000, WINSIZEY, true, RGB(0, 0, 0));

	_kirby.img = new image;
	_kirby.img->init("kirby.bmp", 93, 90, true, RGB(255, 0, 255));
	_kirby.x = WINSIZEX / 2;
	_kirby.y = WINSIZEY / 2;
	_kirby.rc = RectMakeCenter(_kirby.x, _kirby.y, 93, 90);
	_kirby.jumpPower = _kirby.gravity = _kirby.isJump = 0;

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

	if (KEYMANAGER->isStayKeyDown('A')) _kirby.x -= 5;
	if (KEYMANAGER->isStayKeyDown('D')) _kirby.x += 5;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_kirby.isJump = true;
		_kirby.jumpPower = 3;
		_kirby.gravity = 0.08f;
	}

	if (_kirby.isJump)
	{
		_kirby.y -= _kirby.jumpPower;
		_kirby.jumpPower -= _kirby.gravity;
	}


	_kirby.rc = RectMakeCenter(_kirby.x, _kirby.y, 93, 90);
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	_background->render(backDC, 0, 0);
	_kirby.img->render(backDC, _kirby.rc.left, _kirby.rc.top);
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(backDC, _kirby.rc);
	}

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}
