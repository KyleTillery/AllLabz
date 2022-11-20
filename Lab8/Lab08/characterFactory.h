#pragma once
#include "classes.h"
#include "Ijob.h"
#include <memory>
#include <map>
#include "IRace.h"

class IRace;

class characterFactory
{
    public:
        enum enumOfCharacter{WizardType, RogueType, FigherType, ClericType};
        enum raceOfCharacter{ElveType, DwarveType, HumanType, HalflingType};

        std::shared_ptr<Ijob> CreateCharacter(enumOfCharacter characterType, raceOfCharacter raceType);
        static characterFactory & GetCharacterFactory();

        characterFactory(const characterFactory &) = delete;
        characterFactory & operator = (const characterFactory &) = delete;

        auto getCharacterType();
        auto getRaceType();

    private:
        std::map<raceOfCharacter,std::shared_ptr<IRace>> m_raceMap;

        characterFactory();
        ~characterFactory();

        enumOfCharacter characterType;
        raceOfCharacter raceType;
};