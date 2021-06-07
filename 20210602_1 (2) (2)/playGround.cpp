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
	gameNode::init(true);

	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY,
		true, RGB(255, 0, 255));
	
	SCENEMANAGER->addScene("INTRO", new testScene);
	SCENEMANAGER->addScene("OPTION", new testScene2);
	SCENEMANAGER->addScene("STAGE 1", new Stage1);
	SCENEMANAGER->changeScene("INTRO");

	st = new Stage1;
	st->setPlayerAddressLink(pl);

	//pl = new Player;


	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();
}

void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();	
}

void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	IMAGEMANAGER->findImage("���")->render(getMemDC(), 0, 0);	
	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
