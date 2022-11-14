
#include "GameWithObjects.h"
#include "PersonWithObjects.h"
#include <iostream>

using namespace std;

GameWithObjects::GameWithObjects(): m_p1("Huey 1"), m_p2("Louie 2"), m_p3("Dewey 3"), m_deck()
{

}

GameWithObjects::~GameWithObjects()
{
    std::cout<<"GameWithObjects Destructor Called"<<std::endl;	
}

void GameWithObjects::CheatingAdd(Card c)
{

}

void GameWithObjects::RunCheatGame()
{
    Card card1Object = Card(11,1);

    CheatingAdd(card1Object);
    std::cout<<"End Calling AddCardToHandObject"<<std::endl;
    std::cout<<std::endl<<std::endl;
}

bool GameWithObjects::handOut()
{
    for (P1Hand; P1Hand < 7;P1Hand++){
            m_p1.AddCardToHand(std::move(m_deck.DrawCard()));
            std::cout<<"Drawing Cards "<< P1Hand <<std::endl;
        }
    std::cout << "P1 Player::PrintOutHand" << std::endl;
    m_p1.PrintOutHand();
        for (P2Hand; P2Hand < 7;P2Hand++){
            m_p2.AddCardToHand(std::move(m_deck.DrawCard()));
            std::cout<<"Drawing Cards "<< P2Hand <<std::endl;
        }
    std::cout << "P2 Player::PrintOutHand" << std::endl;
    m_p2.PrintOutHand();
    return true;
}
bool GameWithObjects::stackAdd1()
{
    bool stackAdd1;
        do
        {
            m_p1.AddCardToStack();
            stackAdd1 = m_p1.AddCardToStack();
        }
    while (stackAdd1 == true);
    return true;
}

bool GameWithObjects::stackAdd2()
{
    bool stackAdd2;
        do
        {
            m_p2.AddCardToStack();
            stackAdd2 = m_p2.AddCardToStack();
        }
    while (stackAdd2 == true);
    return true;
}


bool GameWithObjects::RunGame()
{


    bool GameEnd = false;
    P1Hand = 1;
    P2Hand = 1;
    handOut();

    

    std::cout << "P1 Player::PrintOutHand" << std::endl;
    m_p1.PrintOutHand();
    std::cout << "P2 Player::PrintOutHand" << std::endl;
    m_p2.PrintOutHand();

        while(GameEnd == false)
        {
        
        if(m_p1.size() == 0)
        {
            for(int i = 0; i < 5; i++)
            {
                m_p1.AddCardToHand(std::move(m_deck.DrawCard()));
            }
        }
        else if (m_p1.size() < 6)
        {
            for(int i = m_p1.size(); i < 6; i++)
            {
                m_p1.AddCardToHand(std::move(m_deck.DrawCard()));

            }
        }

        std::cout << "P1 Player::PrintOutHand" << std::endl;
        m_p1.PrintOutHand();
        std::cout << "P1 Player::PrintOutStack" << std::endl;
        m_p1.PrintOutStack();

        stackAdd1();
        if(m_p1.checkForFullStack())
        {    
            GameEnd = true;
            std::cout << "P1 Player::PrintOutHand" << std::endl;
            m_p1.PrintOutHand();
            std::cout << "P1 Player::PrintOutStack" << std::endl;
            m_p1.PrintOutStack();
            cout << "P1 WINS!!!" <<endl;
            return true;           
        }

        std::cout << "P1 Player::PrintOutHand" << std::endl;
        m_p1.PrintOutHand();
        std::cout << "P1 Player::PrintOutStack" << std::endl;
        m_p1.PrintOutStack();
        cout << "Player 1 trash hand? y/n\n";
        string choice1;
        cin >> choice1;
        if (choice1 == "y"){
            for (int i = m_p1.size(); i > 0; i--){
                m_deck.ReturnCard(std::move(m_p1.RemoveCardFromHand()));
                
            }
        }else if(m_p1.size() > 6) {
            m_deck.ReturnCard(std::move(m_p1.RemoveCardFromHand()));
        }
        else if(m_p1.size() == 6)
        {
            m_deck.ReturnCard(std::move(m_p1.RemoveCardFromHand()));
            m_p1.AddCardToHand(std::move(m_deck.DrawCard()));
        }
        m_p1.PrintOutHand();
        m_p2.PrintOutHand();
        if(m_p1.checkForFullStack())
        {    
            GameEnd = true;
            cout << "P1 WINS!!!" <<endl;
            return true;           
        }

        if(m_p2.size() == 0)
        {
            for(int i = 0; i < 5; i++)
            {
                m_p2.AddCardToHand(std::move(m_deck.DrawCard()));
                std::cout<<"Drawing Cards "<< P2Hand <<std::endl;
            }
        }
        else if (m_p2.size() < 6)
        {
            for(int i = m_p2.size(); i < 6; i++)
            {
                m_p2.AddCardToHand(std::move(m_deck.DrawCard()));

            }
        }

        std::cout << "P2 Player::PrintOutHand" << std::endl;
        m_p2.PrintOutHand();
        std::cout << "P2 Player::PrintOutStack" << std::endl;
        m_p2.PrintOutStack();

        stackAdd2();

        if(m_p2.checkForFullStack())
        {
           GameEnd = true;
           std::cout << "P2 Player::PrintOutHand" << std::endl;
            m_p2.PrintOutHand();
            std::cout << "P2 Player::PrintOutStack" << std::endl;
            m_p2.PrintOutStack();
           cout << "P2 WINS!!!" << endl;
           return true;
        }
        
        std::cout << "P2 Player::PrintOutHand" << std::endl;
        m_p2.PrintOutHand();
        std::cout << "P2 Player::PrintOutStack" << std::endl;
        m_p2.PrintOutStack();
        cout << "Player 2 trash hand? y/n\n";
        string choice2;
        cin >> choice2;
        if (choice2 == "y"){
            for (int i = m_p2.size(); i > 0; i--){
                m_deck.ReturnCard(std::move(m_p2.RemoveCardFromHand()));
            }
        }else if(m_p2.size() > 5){
            m_deck.ReturnCard(std::move(m_p2.RemoveCardFromHand()));
        }
        else if(m_p2.size() == 5)
        {
            m_deck.ReturnCard(std::move(m_p2.RemoveCardFromHand()));
            m_p2.AddCardToHand(std::move(m_deck.DrawCard()));
        }
        m_p1.PrintOutHand();
        m_p2.PrintOutHand();
        if(m_p2.checkForFullStack())
        {
           GameEnd = true;
           std::cout << "P2 Player::PrintOutHand" << std::endl;
            m_p2.PrintOutHand();
            std::cout << "P2 Player::PrintOutStack" << std::endl;
            m_p2.PrintOutStack();
           cout << "P2 WINS!!!" << endl;
           return true;
        }

        }
        return false;
    
    
}

