#include "stdafx.h"
#include "playGround.h"

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse;

playGround _pg;

void setWindowsSize(int x, int y, int width, int height);

//�Լ��� ������ Ÿ�� ����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Application Programming Interface
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int cmdShow)
{
	_hInstance = hInstance;

	//�޼��� ����ü : �ü������ �����ϴ� �޽��� ������ �����ϴ� ����ü
	MSG message;

	//������ ������ �����ϱ� ���� ����ü
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;	//Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;	//������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;	//�ν��Ͻ� ���
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//������ Ŭ���� ������ ������ش�
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(WINNAME, WINNAME, WS_OVERLAPPEDWINDOW, WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY, NULL, (HMENU)NULL, hInstance, NULL);


	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	//�����츦 ���� ȭ�鿡 ����ش�
	ShowWindow(_hWnd, cmdShow);

	if (FAILED(_pg.init()))
	{
		return NULL;
	}

	//
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	_pg.release();

	UnregisterClass(WINNAME, _hInstance);

	return message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _pg.MainProc(hWnd, iMessage, wParam, lParam);
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
	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
}