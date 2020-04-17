#include "BlackJackHand.h"


BlackJackHand::BlackJackHand()
{
    for(int i = 0; i < HANDSIZE; i++)
		hand[i] = NULL;
	cardCount = 0;
}

BlackJackHand::BlackJackHand(PlayingCard *c1, PlayingCard *c2)
{
    for(int i = 0; i < HANDSIZE; i++)
		hand[i] = NULL;
	cardCount = 0;

    hand[cardCount++] = c1;
    hand[cardCount++] = c2;
}

BlackJackHand::~BlackJackHand()
{
	for ( int i = 0; i < cardCount; i++ )
		if ( hand[i] != NULL)
			delete hand[i];
}

bool BlackJackHand::addCard(PlayingCard *c1)
{
    if ( getLowScore() == 21 or isBust() or isFull() )
    {
        return false;
    }
    else
	{
        hand[cardCount++] = c1;
    }

    return true;
}

int BlackJackHand::getCardCount()
{
    return cardCount;
}

int BlackJackHand::getHighScore()
{
    bool firstAce = true;
    int score = 0;

    for ( int i = 0; i < cardCount; i++ )
    {
        if ( hand[i]->getValue() == 'A' and firstAce )
        {
            score += 11;
            firstAce = false;
        }
        else
        {
            score += getCardIntValue(hand[i]->getValue());
        }
    }
    return score;
}

int BlackJackHand::getLowScore()
{
    int score = 0;
    for ( int i = 0; i < cardCount; i++ )
    {
        score += getCardIntValue(hand[i]->getValue());
    }
    return score;
}

void BlackJackHand::clearHand()
{
    for ( int i = 0; i < HANDSIZE; i++ )
    {
        if ( hand[i] != NULL )
            delete hand[i];
        hand[i] = NULL;
    }
    cardCount = 0;
}

bool BlackJackHand::isBust()
{
    return getLowScore() > 21;
}

bool BlackJackHand::isFull()
{
    return cardCount == HANDSIZE;
}

bool BlackJackHand::canTakeCard()
{
    return getLowScore() < 21 and cardCount < HANDSIZE;
}

std::string BlackJackHand::getAllCardCodes()
{
    std::string temp;

    for ( int i = 0; i < cardCount; i++ )
    {
        temp += hand[i]->getCardCode();
        temp += " ";
    }


    return temp;
}


int BlackJackHand::getCardIntValue(char value)
{
    switch (value)
    {
    case 'A':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'T':
    case 'J':
    case 'Q':
    case 'K':
        return 10;
    default:
        return 0;
    }
}
