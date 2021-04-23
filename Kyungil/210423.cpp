#include <Windows.h>

HINSTANCE _hInstance;
HWND _hWnd;
LPCTSTR _lpszClass = TEXT("경일 28기 이시영 :-) ");
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
		
		// 펜(PEN)
		// 인자값(펜 스타일 / 굵기 / 색상)
		HPEN pen = CreatePen(PS_DOT, 5, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		
		MoveToEx(hdc, 100, 100, NULL);
		LineTo(hdc, 200, 200);
		
		SelectObject(hdc, oldPen);
		DeleteObject(pen);

		// 도형 색칠
		HBRUSH brush = CreateSolidBrush(RGB(50, 50, 100));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
		
		Ellipse(hdc, 200, 200, 400, 400);
		Rectangle(hdc, 10, 10, 100, 100);
		
		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		
		// 픽셀 1개를 찍는다는 전설의 SetPixel();
		SetPixel(hdc, 50, 50, RGB(255, 0, 0));
		for (int i = 0; i < 10; i++)
		{
			SetPixel(hdc, 50 + i, 50, RGB(255, 0, 0));
		}
		EndPaint(hWnd, &ps);
	}
	break;

	// 윈도우 창 부수는 화면
	case WM_DESTROY:
	{
		// 윈도우 종료 함수
		PostQuitMessage(0);
	}
	return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}