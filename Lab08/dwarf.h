#pragma once

#include "classes.h"
#include "IRace.h"



class dwarf  : public IRace
{

public:
	dwarf() :  IRace(+1, +1, 0, -1)
	{

	}
    virtual ~dwarf() {}

	void hitPointMod();

	void armorMod();

	void hitBonusMod();

	void initiaveBonus();

};


