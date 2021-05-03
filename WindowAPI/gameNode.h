#pragma once
#include "image.h"

class gameNode
{
private:
	image* _backBuffer; //빈 DC공간과 빈 bitmap공간
	void setBackBuffer();

public:
	gameNode();
	virtual ~gameNode();

	//HRESULT 마소 전용 반환형식인데
	//S_OK, E_FAIL, SUCCEDED
	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 함수
	virtual void render(HDC hdc);	//그리기 함수

	//백버퍼 접근자!g
	image* getBackBuffer() { return _backBuffer; }
	
	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};

