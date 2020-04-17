#include "PlayingCardDeck.h"
#include <stdlib.h>
#include <iostream>

PlayingCardDeck::PlayingCardDeck()
{
    clearDeck();
    makeDeck();
}

PlayingCardDeck::PlayingCardDeck(int numshuffles)
{
	clearDeck();
	makeDeck();
    shuffle(numshuffles);
}

PlayingCardDeck::~PlayingCardDeck()
{
    deleteDeck();
}

PlayingCard * PlayingCardDeck::dealCard()
{
	if ( cardsLeft > 0)
	{
		PlayingCard * temp = deck[--cardsLeft];
		deck[cardsLeft] = NULL;
		return temp;
	}
	else
	{
		return NULL;
	}
}

bool PlayingCardDeck::shuffle(int numshuffles)
{
	if ( cardsLeft == NUMCARDS )
	{
		for ( int i = 0; i < numshuffles; i++ )
		{
			for ( int j = 0; j < NUMCARDS; j++ )
			{
				int other = rand() % NUMCARDS;
				PlayingCard * temp = deck[j];
				deck[j] = deck[other];
				deck[other] = temp;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void PlayingCardDeck::reset()
{
	deleteDeck();
	makeDeck();
}

std::string PlayingCardDeck::getAllCardCodes()
{
    std::string temp;
    int lineCount = 0;

    for ( int i = 0; i < cardsLeft; i++ )
    {
        temp += deck[i]->getCardCode();
        temp += " ";
        lineCount++;
        if ( lineCount >= NUMRANKS )
        {
            temp += "\n";
            lineCount = 0;
        }
    }
    return temp;
}

int PlayingCardDeck::getCountUsed()
{
    return NUMCARDS - cardsLeft;
}

int PlayingCardDeck::getCountRemain()
{
    return cardsLeft;
}

void PlayingCardDeck::clearDeck()
{
    for ( int i = 0; i < NUMCARDS; i++ )
    {
		deck[i] = NULL;

    }
}

void PlayingCardDeck::deleteDeck()
{
	for ( int i = 0; i < NUMCARDS; i++ )
    {
        if ( deck[i] != NULL )
        {
            delete deck[i];
            deck[i] = NULL;
        }
    }
}

void PlayingCardDeck::makeDeck()
{
    char values[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suits[] = {'C','H','D','S'};

    for(int i = 0; i < NUMSUITS; i++)
    {
        for(int j = 0; j < NUMRANKS; j++)
        {
            deck[i * NUMRANKS + j] = new PlayingCard(values[j], suits[i]);
        }
	}

	cardsLeft = NUMCARDS;
}
