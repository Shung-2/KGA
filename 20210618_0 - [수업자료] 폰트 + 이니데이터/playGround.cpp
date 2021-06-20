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

	INIDATA->addData("����", "����", "90");
	INIDATA->addData("����", "��ƽ��", "100");
	INIDATA->addData("����", "�ĺ�ȿ����", "50");

	INIDATA->addData("�Ǳ�", "����", "70");
	INIDATA->addData("�Ǳ�", "��ƽ��", "10");
	INIDATA->addData("�Ǳ�", "�ĺ�ȿ����", "100");

	INIDATA->iniSave("28��");

	_str = INIDATA->loadDataString("28��", "����", "��ƽ��");
	_test = INIDATA->loadDataInterger("28��", "�Ǳ�", "�ĺ�ȿ����");

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

	
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	char str[256];
	HFONT font, oldFont;
	
	CreateFont(
			40,					//������
			0,					//���� ����
			40,					//���� ����
			0,					//���� ����
			600,				//���� ����
			0,					//bool ���� ����(���Ÿ�ü)
			0,					//bool ���� ����
			0,					//bool ���� ��Ҽ�
			HANGUL_CHARSET,		//���� ����
			0,					//��� ��Ȯ��
			0,					//Ŭ���� ��Ȯ��
			0,					//��� ����Ƽ
			0,					//�ڰ�
			TEXT("�ü�ü")		
	);
	

	
	font = CreateFont(50, 0, 0, 0, 100, false, false, false, HANGUL_CHARSET,
		0, 0, 0, 0, TEXT("HY�︪��M"));
	oldFont = (HFONT)SelectObject(getMemDC(), font);
	sprintf_s(str, "�ָ��ΰ�");
	TextOut(getMemDC(), 200, 100, str, strlen(str));
	DeleteObject(font);
	
	HFONT font1, oldFont1;
	RECT rcText = RectMake(300, 200, 400, 100);

	font1 = CreateFont(100, 0, 0, 0, 300, false, false, false, DEFAULT_CHARSET,
		OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS,
		TEXT("Kunstler Script"));

	oldFont1 = (HFONT)SelectObject(getMemDC(), font1);

	DrawText(getMemDC(), TEXT("sandwich"), strlen("sandwich"), &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	DeleteObject(font1);

	TIMEMANAGER->render(getMemDC());
	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
