
#include <iostream>
#include "Player.h"
#include "Dealer.h"

//#define TEST_HAND_METHODS
#define TEST_PLAYER_METHODS

using namespace std;

int main() {

  // Create a Blackjack hand object
  Player myHand;
    
#ifdef TEST_HAND_METHODS
    
    cout << "This tests the methods from the hand, see hand test code" << endl;  // arrays of values and suits for normal cards
    char values[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suits[] = {'C','H','D','S'};

  const int DECK_SIZE = 52;
  const int SUIT_SIZE = 13;
  PlayingCard *deck[DECK_SIZE]; // array of pointers to class objects

  // Initialize and display a card deck
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j<SUIT_SIZE; j++) {
      deck[i * SUIT_SIZE + j] = new PlayingCard(values[j], suits[i]);
      cout << deck[i * SUIT_SIZE + j]->getCardCode();
      cout << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Add each from deck to hand, then remove card from hand
  // before adding next card. Check funcs.
  for(int i = 0; i < DECK_SIZE; i++) {
    cout << deck[i]->getCardCode();
    myHand.takeCard(deck[i]);

    deck[i] = nullptr;  // Remove card from deck
    cout << " : ";
    cout << myHand.showHand();
    cout << " : " << myHand.getLowScore()
         << " : " << myHand.getHighScore()
         << " : " << myHand.busted()
         << endl;
    if(!myHand.wantCard()) {
        cout << "\nClearing hand\n";
        myHand.clearHand();
    }

  } // end for
    
#endif // TEST_HAND_METHODS
    
#ifdef TEST_PLAYER_METHODS
    cout << "\n\nThis tests the player methods of setting stake and making a bet" << endl;

    myHand.setStake(100);
    cout << "Stake should be 100, stake is " << myHand.getStake() << endl;
    cout << "\nNow trying to bet more than stake: ";
    if ( myHand.makeBet(200) )
    {
        cout << " error in checking bet limit\n";
    }
    else
    {
        cout << "caught invalid bet\n";
    }
    cout << "\nNow making a bet of 50: ";
    if (myHand.makeBet(50) )
    {
        cout << " allowed legal bet for 50 \n";
    }
    else
    {
        cout << " did not allow legal bet \n";
    }

    myHand.won();
    cout << "\nAfter winning stake should be 150, is: " << myHand.getStake() << endl;
    
    cout << "\nNow making a bet of 20: ";
    if (myHand.makeBet(20) )
    {
        cout << " allowed legal bet for 20 \n";
    }
    else
    {
        cout << " did not allow legal bet \n";
    }
    myHand.lost();
    cout << "\nAfter losing stake should be 130, is: " << myHand.getStake() << endl;
    
#endif // TEST_PLAYER_METHODS

}

