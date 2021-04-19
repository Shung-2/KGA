#pragma once
#include <iostream>
using namespace std;
class Devil
{
protected:
	int _hp;
	int _mp;
	int _ad;
	int _ap;

public:
	Devil();
	~Devil();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

