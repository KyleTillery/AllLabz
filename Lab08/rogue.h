#pragma once
#include "Ijob.h"
#include <memory>
#include "classes.h"
#include "IRace.h"

class IRace;

class rogue : public Ijob
{
public:

	rogue(std::shared_ptr<IRace> race) : Ijob(race)
	{
        m_AttackDmg = 10;
        m_reach = 2;
	}

    virtual ~rogue() {}
    rogue() = delete;

private:


};