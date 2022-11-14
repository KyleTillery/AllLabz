#include "characterFactory.h"
#include "Ijob.h"
#include "classes.h"
#include "cleric.h"
#include "wizard.h"
#include "fighter.h"
#include "rogue.h"
#include "elves.h"

class IRace;

characterFactory & characterFactory::GetCharacterFactory()
{
   static characterFactory s;
   return s;
}
std::shared_ptr<Ijob> characterFactory::CreateCharacter(enumOfCharacter enumOfTypeCharacterType, raceOfCharacter race)
{
	std::shared_ptr<Ijob> retVal = nullptr;
	if (enumOfTypeCharacterType == WizardType)
	{
		retVal = std::make_shared<wizard>(m_raceMap[race]);
	}
    else if (enumOfTypeCharacterType == RogueType)
    {
        retVal = std::make_shared<rogue>(m_raceMap[race]); 
    }else if (enumOfTypeCharacterType == FigherType)
    {
        retVal = std::make_shared<fighter>(m_raceMap[race]); 
    }else if (enumOfTypeCharacterType == ClericType)
    {
        retVal = std::make_shared<cleric>(m_raceMap[race]); 
    }

	return retVal;
}

characterFactory::characterFactory() 
{
		
	std::shared_ptr<IRace> t1 = std::make_shared<dwarf>();
	std::shared_ptr<IRace> t2 = std::make_shared<Human>();
    std::shared_ptr<IRace> t3 = std::make_shared<Halfling>();
    std::shared_ptr<IRace> t4 = std::make_shared<elf>();
	m_raceMap.insert(std::pair(DwarveType, t1));
	m_raceMap[HumanType]= t2;
    m_raceMap[HalflingType]= t3;
    m_raceMap[ElveType]= t4;
}


 characterFactory::~characterFactory() 
{

}