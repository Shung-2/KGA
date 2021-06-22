#include "stdafx.h"
#include "loadingScene.h"
#include "progressBar.h"

loadingScene::loadingScene()
	: _background(nullptr), _loadingBar(nullptr),
	_currentCount(0)
{
}

loadingScene::~loadingScene()
{
}

HRESULT loadingScene::init()
{
	_background = IMAGEMANAGER->addImage("배경", "블소 로딩.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 50, WINSIZEX, 50);
	_loadingBar->setGauge(0, 0);

	// 쓰레드를 써봅시다
	CreateThread(
		NULL,		   //스레드의 보안속성(자신윈도우가 존재할때)
		NULL,		   //스레드의 스택크기(NULL로 두면 메인쓰레드)
		threadFunction,//사용할 함수
		this,		   //스레드 매개변수(this로 뒀으니 본 클래스)
		NULL,		   //스레드 특성(기다릴지 바로실행할지(NULL))
		NULL		   //스레드 생성 후 스레드의 ID 넘겨줌
	);

	return S_OK;
}

void loadingScene::release()
{
	SAFE_DELETE(_loadingBar);
}

void loadingScene::update()
{
	_loadingBar->update();
	_loadingBar->setGauge(_currentCount, LOADINGMAX);

	if (_currentCount == LOADINGMAX)
	{
		SCENEMANAGER->changeScene("인게임씬");
	}
}

void loadingScene::render()
{
	_background->render(getMemDC());
	_loadingBar->render();
}

DWORD threadFunction(LPVOID lpParameter)
{
	loadingScene* loadingHelper = (loadingScene*)lpParameter;

	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		IMAGEMANAGER->addImage("시작", "블소 인게임.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

		Sleep(1);

		loadingHelper->_currentCount++;
	}


	return 0;
}
