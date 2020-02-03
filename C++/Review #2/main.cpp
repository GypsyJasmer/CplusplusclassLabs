#include <iostream>
#include <limits>

using namespace std;
/*Write a program that asks a user to enter a word from the following list
(turtle, tree, tin. If they entered the word turtle tell them they picked
 an animal. If they entered the word tree, picked a plant.
 IF they entered tin tell them they picked a mineral.
 if they did not enter one of these words, output an error message.
*/
int main()
{

bool valid = true;
char repeat = 'n';
string input;
const string turtle, tree, tin;
long Bignum = numeric_limits <streamsize>:: max();

do {
    cout <<"Please pick one item from the following list, turtle, tree, or tin" << endl;

            //data validation (outlined)
        do {
            cin >>input;
            valid =true;
            if (cin.fail() || (input !=TURTLE && input !=TREE && input !=TIN))
            {
                cin.clear();
                cin.ignore(Bignum, '\n');
                cout << "Computer says no, please enter turtle, tree, or tin" << endl;
                valid = false;
            }
            } while (not valid);



    if (input == turtle)
    {
        cout<<"You picked an animal"<< endl;

    }
    else
        if (input== tree)
    {
        cout<< "You picked a plant" <<endl;
    }
        else
            if (input ==tin)
        {
            cout<< "You picked a mineral" << endl;

        }

        cout <<"pick again?" << endl;
        cin >> repeat;
 } while (repeat =='y');

    return 0;
}
