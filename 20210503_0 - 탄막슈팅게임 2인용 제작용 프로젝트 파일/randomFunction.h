#pragma once
#include "singletonBase.h"
#include <time.h>

class randomFunction : public singletonBase<randomFunction>
{
public:
	randomFunction()
	{
		srand(GetTickCount());
	}
	~randomFunction()
	{

	}

	inline int getInt(int num) { return rand() % num; }

	inline int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum) + fromNum;
	}
};