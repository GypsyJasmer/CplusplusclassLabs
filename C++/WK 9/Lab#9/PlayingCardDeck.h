#ifndef PLAYINGCARDDECK_H
#define PLAYINGCARDDECK_H

#include "PlayingCard.h"

class PlayingCardDeck
{
    private:
        const static int NUMSUITS = 4;
        const static int NUMRANKS = 13;
        const static int NUMCARDS = 52;

        PlayingCard * deck[NUMCARDS];
        int cardsLeft;

        void clearDeck();
        void deleteDeck();
        void makeDeck();

    public:
        PlayingCardDeck();
        PlayingCardDeck(int numshuffles);
        ~PlayingCardDeck();
        PlayingCard * dealCard();
        bool shuffle(int numshuffles);
        void reset();
        std::string getAllCardCodes();
        int getCountUsed();
        int getCountRemain();

};


#endif
