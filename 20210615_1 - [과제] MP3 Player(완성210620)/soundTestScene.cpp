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
	/* �̹���, ����, ��ư �߰� */
	_AddImage();
	_AddSound();
	_ButtonInit();

	/* �ٹ� Ŀ�� RECT ���� �� �̹��� �����Ҵ� */
	_AlbumCover = RectMakeCenter(WINSIZEX / 2 - 200, WINSIZEY / 2, 300, 300);
	_AlbumCoverImg = new image;
	_AlbumCoverImg = IMAGEMANAGER->findImage("3.14");

	/* ���õ� ���� INDEX �ʱ�ȭ */
	_SelectMusicIdx = 0;
	_ImgCheck[20] = false;

	/* VECTOR�� SOUNDMANAGER�� �̿��� �뷡 ����Ʈ ���� */
	vector<string> _SongNameList = SOUNDMANAGER->getFileName();
	for (int i = 0; i < _SongNameList.size(); i++)
	{
		RECT _Songrc = RectMakeCenter(WINSIZEX / 2 + 200, 120 + i * 35, RECT_WIDTH, RECT_HEIGHT);
		_SongList.push_back({ _Songrc, _SongNameList[i] });
	}

	/* �뷡 �÷��� ���� �� ��� ���� */
	_isPlay = true;
	_PlayMode = ALL;
	SOUNDMANAGER->play("3.14");

	/* �÷��̹� ��� */
	_PlayBarBack = RectMake(50, 450, 500, 10);
	_NavigationButton = RectMake(50, 445, 20, 20);

	return S_OK;
}

void soundTestScene::release()
{
}

void soundTestScene::update()
{
	/* ���콺 Ŭ���� ���� ó��*/
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

	/* �뷡�� ���� �ٴٶ��� �� PLAYMODE�� ���� ó�� */
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
	/* RECT ����ȭ */
	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	/* ���õ� �뷡 RECT ���� ��ĥ */
	HBRUSH hBrush, oBrush;
	hBrush = CreateSolidBrush(RGB(128, 128, 128));
	oBrush = (HBRUSH)SelectObject(getMemDC(), hBrush);
	Rectangle(getMemDC(), _SelectRect);
	SelectObject(getMemDC(), oBrush);
	DeleteObject(hBrush);

	/* �뷡 Play ���ο� �̹��� ó�� */
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

	/* �뷡 ���� ��� */
	for (int i = 0; i < _SongList.size(); i++)
	{
		TextOut(getMemDC(), WINSIZEX / 2 + 120, 110 + i * 35, _SongList[i].filename.c_str(), strlen(_SongList[i].filename.c_str()));
	}

	/* PlayBar ��� */
	Rectangle(getMemDC(), _PlayBarBack);
	hBrush = CreateSolidBrush(RGB(128, 128, 128));
	oBrush = (HBRUSH)SelectObject(getMemDC(), hBrush);
	Rectangle(getMemDC(), _PlayBarFront);
	SelectObject(getMemDC(), oBrush);
	DeleteObject(hBrush);

	/* ���� �ð� & ���� �ð� ��� */
	char TimeText[32];
	sprintf_s(TimeText, "%d:%02d / %d:%02d", _StartTime / 60, _StartTime % 60, _MaxTime / 60, _MaxTime % 60);
	TextOut(getMemDC(), 50, 475, TimeText, strlen(TimeText));
	Ellipse(getMemDC(), _NavigationButton);

	Rectangle(getMemDC(), _AlbumCover);
	_AlbumCoverImg->render(getMemDC(), _AlbumCover.left, _AlbumCover.top);
}

void soundTestScene::_AddImage()
{
	IMAGEMANAGER->addImage("������", "image/������.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ǥ", "image/����ǥ.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "image/�������.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("3.14", "image/3.14.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ĵ�", "image/�ĵ�.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Rest", "image/Rest.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Cigarette", "image/Cigarette.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������ ����", "image/������ ����.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ainos", "image/Ainos.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Romance", "image/Romance.bmp", 300, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ݿ�û����", "image/���ݿ�û����.bmp", 300, 300, true, RGB(255, 0, 255));
}

void soundTestScene::_AddSound()
{
	SOUNDMANAGER->addSound("������", "song/1. ũ���� - ������.mp3", true, true);
	SOUNDMANAGER->addSound("����ǥ", "song/2. �������� - ����ǥ.mp3", true, true);
	SOUNDMANAGER->addSound("�������", "song/3. �ݵ� - �������.mp3", true, true);
	SOUNDMANAGER->addSound("3.14", "song/4. ���� - 3.14.mp3", true, true);
	SOUNDMANAGER->addSound("�ĵ�", "song/5. ���ҳ� - �ĵ�.mp3", true, true);
	SOUNDMANAGER->addSound("Rest", "song/6. �鿹�� - Rest.mp3", true, true);
	SOUNDMANAGER->addSound("Cigarette", "song/7. OffonOff - Cigarette (Feat. Tablo, MISO).mp3", true, true);
	SOUNDMANAGER->addSound("������ ����", "song/8. ���� - ������ ���� (With �⸮����).mp3", true, true);
	SOUNDMANAGER->addSound("Ainos", "song/9. ���ο� - ainos.mp3", true, true);
	SOUNDMANAGER->addSound("Romance", "song/10. ġ�� - Romance.mp3", true, true);
	SOUNDMANAGER->addSound("���ݿ�û����", "song/11. ����ݸ� �ʸ��� - ���ݿ�û����.mp3", true, true);

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
		/* PLAY ��ư */
		if (PtInRect(&_Play.rc, _ptMouse) && _isPlay == false)
		{
			_isPlay = true;
			SOUNDMANAGER->resume(_SongList[_SelectMusicIdx].filename);
			_SelectRect = RectMake(WINSIZEX / 2 + 100, 105 + _SelectMusicIdx * 35, RECT_WIDTH, RECT_HEIGHT);
			return;
		}

		/* PAUSE ��ư */
		if (PtInRect(&_Pause.rc, _ptMouse) && _isPlay == true)
		{
			_isPlay = false;
			SOUNDMANAGER->pause(_SongList[_SelectMusicIdx].filename);
			_SelectRect = RectMake(WINSIZEX / 2 + 100, 105 + _SelectMusicIdx * 35, RECT_WIDTH, RECT_HEIGHT);
			return;
		}

		/* NEXT ��ư */
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

		/* BEFORE ��ư */
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

		/* MODE ��ư */
		if (PtInRect(&_Mode.rc, _ptMouse))
		{
			_PlayMode = (MODE)((_PlayMode + 1) % 3);
			_Mode.img = _ModeImg[_PlayMode];
		}

		/* PLAYBAR �� Ŭ���� ��� */
		if (PtInRect(&_PlayBarBack, _ptMouse))
		{
			SOUNDMANAGER->setPosition(_SongList[_SelectMusicIdx].filename,
				((_ptMouse.x - 50) / 500.0f) * (float)SOUNDMANAGER->getLength(_SongList[_SelectMusicIdx].filename));
		}

		/* �뷡(����)�κ��� Ŭ���� ���*/
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

		/* �뷡(����)�κ��� Ŭ�� �� ��� �̹��� ����*/
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
					_ImgCheck[5] = _AlbumCoverImg = IMAGEMANAGER->findImage("������");
				}
				if (_ImgCheck[6])
				{
					_ImgCheck[6] = _AlbumCoverImg = IMAGEMANAGER->findImage("�������");
				}
				if (_ImgCheck[7])
				{
					_ImgCheck[7] = _AlbumCoverImg = IMAGEMANAGER->findImage("������ ����");
				}
				if (_ImgCheck[8])
				{
					_ImgCheck[8] = _AlbumCoverImg = IMAGEMANAGER->findImage("����ǥ");
				}
				if (_ImgCheck[9])
				{
					_ImgCheck[9] = _AlbumCoverImg = IMAGEMANAGER->findImage("���ݿ�û����");
				}
				if (_ImgCheck[10])
				{
					_ImgCheck[10] = _AlbumCoverImg = IMAGEMANAGER->findImage("�ĵ�");
				}
			}
			_ImgCheck[i] = false;
		}
	}
}