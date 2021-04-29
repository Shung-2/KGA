#include "stdafx.h"
#include "image.h"


image::image()
	: _backBuffer(NULL)
{
}


image::~image()
{
}

HRESULT image::init(int width, int height)
{
	if (_backBuffer != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_backBuffer = new IMAGE_INFO;
	_backBuffer->hMemDC = CreateCompatibleDC(hdc); //빈 DC영역 생성해줌
	_backBuffer->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_backBuffer->hOBit = (HBITMAP)SelectObject(_backBuffer->hMemDC, _backBuffer->hBit);
	_backBuffer->width = width;
	_backBuffer->height = height;

	//위에 초기화를 제대로했는데 잘 안됐다면?
	if (_backBuffer == nullptr)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

void image::release()
{
	if (_backBuffer)
	{
		SelectObject(_backBuffer->hMemDC, _backBuffer->hOBit);
		DeleteObject(_backBuffer->hBit);
		DeleteDC(_backBuffer->hMemDC);

		SAFE_DELETE(_backBuffer);
	}


}

void image::render(HDC hdc, int destX, int destY)
{
	//GdiTranparentBlt() -> 구글에서 마젠타 색을 투명하게 해주는 역활을 하는 함수
	//StrachBlt() -> 이름에서도 알 수 있듯이 스트레칭, 이미지의 크기를 조절하는 것이라고 볼 수 있다.
	//

	//DC영역간의 고속복사
	BitBlt(
		hdc,					//복사할 DC	
		destX,					//복사할 좌표(left)
		destY,					//복사할 좌표(top)
		_backBuffer->width,		//복사할 가로크기
		_backBuffer->height,	//복사할 세로크기
		_backBuffer->hMemDC,	//복사될 DC
		0, 0,					//복사될 시작좌표(left, top)
		SRCCOPY);				//복사할때 변형일으키지말어라~
	
}
