#include "stdafx.h"
#include "soundTestScene.h"

soundTestScene::soundTestScene()
{
}

soundTestScene::~soundTestScene()
{
}

HRESULT soundTestScene::init()
{
	/* 이미지, 사운드, 버튼 추가 */
	_AddImage();
	_AddSound();
	_ButtonInit();

	/* 앨범 커버 RECT 생성 및 이미지 동적할당 */
	_AlbumCover = RectMakeCenter(WINSIZEX / 2 - 200, WINSIZEY / 2, 300, 300);
	_AlbumCoverImg = new image;
	_AlbumCoverImg = IMAGEMANAGER->findImage("3.14");

	/* 선택된 뮤직 INDEX 초기화 */
	_SelectMusicIdx = 0;
	_ImgCheck[20] = false;

	/* VECTOR와 SOUNDMANAGER를 이용한 노래 리스트 생성 */
	vector<string> _SongNameList = SOUNDMANAGER->getFileName();
	for (int i = 0; i < _SongNameList.size(); i++)
	{
		RECT _Songrc = RectMakeCenter(WINSIZEX / 2 + 200, 120 + i * 35, RECT_WIDTH, RECT_HEIGHT);
		_SongList.push_back({ _Songrc, _SongNameList[i] });
	}

	/* 노래 플레이 유무 및 모드 설정 */
	_isPlay = true;
	_PlayMode = ALL;
	SOUNDMANAGER->play("3.14");

	/* 플레이바 출력 */
	_PlayBarBack = RectMake(50, 450, 500, 10);
	_NavigationButton = RectMake(50, 445, 20, 20);

	return S_OK;
}

void soundTestScene::release()
{
}

void soundTestScene::update()
{
	/* 마우스 클릭에 따른 처리*/
	_MouseHandle();

	SOUNDMANAGER->getLength(_SongList[_SelectMusicIdx].filename);

	_ClickTime += TIMEMANAGER->getElapsedTime();
	_PlayBarBack = RectMake(50, 450,
		(500.0f / SOUNDMANAGER->getLength(_SongList[_SelectMusicIdx].filename)) * SOUNDMANAGER->getPosition(_SongList[_SelectMusicIdx].filename),
		10);
	_NavigationButton = RectMake(45 + (500.0f / SOUNDMANAGER->getLength(_SongList[_SelectMusicIdx].filename)) * SOUNDMANAGER->getPosition(_SongList[_SelectMusicIdx].filename),
		445, 20, 20);
	_MaxTime = SOUNDMANAGER->getLength(_SongList[_SelectMusicIdx].filename);
	_StartTime = SOUNDMANAGER->getPosition(_SongList[_SelectMusicIdx].filename);

	/* 노래가 끝에 다다랐을 때 PLAYMODE에 따른 처리 */
	if (_MaxTime == _StartTime)
	{
		switch (_PlayMode)
		{
		case ALL:
			SOUNDMANAGER->stop(_SongList[_SelectMusicIdx].filename);
			_SelectMusicIdx = (_SelectMusicIdx + 1) % _SongList.size();
			SOUNDMANAGER->play(_SongList[_SelectMusicIdx].filename);
			_SelectRect = RectMake(50, 80 + _SelectMusicIdx * 20, 300, 20);
			break;

		case ONE:
			SOUNDMANAGER->setPosition(_SongList[_SelectMusicIdx].filename, 0);
			break;

		case SHUFFLE:
			int rand = RND->getInt(_SongList.size());
			SOUNDMANAGER->stop(_SongList[_SelectMusicIdx].filename);
			_SelectMusicIdx = rand;
			SOUNDMANAGER->play(_SongList[_SelectMusicIdx].filename);
			_SelectRect = RectMake(50, 80 + _SelectMusicIdx * 20, 300, 20);
			break;
		}
	}
}

void soundTestScene::render()
{
	/* RECT 투명화 */
	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	/* 선택된 노래 RECT 구역 색칠 */
	HBRUSH hBrush, oBrush;
	hBrush = CreateSolidBrush(RGB(128, 128, 128));
	oBrush = (HBRUSH)SelectObject(getMemDC(), hBrush);
	Rectangle(getMemDC(), _SelectRect);
	SelectObject(getMemDC(), oBrush);
	DeleteObject(hBrush);

	/* 노래 Play 여부에 이미지 처리 */
	if (_isPlay == false)
	{
		_Play.img->render(getMemDC(), _Play.rc.left, _Play.rc.top);
	}
	else
	{
		_Pause.img->render(getMemDC(), _Pause.rc.left, _Pause.rc.top);
	}
	_Before.img->render(getMemDC(), _Before.rc.left, _Before.rc.top);
	_Next.img->render(getMemDC(), _Next.rc.left, _Next.rc.top);
	_Mode.img->render(getMemDC(), _Mode.rc.left, _Mode.rc.top);

	/* 노래 제목 출력 */
	for (int i = 0; i < _SongList.size(); i++)
	{
		TextOut(getMemDC(), WINSIZEX / 2 + 120, 110 + i * 35, _SongList[i].filename.c_str(), strlen(_SongList[i].filename.c_str()));
	}

	/* PlayBar 출력 */
	Rectangle(getMemDC(), _PlayBarBack);
	hBrush = CreateSolidBrush(RGB(128, 128, 128));
	oBrush = (HBRUSH)SelectObject(getMemDC(), hBrush);
	Rectangle(getMemDC(), _PlayBarFront);
	SelectObject(getMemDC(), oBrush);
	DeleteObject(hBrush);

	/* 현재 시간 & 남은 시간 출력 */
	char TimeText[32];
	sprintf_s(TimeText, "%d:%02d / %d:%02d", _StartTime / 60, _StartTime % 60, _MaxTime / 60, _MaxTime % 60);
	TextOut(getMemDC(), 50, 475, TimeText, strlen(TimeText));
	Ellipse(getMemDC(), _NavigationButton);

	Rectangle(getMemDC(), _AlbumCover);
	_AlbumCoverImg->render(getMemDC(), _AlbumCover.left, _AlbumCover.top);
}

void soundTestScene::_AddImage()
{
	IMAGEMANAGER->addImage("놓아줘", "image/놓아줘.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선곡표", "image/선곡표.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("마음대로", "image/마음대로.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("3.14", "image/3.14.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("파도", "image/파도.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Rest", "image/Rest.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Cigarette", "image/Cigarette.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("서로의 조각", "image/서로의 조각.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ainos", "image/Ainos.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Romance", "image/Romance.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("앵콜요청금지", "image/앵콜요청금지.bmp", 300, 300, true, RGB(255, 0, 255));
}

void soundTestScene::_AddSound()
{
	SOUNDMANAGER->addSound("놓아줘", "song/1. 크러쉬 - 놓아줘.mp3", true, true);
	SOUNDMANAGER->addSound("선곡표", "song/2. 에픽하이 - 선곡표.mp3", true, true);
	SOUNDMANAGER->addSound("마음대로", "song/3. 콜드 - 마음대로.mp3", true, true);
	SOUNDMANAGER->addSound("3.14", "song/4. 참솜 - 3.14.mp3", true, true);
	SOUNDMANAGER->addSound("파도", "song/5. 새소년 - 파도.mp3", true, true);
	SOUNDMANAGER->addSound("Rest", "song/6. 백예린 - Rest.mp3", true, true);
	SOUNDMANAGER->addSound("Cigarette", "song/7. OffonOff - Cigarette (Feat. Tablo, MISO).mp3", true, true);
	SOUNDMANAGER->addSound("서로의 조각", "song/8. 프롬 - 서로의 조각 (With 기리보이).mp3", true, true);
	SOUNDMANAGER->addSound("Ainos", "song/9. 옐로우 - ainos.mp3", true, true);
	SOUNDMANAGER->addSound("Romance", "song/10. 치즈 - Romance.mp3", true, true);
	SOUNDMANAGER->addSound("앵콜요청금지", "song/11. 브로콜리 너마저 - 앵콜요청금지.mp3", true, true);

}

void soundTestScene::_ButtonInit()
{
	_Before.rc = RectMakeCenter(WINSIZEX / 2 - 350, WINSIZEY - 97 / 2, 30, 30);
	_Before.img = IMAGEMANAGER->addImage("before", "buttonImage/before_button.bmp", 30, 30, true, RGB(255, 0, 255));

	_Play.rc = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY - 97 / 2, 40, 40);
	_Play.img = IMAGEMANAGER->addImage("play", "buttonImage/play_button.bmp", 40, 40, true, RGB(255, 0, 255));

	_Pause.rc = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY - 97 / 2, 40, 40);
	_Pause.img = IMAGEMANAGER->addImage("pause", "buttonImage/pause_button.bmp", 40, 40, true, RGB(255, 0, 255));

	_Next.rc = RectMakeCenter(WINSIZEX / 2 - 250, WINSIZEY - 97 / 2, 30, 30);
	_Next.img = IMAGEMANAGER->addImage("next", "buttonImage/next_button.bmp", 30, 30, true, RGB(255, 0, 255));

	_ModeImg[0] = IMAGEMANAGER->addImage("all", "buttonImage/all_loop_button.bmp", 30, 30, true, RGB(255, 0, 255));
	_ModeImg[1] = IMAGEMANAGER->addImage("one", "buttonImage/one_loop_button.bmp", 30, 30, true, RGB(255, 0, 255));
	_ModeImg[2] = IMAGEMANAGER->addImage("shuffle", "buttonImage/shuffle_loop_button.bmp", 30, 30, true, RGB(255, 0, 255));

	_Mode.img = IMAGEMANAGER->findImage("all");
	_Mode.rc = RectMakeCenter(WINSIZEX / 2 + 300, WINSIZEY - 97 / 2, 40, 40);
}

void soundTestScene::_MouseHandle()
{
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		/* PLAY 버튼 */
		if (PtInRect(&_Play.rc, _ptMouse) && _isPlay == false)
		{
			_isPlay = true;
			SOUNDMANAGER->resume(_SongList[_SelectMusicIdx].filename);
			_SelectRect = RectMake(WINSIZEX / 2 + 100, 105 + _SelectMusicIdx * 35, RECT_WIDTH, RECT_HEIGHT);
			return;
		}

		/* PAUSE 버튼 */
		if (PtInRect(&_Pause.rc, _ptMouse) && _isPlay == true)
		{
			_isPlay = false;
			SOUNDMANAGER->pause(_SongList[_SelectMusicIdx].filename);
			_SelectRect = RectMake(WINSIZEX / 2 + 100, 105 + _SelectMusicIdx * 35, RECT_WIDTH, RECT_HEIGHT);
			return;
		}

		/* NEXT 버튼 */
		if (PtInRect(&_Next.rc, _ptMouse))
		{
			if (_PlayMode == SHUFFLE)
			{
				int rand = RND->getInt(_SongList.size());
				SOUNDMANAGER->stop(_SongList[_SelectMusicIdx].filename);
				_SelectMusicIdx = rand;
				SOUNDMANAGER->play(_SongList[_SelectMusicIdx].filename);
				_SelectRect = RectMake(WINSIZEX / 2 + 100, 105 + _SelectMusicIdx * 35, RECT_WIDTH, RECT_HEIGHT);
			}
			else
			{
				SOUNDMANAGER->stop(_SongList[_SelectMusicIdx].filename);
				_SelectMusicIdx = (_SelectMusicIdx + 1) % _SongList.size();
				SOUNDMANAGER->play(_SongList[_SelectMusicIdx].filename);
				_SelectRect = RectMake(WINSIZEX / 2 + 100, 105 + _SelectMusicIdx * 35, RECT_WIDTH, RECT_HEIGHT);
			}
			return;
		}

		/* BEFORE 버튼 */
		if (PtInRect(&_Before.rc, _ptMouse))
		{
			SOUNDMANAGER->stop(_SongList[_SelectMusicIdx].filename);
			if (_SelectMusicIdx != 0)
			{
				_SelectMusicIdx--;
			}
			else
			{
				_SelectMusicIdx = _SongList.size() - 1;
			}
			SOUNDMANAGER->play(_SongList[_SelectMusicIdx].filename);
			_SelectRect = RectMake(WINSIZEX / 2 + 100, 105 + _SelectMusicIdx * 35, RECT_WIDTH, RECT_HEIGHT);
		}

		/* MODE 버튼 */
		if (PtInRect(&_Mode.rc, _ptMouse))
		{
			_PlayMode = (MODE)((_PlayMode + 1) % 3);
			_Mode.img = _ModeImg[_PlayMode];
		}

		/* PLAYBAR 를 클릭할 경우 */
		if (PtInRect(&_PlayBarBack, _ptMouse))
		{
			SOUNDMANAGER->setPosition(_SongList[_SelectMusicIdx].filename,
				((_ptMouse.x - 50) / 500.0f) * (float)SOUNDMANAGER->getLength(_SongList[_SelectMusicIdx].filename));
		}

		/* 노래(글자)부분을 클릭할 경우*/
		for (int i = 0; i < _SongList.size(); i++)
		{
			if (PtInRect(&_SongList[i]._Song, _ptMouse))
			{
				if (_ClickTime <= 0.5f && _ClickIdx == i)
				{
					SOUNDMANAGER->stop(_SongList[_SelectMusicIdx].filename);
					_SelectMusicIdx = i;
					SOUNDMANAGER->play(_SongList[_SelectMusicIdx].filename);
					_SelectRect = RectMake(WINSIZEX / 2 + 100, 105 + _SelectMusicIdx * 35, RECT_WIDTH, RECT_HEIGHT);
					_ImgCheck[i] = true;
				}
				_ClickTime = 0;
				_ClickIdx = i;
			}
		}

		/* 노래(글자)부분을 클릭 할 경우 이미지 변경*/
		for (int i = 0; i < _SongList.size(); i++)
		{
			if (_ImgCheck[i])
			{
				if (_ImgCheck[0])
				{
					_ImgCheck[0] = _AlbumCoverImg = IMAGEMANAGER->findImage("3.14");
				}
				if (_ImgCheck[1])
				{
					_ImgCheck[1] = _AlbumCoverImg = IMAGEMANAGER->findImage("Ainos");
				}
				if (_ImgCheck[2])
				{
					_ImgCheck[2] = _AlbumCoverImg = IMAGEMANAGER->findImage("Cigarette");
				}
				if (_ImgCheck[3])
				{
					_ImgCheck[3] = _AlbumCoverImg = IMAGEMANAGER->findImage("Rest");
				}
				if (_ImgCheck[4])
				{
					_ImgCheck[4] = _AlbumCoverImg = IMAGEMANAGER->findImage("Romance");
				}
				if (_ImgCheck[5])
				{
					_ImgCheck[5] = _AlbumCoverImg = IMAGEMANAGER->findImage("놓아줘");
				}
				if (_ImgCheck[6])
				{
					_ImgCheck[6] = _AlbumCoverImg = IMAGEMANAGER->findImage("마음대로");
				}
				if (_ImgCheck[7])
				{
					_ImgCheck[7] = _AlbumCoverImg = IMAGEMANAGER->findImage("서로의 조각");
				}
				if (_ImgCheck[8])
				{
					_ImgCheck[8] = _AlbumCoverImg = IMAGEMANAGER->findImage("선곡표");
				}
				if (_ImgCheck[9])
				{
					_ImgCheck[9] = _AlbumCoverImg = IMAGEMANAGER->findImage("앵콜요청금지");
				}
				if (_ImgCheck[10])
				{
					_ImgCheck[10] = _AlbumCoverImg = IMAGEMANAGER->findImage("파도");
				}
			}
			_ImgCheck[i] = false;
		}
	}
}