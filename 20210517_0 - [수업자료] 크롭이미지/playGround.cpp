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

	_leo = new image;
	_leo->init("����.bmp", WINSIZEX, WINSIZEY);


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

	
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	_leo->render(backDC, 0, 0);
	//������۵� left, top��ǥ�κ��� ����ũ��, ����ũ�� ��ŭ ������ 0,0�� �ѷȴ�
	//_leo->render(backDC, 0, 0, 400, 300, 150, 150);

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}
