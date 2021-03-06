#include "stdafx.h"
#include "gameNode.h"

void gameNode::setBackBuffer()
{
	_backBuffer = new image;
	_backBuffer->init(WINSIZEX, WINSIZEY);
}

gameNode::gameNode()
{

}

gameNode::~gameNode()
{

}

HRESULT gameNode::init()
{
	SetTimer(_hWnd, 1, 10, NULL);
	KEYMANAGER->init();

	return S_OK;
}

void gameNode::release()
{
	KillTimer(_hWnd, 1);
	KEYMANAGER->release();
	KEYMANAGER->releaseSingleton();
}

void gameNode::update()
{
	InvalidateRect(_hWnd, NULL, true);
}

void gameNode::render(HDC hdc)
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC         hdc; //얘 찐 중요합니...

	switch (iMessage)
	{
	case WM_TIMER:
		this->update();
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		this->render(hdc);

		EndPaint(hWnd, &ps);
		break;
	}
	break;

	//마우스 움직이면 여기서 메세지 발생
	case WM_MOUSEMOVE:
		_ptMouse.x = static_cast<float>(LOWORD(lParam));
		_ptMouse.y = static_cast<float>(HIWORD(lParam));

		break;
		
	//마우스 왼쪽 클릭(눌려지고 있을때 여기)
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;


		//윈도우 창 부쉬는(?) 
	case WM_DESTROY:
		//윈도우 종료함수
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
