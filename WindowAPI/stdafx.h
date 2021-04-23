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

using namespace std;

//==================================
// ## ��ũ�� ó�� ## 21.04.23 ##
//==================================

#define WINNAME (LPTSTR)(TEXT("28�� API"))
#define WINSTARTX 50	// ������ â ������ǥ (LEFT)
#define WINSTARTY 50	// ������ â ������ǥ (TOP)
#define WINSIZEX 1024	// ������ ����ũ��
#define WINSIZEY 768	// ������ ����ũ��
#define WINSTYLE WS_CAPTION | WS_SYSMENU