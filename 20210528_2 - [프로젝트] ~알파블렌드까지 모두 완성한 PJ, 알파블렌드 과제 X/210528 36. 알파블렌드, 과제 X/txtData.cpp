// ############################################
// ## 210527 ���� ���� Save&Load, Loop Render ##
// ############################################

#include "stdafx.h"
#include "txtData.h"

txtData::txtData()
{
}

txtData::~txtData()
{
}

HRESULT txtData::init()
{
	return S_OK;
}

void txtData::release()
{
}

void txtData::txtSave(const char* saveFileName, vector<string> vStr)
{
	HANDLE file;
	DWORD write;

	char str[128];

	//126�� �ִ����� �ѱ��� 2byte�� �����÷ο츦 �����ϱ� ����
	strncpy_s(str, 128, vectorArrayCombine(vStr), 126);

	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);

	CloseHandle(file);
}

char* txtData::vectorArrayCombine(vector<string> vArray)
{
	// Combine - �����ϴ�
	char str[128];
	ZeroMemory(str, sizeof(str));
	
	for (int i = 0; i < vArray.size(); ++i)
	{
		strncat_s(str, 128, vArray[i].c_str(), 126);
		if (i + 1 < vArray.size()) strcat_s(str, ",");
		
		// �ؼ�
		// SpaceShip�� ĳ���� ����(X, Y, ��ü��, �ִ�ü��)�� �����Ѵٰ� ����
		// EX) 300, 500, 80, 100
		// vStr[0] = 300, vStr[1] = 500, vStr[2] = 80, vStr[3] = 100
		// ������ ������� 4�̸�, strncat_s�� ���ڿ� �̾� ���̴� �Լ�
		// if�� -> i = 0�̸�, if�� i=0�� �� (i+1, 1<4(���ͻ�����))���� �����ϱ� strncat_s�� ���� ,�� ���δ�.
		// ��� -> 300,500,80,100 �Ϸ�.
		// �̸� txtSave�� �Ѱ��ش�.
	}

	return str;
}

vector<string> txtData::txtLoad(const char* loadFileName)
{
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 128, &read, NULL);

	CloseHandle(file);

	return charArraySeparation(str);
}

// ,�� ���� ���� �Լ�
vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;
	char* temp;
	const char* separator = ",";
	char* token;

	token = strtok_s(charArray, separator, &temp);
	vArray.push_back(token);

	while (NULL != (token = strtok_s(NULL, separator, &temp)))
	{
		vArray.push_back(token);
	}

	return vArray;
}
