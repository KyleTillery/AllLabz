#pragma once

#include <vector>
#include <memory>
#include "classes.h"
#include "IRace.h"
#include "Ijob.h"


// Declaration for the class 

//class Ijob;

class Party
{
private:
   // Data field
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

}; // end PlainBox