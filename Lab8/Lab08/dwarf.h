#pragma once

#include "classes.h"
#include "IRace.h"
#include <iostream>
#include <string>



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

	std::string race = "dwarf";

	std::string getRace();

};


