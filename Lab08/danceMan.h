#pragma once
//danceMan

#include "classes.h"
#include "IRace.h"


class Halfling  : public IRace
{

public:
	Halfling() :  IRace(-2, -2, -2, +10)
	{

	}
    virtual ~Halfling() {}
	void hitPointMod();

	void armorMod();

	void hitBonusMod();

	void initiaveBonus();

};