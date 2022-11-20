#pragma once

#include <vector>
#include <memory>
#include "classes.h"
#include "IRace.h"
#include "Ijob.h"
#include <iostream>


// Declaration for the class 

//class Ijob;

class Party
{
private:
   // Data field
   std::shared_ptr<Ijob> m_topLeft;
   std::shared_ptr<Ijob> m_topRight;
   std::shared_ptr<Ijob> m_bottomLeft;
   std::shared_ptr<Ijob> m_bottomRight;
   std::shared_ptr<Ijob> m_Main;
   std::vector<std::shared_ptr<Ijob>> m_Members;
   
public:
   // Default constructor
    Party();
   
   // Parameterized constructor
    Party(const std::shared_ptr<Ijob> flagship);
   
   // Mutator method that can change the value of the data field
   void setMain(const std::shared_ptr<Ijob>  theItem);
   
   // Accessor method to get the value of the data field
   std::shared_ptr<Ijob> getMain() const;

   void addMember(const std::shared_ptr<Ijob> theItem);

   std::vector<std::shared_ptr<Ijob>> getMember();

   
   virtual int attack(std::shared_ptr<Ijob> player);
   virtual void takeDamage(int m_AttackDmg, std::shared_ptr<Ijob> player, int roll);
   virtual int checkAlive(std::shared_ptr<Ijob> player);

}; // end PlainBox