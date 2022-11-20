#include "Ijob.h"



std::shared_ptr<IRace> Ijob::getrace(){
    return m_race;
}

int Ijob::getAttackDamage()
{
    return m_AttackDmg;
}

int Ijob::reach()
{
    return m_reach;
}