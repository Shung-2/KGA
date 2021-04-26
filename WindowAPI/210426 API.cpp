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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	// wParam - 모든 키 입력 및 마우스 클릭
	// lParam - 마우스 좌표

	// 안에서 호출할 땐 static을 꼭 선언하자
	static RECT rc;
	static RECT rc2;
	static RECT rc3;

	switch (iMessage)
	{
		// 윈도우 창이 딱 한번 생성될때 호출되는 것
	case WM_CREATE:
		rc = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 100, 100);
		rc2 = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
		rc3 = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 50, 50);

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// 사각형 생성
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		Rectangle(hdc, rc2.left, rc2.top, rc2.right, rc2.bottom);
		Rectangle(hdc, rc3.left, rc3.top, rc3.right, rc3.bottom);

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
		
		이하 과제 1.
		*/

		case VK_LEFT:
			// 왼쪽 벽 바깥으로 못나가게
			if (rc.left <= 0) break;
			if (rc2.left <= 0) break;

			// 내부박스 충돌 구현
			rc.left -= 10;
			rc.right -= 10;
			if (rc3.right > rc.right)
			{
				rc3.left -= 10;
				rc3.right -= 10;
			}

			// 왼쪽키 누를 때 박스 충돌
			if (rc.left < rc2.right &&
				rc.right > rc2.left &&
				rc.bottom > rc2.top &&
				rc.top < rc2.bottom)
			{
				int width = rc2.right - rc2.left;
				rc2.right = rc.left;
				rc2.left = rc2.right - width;
			}

			InvalidateRect(_hWnd, NULL, true);
			break;

		case VK_RIGHT:
			// 오른쪽 벽 바깥으로 못나가게
			if (rc.right >= WINSIZEX) break;
			if (rc2.right >= WINSIZEX) break;

			// 내부박스 충돌 구현
			rc.left += 10;
			rc.right += 10;
			if (rc3.left < rc.left)
			{
				rc3.left += 10;
				rc3.right += 10;
			}

			// 오른쪽키 누를 때 박스 충돌
			if (rc.left < rc2.right &&
				rc.bottom > rc2.top &&
				rc.right > rc2.left &&
				rc.top < rc2.bottom)
			{
				int width = rc2.right - rc2.left;
				rc2.left = rc.right;
				rc2.right = rc2.left + width;
			}

			InvalidateRect(_hWnd, NULL, true);
			break;

		case VK_UP:
			// 위쪽 벽 바깥으로 못나가게
			if (rc.top <= 0) break;
			if (rc2.top <= 0) break;

			// 내부박스 충돌 구현
			rc.top -= 10;
			rc.bottom -= 10;
			if (rc3.bottom > rc.bottom)
			{
				rc3.top -= 10;
				rc3.bottom -= 10;
			}

			// 위쪽키 누를 때 박스 충돌
			if (rc.top < rc2.bottom &&
				rc.left < rc2.right &&
				rc.right > rc2.left &&
				rc.bottom > rc2.top)
			{
				int height = rc2.bottom - rc2.top;
				rc2.bottom = rc.top;
				rc2.top = rc2.bottom - height;
			}

			InvalidateRect(_hWnd, NULL, true);
			break;

		case VK_DOWN:
			// 아래쪽 벽 바깥으로 못나가게
			if (rc.bottom >= WINSIZEY) break;
			if (rc2.bottom >= WINSIZEY) break;

			// 내부박스 충돌 구현
			rc.top += 10;
			rc.bottom += 10;
			if (rc3.top < rc.top)
			{
				rc3.top += 10;
				rc3.bottom += 10;
			}

			// 아래키 누를 때 박스 충돌
			if (rc.bottom > rc2.top &&
				rc.left < rc2.right &&
				rc.right > rc2.left &&
				rc.top < rc2.bottom)
			{
				int height = rc2.bottom - rc2.top;
				rc2.top = rc.bottom;
				rc2.bottom = rc2.top + height;
			}

			InvalidateRect(_hWnd, NULL, true);
			break;
		}
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