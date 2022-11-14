// tests.cpp

#include "Card.h"
#include "GameWithObjects.h"
#include "PersonWithObjects.h"
#include "DeckWithObjects.h"
#include "GameWithSmartPointers.h"
#include "PersonWithSmartPointers.h"
#include "DeckWithSmartPointers.h"
#include <gtest/gtest.h>
#include <exception>
#include <iostream>

		
 		TEST(DeckWithObjects,printDeck) //first is directory name and the second in what test its is then have the test input in the {}
		{
			bool work;
			DeckWithObjects m_deck;
			EXPECT_TRUE(m_deck.PrintDeck());

			
		}
		TEST(DeckWithObjects,drawcard)
		{
			bool work;
			std::list<Card> m_deck;
			DeckWithObjects n_deck;
			m_deck.push_back(std::move(Card(1,0)));
       		m_deck.push_back(std::move(Card(2,1)));
        	m_deck.push_back(std::move(Card(3,2)));
			int first = n_deck.size();
			std::move(n_deck.DrawCard()); 
			int second = n_deck.size();
			if (first > second){
				work = true;
			}else {
				work = false;
			}
			EXPECT_TRUE(work);
		}
		TEST(DeckWithObjects,returncard)
		{
			bool work;
			std::list<Card> m_deck;
			DeckWithObjects n_deck;
			int first = m_deck.size();
			m_deck.push_back(std::move(Card(1,0)));
			int second = m_deck.size();
			if (first < second){
				work = true;
			}else{
				work = false;
			}
			EXPECT_TRUE(work);
		}
		
		TEST(PersonWithObjects,fullstack)
		{
			PersonWithObjects p("TEST");
			ASSERT_FALSE(p.checkForFullStack());
		}
		TEST(PersonWithObjects,AddToHand)
		{
			PersonWithObjects p("TEST");
			DeckWithObjects m_deck;
			EXPECT_TRUE(p.AddCardToHand(std::move(m_deck.DrawCard())));
		}
		TEST(PersonWithObjects,AddToStack)
		{
			PersonWithObjects p("TEST");
			DeckWithObjects m_deck;
			p.AddCardToHand(std::move(m_deck.DrawCard()));
			EXPECT_TRUE(p.AddCardToStack());
		}
		TEST(DeckWithSmartPointers,printDeck) 
		{
			bool work;
			DeckWithObjects m_deck;
			EXPECT_TRUE(m_deck.PrintDeck());

			
		} 
		TEST(DeckWithSmartPointers,drawcard)
		{
			bool work;
			std::list<Card> m_deck;
			DeckWithObjects n_deck;
			int first = n_deck.size();
			std::move(n_deck.DrawCard()); 
			int second = n_deck.size();
			if (first > second){
				work = true;
			}else {
				work = false;
			}
			EXPECT_TRUE(work);
		}
		TEST(DeckWithSmartPointers,returncard)
		{
			bool work;
			std::list<Card> m_deck;
			DeckWithObjects n_deck;
			int first = m_deck.size();
			m_deck.push_back(std::move(Card(1,0)));
			int second = m_deck.size();
			if (first < second){
				work = true;
			}else{
				work = false;
			}
			EXPECT_TRUE(work);
		}
		TEST(PersonWithSmartPointers,fullstack)
		{
			PersonWithObjects p("TEST");
			ASSERT_FALSE(p.checkForFullStack());
		}
		TEST(PersonWithSmartPointers,AddToHand)
		{
			PersonWithObjects p("TEST");
			DeckWithObjects m_deck;
			EXPECT_TRUE(p.AddCardToHand(std::move(m_deck.DrawCard())));
		}
		TEST(PersonWithSmartPointers,AddToStack)
		{
			PersonWithObjects p("TEST");
			DeckWithObjects m_deck;
			p.AddCardToHand(std::move(m_deck.DrawCard()));
			EXPECT_TRUE(p.AddCardToStack());
		}
		TEST(GameWithObjects, handOut)
		{
			GameWithObjects gameTest;
			EXPECT_TRUE(gameTest.handOut());
		}
		TEST(GameWithObjects, stackAdd1)
		{
			GameWithObjects gameTest2;
			EXPECT_TRUE(gameTest2.stackAdd1());
		}
		TEST(GameWithObjects, stackAdd2)
		{
			GameWithObjects gameTest3;
			EXPECT_TRUE(gameTest3.stackAdd2());
		}
		TEST(GameWithSmartPointers, handOut)
		{
			GameWithSmartPointers gameTest;
			EXPECT_TRUE(gameTest.handOut());
		}
		TEST(GameWithSmartPointers, testNoTrash)
		{
			GameWithSmartPointers gameTest2;
			EXPECT_TRUE(gameTest2.stackAdd1());
		}
		TEST(GameWithSmartPointers, testBool)
		{
			GameWithSmartPointers gameTest3;
			EXPECT_TRUE(gameTest3.stackAdd2());
		}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
