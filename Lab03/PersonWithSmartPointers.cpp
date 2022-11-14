
#include "PersonWithSmartPointers.h"
#include <iostream>

PersonWithSmartPointers::PersonWithSmartPointers(std::string name) :m_name(name)
{

}




std::string PersonWithSmartPointers::GetName() const
{
    return m_name;
}

PersonWithSmartPointers::~PersonWithSmartPointers()
{
    std::cout << "Deleting PersonWithObjects" << m_name << std::endl;
    
}

void PersonWithSmartPointers::AddCardToHand(std::shared_ptr<Card> c)  
{
    std::cout<<"   AddCardToHandPointer :"<<c->GetValue()<<" "<<c->GetSuit()<<" "<<c->GetGuid()<<std::endl;
    m_listOfCards.push_front(c);
}



std::shared_ptr<Card> PersonWithSmartPointers::RemoveCardFromHand()  
{
    std::shared_ptr<Card> retVal = m_listOfCards.front();
    m_listOfCards.pop_front();
    return retVal;
}


void PersonWithSmartPointers::PrintOutHand()  
{
    
    for(auto it = m_listOfCards.begin(); it != m_listOfCards.end(); it++)
    {
        std::cout<<(*it)->GetSuit()<<" "<<(*it)->GetValue()<<" "<<(*it)->GetGuid()<<std::endl;
    }
}

void PersonWithSmartPointers::PrintOutStack()
{
    for (auto it = m_stackOfCards.begin(); it != m_stackOfCards.end(); it++)
    {
        std::cout << (*it)->GetSuit() << " " << (*it)->GetValue() << " " << (*it)->GetGuid()<< std::endl;
    }
    std::cout << std::endl;
}


bool PersonWithSmartPointers::AddCardToStack()
{
    for (auto it = m_listOfCards.begin(); it != m_listOfCards.end(); it++)
    {
        if(m_stackOfCards.size() == 0 && (*it)->GetValue() == 1)
        {
            m_stackOfCards.push_front(*it);
            return true;
        }
        if ((*it)->GetValue() == (m_stackOfCards.size() + 1) )
        {
            m_stackOfCards.push_front(*it);
            return true;
        }
    }
    return false;
}

bool PersonWithSmartPointers::checkForFullStack()
{
    if (m_stackOfCards.size() == 13)
    {
        return true;
    }
    else
        return false;
}

int PersonWithSmartPointers::size()
{
    return m_listOfCards.size();
}

