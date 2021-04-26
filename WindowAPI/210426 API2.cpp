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

// 210426 - �簢�� ������ ���� RECT
// ���������� �����Ҳ��� �����ص� �����ϴ�!
// RECT _rc;

enum BOX
{
	BOX_FIRST,
	BOX_SECOND,
	BOX_END
};

BOX CURRENTBOX; // �� �̳ѹ��� ���� �ڽ��� ����Ѵ�.
RECT _rc[BOX_END], _rcIN;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
		// ������ â�� �� �ѹ� �����ɶ� ȣ��Ǵ� ��
	case WM_CREATE:
		_rc[BOX_FIRST] = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 100, 100);
		_rc[BOX_SECOND] = RectMakeCenter(WINSIZEX / 2 + 150, WINSIZEY / 2, 100, 100);
		_rcIN = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 50, 50);

		CURRENTBOX = BOX_FIRST;
		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// �簢�� ����
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
		// wParam - ��� Ű �Է� �� ���콺 Ŭ��
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;

			/*
			�������
			1. ���� �����̴� �簢�� �ȿ� ���� �簢���� �ִ�. ū �簢�� ������ �� ���� �簢���� �� �����ӿ� ���� ���� �ٴѴ�.
			2. ��� �簢���� ȭ�� ������ ���� �� ����.

			���� 1. �簢�� �б�.
			���� 2. �簢���� �����̴ٰ� �ٸ� �簢���̶� �ε�����. �ȿ� �ִ� ���� �簢���� �ٸ� �簢�� ������ �̵��ϴ��� �� �簢���� �����δ�.

			���� ���� 2.
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

		//������ â �μ��� �Լ� 
	case WM_DESTROY:
		//������ �����Լ�
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