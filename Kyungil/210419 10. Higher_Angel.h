#pragma once
#include "210419 10. Angel.h"

class Higher_Angel : public Angel
{
public:
	Higher_Angel();
	~Higher_Angel();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

