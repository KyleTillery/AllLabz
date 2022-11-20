#pragma once

#include "dwarf.h"
#include "human.h"
#include "elf.h"
#include "danceMan.h"
#include <memory>
#include "classes.h"
#include "IRace.h"

class IRace;


class Ijob
{
public:

    Ijob(std::shared_ptr<IRace> race) : m_reach(0), m_AttackDmg(0), m_race(race)
    {

    }

    std::shared_ptr<IRace> getrace();
    int getAttackDamage();
    int reach();

    virtual ~Ijob() {}
    std::shared_ptr<IRace> m_race;
    

protected:
	int m_AttackDmg;
    int m_reach;
	

};




