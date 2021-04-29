#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"

using namespace std;

//==================================
// ## ��ũ�� ó�� ## 21.04.23 ##
//==================================

#define WINNAME (LPTSTR)(TEXT("���� 28�� �̽ÿ� API"))
#define WINSTARTX 50	//������ â ������ǥ (left)
#define WINSTARTY 50	//������ â ������ǥ (top)
#define WINSIZEX 1024	//������ ����ũ��
#define WINSIZEY 800	//������ ����ũ��
#define WINSTYLE WS_CAPTION | WS_SYSMENU
#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}

//==================================
// ## extern ## 21.04.28 ##
//==================================
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;