#pragma once
#include "PersonWithObjects.h"
#include "DeckWithObjects.h"
#include "Card.h"



class GameWithObjects
{
	public:
		GameWithObjects();

		virtual ~GameWithObjects();

		bool RunGame();
		void RunCheatGame();
		void CheatingAdd(Card c);
		bool handOut();
		bool stackAdd1();
		bool stackAdd2();
    private:

		void PrintOutQueueOfPeople();

		void PrintOutStackOfPeople();

        PersonWithObjects m_p1;
        PersonWithObjects m_p2;
        PersonWithObjects m_p3;
        DeckWithObjects m_deck;
		int P1Hand;
		int P2Hand;
};