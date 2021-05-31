// ############################################
// ## 210527 수업 내용 Save&Load, Loop Render ##
// ############################################

#include "stdafx.h"
#include "saveLoadTest.h"

saveLoadTest::saveLoadTest()
{
}

saveLoadTest::~saveLoadTest()
{
}
 
void saveLoadTest::update()
{
	//if (KEYMANAGER->isOnceKeyDown(VK_F1)) save();
	//if (KEYMANAGER->isOnceKeyDown(VK_F2)) load();
}

void saveLoadTest::save()
{
	// 파일 입출력에는 다양한 방식
	// C		- FILE * 기능없고 기능없어서인지 빠름
	// C++		- ifstream, ofstream - 기능 많고, 그래서인지 느림
	// WIN32	- CreateFile - 솔직히 보편적이진 않음.
	// Unity	- Json

	HANDLE file;
	DWORD write;

	char str[128] = "춘춘이는 준포폴도 있지만 팀포폴도 미리 생각해라";
	// 인자값(파일명, 속성, 공유모드설정, 보안의 속성,
	// 파일생성을 어떻게 할래?, 파일의 속성, ?)
	file = CreateFile("반장.txt", GENERIC_WRITE, FALSE,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	// 파일의 문자열 버퍼만큼
	WriteFile(file, str, strlen(str), &write, NULL);
	CloseHandle(file);
}

void saveLoadTest::load()
{
	HANDLE file;
	DWORD read;

	// 문자열 읽어들이는 버퍼수만큼 그때그때 동작할당하면 더 깔끔하고 좋다.
	char str[128];

	file = CreateFile("반장.txt", GENERIC_READ, FALSE,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	CloseHandle(file);

	// 3번째 인자 - 제목, MB_OK (라디오메시지)
	MessageBox(_hWnd, str, "담주 금요일 기획서 알죠?", MB_OK);
}