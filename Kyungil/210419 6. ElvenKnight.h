#pragma once
#include "210419 5. Elf.h"

class ElvenKnight : public Elf
{
public:
	ElvenKnight();
	~ElvenKnight();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};