#include "party.h"
#include "IRace.h"
#include <cmath>

class Ijob;
Party::Party()
{
}  // end default constructor


Party::Party(const std::shared_ptr<Ijob> theItem) : m_Main(theItem)
{
}  // end constructor


void Party::setMain(const std::shared_ptr<Ijob> theItem)
{
    m_Main = theItem;
}  // end setItem


std::shared_ptr<Ijob> Party::getMain() const
{
   return m_Main;
}  // end getItem


void Party::addMember(const std::shared_ptr<Ijob> theItem)
{ 
    m_Members.push_back(theItem);
}

std::vector<std::shared_ptr<Ijob>> Party::getMember()
{
    return m_Members;
}

int Party::attack(std::shared_ptr<Ijob> player){
    int attackdamage;
    attackdamage = player->getAttackDamage();
    
    
}

void Party::takeDamage(int attack, std::shared_ptr<Ijob> player, int roll){
    int health;
    int thething;
    auto race = player->getrace();
    health = race->getHP();
    if (roll >= race->getArmorClass()){
        health = health - attack;
        race->setHp(health);
    }else{
        std::cout << roll <<" dosn't beat " << race->getArmorClass() << " you miss\n";
    }
    
}

int Party::checkAlive(std::shared_ptr<Ijob> player){
    auto race = player->getrace();
    if (race->getHP() > 0){
        std::cout << "new health is: " << race->getHP() << "\n";
        return 0;
    }else{
        std::cout << "character is dead\n";
        return 1;
    }
}

