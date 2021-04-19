#pragma once
#include "210419 8. Human.h"

class HumanNobility : public Human
{
public:
	HumanNobility();
	~HumanNobility();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

