#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init();

	// 게임 시스템 초기화
	/* 배경화면 초기화(낮, 밤) */
	_background = new image;
	_background->init("배경화면.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	_background_night = new image;
	_background_night->init("밤.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	_background_change = true;
	
	// 땅 초기화
	_land = RectMake(0, WINSIZEY / 2 + 275, 600, 190);
	_landimg = new image;
	_landimg->init("땅.bmp", 600, 190, false, RGB(255, 0, 255));

	// 점수 그림 초기화
	for (int i = 0; i < 10; i++)
	{
		_num[i] = new image;
		sprintf_s(_strNum, "image/score/%d.bmp", i);
		_num[i]->init(_strNum, 28, 30, true, RGB(255, 0, 255));
	}

	// 플레이어 초기화
	_playerimg = new image;												// 플레이어 이미지 초기화
	_playerimg->init("플레이어.bmp", 50, 50, true, RGB(255, 0, 255));	// 플레이어 이미지 출력
	_x = WINSIZEX / 2 - 100;											// 플레이어의 X 값 설정
	_y = WINSIZEY / 2;													// 플레이어의 Y 값 설정
	_player = RectMakeCenter(_x, _y, 50, 50);							// 설정한 X, Y값을 이용한 플레이어 생성 
	_jumpPower = _gravity = _score1 = _score10 = 0;						// Jumppower, gravity, socre 초기화
	_isJump = false;													// 점프 상태
	_isGameStart = false;												// 게임 스타트 상태
	_isGameOver = true;													// 게임 오버 상태

	// 파이프 초기화
	_pipe_top_image = new image;
	_pipe_top_image->init("위 터널.bmp", 100, 400, true, RGB(255, 0, 255));
	_pipe_bottom_image = new image;
	_pipe_bottom_image->init("아래 터널.bmp", 100, 400, true, RGB(255, 0, 255));

	for (int i = 0; i < PIPEMAX; i++)
	{	
		// Y축 랜덤 설정
		_rndY = RND->getFromIntTo(300, 500);

		// socre 초기화
		_pipe[i].score = RectMakeCenter(WINSIZEX / 2 + 200 + (i * 350), _rndY, 10, 100);

		// top 초기화
		_pipe[i].top = RectMakeCenter
		(
			(_pipe[i].score.left + _pipe[i].score.right) / 2,
			(_pipe[i].score.top + _pipe[i].score.bottom) / 2 - 300,
			100, 400
		);

		// bottom 초기화
		_pipe[i].bottom = RectMakeCenter
		(
			(_pipe[i].score.left + _pipe[i].score.right) / 2,
			(_pipe[i].score.top + _pipe[i].score.bottom) / 2 + 300,
			100, 400
		);

		// 충돌여부 초기화
		_pipe[i]._isCrash = false;
	}
	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();
}

//여기에다 연산하세요 제에발
void playGround::update()
{
	gameNode::update();

	// 엔터키 누를 시 게임시작.
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isGameStart = true;
		_isGameOver = false;
	}

	if (!_isGameOver)
	{
		// Space(점프)를 할 떄 중력값, 파워, 점프 여부 초기화
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_gravity = 0.15f;
			_jumpPower = 3.0f;
			_isJump = true;
		}

		// 점프 상태일 때 _y 값 설정
		if (_isJump)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;
		}

		for (int i = 0; i < PIPEMAX; i++)
		{
			// 스코어 움직임
			_pipe[i].score.left -= 5;
			_pipe[i].score.right -= 5;

			// TOP, BOTTOM 연산
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

			// TOP의 오른쪽이 0보다 작을때 (맵 밖으로 나갈 경우)
			if (_pipe[i].top.right < 0)
			{
				_rndY = RND->getFromIntTo(300, 500);								// Y축 랜덤 설정
				_pipe[i].score = RectMakeCenter(WINSIZEX + 350, _rndY, 10, 100);	// 스코어 재생성
				_pipe[i]._isCrash = false;											// 충돌여부 끔
			}

			// IntersectRect를 이용한 충돌 여부 (점수 상승)
			RECT temp;
			if (IntersectRect(&temp, &_player, &_pipe[i].score) && !_pipe[i]._isCrash)
			{
				_score1++;															// 점수추가
				_pipe[i]._isCrash = true;											// 충돌여부 킴
			}

			if (_score1 > 9)														// 일의 자리숫자가 9보다 커지면
			{
				_score1 = 0;														// 0으로 초기화 시켜주고
				_score10++;															// 십의 자리 숫자를 올려준다.
			}

			if (_score10 % 3 == 0 && _score10 != 0)									// 스코어가 0이 아니고 3으로 나눈 나머지가 0일떄
				_background_change = false;											// 맵 체인지

			if (_score10 >= 6)														// 스코어가 6 이상일 떄
				_background_change = true;											// 맵 체인지
			
			// IntersectRect를 이용한 충돌 여부 (게임 패배)
			if (IntersectRect(&temp, &_player, &_pipe[i].top) ||
				IntersectRect(&temp, &_player, &_pipe[i].bottom) ||
				IntersectRect(&temp, &_player, &_land))								// 땅(land) 추가 완료.
			{
				_isGameOver = true;													// 게임오버 킴
			}
		}
	}

	// 'A'키를 입력할 떄 재시작
	if (KEYMANAGER->isOnceKeyDown(0x41))
	{
		if (_isGameOver) this->init();
	}

	// 플레이어 재 연산
	_player = RectMakeCenter(_x, _y, 50, 50);
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	// bool 값에 따른 배경화면 출력
	if (_background_change)
	{
		_background->render(backDC, 0, 0);
	}
	else
	{
		_background_night->render(backDC, 0, 0);
	}
	
	// 플레이어 출력
	_playerimg->render(backDC, _player.left, _player.top);

	// 초기 시작 안내 문구 출력
	if (!_isGameStart)
	{
		char str2[128];
		sprintf_s(str2, "시작하려면 Enter를 누르세요.");
		TextOut(backDC, WINSIZEX / 2, WINSIZEY / 2, str2, strlen(str2));
	}

	// top, bottom, score 출력
	for (int i = 0; i < PIPEMAX; i++)
	{		
		_pipe_top_image->render(backDC, _pipe[i].top.left, _pipe[i].top.top);
		_pipe_bottom_image->render(backDC, _pipe[i].bottom.left, _pipe[i].bottom.top);
		// 가운데 스코어 출력
		// Rectangle(backDC, _pipe[i].score);
	}

	// 땅 출력
	_landimg->render(backDC, 0, WINSIZEY / 2 + 275);

	// 점수 출력
	_num[_score1]->render(backDC, WINSIZEX / 2, WINSIZEY / 2 - 350);
	_num[_score10]->render(backDC, WINSIZEX / 2 - 20, WINSIZEY / 2 - 350);

	// 패배 했을 때 재시작 안내 문구 출력
	if (_isGameOver == true && _isGameStart)
	{
		char str3[128];
		sprintf_s(str3, "다시 시작하려면 'A'키를 누르세요.");
		TextOut(backDC, WINSIZEX / 2, WINSIZEY / 2, str3, strlen(str3));
	}

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}