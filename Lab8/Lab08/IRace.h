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
    virtual void setHp(int hp);
    virtual int getIni();

    ~IRace() {}
protected:
	int m_HitPoints;
    int m_armor;
    int m_HitBonus;
    int m_initiative;
};