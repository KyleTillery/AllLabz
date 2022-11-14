#pragma once


#include <memory>



class IRace
{
public:
	IRace(int HitPoints, int  armor, int  HitBonus, int initiative)	{
        m_HitPoints = HitPoints + 10;
        m_armor = armor + 10;
        m_HitBonus = HitBonus;
        m_initiative = initiative;
    }

	virtual int getHP();
    virtual int getArmorClass();
    virtual int getHitBonus();
    virtual void attack(int m_reach);
    virtual void takeDamage(int m_AttackDmg);;

    ~IRace() {}
protected:
	int m_HitPoints;
    int m_armor;
    int m_HitBonus;
    int m_initiative;
};