#include "PlayingCard.h"

PlayingCard::PlayingCard()
{
    suit = '0';
    value = '0';
}

PlayingCard::PlayingCard(char value, char suit)
{

    if ( isGood (value, suit))
    {
        this->suit = suit;
        this->value = value;
    }
    else
    {
        this->suit = '0';
        this->value = '0';
    }
}


bool PlayingCard::setCard (char value, char suit)
{

    if ( isGood (value,suit))
    {
        this->suit = suit;
        this->value = value;
        return true;
    }
    else
    {
        this->suit = '0';
        this->value = '0';
        return false;
    }
}


char PlayingCard::getValue()
{
    return value;
}

char PlayingCard::getSuit()
{
    return suit;
}

std::string PlayingCard::getCardCode()
{
    std::string temp = "";
    return temp + value + suit;
}

bool PlayingCard::isValid()
{
    return isGood(suit,value);
}


bool PlayingCard::isGood(char value, char suit)
{
   bool goodSuit = false;
   bool goodValue = false;

   switch (suit)
   {
		case 'C':
		case 'D':
		case 'H':
		case 'S':
			goodSuit = true;
			break;
		default:
			goodSuit = false;
   }

	if ( goodSuit )
	{
		switch (value)
		{
			case 'A':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'T':
			case 'J':
			case 'Q':
			case 'K':
				goodValue = true;
				break;
			default:
				goodValue = false;
		}

	}
	else
	{
		goodValue = false;
	}

	goodSuit = goodValue;

	if ( value == 'J' && (suit == 'R' || suit == 'B'))
	{
		goodSuit = goodValue = true;
	}

   return goodSuit && goodValue;
}
