// ############################################
// ## 210527 수업 내용 Save&Load, Loop Render ##
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

	//126을 넣는이유 한글은 2byte라 오버플로우를 방지하기 위함
	strncpy_s(str, 128, vectorArrayCombine(vStr), 126);

	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);

	CloseHandle(file);
}

char* txtData::vectorArrayCombine(vector<string> vArray)
{
	// Combine - 조합하다
	char str[128];
	ZeroMemory(str, sizeof(str));
	
	for (int i = 0; i < vArray.size(); ++i)
	{
		strncat_s(str, 128, vArray[i].c_str(), 126);
		if (i + 1 < vArray.size()) strcat_s(str, ",");
		
		// 해석
		// SpaceShip의 캐릭터 정보(X, Y, 현체력, 최대체력)를 저장한다고 하자
		// EX) 300, 500, 80, 100
		// vStr[0] = 300, vStr[1] = 500, vStr[2] = 80, vStr[3] = 100
		// 벡터의 사이즈는 4이며, strncat_s은 문자열 이어 붙이는 함수
		// if문 -> i = 0이며, if문 i=0일 때 (i+1, 1<4(벡터사이즈))보다 작으니까 strncat_s을 통해 ,를 붙인다.
		// 결과 -> 300,500,80,100 완료.
		// 이를 txtSave로 넘겨준다.
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

// ,를 때기 위한 함수
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
