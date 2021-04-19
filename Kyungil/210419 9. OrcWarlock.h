#pragma once
#include "210419 9. Orc.h"

class OrcWarlock : public Orc
{
public:
	OrcWarlock();
	~OrcWarlock();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

