#include <iostream>
#include "TTT.h"
using namespace std;

bool repeat();

int main()
{
    do {
        TTT * theBoard = new TTT;
        theBoard->instructions();
        char player = X;
        bool done = false;
        do {

            theBoard->display();
            theBoard->getMove(player);
            done = theBoard->isWin() or theBoard->isTie();
            if (!done)
                player = (player == X)?O:X;
        } while (!done);

        if (theBoard->isWin())
            cout << "Player " << player << " you win" << endl;

        if (theBoard->isTie())
            cout << "Tie game" << endl;

        delete theBoard;

    } while (repeat());
    return 0;
}

bool repeat()
{
    const int BIG_NUM = 100;
    const char EOL = '\n';
    cout << "Do you want to play again? (Y/N) ";
    char response;
    do {
        cin >> response;
        response = tolower(response);
        if ( response != 'y' and response != 'n' )
        {
            cout << "Invalid response" << endl;
            cin.clear();
            cin.ignore(BIG_NUM, EOL);
        }
    } while (response != 'y' and response != 'n');
    return response == 'y';
}
