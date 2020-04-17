#include "Dealer.h"

/**************************************
// this is different from the player showHand in that the first card
is shown as XX to indicate that it is face down
**************************************/
std::string Dealer::showHand()
{

}

/**************************************
this is used to show the dealer's full hand
after the player is done taking cards.
**************************************/
std::string Dealer::fullHand()
{
    return theDeck-> BlackJackHand.isFull();
}

/**************************************
return the next card from the deck
**************************************/
Dealer::PlayingCard * dealCard(PlayingCard * dealCard())
{
     return theDeck-> dealCard(c);
}


int Dealer::cardsLeft()
{

}

/**************************************
this resets and shuffles the deck to start play over again.
**************************************/
void Dealer::shuffle()
{
    this->shuffle();
}
