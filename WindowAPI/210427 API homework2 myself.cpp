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

	_hWnd = CreateWindow(WINNAME, WINNAME, WS_OVERLAPPEDWINDOW, WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY, NULL, (HMENU)NULL, hInstance, NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
	ShowWindow(_hWnd, cmdShow);

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

POINT _ptMouse;
RECT _rc;
bool _flag;			// 마우스 클릭 유무
int _sect;			// 분면 정의
int _disX, _disY;	// 중점에서 마우스 클릭좌표 거리를 뺀 값을 구하기 위한 변수

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	char str[128];

	switch (iMessage)
	{
		// 윈도우 창이 생성될때 딱 한번 호출되는 것
	case WM_CREATE:
	{
		_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
	}
	break;

	// 그림을 그려주는 것
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		sprintf_s(str, "마우스 X : %d, 마우스 Y : %d", _ptMouse.x, _ptMouse.y);
		TextOut(hdc, 20, 20, str, strlen(str));

		Rectangle(hdc, _rc);
		EndPaint(hWnd, &ps);
	}
	break;

	// 마우스 움직이면 여기서 메시지 발생
	case WM_MOUSEMOVE:
	{
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);

		if (_flag)
		{
			switch (_sect)
			{
			case 1:
				_rc.left = _ptMouse.x - _disX;
				_rc.top = _ptMouse.y - _disY;
				break;
			case 2:
				_rc.right = _ptMouse.x - _disX;
				_rc.top = _ptMouse.y - _disY;
				break;
			case 3:
				_rc.left = _ptMouse.x - _disX;
				_rc.bottom = _ptMouse.y - _disY;
				break;
			case 4:
				_rc.right = _ptMouse.x - _disX;
				_rc.bottom = _ptMouse.y - _disY;
				break;
			}
		}
		InvalidateRect(_hWnd, NULL, true);
	}
	break;

	// 마우스 왼쪽 클릭 (눌려지고 있을때 여기)
	case WM_LBUTTONDOWN:
	{
		//마우스가 렉트안을 클릭했을 떄
		if (_rc.left < _ptMouse.x && _ptMouse.x < _rc.right &&
			_rc.top < _ptMouse.y && _ptMouse.y < _rc.bottom)
		{
			_flag = true;

			// 중점 구하기
			int centerX = (_rc.left + _rc.right) / 2;
			int centerY = (_rc.top + _rc.bottom) / 2;

			/* 사분면
			ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
			|		  |		   |
			|		  |		   |
			|	 1	  |	  2	   |
			|		  |		   |
			|		  |		   |
			ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
			|		  |		   |
			|		  |		   |
			|	 3	  |	  4	   |
			|		  |		   |
			|		  |		   |
			ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
			*/

			// 1 분면
			if (_ptMouse.x < centerX && _ptMouse.y < centerY)
			{
				_sect = 1;
				_disX = LOWORD(lParam) - _rc.left;
				_disY = HIWORD(lParam) - _rc.top;
			}
			// 2 분면
			if (_ptMouse.x > centerX && _ptMouse.y < centerY)
			{
				_sect = 2;
				_disX = LOWORD(lParam) - _rc.right;
				_disY = HIWORD(lParam) - _rc.top;
			}
			// 3 분면
			if (_ptMouse.x < centerX && _ptMouse.y > centerY)
			{
				_sect = 3;
				_disX = LOWORD(lParam) - _rc.left;
				_disY = HIWORD(lParam) - _rc.bottom;
			}
			// 4 분면
			if (_ptMouse.x > centerX && _ptMouse.y > centerY)
			{
				_sect = 4;
				_disX = LOWORD(lParam) - _rc.right;
				_disY = HIWORD(lParam) - _rc.bottom;
			}
		}
	}
	break;

	// 마우스 왼쪽 눌렀다 뗏을 때
	case WM_LBUTTONUP:
	{
		_flag = false;
	}
	break;

	// 키(아무)가 눌렸을 때
	case WM_KEYDOWN:
		// wParam - 모든 키 입력 및 마우스 클릭
		switch (wParam)
		{
			// ESC가 눌렸을 때
		case VK_ESCAPE:
		{
			PostQuitMessage(0);
		}
		break;
		}
		break;

		//윈도우 종료함수
	case WM_DESTROY:
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