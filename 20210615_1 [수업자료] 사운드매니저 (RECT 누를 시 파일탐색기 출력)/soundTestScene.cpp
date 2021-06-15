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
	SOUNDMANAGER->addSound("BTS", "BTS-Butter.mp3", true, true);
	SOUNDMANAGER->addSound("BTS2", "BTS-Butter.mp3", true, true);
	SOUNDMANAGER->addSound("Æ÷Å»", "Æ÷Å»2ÅÍ·¿¿ÀÆä¶ó.mp3", true, false);

	_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);

	return S_OK;
}

void soundTestScene::release()
{
}

void soundTestScene::update()
{
	{
		if (KEYMANAGER->isOnceKeyDown('Q'))
		{
			SOUNDMANAGER->play("BTS", 1.0f);
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			SOUNDMANAGER->stop("BTS");
		}
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			SOUNDMANAGER->pause("BTS");
		}
		if (KEYMANAGER->isOnceKeyDown('R'))
		{
			SOUNDMANAGER->resume("BTS");
		}

		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			SOUNDMANAGER->play("BTS2", 0.5f);
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			SOUNDMANAGER->stop("BTS2");
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			SOUNDMANAGER->pause("BTS2");
		}
		if (KEYMANAGER->isOnceKeyDown('F'))
		{
			SOUNDMANAGER->resume("BTS2");
		}

		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			SOUNDMANAGER->play("Æ÷Å»", 0.5f);
		}
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			SOUNDMANAGER->stop("Æ÷Å»");
		}
		if (KEYMANAGER->isOnceKeyDown('C'))
		{
			SOUNDMANAGER->pause("Æ÷Å»");
		}
		if (KEYMANAGER->isOnceKeyDown('V'))
		{
			SOUNDMANAGER->resume("Æ÷Å»");
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_rc, _ptMouse))
		{
			OPENFILENAME ofn;
			char filePathSize[1028] = "";
			ZeroMemory(&ofn, sizeof(OPENFILENAME));

			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = filePathSize;
			ofn.nMaxFile = sizeof(filePathSize);
			ofn.nFilterIndex = true;
			ofn.nMaxFileTitle = NULL;
			ofn.lpstrFileTitle = NULL;
			ofn.lpstrInitialDir = NULL;
			ofn.lpstrFilter = ("Á¦¿¡¹ßÀ½¾ÇÆÄÀÏ¸¸");
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetOpenFileName(&ofn) == FALSE) return;

			char temp[1028];
			strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));

			char* context = NULL;
			char* token = strtok_s(temp, "\\", &context);

			while (strlen(context))
			{
				token = strtok_s(NULL, "\\", &context);
			}

			SOUNDMANAGER->addSound(token, ofn.lpstrFile, false, false);
			SOUNDMANAGER->play(token);
		}
	}


}

void soundTestScene::render()
{
	Rectangle(getMemDC(), _rc);
}
