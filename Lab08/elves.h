#pragma once

#include "classes.h"
#include "IRace.h"


class elf  : public IRace
{

public:
	elf() :  IRace(-1, 0, +1, +1)
	{

	}
    virtual ~elf() {}
	void hitPointMod();

	void armorMod();

	void hitBonusMod();

	void initiaveBonus();

};

