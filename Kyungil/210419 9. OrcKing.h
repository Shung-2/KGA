#pragma once
#include "210419 9. Orc.h"

class OrcKing : public Orc
{
public:
	OrcKing();
	~OrcKing();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

