#pragma once

#include "classes.h"
#include "IRace.h"
#include <iostream>
#include <string>


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

	std::string race = "elf";

	std::string getRace();

};

