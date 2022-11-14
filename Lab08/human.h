#pragma once

#include "classes.h"
#include "IRace.h"



class Human  : public IRace
{

public:
	Human() :  IRace(0, 0, +1, 0)
	{

	}
    virtual ~Human() {}

	void hitPointMod();

	void armorMod();

	void hitBonusMod();

	void initiaveBonus();
	

};