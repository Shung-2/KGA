#pragma once
#include "210419 10. Angel.h"
class Middle_Angel : public Angel
{
public:
	Middle_Angel();
	~Middle_Angel();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

