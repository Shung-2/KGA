#include <Windows.h>

HINSTANCE _hInstance;
HWND _hWnd;
LPCTSTR _lpszClass = TEXT("���� 28�� �̽ÿ� :-) ");
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
	wndClass.lpszClassName = _lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		_lpszClass,
		_lpszClass,
		WS_OVERLAPPEDWINDOW,
		50,
		50,	
		800,
		600,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

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
		
		// ��(PEN)
		// ���ڰ�(�� ��Ÿ�� / ���� / ����)
		HPEN pen = CreatePen(PS_DOT, 5, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		
		MoveToEx(hdc, 100, 100, NULL);
		LineTo(hdc, 200, 200);
		
		SelectObject(hdc, oldPen);
		DeleteObject(pen);

		// ���� ��ĥ
		HBRUSH brush = CreateSolidBrush(RGB(50, 50, 100));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
		
		Ellipse(hdc, 200, 200, 400, 400);
		Rectangle(hdc, 10, 10, 100, 100);
		
		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		
		// �ȼ� 1���� ��´ٴ� ������ SetPixel();
		SetPixel(hdc, 50, 50, RGB(255, 0, 0));
		for (int i = 0; i < 10; i++)
		{
			SetPixel(hdc, 50 + i, 50, RGB(255, 0, 0));
		}
		EndPaint(hWnd, &ps);
	}
	break;

	// ������ â �μ��� ȭ��
	case WM_DESTROY:
	{
		// ������ ���� �Լ�
		PostQuitMessage(0);
	}
	return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}