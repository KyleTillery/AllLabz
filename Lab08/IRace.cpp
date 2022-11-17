
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
void IRace::attack(int reach){
    //if statment saying if it can attack the back or front
}
void IRace::takeDamage(int attack){
    m_HitPoints = m_HitPoints - attack;
}
