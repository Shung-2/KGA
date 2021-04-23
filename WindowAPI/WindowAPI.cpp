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
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
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


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// 선
		//LineMake(hdc, 50, 50, 200, 200);
		//LineMake(hdc, 250, 250, 400, 200);

		// 사각형
		//RectangleMake(hdc, WINSIZEX / 2, WINSIZEY / 2, 100, 100);
		//RectangleMakeCenter(hdc, WINSIZEX / 2, WINSIZEY / 2, 100, 100);

		// 원
		//EllipseMake(hdc, WINSIZEX / 2, WINSIZEY / 2, 500, 500);
		EllipseMakeCenter(hdc, WINSIZEX / 2, WINSIZEY / 2, 500, 500);
		EllipseMakeCenter(hdc, WINSIZEX / 2, WINSIZEY / 2, 450, 450);

		// 월요일 - 키보드
		// 화요일 - 마우스
		// 수요일 - 게임로직
		// 목요일 - 런게임
		// 금요일 - 랜덤함수 이용한 게임
		
		// 월요일 - 슈팅게임
		// 화요일 - 슈팅게임
		// 수요일 - 피타고라스 형과 라디안과 디그리의 세계
		// ~수요일 - 이미지

		EndPaint(hWnd, &ps);
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