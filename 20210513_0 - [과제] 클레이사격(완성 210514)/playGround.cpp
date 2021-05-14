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
	_isGameStart = false;	// ���� ���� ���� ����
	_isGameOver = true;		// ���� ���� ���� ����
	_gameOverCount = 0;		// ���� ���� ī��Ʈ ����
	_score1 = _score10 = 0; // ���� ���� �ʱ�ȭ ����

	// ���� �׸� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
	{
		_num[i] = new image;
		sprintf_s(_strNum, "resource/score/%d.bmp", i);
		_num[i]->init(_strNum, 28, 30, true, RGB(255, 0, 255));
	}

	// ���ȭ�� ���� & �ʱ�ȭ
	_background = new image;
	_background->init("resource/���.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	
	// ��/�� ��Ī�ӽ� ���� & �ʱ�ȭ
	_left_PitchingMachine = RectMake(0, WINSIZEY / 2 + 100, 50, 30);
	_right_PitchingMachine = RectMake(WINSIZEX / 2 + 208 , WINSIZEY / 2 + 100, 50, 30);
	
	// �� �ʱ�ȭ
	_ballFireTimer = 0;									// �� Ÿ�̸� ����	
	for (int i = 0; i < BALLMAX; i++)
	{
		_ball[i].speed = RND->getFromFloatTo(5, 7);		// �� ���ǵ� ����
		_ball[i].angle = PI / 2;						// �� ���� ����
		_ball[i].radius = 10;							// �� ������ ����
		_ball[i].gravity = 0;							// �� �߷� ����
		_ball[i].isFire = false;						// �� �߻翩�� ����
	}

	// �� �̹��� ���� & �ʱ�ȭ
	_ballimg = new image;
	_ballimg->init("resource/��.bmp", 30, 30, true, RGB(255, 0, 255));

	// ��ݴ�, ��ݴ� �̹���, ��ݴ� ���� ���� & �ʱ�ȭ
	_launch_Pad = RectMakeCenter(WINSIZEX /2 , WINSIZEY / 2, 50, 50);
	_launch_Pad_img = new image;
	_launch_Pad_img->init("resource/��ݴ�.bmp", 50, 50, true, RGB(255, 0, 255));
	_launch_Pad_Zone = RectMake(WINSIZEX / 2 - 25, 0, 50, WINSIZEY);

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

	// ���� �Է� �� ���� ����
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isGameStart = true;
		_isGameOver = false;
	}

	if (!_isGameOver)
	{
		_ballFireTimer += 10;	// Ÿ�̸� ����
		ballFire();				// �� �߻�
		ballMove();				// �� ������

		// �浹���� ����
		for (int i = 0; i < BALLMAX; i++)
		{
			if (!_ball[i].isFire) continue;

			// ��ݴ� �����ȿ� ���� ������
			if (_launch_Pad_Zone.left < _ball[i].x && _ball[i].x < _launch_Pad_Zone.right)
			{
				_launch_Pad.top = _ball[i].y - 10;	// ��ݴ��� Y���� ���� �����ӿ� ���� �������ش�.

				// PtInRect�� ����ϱ� ���� POINT ����
				POINT pt;
				pt.x = _ball[i].x;
				pt.y = _ball[i].y;

				// �����̽� Ű �Է� �� ��ݴ�� ���� �浹�� �� ���� �������ش�.
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
				{
					PtInRect(&_launch_Pad, pt);
					_ball[i].isFire = false;
					_score1++;
				}
			}
			
			// �����ڸ� ���ڰ� 9���� Ŀ���� 0�ʱ�ȭ �� �����ڸ��� 1 ����
			if (_score1 > 9)														// ���� �ڸ����ڰ� 9���� Ŀ����
			{
				_score1 = 0;														// 0���� �ʱ�ȭ �����ְ�
				_score10++;															// ���� �ڸ� ���ڸ� �÷��ش�.
			}
		}
	}

	// ���� ���� ����
	if (_gameOverCount == GAMEOVER_VALUE)
	{
		_isGameOver = true;
	}

	// 'A'Ű ���� �� �����
	if (KEYMANAGER->isOnceKeyDown(0x41))
	{
		if (_isGameOver) this->init();
	}
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	// ���ȭ�� ���
	_background->render(backDC, 0, 0);

	// ��ݴ� ���� ���
	//Rectangle(backDC, _launch_Pad_Zone);

	// ��Ī�ӽ� ���
	//Rectangle(backDC, _left_PitchingMachine);
	//Rectangle(backDC, _right_PitchingMachine);
	
	// ��ݴ� ���
	_launch_Pad_img->render(backDC, _launch_Pad.left, _launch_Pad.top);
	//Rectangle(backDC, _launch_Pad);

	// �ʱ� ���� �ȳ� ���� ���
	if (!_isGameStart)
	{
		char str1[128], str2[128], str3[128];
		sprintf_s(str1, "= = = = = = = = = = = = = =");
		sprintf_s(str2, "PRESS ENTER TO START");
		sprintf_s(str3, "= = = = = = = = = = = = = =");
		TextOut(backDC, WINSIZEX / 2 - 80, WINSIZEY / 2 - 170, str1, strlen(str1));
		TextOut(backDC, WINSIZEX / 2 - 80, WINSIZEY / 2 - 150, str2, strlen(str2));
		TextOut(backDC, WINSIZEX / 2 - 80, WINSIZEY / 2 - 130, str3, strlen(str3));
	}

	// �� ���	
	for (int i = 0; i < BALLMAX; i++)
	{
		if (!_ball[i].isFire) continue;
			_ballimg->render(backDC, _ball[i].x, _ball[i].y);		
	}

	// ���� ���� ī��Ʈ üũ
	char str[128];
	sprintf_s(str, "MISS COUNT %d = GAME OVER", GAMEOVER_VALUE);
	TextOut(backDC, 20, 5, str, strlen(str));
	char str5[128];
	sprintf_s(str5, "MISS : %d", _gameOverCount);
	TextOut(backDC, 20, 25, str5, strlen(str5));

	// ���� ���
	_num[_score1]->render(backDC, WINSIZEX / 2 - 10, WINSIZEY / 2 - 200);
	_num[_score10]->render(backDC, WINSIZEX / 2 - 30, WINSIZEY / 2 - 200);

	// ������� �� ����� �ȳ� ���� ���
	if (_isGameOver == true && _isGameStart)
	{
		char str4[128];
		sprintf_s(str4, "RESTART PRESS 'A'!");
		TextOut(backDC, WINSIZEX / 2- 70, WINSIZEY / 2 - 120, str4, strlen(str4));
	}

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}

// �߻�
void playGround::ballFire()
{
	// �߻�Ÿ�̸Ӱ� 750���� ������ �׻� ����.
	if (_ballFireTimer < 750)
	{
		return;
	}

	// �߻�Ÿ�̸Ӱ� 750�̻� Ŀ���� ��
	for (int i = 0; i < BALLMAX; i++)
	{
		if (_ball[i].isFire) continue;		
		_ball[i].isFire = true;

		_ball[i].gravity = 0;	// ���� �߷��� �ʱ�ȭ, ���� ������ ��� �����Ǽ� ������ �򸮰� �ȴ�.

		_ballRND = RND->getInt(2);	// �� ��/�� ��������
		if (_ballRND == 0) // ���ʿ��� ������ ��
		{
			_ball[i].x = (_left_PitchingMachine.right + 10) + cosf(_ball[i].angle);
			_ball[i].y = (_left_PitchingMachine.top + 10) - sinf(_ball[i].angle);
			_ball[i].angle = RND->getFromFloatTo(PI / 6, PI / 4);
		}		
		else // �����ʿ��� ������ ��
		{
			_ball[i].x = _right_PitchingMachine.left - 10;
			_ball[i].y = _right_PitchingMachine.top + 15;
			_ball[i].angle = RND->getFromFloatTo(PI / 1.125, PI / 1.24);
		}
		_ballFireTimer = 0;	// �߻� Ÿ�̸� �ʱ�ȭ
		break;
	}
}

// �� �̵�
void playGround::ballMove()
{
	for (int i = 0; i < BALLMAX; i++)
	{
		if (!_ball[i].isFire) continue;

		// ���� Y�� �������� ȭ�� �ٱ����� �������
		if (_ball[i].y >= WINSIZEY)
		{
			_gameOverCount++;			// ī��Ʈ ++
			_ball[i].isFire = false;	// ī��Ʈ ��� �����°� �����ϱ� ���� �̻��� ��ü ����
		}

		_ball[i].gravity += 0.08f;
		_ball[i].x += cosf(_ball[i].angle) * _ball[i].speed;
		_ball[i].y += -sinf(_ball[i].angle) * _ball[i].speed + _ball[i].gravity;
	}
}