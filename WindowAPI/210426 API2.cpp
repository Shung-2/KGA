#include "stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPCTSTR _lpszClass = TEXT("경일 28기 이시영 :-) ");

void setWindowsSize(int x, int y, int width, int height);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{
	_hInstance = hInstance;

	MSG message;
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
	ShowWindow(_hWnd, cmdShow);

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

// 210426 - 사각형 생성을 위한 RECT
// 전역공간에 선언할꺼면 선언해도 무방하다!
// RECT _rc;

enum BOX
{
	BOX_FIRST,
	BOX_SECOND,
	BOX_END
};

BOX CURRENTBOX; // 이 이넘문을 현재 박스로 사용한다.
RECT _rc[BOX_END], _rcIN;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
		// 윈도우 창이 딱 한번 생성될때 호출되는 것
	case WM_CREATE:
		_rc[BOX_FIRST] = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 100, 100);
		_rc[BOX_SECOND] = RectMakeCenter(WINSIZEX / 2 + 150, WINSIZEY / 2, 100, 100);
		_rcIN = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 50, 50);

		CURRENTBOX = BOX_FIRST;
		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// 사각형 생성
		for (int i = 0; i < BOX_END; i++)
		{
			Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
		}
		Rectangle(hdc, _rcIN.left, _rcIN.top, _rcIN.right, _rcIN.bottom);

		EndPaint(hWnd, &ps);
		break;
	}
	break;

	case WM_KEYDOWN:
		// wParam - 모든 키 입력 및 마우스 클릭
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;

			/*
			공통사항
			1. 내가 움직이는 사각형 안에 작은 사각형이 있다. 큰 사각형 움직일 때 작은 사각형은 내 움직임에 맞춰 끌려 다닌다.
			2. 모든 사각형은 화면 밖으로 나갈 수 없다.

			과제 1. 사각을 밀기.
			과제 2. 사각형이 움직이다가 다른 사각형이랑 부딪혔다. 안에 있는 작은 사각형이 다른 사각형 가운대로 이동하더니 그 사각형이 움직인다.

			이하 과제 2.
			*/

		case VK_LEFT:
			_rc[CURRENTBOX].left -= 5;
			_rc[CURRENTBOX].right -= 5;

			if (_rcIN.right > _rc[CURRENTBOX].right)
			{
				int width = _rcIN.right - _rcIN.left;
				_rcIN.right = _rc[CURRENTBOX].right;
				_rcIN.left = _rcIN.right - width;
			}
			break;

		case VK_RIGHT:
			_rc[CURRENTBOX].left += 5;
			_rc[CURRENTBOX].right += 5;

			if (_rcIN.left < _rc[CURRENTBOX].left)
			{
				int width = _rcIN.right - _rcIN.left;
				_rcIN.left = _rc[CURRENTBOX].left;
				_rcIN.right = _rcIN.left + width;
			}
			break;

		case VK_UP:
			_rc[CURRENTBOX].top -= 5;
			_rc[CURRENTBOX].bottom -= 5;

			if (_rcIN.bottom > _rc[CURRENTBOX].bottom)
			{
				int height = _rcIN.bottom - _rcIN.top;
				_rcIN.bottom = _rc[CURRENTBOX].bottom;
				_rcIN.top = _rcIN.bottom - height;
			}
			break;

		case VK_DOWN:
			_rc[CURRENTBOX].top += 5;
			_rc[CURRENTBOX].bottom += 5;

			if (_rcIN.top < _rc[CURRENTBOX].top)
			{
				int height = _rcIN.bottom - _rcIN.top;
				_rcIN.top = _rc[CURRENTBOX].top;
				_rcIN.bottom = _rcIN.top + height;
			}
			break;
		}
		
		RECT temp;
		if (IntersectRect(&temp, &_rc[BOX_FIRST], &_rc[BOX_SECOND]))
		{
			switch (CURRENTBOX)
			{
			case BOX_FIRST:
				CURRENTBOX = BOX_SECOND;
				break;
			case BOX_SECOND:
				CURRENTBOX = BOX_FIRST;
				break;
			}
			_rcIN = RectMakeCenter((_rc[CURRENTBOX].right + _rc[CURRENTBOX].left) / 2,
				(_rc[CURRENTBOX].top + _rc[CURRENTBOX].bottom) / 2, 50, 50);
		}

		/*
		if (_rc[BOX_FIRST].right  > _rc[BOX_SECOND].left &&
			_rc[BOX_FIRST].left   < _rc[BOX_SECOND].right &&
			_rc[BOX_FIRST].top    < _rc[BOX_SECOND].bottom &&
			_rc[BOX_FIRST].bottom > _rc[BOX_SECOND].top)
		{
			switch (CURRENTBOX)
			{
				case BOX_FIRST:
					CURRENTBOX = BOX_SECOND;
				break;
				case BOX_SECOND:
					CURRENTBOX = BOX_FIRST;
				break;

			}

			_rcIN = RectMakeCenter((_rc[CURRENTBOX].right + _rc[CURRENTBOX].left) / 2,
				(_rc[CURRENTBOX].top + _rc[CURRENTBOX].bottom) / 2, 50, 50);
		}
		*/
		InvalidateRect(_hWnd, NULL, true);
		break;

		//윈도우 창 부수는 함수 
	case WM_DESTROY:
		//윈도우 종료함수
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;
	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	//얘가 실제 클라이언트 영역 조정 들어가는 함수
	AdjustWindowRect(&winRect, WINSTYLE, false);

	//조정된 영역으로 다시 한 번 윈도우 위치 잡아주는 함수
	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left), (winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
}