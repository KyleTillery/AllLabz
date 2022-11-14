#pragma once
#include <list>
#include "Card.h"

class DeckWithObjects
{
    public:
        DeckWithObjects();
        virtual ~DeckWithObjects();

        Card DrawCard();
        bool ReturnCard(Card c);

        bool PrintDeck();
        int size();

    private:

        std::list<Card> m_deck;

};