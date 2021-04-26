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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	// wParam - ��� Ű �Է� �� ���콺 Ŭ��
	// lParam - ���콺 ��ǥ

	// �ȿ��� ȣ���� �� static�� �� ��������
	static RECT rc;
	static RECT rc2;
	static RECT rc3;

	switch (iMessage)
	{
		// ������ â�� �� �ѹ� �����ɶ� ȣ��Ǵ� ��
	case WM_CREATE:
		rc = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 100, 100);
		rc2 = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
		rc3 = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 50, 50);

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// �簢�� ����
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		Rectangle(hdc, rc2.left, rc2.top, rc2.right, rc2.bottom);
		Rectangle(hdc, rc3.left, rc3.top, rc3.right, rc3.bottom);

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
		
		���� ���� 1.
		*/

		case VK_LEFT:
			// ���� �� �ٱ����� ��������
			if (rc.left <= 0) break;
			if (rc2.left <= 0) break;

			// ���ιڽ� �浹 ����
			rc.left -= 10;
			rc.right -= 10;
			if (rc3.right > rc.right)
			{
				rc3.left -= 10;
				rc3.right -= 10;
			}

			// ����Ű ���� �� �ڽ� �浹
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
			// ������ �� �ٱ����� ��������
			if (rc.right >= WINSIZEX) break;
			if (rc2.right >= WINSIZEX) break;

			// ���ιڽ� �浹 ����
			rc.left += 10;
			rc.right += 10;
			if (rc3.left < rc.left)
			{
				rc3.left += 10;
				rc3.right += 10;
			}

			// ������Ű ���� �� �ڽ� �浹
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
			// ���� �� �ٱ����� ��������
			if (rc.top <= 0) break;
			if (rc2.top <= 0) break;

			// ���ιڽ� �浹 ����
			rc.top -= 10;
			rc.bottom -= 10;
			if (rc3.bottom > rc.bottom)
			{
				rc3.top -= 10;
				rc3.bottom -= 10;
			}

			// ����Ű ���� �� �ڽ� �浹
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
			// �Ʒ��� �� �ٱ����� ��������
			if (rc.bottom >= WINSIZEY) break;
			if (rc2.bottom >= WINSIZEY) break;

			// ���ιڽ� �浹 ����
			rc.top += 10;
			rc.bottom += 10;
			if (rc3.top < rc.top)
			{
				rc3.top += 10;
				rc3.bottom += 10;
			}

			// �Ʒ�Ű ���� �� �ڽ� �浹
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