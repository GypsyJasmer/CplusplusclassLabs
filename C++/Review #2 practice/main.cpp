#include <iostream>
#include <limits>

/*Write a program that asks the user for an integer,
keeps asking until the user enters a value between -99 and 99,
and then outputs whether the number was positive, negative, or zero.
*/
using namespace std;

int main()
{

bool valid = true;
int input;
const int MAX=99, MIN=-99;
long Bignum = numeric_limits <streamsize>:: max();

   do
    {
        cout <<"Please enter a number between -99 and 99" << endl;

        //data validation (outlined)
        do {
            cin >>input;
            valid =true;
            if (cin.fail() && input>-99 || input<99 )
            {
                cin.clear();
                cin.ignore(Bignum, '\n');
                cout << "Computer says no" << endl;
                valid = false;
            }
            } while (not valid);


    if (input < MIN || input > MAX)
    {
        cout<<"Computer says no, please input a whole number between -99 to 99"<< endl;

    }
    else
        if (input<0) //this output if value is less than 0 and would be a negative number.
    {
        cout<< input << " is a negative number"<<endl;
    }
        else
            if (input >0)//this out is if input is greater than 0 which would be a positive number.
        {
            cout<< input << " is a positive number"<< endl;

        }
            else
                cout<< "Your number was zero"<< endl;
    }while(input !=-1);

    return 0;
}
