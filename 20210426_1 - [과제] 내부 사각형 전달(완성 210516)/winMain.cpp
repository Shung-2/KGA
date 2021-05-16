#include "stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPCTSTR _lpszClass = TEXT("눈누난나");

void setWindowsSize(int x, int y, int width, int height);

//함수의 프로토 타입 선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Application Programming Interface
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{
	_hInstance = hInstance;

	//메세지 구조체 : 운영체제에서 발행하는 메시지 정보를 저장하는 구조체
	MSG message;

	//윈도우 정보를 저장하기 위한 구조체
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;	//클래스 여분 메모리
	wndClass.cbWndExtra = 0;	//윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;	//인스턴스 등록
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//윈도우 클래스 정보를 등록해준다
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		WINNAME,				//윈도우 클래스 이름
		WINNAME,				//윈도우 타이틀 바의 이름
		WS_OVERLAPPEDWINDOW,	//윈도우 스타일
		WINSTARTX,				//윈도우 시작좌표 Left
		WINSTARTY,				//윈도우 시작좌표 top
		WINSIZEX,				//윈도우 가로크기
		WINSIZEY,				//윈도우 세로크기
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	//윈도우를 정말 화면에 띄워준다
	ShowWindow(_hWnd, cmdShow);

	//
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

// BOX ENUM문을 만들어준다.
enum BOX
{
	BOX_FIRST,	// VALUE = 0
	BOX_SECOND, // VALUE = 1
	BOX_END		// VALUE = 2
};

BOX CURRENTBOX;					// ENUM문 BOX를 사용하는 'CURRENTBOX'를 생성
RECT _rc[BOX_END], _rcIN;		// _rc[BOX_END](2)의 크기만큼의 RECT와 _rcIn(내부박스) 생성

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
	// 윈도우 창이 딱 한번 생성될때 호출된다.
	case WM_CREATE:
		
		// 초기화 (순서 =  왼쪽 박스, 오른쪽 박스, 내부 박스)
		_rc[BOX_FIRST] = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 100, 100);
		_rc[BOX_SECOND] = RectMakeCenter(WINSIZEX / 2 + 150, WINSIZEY / 2, 100, 100);
		_rcIN = RectMakeCenter(WINSIZEX / 2 - 150, WINSIZEY / 2, 50, 50);
		
		// 선택된 박스(CURRENTBOX)에 BOX_FIRST(왼쪽 박스) 삽입
		CURRENTBOX = BOX_FIRST;
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// _rc 출력 (왼쪽, 오른쪽 박스)
		for (int i = 0; i < BOX_END; i++)
		{
			Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
		}

		// _rcIn(내부박스) 출력
		Rectangle(hdc, _rcIN.left, _rcIN.top, _rcIN.right, _rcIN.bottom);

		EndPaint(hWnd, &ps);
		break;
	}
	break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			// ESC 누를 시 종료
			PostQuitMessage(0);
			break;

		case VK_LEFT: // 왼

			// CURRENTBOX == 선택된 박스.
			// _rc[BOX_END]의 CURRENTBOX=(BOX_FIRST)
			_rc[CURRENTBOX].left -= 5;
			_rc[CURRENTBOX].right -= 5;

			// 내부 박스 이동 조건
			if (_rcIN.right > _rc[CURRENTBOX].right)
			{
				int width = _rcIN.right - _rcIN.left;
				_rcIN.right = _rc[CURRENTBOX].right;
				_rcIN.left = _rcIN.right - width;
			}
			break;

		case VK_RIGHT: // 오
			
			// CURRENTBOX == 선택된 박스.
			// _rc[BOX_END]의 CURRENTBOX=(BOX_FIRST)
			_rc[CURRENTBOX].left += 5;
			_rc[CURRENTBOX].right += 5;

			// 내부 박스 이동 조건
			if (_rcIN.left < _rc[CURRENTBOX].left)
			{
				int width = _rcIN.right - _rcIN.left;
				_rcIN.left = _rc[CURRENTBOX].left;
				_rcIN.right = _rcIN.left + width;
			}
			break;

		case VK_UP: // 위

			// CURRENTBOX == 선택된 박스.
			// _rc[BOX_END]의 CURRENTBOX=(BOX_FIRST)
			_rc[CURRENTBOX].top -= 5;
			_rc[CURRENTBOX].bottom -= 5;

			// 내부 박스 이동 조건
			if (_rcIN.bottom > _rc[CURRENTBOX].bottom)
			{
				int height = _rcIN.bottom - _rcIN.top;
				_rcIN.bottom = _rc[CURRENTBOX].bottom;
				_rcIN.top = _rcIN.bottom - height;
			}
			break;

		case VK_DOWN: // 아래

			// CURRENTBOX == 선택된 박스.
			// _rc[BOX_END]의 CURRENTBOX=(BOX_FIRST)
			_rc[CURRENTBOX].top += 5;
			_rc[CURRENTBOX].bottom += 5;

			// 내부 박스 이동 조건
			if (_rcIN.top < _rc[CURRENTBOX].top)
			{
				int height = _rcIN.bottom - _rcIN.top;
				_rcIN.top = _rc[CURRENTBOX].top;					
				_rcIN.bottom = _rcIN.top + height;
			}
			break;
		}

		// IntersectRect를 이용한 충돌처리
		RECT temp;

		// _rc[BOX_FIRST]와 _rc[BOX_SECOND]가 충돌할 경우
		// > 즉 왼쪽 박스와 오른쪽 박스가 충돌할경우
		if (IntersectRect(&temp, &_rc[BOX_FIRST], &_rc[BOX_SECOND]))
		{
			switch (CURRENTBOX)
			{
			
			// 왼쪽 박스일 경우
			case BOX_FIRST: 
				CURRENTBOX = BOX_SECOND; // BOX_SECOND를 선택된 박스로 변경한다. 
				break;
			
			case BOX_SECOND:
				CURRENTBOX = BOX_FIRST; // BOX_FIRST를 선택된 박스로 변경한다. 
				break;
			}

			// 이후 _rcIn(내부박스)를 재생성한다. CURRENTBOX를 기준으로!
			_rcIN = RectMakeCenter((_rc[CURRENTBOX].right + _rc[CURRENTBOX].left) / 2,
				(_rc[CURRENTBOX].top + _rc[CURRENTBOX].bottom) / 2, 50, 50);
		}
		InvalidateRect(_hWnd, NULL, true);
		break;

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
	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
}