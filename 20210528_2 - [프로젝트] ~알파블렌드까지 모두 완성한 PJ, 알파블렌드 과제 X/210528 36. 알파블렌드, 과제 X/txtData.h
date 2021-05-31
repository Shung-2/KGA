// ############################################
// ## 210527 수업 내용 Save&Load, Loop Render ##
// ############################################

#pragma once
#include "singletonBase.h"
#include <vector>
#include <string>

class txtData : public singletonBase<txtData>
{
public:
	txtData();
	~txtData();

	HRESULT init();
	void release();

	// SAVE
	void txtSave(const char* saveFileName, vector<string> vStr);
	char* vectorArrayCombine(vector<string> vArray);
	
	// LOAD
	vector<string> txtLoad(const char* loadFileName);
	vector<string> charArraySeparation(char charArray[]);
};