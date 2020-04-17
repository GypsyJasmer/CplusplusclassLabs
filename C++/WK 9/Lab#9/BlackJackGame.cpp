

#include <iostream>
#include <cstdlib>
#include <limits>
#include <time.h>
#include "Player.h"
#include "Dealer.h"

using namespace std;

int getStake();
int getBet(int stake);
void showTable(Dealer & dealer, Player & player);
void showFullTable(Dealer & dealer, Player & player);
bool getResponse(string question);



int main()
{
        // minimun deck before reshuffling
	const int MINDECK = 20;
        // number of shuffles for new deck
    const int NUM_SHUFFLES = 7;
	int bet;
	bool hit;

		// initialize random number generator
	srand( (unsigned int)time(NULL) );

		// create player and dealer
		// start with shuffled deck
	Dealer dealer(NUM_SHUFFLES);
	Player player;

	player.setStake(getStake());

	bool donePlaying = false;
	do {
			// make sure deck is good
			if ( dealer.cardsLeft() < MINDECK )
			{
				cout << endl << "Reshuffling deck\n";
				dealer.shuffle();
			}

				// get bet
            bet = getBet(player.getStake());
			player.makeBet(bet);

				// deal starting cards;
			player.takeCard(dealer.dealCard());
			dealer.takeCard(dealer.dealCard());
			player.takeCard(dealer.dealCard());
			dealer.takeCard(dealer.dealCard());

				// show starting position
			showTable(dealer, player);

				// get player hits
			do{
				 hit = getResponse("Do you want a hit(y/n)?");
				 if ( hit )
				 {
                     hit = player.takeCard(dealer.dealCard());
                     if ( !hit )
                         cout << "\nYou can not take another card!!" << endl;
                     else
                         showTable(dealer, player);
				 }
			} while ( hit );

				// now show dealer down card
			showFullTable(dealer, player);

				// now get dealer careds if nneded
			if ( !player.busted() )
			{
				while ( dealer.wantCard() )
				{
					cout << endl << "Dealer takes a card" << endl;
					dealer.takeCard(dealer.dealCard());
					showFullTable(dealer, player);
				}
			}

				// decide who won
			if ( player.busted() )
			{
				cout << "You busted, you lost" << endl;
				player.lost();
			}
			else if ( dealer.busted() )
			{
				cout << "Dealer busted, you won" << endl;
				player.won();
			}
			else if ( player.getScore() > dealer.getScore() )
			{
				cout << "You beat the dealers hand" << endl;
				player.won();
			}
			else if ( player.getScore() < dealer.getScore() )
			{
				cout << "Dealers hand beat yours" << endl;
				player.lost();
			}
			else
			{
				cout << "Push, neither won" << endl;
			}

                // update your stake and toss the old cards
			cout << "Your stake is now " << player.getStake() << endl;
			player.clearHand();
			dealer.clearHand();

			// see if done
		donePlaying = getResponse("Are you done playing (y/n)?");
	} while ( !donePlaying );


	return 0;
}

    // show the table with dealer card down
void showTable(Dealer & dealer, Player & player)
{
	cout << endl << "The current table is " << endl;
	cout << "  dealer: ";
	cout << dealer.showHand() << endl;
	cout << "  player: ";
	cout << player.showHand() << endl;

}

    // show the table with dealer cards showing
void showFullTable(Dealer & dealer, Player & player)
{
	cout << endl << "The full table is " << endl;
	cout << "  dealer: ";
	cout << dealer.fullHand() << endl;
	cout << "  player: ";
	cout << player.showHand() << endl;

}

    // get a new legal bet
int getBet(int stake)
{
	int bet;
    bool valid = false;
	do {
        valid = true;
		cout << "Enter your bet (between 1 and your stake): ";
		cin >> bet;
        if ( cin.fail() )
        {
            cout << "Invalid input " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }
        else
            if ( bet <= 0 or bet > stake )
            {
                cout << "Invalid bet amount" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                valid = false;
            }
	} while ( !valid );
	return bet;
}

    // get a valid stake
int getStake(){
	int stake;
    bool valid;
	do {
		cout << "Enter your starting gambling stake: ";
		cin >> stake;
        valid = true;
        if ( cin.fail() )
        {
            cout << "Invalid input " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }
        else
            if ( stake <= 0 )
            {
                cout << "Invalid stake amount" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                valid = false;
            }
	} while ( !valid );
	return stake;
}

    // get a yes or no response to a question
bool getResponse(string question){
	char response;
	bool done = false;
	bool invalidResponse = true;
	do {
		cout << question << " ";
		cin >> response;
		switch (response){
			case 'y':
			case 'Y':
				done = true;
				invalidResponse = false;
				break;
			case 'n':
			case 'N':
				done = false;
				invalidResponse = false;
				break;
			default:
				invalidResponse = true;
		}
	} while ( invalidResponse );
	return done;
}



