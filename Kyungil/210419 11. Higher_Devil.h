#pragma once
#include "210419 11. Devil.h"
class Higher_Devil : public Devil
{
public:
	Higher_Devil();
	~Higher_Devil();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

