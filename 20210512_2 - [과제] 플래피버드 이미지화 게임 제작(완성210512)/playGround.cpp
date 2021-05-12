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

	// ���� �ý��� �ʱ�ȭ
	/* ���ȭ�� �ʱ�ȭ(��, ��) */
	_background = new image;
	_background->init("���ȭ��.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	_background_night = new image;
	_background_night->init("��.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	_background_change = true;
	
	// �� �ʱ�ȭ
	_land = RectMake(0, WINSIZEY / 2 + 275, 600, 190);
	_landimg = new image;
	_landimg->init("��.bmp", 600, 190, false, RGB(255, 0, 255));

	// ���� �׸� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
	{
		_num[i] = new image;
		sprintf_s(_strNum, "image/score/%d.bmp", i);
		_num[i]->init(_strNum, 28, 30, true, RGB(255, 0, 255));
	}

	// �÷��̾� �ʱ�ȭ
	_playerimg = new image;												// �÷��̾� �̹��� �ʱ�ȭ
	_playerimg->init("�÷��̾�.bmp", 50, 50, true, RGB(255, 0, 255));	// �÷��̾� �̹��� ���
	_x = WINSIZEX / 2 - 100;											// �÷��̾��� X �� ����
	_y = WINSIZEY / 2;													// �÷��̾��� Y �� ����
	_player = RectMakeCenter(_x, _y, 50, 50);							// ������ X, Y���� �̿��� �÷��̾� ���� 
	_jumpPower = _gravity = _score1 = _score10 = 0;						// Jumppower, gravity, socre �ʱ�ȭ
	_isJump = false;													// ���� ����
	_isGameStart = false;												// ���� ��ŸƮ ����
	_isGameOver = true;													// ���� ���� ����

	// ������ �ʱ�ȭ
	_pipe_top_image = new image;
	_pipe_top_image->init("�� �ͳ�.bmp", 100, 400, true, RGB(255, 0, 255));
	_pipe_bottom_image = new image;
	_pipe_bottom_image->init("�Ʒ� �ͳ�.bmp", 100, 400, true, RGB(255, 0, 255));

	for (int i = 0; i < PIPEMAX; i++)
	{	
		// Y�� ���� ����
		_rndY = RND->getFromIntTo(300, 500);

		// socre �ʱ�ȭ
		_pipe[i].score = RectMakeCenter(WINSIZEX / 2 + 200 + (i * 350), _rndY, 10, 100);

		// top �ʱ�ȭ
		_pipe[i].top = RectMakeCenter
		(
			(_pipe[i].score.left + _pipe[i].score.right) / 2,
			(_pipe[i].score.top + _pipe[i].score.bottom) / 2 - 300,
			100, 400
		);

		// bottom �ʱ�ȭ
		_pipe[i].bottom = RectMakeCenter
		(
			(_pipe[i].score.left + _pipe[i].score.right) / 2,
			(_pipe[i].score.top + _pipe[i].score.bottom) / 2 + 300,
			100, 400
		);

		// �浹���� �ʱ�ȭ
		_pipe[i]._isCrash = false;
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

	// ����Ű ���� �� ���ӽ���.
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isGameStart = true;
		_isGameOver = false;
	}

	if (!_isGameOver)
	{
		// Space(����)�� �� �� �߷°�, �Ŀ�, ���� ���� �ʱ�ȭ
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_gravity = 0.15f;
			_jumpPower = 3.0f;
			_isJump = true;
		}

		// ���� ������ �� _y �� ����
		if (_isJump)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;
		}

		for (int i = 0; i < PIPEMAX; i++)
		{
			// ���ھ� ������
			_pipe[i].score.left -= 5;
			_pipe[i].score.right -= 5;

			// TOP, BOTTOM ����
			_pipe[i].top = RectMakeCenter
			(
				(_pipe[i].score.left + _pipe[i].score.right) / 2,
				(_pipe[i].score.top + _pipe[i].score.bottom) / 2 - 300,
				100, 400
			);

			_pipe[i].bottom = RectMakeCenter
			(
				(_pipe[i].score.left + _pipe[i].score.right) / 2,
				(_pipe[i].score.top + _pipe[i].score.bottom) / 2 + 300,
				100, 400
			);

			// TOP�� �������� 0���� ������ (�� ������ ���� ���)
			if (_pipe[i].top.right < 0)
			{
				_rndY = RND->getFromIntTo(300, 500);								// Y�� ���� ����
				_pipe[i].score = RectMakeCenter(WINSIZEX + 350, _rndY, 10, 100);	// ���ھ� �����
				_pipe[i]._isCrash = false;											// �浹���� ��
			}

			// IntersectRect�� �̿��� �浹 ���� (���� ���)
			RECT temp;
			if (IntersectRect(&temp, &_player, &_pipe[i].score) && !_pipe[i]._isCrash)
			{
				_score1++;															// �����߰�
				_pipe[i]._isCrash = true;											// �浹���� Ŵ
			}

			if (_score1 > 9)														// ���� �ڸ����ڰ� 9���� Ŀ����
			{
				_score1 = 0;														// 0���� �ʱ�ȭ �����ְ�
				_score10++;															// ���� �ڸ� ���ڸ� �÷��ش�.
			}

			if (_score10 % 3 == 0 && _score10 != 0)									// ���ھ 0�� �ƴϰ� 3���� ���� �������� 0�ϋ�
				_background_change = false;											// �� ü����

			if (_score10 >= 6)														// ���ھ 6 �̻��� ��
				_background_change = true;											// �� ü����
			
			// IntersectRect�� �̿��� �浹 ���� (���� �й�)
			if (IntersectRect(&temp, &_player, &_pipe[i].top) ||
				IntersectRect(&temp, &_player, &_pipe[i].bottom) ||
				IntersectRect(&temp, &_player, &_land))								// ��(land) �߰� �Ϸ�.
			{
				_isGameOver = true;													// ���ӿ��� Ŵ
			}
		}
	}

	// 'A'Ű�� �Է��� �� �����
	if (KEYMANAGER->isOnceKeyDown(0x41))
	{
		if (_isGameOver) this->init();
	}

	// �÷��̾� �� ����
	_player = RectMakeCenter(_x, _y, 50, 50);
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	// bool ���� ���� ���ȭ�� ���
	if (_background_change)
	{
		_background->render(backDC, 0, 0);
	}
	else
	{
		_background_night->render(backDC, 0, 0);
	}
	
	// �÷��̾� ���
	_playerimg->render(backDC, _player.left, _player.top);

	// �ʱ� ���� �ȳ� ���� ���
	if (!_isGameStart)
	{
		char str2[128];
		sprintf_s(str2, "�����Ϸ��� Enter�� ��������.");
		TextOut(backDC, WINSIZEX / 2, WINSIZEY / 2, str2, strlen(str2));
	}

	// top, bottom, score ���
	for (int i = 0; i < PIPEMAX; i++)
	{		
		_pipe_top_image->render(backDC, _pipe[i].top.left, _pipe[i].top.top);
		_pipe_bottom_image->render(backDC, _pipe[i].bottom.left, _pipe[i].bottom.top);
		// ��� ���ھ� ���
		// Rectangle(backDC, _pipe[i].score);
	}

	// �� ���
	_landimg->render(backDC, 0, WINSIZEY / 2 + 275);

	// ���� ���
	_num[_score1]->render(backDC, WINSIZEX / 2, WINSIZEY / 2 - 350);
	_num[_score10]->render(backDC, WINSIZEX / 2 - 20, WINSIZEY / 2 - 350);

	// �й� ���� �� ����� �ȳ� ���� ���
	if (_isGameOver == true && _isGameStart)
	{
		char str3[128];
		sprintf_s(str3, "�ٽ� �����Ϸ��� 'A'Ű�� ��������.");
		TextOut(backDC, WINSIZEX / 2, WINSIZEY / 2, str3, strlen(str3));
	}

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}