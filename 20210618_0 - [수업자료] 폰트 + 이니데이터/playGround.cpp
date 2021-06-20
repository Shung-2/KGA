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
	gameNode::init(true);

	INIDATA->addData("춘춘", "무력", "90");
	INIDATA->addData("춘춘", "비틱력", "100");
	INIDATA->addData("춘춘", "식비효율력", "50");

	INIDATA->addData("의규", "무력", "70");
	INIDATA->addData("의규", "비틱력", "10");
	INIDATA->addData("의규", "식비효율력", "100");

	INIDATA->iniSave("28기");

	_str = INIDATA->loadDataString("28기", "춘춘", "비틱력");
	_test = INIDATA->loadDataInterger("28기", "의규", "식비효율력");

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
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
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	char str[256];
	HFONT font, oldFont;
	
	CreateFont(
			40,					//문자폭
			0,					//문자 넓이
			40,					//문자 기울기
			0,					//문자 방향
			600,				//문자 굵기
			0,					//bool 문자 기울기(이탤릭체)
			0,					//bool 문자 밑줄
			0,					//bool 문자 취소선
			HANGUL_CHARSET,		//문자 셋팅
			0,					//출력 정확도
			0,					//클리핑 정확도
			0,					//출력 퀄리티
			0,					//자간
			TEXT("궁서체")		
	);
	

	
	font = CreateFont(50, 0, 0, 0, 100, false, false, false, HANGUL_CHARSET,
		0, 0, 0, 0, TEXT("HY울릉도M"));
	oldFont = (HFONT)SelectObject(getMemDC(), font);
	sprintf_s(str, "주말인가");
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
	//여기도 건들지마라
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
