#pragma once
#include "210419 8. Human.h"

class HumanAssassin : public Human
{
public:
	HumanAssassin();
	~HumanAssassin();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

