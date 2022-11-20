#pragma once
#include "Ijob.h"
#include <memory>
#include "classes.h"
#include "IRace.h"

class IRace;

class cleric : public Ijob
{
public:

	cleric(std::shared_ptr<IRace> race) : Ijob(race)
	{
        m_AttackDmg = 3;
        m_reach = 2;
	}

    virtual ~cleric() {}
    cleric() = delete;

private:


};