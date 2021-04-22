#include <Windows.h>

// �ν��Ͻ� : �޸� �� �Ҵ�Ǿ� �������� ���α׷�, OS�� Ȯ���ϱ� ���� ��
HINSTANCE _hInstance;

// ������ �ڵ� : ��󳢸� �����ϱ� ���� ����Ѵ�.
HWND _hWnd;

// ������ Ŭ���� �̸�
LPCTSTR _lpszClass = TEXT("���� 28�� �̽ÿ� :-) ");

// �Լ��� ������ Ÿ�� ����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// API (Application Programming Interface)
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
// WinMain�� ��Ȱ
// 1. ������â ���� �� ȭ�鿡 ����
// 2. �޽��� ����

// ���ڰ� ���� 
// hInstance - �ν��Ͻ� �ڵ�
// hPrevInstance - ������ ����� �ν��ϵ� �ڵ�
// lpszCmdParam - ������� �Էµ� ���α׷� �μ�
// cmdShow - ���α׷��� ���۵� ����
{
	_hInstance = hInstance;

	//�޼��� ����ü : �ü������ �����ϴ� �޽��� ������ �����ϴ� ����ü
	MSG message;

	//������ ������ �����ϱ� ���� ����ü
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;										// Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;										// ������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ������ �۾������� ĥ�� ���
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// Ŀ�� ����
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// Ÿ��Ʋ�� �»�ܿ� ������ �����ܰ� �����찡 �ּ�ȭ �Ǿ��� �� ������ ������
	wndClass.hInstance = hInstance;									// ������ Ŭ������ ����� �ν��Ͻ� ���
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						// �޽����� ó���ϴ� �Լ��� ���� (������ ���ν���)
	wndClass.lpszClassName = _lpszClass;							// ����ϰ��� �ϴ� ������ Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;									// Ŭ�����κ��� ������� �����찡 ����� �޴� ����
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						// ������ Ŭ������ ��Ÿ�� ����

	
	RegisterClass(&wndClass);	// ������ Ŭ���� ������ ������ش�
								   
	_hWnd = CreateWindow(		   
		_lpszClass,				// ������ Ŭ���� �̸�
		_lpszClass,				// ������ Ÿ��Ʋ ���� �̸�
		WS_OVERLAPPEDWINDOW,	// ������ ��Ÿ��
		50,						// ������ ������ǥ Left
		50,						// ������ ������ǥ top
		800,					// ������ ����ũ��
		600,					// ������ ����ũ��
		NULL,					// �θ� ������
		(HMENU)NULL,			// �޴� �ڵ�
		hInstance,				// �ν��Ͻ� ����
		NULL);

	ShowWindow(_hWnd, cmdShow); // �����츦 ����� ȭ�鿡 ����ش�

	// MSG = �ü������ �߻��ϴ� �޽��� ������ �������� ���� ����ü
	while (GetMessage(&message, 0, 0, 0)) // GetMessage ������
	{
		TranslateMessage(&message);	// Ű���� �Է¸޽��� ó���� ���
		DispatchMessage(&message);	// ������ ���ν����� ���޵� �޽����� ���� �����쿡 �����Ѵ�. 
	}
	return message.wParam;
}

// ������ ���ν��� : �޽����� �ü�� ������ �����Ͽ� ȣ���Ѵ�.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
// ���ڰ� ���� 
// hWnd - �����찡 �߻��� �޽������� ����
// iMessage - �޽��� ���� ��ȣ
// wParam - ���콺 ��ư�� ���¿� Ű���� ����Ű�� ���¸� �����Ѵ�.
// lParam - ���콺 Ŭ�� ��ǥ�� �����Ѵ�.
{
	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
	case WM_PAINT:
	{
		// ��Ƽ����Ʈ, ���̵� ����Ʈ, �����ڵ�
		// strlen	 = wcslen	   = _tcslen(���ڿ� ����)
		// strcmp	 = wcscmp	   = _tcscmp(���ڿ� ��)
		// strcpy	 = wcscpy	   = _tcscpy(���ڿ� ����)
		// strchr	 = wcschr	   = _tcschr(���� ã��)
		// ���..

		hdc = BeginPaint(hWnd, &ps);

		// ȭ�鿡 ���ڸ� ����غ���
		TextOut(hdc, 50, 100, "����ȣ~", strlen("����ȣ~"));
		TextOut(hdc, 50, 150, "������ ��������?~", strlen("������ ��������?~"));
		TextOut(hdc, 250, 100, "2D �غ�ƾ� ��?", strlen("2D �غ�ƾ� ��?"));

		// RGB ���� �⺻ ����
		// 0, 0, 0 ����
		// 255, 255, 255 �Ͼ�
		SetTextColor(hdc, RGB(255, 0, 0));
		// �� �����δ� ��ĥ�Ǽ� ��µȴ� :)

		// �Ź� �̷��� ����ҷ�? ��, ���� ���!
		const char* str = "�Ǳ� �հ��ϰ� �ʹ�.";
		TextOut(hdc, 250, 150, str, strlen(str));

		// ���� �׾�ô�
		MoveToEx(hdc, 50, 50, NULL); // 50, 50�� �������� �д�
		LineTo(hdc, 100, 100);		 // 100, 100 ���� �ߴ´�.
		LineTo(hdc, 150, 100);
		LineTo(hdc, 150, 300);
		 
		MoveToEx(hdc, 450, 50, NULL);
		LineTo(hdc, 300, 250);

		// �簢�� �׸��� �Լ� == Rectangle();
		Rectangle(hdc, 10, 10, 100, 100);

		// ���׶�� �׸��� �Լ� == Ellipse()
		Ellipse(hdc, 10, 10, 100, 100);

		// ����
		// 1. ���� �������� �ڱ� �̸��� �׷����ÿ�
		// 2. �������
		
		// 1. �̽ÿ�
		Ellipse(hdc, 30, 30, 60, 60);		// ��
		MoveToEx(hdc, 75, 15, NULL);		// ��
		LineTo(hdc, 75, 75);				// ��

		MoveToEx(hdc, 100, 30, NULL);		// ��
		LineTo(hdc, 82.5, 62.5);			// ��
		MoveToEx(hdc, 100, 30, NULL);		// ��
		LineTo(hdc, 117.5, 62.5);			// ��
		MoveToEx(hdc, 135, 15, NULL);		// ��
		LineTo(hdc, 135, 75);				// ��

		Ellipse(hdc, 160, 30, 190, 60);		// ��
		MoveToEx(hdc, 200, 37.5, NULL);		// ��
		LineTo(hdc, 215, 37.5);				// ��
		MoveToEx(hdc, 200, 50, NULL);		// ��
		LineTo(hdc, 215, 50);				// ��
		MoveToEx(hdc, 215, 25, NULL);		// ��
		LineTo(hdc, 215, 70);				// ��
		Ellipse(hdc, 180, 70, 210, 100);	// ��

		// 2. �������
		Ellipse(hdc, 250, 150, 750, 550);	// �ٱ��� ��
		Ellipse(hdc, 275, 175, 725, 525);	// ���� ��

		MoveToEx(hdc, 500, 175, NULL);		// ���ﰢ��
		LineTo(hdc, 285, 400);
		LineTo(hdc, 715, 400);
		LineTo(hdc, 500, 175);

		MoveToEx(hdc, 500, 525, NULL);		// ������ ���ﰢ��
		LineTo(hdc, 295, 275);
		LineTo(hdc, 702.5, 275);
		LineTo(hdc, 500, 525);

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