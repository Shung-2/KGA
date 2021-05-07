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

	_radian = PI / 2;
	_degree = 45.0f;

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
	char strRadian[128];
	char strDegree[128];

	sprintf_s(strRadian, "%.2f ���� ���� %.2f ��׸��� ����",
		_radian, _radian * (180.0f / PI));
	TextOut(backDC, 100, 100, strRadian, strlen(strRadian));

	sprintf_s(strDegree, "%.2f ��׸� ���� %.2f ���ȿ� ����",
		_degree, _degree * (PI / 180.0f));
	TextOut(backDC, 100, 200, strDegree, strlen(strDegree));

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}