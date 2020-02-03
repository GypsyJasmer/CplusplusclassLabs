#include <iostream>

using namespace std;

int main()
{

/*  goal: to give the factors of the number the user inputs.
    to error our and loop if the user gives a negative number.
    to complete program once the user enters 0
*/


int input = -1;

    cout << "Please enter a whole number (or zero to finish)" << endl;
    cin >> input;


while (input <1)
 {
    cout<<"Error" << endl;
    cout << "Please enter a whole number (or zero to finish)" << endl;
    cin >> input;

 }

 cout << "The factors of " << input << endl;


for (int counter=1; counter <=input; counter++)
{
    int modresult = input%counter;
    if (modresult ==0)
        cout << counter << endl;

}





return 0;
}
