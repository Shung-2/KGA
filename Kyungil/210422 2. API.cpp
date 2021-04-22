#include <Windows.h>

// 인스턴스 : 메모리 상에 할당되어 실행중인 프로그램, OS를 확인하기 위한 값
HINSTANCE _hInstance;

// 윈도우 핸들 : 대상끼리 구분하기 위해 사용한다.
HWND _hWnd;

// 윈도우 클래스 이름
LPCTSTR _lpszClass = TEXT("경일 28기 이시영 :-) ");

// 함수의 프로토 타입 선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// API (Application Programming Interface)
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
// WinMain의 역활
// 1. 윈도우창 세팅 후 화면에 띄우고
// 2. 메시지 루프

// 인자값 설명 
// hInstance - 인스턴스 핸들
// hPrevInstance - 이전에 실행된 인스턴드 핸들
// lpszCmdParam - 명령으로 입력된 프로그램 인수
// cmdShow - 프로그램이 시작될 형태
{
	_hInstance = hInstance;

	//메세지 구조체 : 운영체제에서 발행하는 메시지 정보를 저장하는 구조체
	MSG message;

	//윈도우 정보를 저장하기 위한 구조체
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;										// 클래스 여분 메모리
	wndClass.cbWndExtra = 0;										// 윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 윈도우 작업영역에 칠할 배경
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// 커서 지정
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// 타이틀바 좌상단에 보여줄 아이콘과 윈도우가 최소화 되었을 때 보여줄 아이콘
	wndClass.hInstance = hInstance;									// 윈도우 클래스를 등록한 인스턴스 등록
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						// 메시지를 처리하는 함수를 지정 (윈도우 프로시저)
	wndClass.lpszClassName = _lpszClass;							// 등록하고자 하는 윈도우 클래스 이름
	wndClass.lpszMenuName = NULL;									// 클래스로부터 만들어진 윈도우가 사용할 메뉴 지정
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						// 윈도우 클래스의 스타일 지정

	
	RegisterClass(&wndClass);	// 윈도우 클래스 정보를 등록해준다
								   
	_hWnd = CreateWindow(		   
		_lpszClass,				// 윈도우 클래스 이름
		_lpszClass,				// 윈도우 타이틀 바의 이름
		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
		50,						// 윈도우 시작좌표 Left
		50,						// 윈도우 시작좌표 top
		800,					// 윈도우 가로크기
		600,					// 윈도우 세로크기
		NULL,					// 부모 윈도우
		(HMENU)NULL,			// 메뉴 핸들
		hInstance,				// 인스턴스 지정
		NULL);

	ShowWindow(_hWnd, cmdShow); // 윈도우를 사용자 화면에 띄워준다

	// MSG = 운영체제에서 발생하는 메시지 정보를 저장히기 위한 구조체
	while (GetMessage(&message, 0, 0, 0)) // GetMessage 대기상태
	{
		TranslateMessage(&message);	// 키보드 입력메시지 처리를 담당
		DispatchMessage(&message);	// 윈도우 프로시저에 전달된 메시지를 실제 윈도우에 전달한다. 
	}
	return message.wParam;
}

// 윈도우 프로시저 : 메시지를 운영체제 강제로 전달하여 호출한다.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
// 인자값 설명 
// hWnd - 윈도우가 발생한 메시지인지 구분
// iMessage - 메시지 구분 번호
// wParam - 마우스 버튼의 상태와 키보드 조합키의 상태를 전달한다.
// lParam - 마우스 클릭 좌표를 전달한다.
{
	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{
	case WM_PAINT:
	{
		// 멀티바이트, 와이드 바이트, 유니코드
		// strlen	 = wcslen	   = _tcslen(문자열 길이)
		// strcmp	 = wcscmp	   = _tcscmp(문자열 비교)
		// strcpy	 = wcscpy	   = _tcscpy(문자열 복사)
		// strchr	 = wcschr	   = _tcschr(문자 찾기)
		// 등등..

		hdc = BeginPaint(hWnd, &ps);

		// 화면에 글자를 출력해보자
		TextOut(hdc, 50, 100, "무야호~", strlen("무야호~"));
		TextOut(hdc, 50, 150, "점심은 뭐먹을까?~", strlen("점심은 뭐먹을까?~"));
		TextOut(hdc, 250, 100, "2D 준비됐어 영?", strlen("2D 준비됐어 영?"));

		// RGB 색상 기본 참고
		// 0, 0, 0 검정
		// 255, 255, 255 하양
		SetTextColor(hdc, RGB(255, 0, 0));
		// 이 밑으로는 색칠되서 출력된다 :)

		// 매번 이렇게 출력할래? 놉, 변수 출력!
		const char* str = "실기 합격하고 싶다.";
		TextOut(hdc, 250, 150, str, strlen(str));

		// 선을 그어봅시다
		MoveToEx(hdc, 50, 50, NULL); // 50, 50에 시작점을 둔다
		LineTo(hdc, 100, 100);		 // 100, 100 선을 긋는다.
		LineTo(hdc, 150, 100);
		LineTo(hdc, 150, 300);
		 
		MoveToEx(hdc, 450, 50, NULL);
		LineTo(hdc, 300, 250);

		// 사각형 그리기 함수 == Rectangle();
		Rectangle(hdc, 10, 10, 100, 100);

		// 동그라미 그리기 함수 == Ellipse()
		Ellipse(hdc, 10, 10, 100, 100);

		// 과제
		// 1. 선과 도형으로 자기 이름을 그려보시오
		// 2. 도막사라무
		
		// 1. 이시영
		Ellipse(hdc, 30, 30, 60, 60);		// ㅇ
		MoveToEx(hdc, 75, 15, NULL);		// ㅣ
		LineTo(hdc, 75, 75);				// ㅣ

		MoveToEx(hdc, 100, 30, NULL);		// ㅅ
		LineTo(hdc, 82.5, 62.5);			// ㅅ
		MoveToEx(hdc, 100, 30, NULL);		// ㅅ
		LineTo(hdc, 117.5, 62.5);			// ㅅ
		MoveToEx(hdc, 135, 15, NULL);		// ㅣ
		LineTo(hdc, 135, 75);				// ㅣ

		Ellipse(hdc, 160, 30, 190, 60);		// ㅇ
		MoveToEx(hdc, 200, 37.5, NULL);		// ㅕ
		LineTo(hdc, 215, 37.5);				// ㅕ
		MoveToEx(hdc, 200, 50, NULL);		// ㅕ
		LineTo(hdc, 215, 50);				// ㅕ
		MoveToEx(hdc, 215, 25, NULL);		// ㅣ
		LineTo(hdc, 215, 70);				// ㅣ
		Ellipse(hdc, 180, 70, 210, 100);	// ㅇ

		// 2. 도막사라무
		Ellipse(hdc, 250, 150, 750, 550);	// 바깥쪽 원
		Ellipse(hdc, 275, 175, 725, 525);	// 안쪽 원

		MoveToEx(hdc, 500, 175, NULL);		// 정삼각형
		LineTo(hdc, 285, 400);
		LineTo(hdc, 715, 400);
		LineTo(hdc, 500, 175);

		MoveToEx(hdc, 500, 525, NULL);		// 뒤집은 정삼각형
		LineTo(hdc, 295, 275);
		LineTo(hdc, 702.5, 275);
		LineTo(hdc, 500, 525);

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