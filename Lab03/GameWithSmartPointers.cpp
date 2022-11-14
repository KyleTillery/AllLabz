#include "GameWithSmartPointers.h"
#include <iostream>
#include <list>
#include "Card.h"
#include "PersonWithSmartPointers.h"
#include "DeckWithSmartPointers.h"

using namespace std;

GameWithSmartPointers::GameWithSmartPointers()
{
    m_p1 = std::make_unique<PersonWithSmartPointers>("Huey 1");
    m_p2 = std::make_unique<PersonWithSmartPointers>("Louie 2");
    m_p3 = std::make_unique<PersonWithSmartPointers>("Dewey 3");
    m_deck = std::make_unique<DeckWithSmartPointers> ();
}

GameWithSmartPointers::~GameWithSmartPointers()
{
    std::cout<<"GameWithSmartPointers Destructor Called"<<std::endl;	

}
bool GameWithSmartPointers::handOut()
{
    for (P1Hand; P1Hand < 7;P1Hand++){
            m_p1->AddCardToHand(std::move(m_deck->DrawCard()));
        }
    std::cout << "P1 Player::PrintOutHand" << std::endl;
    m_p1->PrintOutHand();
        for (P2Hand; P2Hand < 7;P2Hand++){
            m_p2->AddCardToHand(std::move(m_deck->DrawCard()));
        }
    std::cout << "P2 Player::PrintOutHand" << std::endl;
    m_p2->PrintOutHand();
    return true;
}
bool GameWithSmartPointers::stackAdd1()
{
    bool stackAdd1;
        do
        {
            m_p1->AddCardToStack();
            stackAdd1 = m_p1->AddCardToStack();
        }
    while (stackAdd1 == true);
    return true;
}

bool GameWithSmartPointers::stackAdd2()
{
    bool stackAdd2;
        do
        {
            m_p2->AddCardToStack();
            stackAdd2 = m_p2->AddCardToStack();
        }
    while (stackAdd2 == true);
    return true;
}

bool GameWithSmartPointers::RunGame()
{
    bool GameEnd = false;
    P1Hand = 1;
    P2Hand = 1;
    handOut();
    

    

    std::cout << "P1 Player::PrintOutHand" << std::endl;
    m_p1->PrintOutHand();
    std::cout << "P2 Player::PrintOutHand" << std::endl;
    m_p2->PrintOutHand();



        while(GameEnd == false)
        {
        if(m_p1->size() == 0)
        {
            for(int i = 0; i < 5; i++)
            {
                m_p1->AddCardToHand(m_deck->DrawCard());
            }
        }
        else if (m_p1->size() < 6)
        {
            for(int i = m_p1->size(); i < 6; i++)
            {
                m_p1->AddCardToHand(m_deck->DrawCard());

            }
        }
        stackAdd1();
        if(m_p1->checkForFullStack())
        {    
            GameEnd = true;
            std::cout << "P1 Player::PrintOutHand" << std::endl;
            m_p1->PrintOutHand();
            std::cout << "P1 Player::PrintOutStack" << std::endl;
            m_p1->PrintOutStack();
            cout << "P1 WINS!!!" <<endl;
            return true;           
        }

        std::cout << "P1 Player::PrintOutHand" << std::endl;
        m_p1->PrintOutHand();
        std::cout << "P1 Player::PrintOutStack" << std::endl;
        m_p1->PrintOutStack();
        cout << "Player 1 trash hand? y/n\n";
        string choice1;
        cin >> choice1;
        if (choice1 == "y"){
            for (int i = m_p1->size(); i > 0; i--){
                m_deck->ReturnCard(m_p1->RemoveCardFromHand());
                
            }
        }else if(m_p1->size() > 6) {
            m_deck->ReturnCard(m_p1->RemoveCardFromHand());
        }
        else if(m_p1->size() == 6)
        {
            m_deck->ReturnCard(m_p1->RemoveCardFromHand());
            m_p1->AddCardToHand(m_deck->DrawCard());
        }
        m_p1->PrintOutHand();
        m_p2->PrintOutHand();
        if(m_p1->checkForFullStack())
        {    
            GameEnd = true;
            std::cout << "P1 Player::PrintOutHand" << std::endl;
            m_p1->PrintOutHand();
            std::cout << "P1 Player::PrintOutStack" << std::endl;
            m_p1->PrintOutStack();
            cout << "P1 WINS!!!" <<endl;
            return true;           
        }

        if(m_p2->size() == 0)
        {
            for(int i = 0; i < 5; i++)
            {
                m_p2->AddCardToHand(m_deck->DrawCard());
                std::cout<<"Drawing Cards "<< P2Hand <<std::endl;
            }
        }
        else if (m_p2->size() < 6)
        {
            for(int i = m_p2->size(); i < 6; i++)
            {
                m_p2->AddCardToHand(m_deck->DrawCard());

            }
        }
        stackAdd2();
        if(m_p2->checkForFullStack())
        {
           GameEnd = true;
           std::cout << "P2 Player::PrintOutHand" << std::endl;
            m_p2->PrintOutHand();
            std::cout << "P2 Player::PrintOutStack" << std::endl;
            m_p2->PrintOutStack();  
           cout << "P2 WINS!!!" << endl;
           return true;
        }
        
        std::cout << "P2 Player::PrintOutHand" << std::endl;
        m_p2->PrintOutHand();
        std::cout << "P2 Player::PrintOutStack" << std::endl;
        m_p2->PrintOutStack();
        cout << "Player 2 trash hand? y/n\n";
        string choice2;
        cin >> choice2;
        if (choice2 == "y"){
            for (int i = m_p2->size(); i > 0; i--){
                m_deck->ReturnCard(m_p2->RemoveCardFromHand());
            }
        }else if(m_p2->size() > 5){
            m_deck->ReturnCard(m_p2->RemoveCardFromHand());
        }
        else if(m_p2->size() == 5)
        {
            m_deck->ReturnCard(m_p2->RemoveCardFromHand());
            m_p2->AddCardToHand(m_deck->DrawCard());
        }
        m_p1->PrintOutHand();
        m_p2->PrintOutHand();
        if(m_p2->checkForFullStack())
        {
           GameEnd = true;
           std::cout << "P2 Player::PrintOutHand" << std::endl;
            m_p2->PrintOutHand();
            std::cout << "P2 Player::PrintOutStack" << std::endl;
            m_p2->PrintOutStack();
           cout << "P2 WINS!!!" << endl;
           return true;
        }
        

        }
        return false;
}

