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

using namespace std;


int main()
{
    Party Party1;
	Party Party2;
    std::shared_ptr<Ijob> guy11,guy12,guy13,guy14,guy21,guy22,guy23,guy24;
    
    //WizardType    RogueType   FigherType  ClericType
    //HumanType     DwarveType  HalflingType   ElveType
    guy11 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::FigherType, characterFactory::HumanType);

    guy12 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::WizardType, characterFactory::DwarveType);
    guy13 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::FigherType, characterFactory::HumanType);
    guy14 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::RogueType, characterFactory::HalflingType);

    guy21 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::FigherType, characterFactory::HumanType);

    guy22 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::RogueType, characterFactory::ElveType);
    guy23 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::FigherType, characterFactory::HalflingType);
    guy24 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::ClericType, characterFactory::DwarveType);

    Party1.addMember(guy11);
    Party2.addMember(guy21);
    Party1.addMember(guy12);
    Party1.addMember(guy13);
    Party1.addMember(guy14);
    Party2.addMember(guy22);
    Party2.addMember(guy23);
    Party2.addMember(guy24);

    bool alive = true;
    int deathsParty1 = 0;
    int deathsParty2 = 0;

    int ini1, ini2, ini;
    ini1 = 0;
    ini2 = 0;
    for (int i = 0; i < 4; i++){
        vector<std::shared_ptr<Ijob>> members1 = Party1.getMember();
        std::shared_ptr<IRace> race1 = members1[i]->getrace();
        ini = race1->getIni();
        ini1 = ini1 + ini;
    }
    
    for (int i = 0; i < 4; i++){
        vector<std::shared_ptr<Ijob>> members2 = Party2.getMember();
        std::shared_ptr<IRace> race2 = members2[i]->getrace();
        ini = race2->getIni();
        ini1 = ini2 + ini;
    }

    if (ini1 > ini2){
        ini1 = 1;
        ini2 = 0;
    }else{
        ini1 = 0;
        ini2 = 1;
    }

    while(alive){
        int who, dude, roll, attack, hitBonus, playerAlive;
        
        //Party 1 Go
        if (ini1 > ini2){
            cout << "Party 1: \n";
            cout << "Who are you attacking with?\n1-Front Left\n2-Front Right\n3-Back Left\n4-Back Right\n";
            cin >> dude;
            vector<std::shared_ptr<Ijob>> members1 = Party1.getMember();
            std::shared_ptr<Ijob> m1 = members1[dude-1];
            playerAlive = Party1.checkAlive(m1);
            while (playerAlive == 1){
                cout << "character is dead try again.\n";
                cin >> dude;
                members1 = Party1.getMember();
                m1 = members1[dude-1];
                playerAlive = Party1.checkAlive(m1);
            }
            cout<< "Who are you attacking?\n1-Front Left\n2-Front Right\n3-Back Left\n4-Back Right\n";
            cin >> who;
            vector<std::shared_ptr<Ijob>> members2 = Party2.getMember();
            std::shared_ptr<Ijob> m2 = members2[who-1];
            playerAlive = Party2.checkAlive(m2);
            while (playerAlive == 1){
                cout << "character is dead try again.\n";
                cin >> who;
                members2 = Party2.getMember();
                m2 = members2[who-1];
                playerAlive = Party2.checkAlive(m2);
            }

            
            attack = Party1.attack(m2);
            auto race1 = m1->getrace();
            hitBonus = race1->getHitBonus();
            roll = ((rand() % 20 + 1) + hitBonus);
            cout << roll << endl;
            Party2.takeDamage(attack, m2, roll);
            deathsParty2 = deathsParty2 + Party2.checkAlive(m2);
            if(deathsParty2 > 3){
                alive = false;
                cout << "Team 1 wins\n";
                break;
            }
            ini1 = ini1 - 2;
        }
        //Party 2 go
        if (ini2 > ini1){
            cout << "Party 2: \n";
            cout << "Who are you attacking with?\n1-Front Left\n2-Front Right\n3-Back Left\n4-Back Right\n";
            cin >> dude;
            vector<std::shared_ptr<Ijob>> members22 = Party2.getMember();
            std::shared_ptr<Ijob> m22 = members22[dude-1];
            playerAlive = Party2.checkAlive(m22);
            while (playerAlive == 1){
                cout << "character is dead try again.\n";
                cin >> dude;
                members22 = Party2.getMember();
                m22 = members22[dude-1];
                playerAlive = Party2.checkAlive(m22);
            }
            cout<< "Who are you attacking?\n1-Front Left\n2-Front Right\n3-Back Left\n4-Back Right\n";
            cin >> who;
            vector<std::shared_ptr<Ijob>> members11 = Party1.getMember();
            std::shared_ptr<Ijob> m11 = members11[who-1];
            playerAlive = Party1.checkAlive(m22);
            while (playerAlive == 1){
                cout << "character is dead try again.\n";
                cin >> who;
                members11 = Party1.getMember();
                m11 = members11[who-1];
                playerAlive = Party1.checkAlive(m11);
            }
            attack = Party2.attack(m11);
            auto race2 = m22->getrace();
            hitBonus = race2->getHitBonus();
            roll = ((rand() % 20 + 1) + hitBonus);
            cout << roll << endl;
            Party1.takeDamage(attack, m11, roll);
            deathsParty1 = deathsParty1 + Party1.checkAlive(m11);
            if(deathsParty1 > 3){
                alive = false;
                cout << "Team 2 wins\n";
                break;           
            }
            ini2 = ini2 - 2;
        }
        

    }

}