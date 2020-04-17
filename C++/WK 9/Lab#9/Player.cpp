#include "Player.h"


/**************************************
//this is an int that represents your entire betting stake.
It can be set in the overloaded constructor or by a separate method.
**************************************/
void Player::setStake(int stake)
{
    this-> stake=stake;

}
/**************************************
//returns high score unless it is over 21, then it return low score
**************************************/
int Player::getScore()
{
    if(getHighScore()==21)
    {
        return theHand-> getHighScore();
    }
    else
    {
        return theHand-> getLowScore();
    }

}

/**************************************
// adds a card to the player's hand
**************************************/
bool Player::takeCard(PlayingCard*c)
{
    return theHand-> addCard(c);
}

/**************************************
//returns a string showing the contents of the hand
**************************************/
std::string Player::showHand()
{
    return theHand->getAllCardCodes();
}
/**************************************
//returns true is the player busted
**************************************/
bool Player::busted()
{
    return theHand->isBust();
}

/**************************************
//returns true if the player wants a card (getScore<16)
**************************************/
bool Player::wantCard()
{
    return theHand-> canTakeCard()&& theHand->getHighScore()<16;
}
/**************************************
//clears the cards from the hand for the next deal
**************************************/
void Player::clearHand()
{
    return theHand->clearHand();
}
/**************************************
//saves the bet if it is less than the stake and returns true, otherwise returns false
**************************************/
bool Player::makeBet(int bet)
{
    if(bet<stake)
    {
        return true;
    }
    else
    {
        return false;
    }

}
/**************************************
//adds the bet to the stake this is an int that
represents your bet on this hand. It is used to update
the stake after you either win or lose based on
your hand vs. the dealer's hand.
**************************************/
void Player::won()
{
    stake+=bet;
}
/**************************************
//subtracts the bet from the stake
**************************************/
void Player::lost()
{
    stake-=bet;
}
