// ############################################
// ## 210527 ���� ���� Save&Load, Loop Render ##
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
	// ���� ����¿��� �پ��� ���
	// C		- FILE * ��ɾ��� ��ɾ������ ����
	// C++		- ifstream, ofstream - ��� ����, �׷������� ����
	// WIN32	- CreateFile - ������ ���������� ����.
	// Unity	- Json

	HANDLE file;
	DWORD write;

	char str[128] = "�����̴� �������� ������ �������� �̸� �����ض�";
	// ���ڰ�(���ϸ�, �Ӽ�, ������弳��, ������ �Ӽ�,
	// ���ϻ����� ��� �ҷ�?, ������ �Ӽ�, ?)
	file = CreateFile("����.txt", GENERIC_WRITE, FALSE,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	// ������ ���ڿ� ���۸�ŭ
	WriteFile(file, str, strlen(str), &write, NULL);
	CloseHandle(file);
}

void saveLoadTest::load()
{
	HANDLE file;
	DWORD read;

	// ���ڿ� �о���̴� ���ۼ���ŭ �׶��׶� �����Ҵ��ϸ� �� ����ϰ� ����.
	char str[128];

	file = CreateFile("����.txt", GENERIC_READ, FALSE,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	CloseHandle(file);

	// 3��° ���� - ����, MB_OK (�����޽���)
	MessageBox(_hWnd, str, "���� �ݿ��� ��ȹ�� ����?", MB_OK);
}