#pragma once
#include "Ijob.h"
#include <memory>
#include "classes.h"
#include "IRace.h"

class IRace;

class wizard : public Ijob
{
public:

	wizard(std::shared_ptr<IRace> race) : Ijob(race)
	{
        m_AttackDmg = 7;
        m_reach = 2;
	}

    virtual ~wizard() {}
    wizard() = delete;

private:


};