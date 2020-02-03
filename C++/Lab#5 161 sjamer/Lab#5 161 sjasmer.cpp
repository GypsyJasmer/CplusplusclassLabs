/* to do:
-data validation (outlined)
-nested loop set number of sticks (outlined)
-Go again (outlined)
-see if computer or two people (swap players)
*/

    // 2 -- get and validate input
    // integer between 1 and 3
    // not greater than remaining sticks
    // 3 -- update board
    // subtract move from number of sticks remaining
    // 4 -- see if done
    // if number of sticks is zero, set playing to false
    // 5 -- if not done, alternate player
    // if player 1, go to player 2
    // if player 2, go to player 1

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

 using namespace std;

 int main()
 {

bool valid = true;
const int Maxsticks = 11;
int removed, sticks=Maxsticks, whoplays=1;
char repeat ='n';
long Bignum = numeric_limits <streamsize>::max();



//Do while for play again
do {

    cout<< "Welcome to Nim!" <<endl;
    cout<< "2 Players will take turns removing 1, 2, or 3 sticks from the initial 11." <<
        "The player removing the last stick wins!" << endl;


    do
    {
        cout << "The game currently looks like this:" << endl;

        /*loops for sticks no need for nested due to
        declaration-or-expression(optional) ; declaration-or-expression(optional) ; expression(optional)
        */
        for (int i = 0; i< sticks; i++)
        {
            cout << "|";
        }
        cout << endl;

        if (whoplays == 1)
        {
            cout << "Player 1, it's your turn!" << endl;
        }
        else
        {
            cout << "Player 2, it's your turn!" << endl;
        }
        if(sticks<=11)
        {
            cout << "There are " << sticks << " sticks in the pile" << endl;
            cout << "Do you want to remove 1,2,or 3 sticks?"<<endl;
        }

        //data validation (outlined)
        do {
            cin >>removed;
            valid =true;
            if (cin.fail() || removed < 1 || removed > 3 )
            {
                cin.clear();
                cin.ignore(Bignum, '\n');
                cout << "Bad input, need 1, 2, or 3" << endl;
                valid = false;
            }
            } while (not valid);

            sticks = (sticks - removed);

            for(int i=sticks; i>0; i--)
            {
                cout << "|";
            }
            cout << endl;


            if (sticks<1)
            {
                cout << "Player " << whoplays << " is the winner!"<< endl;
                valid = false;
            }

            else if (whoplays==1)
            {
                whoplays=2;
            }
            else
            {
                whoplays=1;
            }


    } while (sticks >=0);

    // announce winner using player number
        cout << "The winner is " <<endl;
        cout <<"Go again, y/n?" << endl;
        cin >> repeat;

 } while (repeat =='y');

 cout << "Thanks for playing Nim, goodbye"<<endl;

return 0;
}


