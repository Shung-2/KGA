#pragma once
#include "210419 5. Elf.h"

class ElfArcher : public Elf
{
public:
	ElfArcher();
	~ElfArcher();

	virtual void QSkill();
	virtual void WSkill();
	virtual void ESkill();
	virtual void RSkill();

	void Output();
};

