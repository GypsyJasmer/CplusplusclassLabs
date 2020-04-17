//I'm pretty sure there are memory leaks.

#include <iostream>
#include <iomanip>

using namespace std;

// global constants
const int SIZE = 10;

void createArray(int theArray[]);
void displayArray(int theArray[]);

int main()
{

    int theArray[SIZE];

    createArray(theArray); //calling function to initiate array
    displayArray(theArray); //calling function to display array.

return 0;

}

void createArray (int theArray[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 != 0)
        {
            theArray[i] += i;
        }
    }

}
void displayArray(int theArray[])
{
   cout << "Here are the first 10 odd numbers" << endl;

    const int NUMS_PER_ROW = 5;
    int counter = 0;

    for(int i = 0; i < SIZE; i++)
    {
        cout << setw(6) << theArray[i];
        counter++;
        if (counter >= NUMS_PER_ROW)
        {
            counter = 0;
            cout << endl;
        }
    }
    cout << endl;
}
