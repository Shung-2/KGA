#include "stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPCTSTR _lpszClass = TEXT("���� 28�� �̽ÿ� :-) ");

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
bool _flag;			// ���콺 Ŭ�� ����
int _sect;			// �и� ����
int _disX, _disY;	// �������� ���콺 Ŭ����ǥ �Ÿ��� �� ���� ���ϱ� ���� ����

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	char str[128];

	switch (iMessage)
	{
		// ������ â�� �����ɶ� �� �ѹ� ȣ��Ǵ� ��
	case WM_CREATE:
	{
		_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
	}
	break;

	// �׸��� �׷��ִ� ��
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		sprintf_s(str, "���콺 X : %d, ���콺 Y : %d", _ptMouse.x, _ptMouse.y);
		TextOut(hdc, 20, 20, str, strlen(str));

		Rectangle(hdc, _rc);
		EndPaint(hWnd, &ps);
	}
	break;

	// ���콺 �����̸� ���⼭ �޽��� �߻�
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

	// ���콺 ���� Ŭ�� (�������� ������ ����)
	case WM_LBUTTONDOWN:
	{
		//���콺�� ��Ʈ���� Ŭ������ ��
		if (_rc.left < _ptMouse.x && _ptMouse.x < _rc.right &&
			_rc.top < _ptMouse.y && _ptMouse.y < _rc.bottom)
		{
			_flag = true;

			// ���� ���ϱ�
			int centerX = (_rc.left + _rc.right) / 2;
			int centerY = (_rc.top + _rc.bottom) / 2;

			/* ��и�
			�ѤѤѤѤѤѤѤѤѤѤ�
			|		  |		   |
			|		  |		   |
			|	 1	  |	  2	   |
			|		  |		   |
			|		  |		   |
			�ѤѤѤѤѤѤѤѤѤѤ�
			|		  |		   |
			|		  |		   |
			|	 3	  |	  4	   |
			|		  |		   |
			|		  |		   |
			�ѤѤѤѤѤѤѤѤѤѤ�
			*/

			// 1 �и�
			if (_ptMouse.x < centerX && _ptMouse.y < centerY)
			{
				_sect = 1;
				_disX = LOWORD(lParam) - _rc.left;
				_disY = HIWORD(lParam) - _rc.top;
			}
			// 2 �и�
			if (_ptMouse.x > centerX && _ptMouse.y < centerY)
			{
				_sect = 2;
				_disX = LOWORD(lParam) - _rc.right;
				_disY = HIWORD(lParam) - _rc.top;
			}
			// 3 �и�
			if (_ptMouse.x < centerX && _ptMouse.y > centerY)
			{
				_sect = 3;
				_disX = LOWORD(lParam) - _rc.left;
				_disY = HIWORD(lParam) - _rc.bottom;
			}
			// 4 �и�
			if (_ptMouse.x > centerX && _ptMouse.y > centerY)
			{
				_sect = 4;
				_disX = LOWORD(lParam) - _rc.right;
				_disY = HIWORD(lParam) - _rc.bottom;
			}
		}
	}
	break;

	// ���콺 ���� ������ ���� ��
	case WM_LBUTTONUP:
	{
		_flag = false;
	}
	break;

	// Ű(�ƹ�)�� ������ ��
	case WM_KEYDOWN:
		// wParam - ��� Ű �Է� �� ���콺 Ŭ��
		switch (wParam)
		{
			// ESC�� ������ ��
		case VK_ESCAPE:
		{
			PostQuitMessage(0);
		}
		break;
		}
		break;

		//������ �����Լ�
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

	//�갡 ���� Ŭ���̾�Ʈ ���� ���� ���� �Լ�
	AdjustWindowRect(&winRect, WINSTYLE, false);

	//������ �������� �ٽ� �� �� ������ ��ġ ����ִ� �Լ�
	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left), (winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
}