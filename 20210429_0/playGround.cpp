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

	_x = WINSIZEX / 2 - 250;
	_y = WINSIZEY / 2 + 250;

	// �÷��̾� �ʱ�ȭ(����)
	_player = RectMakeCenter(_x, _y, 100, 100);	

	_jumpPower = _gravity = _jumpCount = 0;
	_isJump = false;
	_isGameover = false;
	_jumpcheck = true;
	
	// �� �ʱ�ȭ(����)
	for (int i = 0; i < LANDMAX; i++)
	{
		_rndX = RND->getFromIntTo(0, 1200);
		_land[i].crush = RectMakeCenter(_rndX, WINSIZEY / 2 + 415 + (i * 350), 50, 50);
		
		_land[i].left = RectMakeCenter
		(_land[i].crush.left - 300, WINSIZEY / 2 + 350, 400, 100);

		_land[i].Middle = RectMakeCenter
		(_land[i].crush.right + 300, WINSIZEY / 2 + 350, 400, 100);

		_land[i].right = RectMakeCenter
		(_land[i].Middle.right + 300, WINSIZEY / 2 + 350, 400, 100);
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

	// ���͹�
	/*
	_count++;

	if (_count % 50 == 0)
	{
		_rc.left += 10;
		_rc.right += 10;

		_count = 0;
	}
	*/

	if (!_isGameover)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _jumpcheck == true)
		{
			_gravity = 0.15f;
			_jumpPower = 5.0f;
			_jumpCount++;
			_isJump = true;
		}

		if (_jumpCount == 2)
		{
			_jumpcheck = false;
			_jumpCount = 0;
		}

		if (_isJump)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;
		}

		for (int i = 0; i < LANDMAX; i++)
		{
			_land->crush.left  -= 1;
			_land->crush.right -= 1;

			_land[i].left = RectMakeCenter
			(_land[i].crush.left - 300, WINSIZEY / 2 + 350, 400, 100);

			_land[i].Middle = RectMakeCenter
			(_land[i].crush.right + 300, WINSIZEY / 2 + 350, 400, 100);

			_land[i].right = RectMakeCenter
			(_land[i].Middle.right + 300, WINSIZEY / 2 + 350, 400, 100);

			if (_land[i].Middle.left < 0)
			{
				_rndX = RND->getFromIntTo(0, 1200);
				_land[i].crush = RectMakeCenter(_rndX, WINSIZEY / 2 + 415 + (i * 350), 50, 50);
			}

			if (_player.bottom > _land[i].left.top   ||
				_player.bottom > _land[i].Middle.top ||
				_player.bottom > _land[i].right.top)
			{
				_jumpcheck = true;
			}

			RECT temp;
			if (IntersectRect(&temp, &_player, &_land->crush))
			{
				_isGameover = true;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (_isGameover) this->init();
	}
	_player = RectMakeCenter(_x, _y, 100, 100);
	
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS); // ��� ��ȭ����� �����ϸ� �ȴ�.
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================
	Rectangle(backDC, _player);

	for (int i = 0; i < 1; i++)
	{
		Rectangle(backDC, _land[i].left);
		Rectangle(backDC, _land[i].crush);
		Rectangle(backDC, _land[i].Middle);
		Rectangle(backDC, _land[i].right);
	}

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}