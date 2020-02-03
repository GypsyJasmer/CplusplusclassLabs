
#include <iostream>
#include <limits>


using namespace std;

const long BIGNUM = numeric_limits <streamsize>::max();

int getValue(int num1);
void doCalc(int values, int numVal);

int main()
{
/*
Main should look like this

-ask for number of values
-get the number of values to be entered (using getValue)
-call doCalc to read in that many values, sum them, and return the total and average

-display the total and average
*/

    int numVal, average;
    bool valid = true;

    cout<<"Enter the number of values." <<endl;
      //data validation for the number of values entered.
        do {
            cin >>numVal;
            valid =true;
            if (cin.fail() || numVal<2)
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Please enter the numbers of data" << endl;
                valid = false;
            }
            } while (not valid);

    getValue(int numVal);
    doCalc(int values, int numVal);




return 0;
}

//getNumber:  input a number, validate it, and return it
int getValue(int num1)
{
    int numVal, values;
    cout<< "Enter"<< numVal << "whole numbers between 1-99"<<endl;

            //data validation
        do {
            cin >>values;
            valid =true;
            if (cin.fail() || values>=1 && values<99)
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Computer says no" << endl;
                valid = false;
            }
            } while (not valid);


    return values;
}

//call doCalc to read in that many values, sum them, and return the total and average
//doCalc:  pass in a count, read in that many numbers, sum them, and return the total and average
void doCalc(int values, int numVal)
{
    int sum, average, values, numVal;

    sum=sum+values;
    average=sum/numVal;
    cout << "The sum of all the numbers is " << sum <<endl;
    cout << "The average of all the numbers is "<< average <<endl;

}
