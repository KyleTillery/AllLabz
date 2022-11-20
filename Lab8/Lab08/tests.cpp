#include <gtest/gtest.h>
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
#include <cstdlib>

TEST(dndTests, job1)
{
    Party Party;
    std::shared_ptr<Ijob> guy = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::WizardType, characterFactory::HalflingType);
    int dmg = guy->getAttackDamage();
    ASSERT_EQ(dmg,7);
    int reach = guy->reach();
    ASSERT_EQ(reach, 2);

}
TEST(dndTests, job2)
{
    Party Party;
    std::shared_ptr<Ijob> guy = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::RogueType, characterFactory::DwarveType);
    int dmg = guy->getAttackDamage();
    ASSERT_EQ(dmg,5);
    int reach = guy->reach();
    ASSERT_EQ(reach, 2);
}
TEST(dndTests, race1)
{
    Party Party;
    std::shared_ptr<Ijob> guy = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::WizardType, characterFactory::HalflingType);
    std::shared_ptr<IRace> race = guy->getrace();
    int ac = race->getArmorClass();
    ASSERT_EQ(ac, 8);
    int hb = race->getHitBonus();
    ASSERT_EQ(hb, -2);
    int hp = race->getHP();
    ASSERT_EQ(hp, 8);
    int ini = race->getIni();
    ASSERT_EQ(ini, 10);
    race->setHp(2);
    hp = race->getHP();
    ASSERT_EQ(hp, 2);
}
TEST(dndTests, race2)
{
    Party Party;
    std::shared_ptr<Ijob> guy = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::WizardType, characterFactory::HumanType);
    std::shared_ptr<IRace> race = guy->getrace();
    int ac = race->getArmorClass();
    ASSERT_EQ(ac, 10);
    int hb = race->getHitBonus();
    ASSERT_EQ(hb, 1);
    int hp = race->getHP();
    ASSERT_EQ(hp, 10);
    int ini = race->getIni();
    ASSERT_EQ(ini, 0);
    race->setHp(2);
    hp = race->getHP();
    ASSERT_EQ(hp, 2);
}
TEST(dndTests, party1)
{
    Party Party;
    std::shared_ptr<Ijob> guy = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::WizardType, characterFactory::HalflingType);
    std::shared_ptr<IRace> race = guy->getrace();
    std::shared_ptr<Ijob> guy2 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::FigherType, characterFactory::HumanType);
    std::shared_ptr<Ijob> guy3 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::RogueType, characterFactory::DwarveType);
    std::shared_ptr<Ijob> guy4 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::ClericType, characterFactory::ElveType);

    Party.addMember(guy);
    Party.getMember();
    Party.addMember(guy2);
    Party.addMember(guy3);
    Party.addMember(guy4);
    int dmg = Party.attack(guy);
    Party.takeDamage(dmg, guy2, 2);
    int alive = Party.checkAlive(guy2);
    ASSERT_EQ(alive, 0);
}
TEST(dndTests, party2)
{
    Party Party;
    std::shared_ptr<Ijob> guy = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::WizardType, characterFactory::HalflingType);
    std::shared_ptr<IRace> race = guy->getrace();
    std::shared_ptr<Ijob> guy2 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::FigherType, characterFactory::HumanType);
    std::shared_ptr<Ijob> guy3 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::RogueType, characterFactory::DwarveType);
    std::shared_ptr<Ijob> guy4 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::ClericType, characterFactory::ElveType);

    Party.addMember(guy);
    Party.getMember();
    Party.addMember(guy2);
    Party.addMember(guy3);
    Party.addMember(guy4);
    int dmg = Party.attack(guy);
    Party.takeDamage(dmg, guy2, 10);
    int alive = Party.checkAlive(guy2);
    ASSERT_EQ(alive, 1);
}		
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}