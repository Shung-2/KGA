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
	_background = IMAGEMANAGER->addImage("���", "��� �ε�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 50, WINSIZEX, 50);
	_loadingBar->setGauge(0, 0);

	// �����带 �Ế�ô�
	CreateThread(
		NULL,		   //�������� ���ȼӼ�(�ڽ������찡 �����Ҷ�)
		NULL,		   //�������� ����ũ��(NULL�� �θ� ���ξ�����)
		threadFunction,//����� �Լ�
		this,		   //������ �Ű�����(this�� ������ �� Ŭ����)
		NULL,		   //������ Ư��(��ٸ��� �ٷν�������(NULL))
		NULL		   //������ ���� �� �������� ID �Ѱ���
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
		SCENEMANAGER->changeScene("�ΰ��Ӿ�");
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
		IMAGEMANAGER->addImage("����", "��� �ΰ���.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

		Sleep(1);

		loadingHelper->_currentCount++;
	}


	return 0;
}
