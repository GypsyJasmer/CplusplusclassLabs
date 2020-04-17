#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED
#include "BlackJackHand.h"
#include "PlayingCardDeck.h"
#include <iostream>
#include <sstream>
#include <string>

//Inherits from Player. Adds the ability to deal cards and manage the deck. Does not use the methods for managing bets or stake.
class Dealer{

    private:
        //pointer to a PlayingCardDeck that is created during the constructor and used for methods that deal cards
		PlayingCardDeck * theDeck;

    public:
        //default create a PlayingCardDeck
    	Dealer(){this->theDeck = new PlayingCardDeck();}
    	//overload constructor takes one argument, uses that to create a PlayCardDeck and shuffle it
    	Dealer(int numShuffles);
        //Destructor
        ~Dealer (){delete theDeck;}

        std::string showHand(PlayingCard * dealCard());
        std::string fullHand();
        PlayingCard * dealCard();
        int cardsLeft();
        void shuffle();


       /*
        PlayingCard * dealCard();
        bool shuffle(int numshuffles);
        void reset();
        std::string getAllCardCodes();
        int getCountUsed();
        int getCountRemain(); */

};

#endif // DEALER_H_INCLUDED
