#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "BlackJackHand.h"
#include <iostream>
#include <sstream>
#include <string>

class Player{
    private:

        //represents the entire betting stake. It can be set in the overloaded constructor or by a separate method.
        int stake;
        //represents your bet on this hand. It is used to update the stake after you either win or lose based on your hand vs the dealer's hand.
        int bet;

    protected:
         //this is a BlackJackHand that is created within the Player's constructor and used as the basis for most of the PLayer class methods
        BlackJackHand *theHand;


    public:
        //default constructor
        Player() {theHand = new BlackJackHand; stake=0; }
        //overload constructor
        Player(int stake) {this->stake=stake; theHand = new BlackJackHand;}
        //Destructor
        ~Player (){delete theHand;}

        //setters/mutator
        //sets the betting stake for the player
        void setStake(int stake);


        //getters/accessor
        //returns high score unless it is over 21, then it return low score
        int getScore();
        //returns the low score of the hand
        int getLowScore() {return theHand->getLowScore();}
        //returns the high score of the hand
        int getHighScore(){return theHand->getHighScore();}
        //returns the current value of the betting stake
        //this is an int that represents your entire betting stake. It can be set in the overloaded constructor or by a separate method.
        int getStake(){return stake;}

        //other Methods
        //adds a card to the player's hand
        bool takeCard(PlayingCard*c);
        //returns a string showing the contents of the hand
        std::string showHand();
        //returns true is the player busted
        bool busted();
        //returns true if the player wans a card (getScore<16)
        bool wantCard();
        //clears the cards from the hand for the next deal
        void clearHand();
        //saves the bet if it is less than the stake and returns true, otherwise returns false
        bool makeBet(int bet);
        //adds the bet to the stake
        void won();
        //subtracts the bet from the stake
        void lost();

};

#endif // PLAYER_H_INCLUDED
