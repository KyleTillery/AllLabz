#include <iostream>
#include <memory>
#include "classes.h"
#include "human.h"
#include "dwarf.h"
#include "danceMan.h"
#include "Ijob.h"
#include "wizard.h"
#include "rogue.h"
#include "fighter.h"
#include "cleric.h"
#include "characterFactory.h"
#include "elves.h"
#include "party.h"
#include "IRace.h"

using namespace std;

int main()
{
    Party Party1;
	Party Party2;

	std::shared_ptr<Ijob> val = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::WizardType, characterFactory::HalflingType);


    Party1.setMain(val);

    val = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::FigherType, characterFactory::DwarveType);

    

    Party1.addMember(val);

    std::vector<std::shared_ptr<Ijob> > member = Party1.getMember();


}