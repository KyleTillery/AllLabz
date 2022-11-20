
#include "IRace.h"


int IRace::getHP()
{
    return m_HitPoints;
}
int IRace::getArmorClass(){
    return m_armor;
}
int IRace::getHitBonus(){
    return m_HitBonus;
}

void IRace::setHp(int hp)
{
    m_HitPoints = hp;
}

int IRace::getIni()
{
    return m_initiative;
}
