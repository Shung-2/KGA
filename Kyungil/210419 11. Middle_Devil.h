#pragma once
#include "210419 11. Devil.h"
class Middle_Devil : public Devil

{
public:
	Middle_Devil();
	~Middle_Devil();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

