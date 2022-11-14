#pragma once

#include "Card.h"
#include <string>
#include <list>

class PersonWithObjects
{
public:

	PersonWithObjects(std::string name) ;

	PersonWithObjects() = delete;

	PersonWithObjects(const PersonWithObjects &p);

	PersonWithObjects(PersonWithObjects && obj);


	std::string GetName() const;

	virtual ~PersonWithObjects();

	bool AddCardToHand(Card  c);
	bool AddCardToHand(Card& c);
	Card RemoveCardFromHand();
	void PrintOutHand();
	bool AddCardToStack();
	bool checkForFullStack();
	int size();
	void PrintOutStack();

	

    private: 
        std::string m_name;
        std::list< Card > m_stackOfCards;
        std::list< Card > m_listOfCards;
		

};