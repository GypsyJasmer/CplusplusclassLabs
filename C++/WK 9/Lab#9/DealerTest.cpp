
#include <iostream>
#include <time.h>
#include "Player.h"
#include "Dealer.h"


using namespace std;

//#define TEST_HAND_METHODS
#define TEST_DEALER_METHODS

int main() {

		// initialize random number generator
	srand( (unsigned int)time(NULL) );
		// Create a Blackjack dealer object
	Dealer myHand;

#ifdef TEST_HAND_METHODS
    cout << "This tests the dealer hand methods the same as PlayerTest " << endl;
        // arrays of values and suits for normal cards
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
    
#ifdef TEST_DEALER_METHODS

    cout << "\nThis checks dealer specific methods " << endl;
		// check dealing capability
	cout << "First, the dealer dealing an unshuffled deck" << endl;
	int cardsOnLine = 0;
	while ( myHand.cardsLeft() > 0 )
	{
		cout << myHand.dealCard()->getCardCode() << " ";
		cardsOnLine++;
		if ( cardsOnLine > 12 )
		{
			cout << endl;
			cardsOnLine = 0;
		}
	}

		// reset and redeal
	cout << "\nNow with a new shuffled deck" << endl;
	myHand.shuffle();
	while ( myHand.cardsLeft() > 0 )
	{
		cout << myHand.dealCard()->getCardCode() << " ";
		cardsOnLine++;
		if ( cardsOnLine > 12 )
		{
			cout << endl;
			cardsOnLine = 0;
		}
	}

#endif // TEST_DEALER_METHODS
}


