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
	_isGameStart = false;	// 게임 시작 유무 설정
	_isGameOver = true;		// 게임 종료 유무 설정
	_gameOverCount = 0;		// 게임 종료 카운트 설정
	_score1 = _score10 = 0; // 게임 점수 초기화 설정

	// 점수 그림 초기화
	for (int i = 0; i < 10; i++)
	{
		_num[i] = new image;
		sprintf_s(_strNum, "resource/score/%d.bmp", i);
		_num[i]->init(_strNum, 28, 30, true, RGB(255, 0, 255));
	}

	// 배경화면 선언 & 초기화
	_background = new image;
	_background->init("resource/배경.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	
	// 좌/우 피칭머신 선언 & 초기화
	_left_PitchingMachine = RectMake(0, WINSIZEY / 2 + 100, 50, 30);
	_right_PitchingMachine = RectMake(WINSIZEX / 2 + 208 , WINSIZEY / 2 + 100, 50, 30);
	
	// 볼 초기화
	_ballFireTimer = 0;									// 공 타이머 설정	
	for (int i = 0; i < BALLMAX; i++)
	{
		_ball[i].speed = RND->getFromFloatTo(5, 7);		// 공 스피드 설정
		_ball[i].angle = PI / 2;						// 공 각도 설정
		_ball[i].radius = 10;							// 공 반지름 설정
		_ball[i].gravity = 0;							// 공 중력 설정
		_ball[i].isFire = false;						// 공 발사여부 설정
	}

	// 공 이미지 선언 & 초기화
	_ballimg = new image;
	_ballimg->init("resource/공.bmp", 30, 30, true, RGB(255, 0, 255));

	// 사격대, 사격대 이미지, 사격대 구역 선언 & 초기화
	_launch_Pad = RectMakeCenter(WINSIZEX /2 , WINSIZEY / 2, 50, 50);
	_launch_Pad_img = new image;
	_launch_Pad_img->init("resource/사격대.bmp", 50, 50, true, RGB(255, 0, 255));
	_launch_Pad_Zone = RectMake(WINSIZEX / 2 - 25, 0, 50, WINSIZEY);

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

	// 엔터 입력 시 게임 시작
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isGameStart = true;
		_isGameOver = false;
	}

	if (!_isGameOver)
	{
		_ballFireTimer += 10;	// 타이머 설정
		ballFire();				// 총 발사
		ballMove();				// 총 움직임

		// 충돌여부 판정
		for (int i = 0; i < BALLMAX; i++)
		{
			if (!_ball[i].isFire) continue;

			// 사격대 구역안에 볼이 들어오면
			if (_launch_Pad_Zone.left < _ball[i].x && _ball[i].x < _launch_Pad_Zone.right)
			{
				_launch_Pad.top = _ball[i].y - 10;	// 사격대의 Y축을 볼에 움직임에 따라 변경해준다.

				// PtInRect를 사용하기 위한 POINT 선언
				POINT pt;
				pt.x = _ball[i].x;
				pt.y = _ball[i].y;

				// 스페이스 키 입력 후 사격대와 공이 충돌할 때 공을 삭제해준다.
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
				{
					PtInRect(&_launch_Pad, pt);
					_ball[i].isFire = false;
					_score1++;
				}
			}
			
			// 일의자리 숫자가 9보다 커지면 0초기화 및 십의자리수 1 증가
			if (_score1 > 9)														// 일의 자리숫자가 9보다 커지면
			{
				_score1 = 0;														// 0으로 초기화 시켜주고
				_score10++;															// 십의 자리 숫자를 올려준다.
			}
		}
	}

	// 게임 오버 조건
	if (_gameOverCount == GAMEOVER_VALUE)
	{
		_isGameOver = true;
	}

	// 'A'키 통한 떄 재시작
	if (KEYMANAGER->isOnceKeyDown(0x41))
	{
		if (_isGameOver) this->init();
	}
}

//여기에다 그려라 좀! 쫌!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================

	// 배경화면 출력
	_background->render(backDC, 0, 0);

	// 사격대 구역 출력
	//Rectangle(backDC, _launch_Pad_Zone);

	// 피칭머신 출력
	//Rectangle(backDC, _left_PitchingMachine);
	//Rectangle(backDC, _right_PitchingMachine);
	
	// 사격대 출력
	_launch_Pad_img->render(backDC, _launch_Pad.left, _launch_Pad.top);
	//Rectangle(backDC, _launch_Pad);

	// 초기 시작 안내 문구 출력
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

	// 공 출력	
	for (int i = 0; i < BALLMAX; i++)
	{
		if (!_ball[i].isFire) continue;
			_ballimg->render(backDC, _ball[i].x, _ball[i].y);		
	}

	// 게임 오버 카운트 체크
	char str[128];
	sprintf_s(str, "MISS COUNT %d = GAME OVER", GAMEOVER_VALUE);
	TextOut(backDC, 20, 5, str, strlen(str));
	char str5[128];
	sprintf_s(str5, "MISS : %d", _gameOverCount);
	TextOut(backDC, 20, 25, str5, strlen(str5));

	// 점수 출력
	_num[_score1]->render(backDC, WINSIZEX / 2 - 10, WINSIZEY / 2 - 200);
	_num[_score10]->render(backDC, WINSIZEX / 2 - 30, WINSIZEY / 2 - 200);

	// 종료됐을 때 재시작 안내 문구 출력
	if (_isGameOver == true && _isGameStart)
	{
		char str4[128];
		sprintf_s(str4, "RESTART PRESS 'A'!");
		TextOut(backDC, WINSIZEX / 2- 70, WINSIZEY / 2 - 120, str4, strlen(str4));
	}

	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(hdc, 0, 0);
}

// 발사
void playGround::ballFire()
{
	// 발사타이머가 750보다 작으면 항상 리턴.
	if (_ballFireTimer < 750)
	{
		return;
	}

	// 발사타이머가 750이상 커졌을 때
	for (int i = 0; i < BALLMAX; i++)
	{
		if (_ball[i].isFire) continue;		
		_ball[i].isFire = true;

		_ball[i].gravity = 0;	// 공의 중력을 초기화, 하지 않으면 계속 누적되서 밑으로 쏠리게 된다.

		_ballRND = RND->getInt(2);	// 공 좌/우 랜덤설정
		if (_ballRND == 0) // 왼쪽에서 나오는 공
		{
			_ball[i].x = (_left_PitchingMachine.right + 10) + cosf(_ball[i].angle);
			_ball[i].y = (_left_PitchingMachine.top + 10) - sinf(_ball[i].angle);
			_ball[i].angle = RND->getFromFloatTo(PI / 6, PI / 4);
		}		
		else // 오른쪽에서 나오는 공
		{
			_ball[i].x = _right_PitchingMachine.left - 10;
			_ball[i].y = _right_PitchingMachine.top + 15;
			_ball[i].angle = RND->getFromFloatTo(PI / 1.125, PI / 1.24);
		}
		_ballFireTimer = 0;	// 발사 타이머 초기화
		break;
	}
}

// 볼 이동
void playGround::ballMove()
{
	for (int i = 0; i < BALLMAX; i++)
	{
		if (!_ball[i].isFire) continue;

		// 공이 Y축 기준으로 화면 바깥으로 나간경우
		if (_ball[i].y >= WINSIZEY)
		{
			_gameOverCount++;			// 카운트 ++
			_ball[i].isFire = false;	// 카운트 계속 오르는걸 방지하기 위한 미사일 객체 삭제
		}

		_ball[i].gravity += 0.08f;
		_ball[i].x += cosf(_ball[i].angle) * _ball[i].speed;
		_ball[i].y += -sinf(_ball[i].angle) * _ball[i].speed + _ball[i].gravity;
	}
}