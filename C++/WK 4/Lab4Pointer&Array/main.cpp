/*;

In order to give you more prac:ce with pointers, you are to do all array element accesses with a pointer
instead of using subscrip:ng. (int * ptr = array; *ptr = VALUE; instead of array[0] = VALUE;)
-used Jim's documents from our example problems.

*(anArray +i) =rand() %99;
or
anArray [i]

*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// global constants
const int MINSIZE=10;
const int MAXSIZE=20;
const int MINVALUE=1;
const int MAXVALUE=99;
const long BIGNUM = numeric_limits <streamsize>::max();

// function protocols
int getsize();
int *createArray(int size); //pointer needed
void sortArray(int *theArray, int size);
void displayArray(int *theArray, int size);
int getInteger();
bool binarySearch(int VALUE, int *theArray, int size);




int main()
{
    srand(static_cast<int>(time(NULL))); //why is this needed?
    //srand(time(NULL));

    int size=getsize();

    int *theArray = createArray(size);
    sortArray(theArray, size);
    displayArray(theArray, size);
    int VALUE = getInteger();
    bool inList = binarySearch(VALUE, theArray, size);

    if (inList)
    {
        cout<<"Your number is in the array."<<endl;
    }
    else

    {
        cout<<"Your number is NOT in the array."<<endl;
    }

/*
Process
-you will get a VALUE from the user between 10 and 20,
-create an array of this size using dynamic memory allocation,
-fill the array with random numbers between 1 and 99,
-sort the array,
-then display the array
-You will then ask the user for 3 numbers and for each VALUE you will say whether it
is in the array or not.
*/

    return 0;
}


//ask user for array size VALUEs 10-20
int getsize()
{
    //data validation of array that is between 10-20.return VALUE to main.
    int size;
    bool valid = true;

    cout << "Please enter a number from 10-20" << endl;
        //data validation of player's choice
        do {
            cin >>size;
            valid =true;
            if (cin.fail() || size <MINSIZE || size>MAXSIZE)
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Computer says no, invalid move" << endl;
                valid = false;
            }
            } while (not valid);


    return size;
}


//initiate array fill w/ rand 1 -99 integers
int *createArray(int size)
{

    int *theArray=new int[size];

    for(int i = 0; i < size; i++)
        {
            *(theArray +i) =rand() %99; //dereferencing
        }

        return theArray;
}

//pass main array & length, array sorted in ascending order.
// selection sort in ascending order
void sortArray(int *theArray, int size)
{
    int startScan, minIndex, minValue;

    for (startScan =0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = theArray[startScan];

        for(int i = startScan +1; i < size; i++)
        {
            if(theArray[i]<minValue)
            {
                minValue = theArray[i];
                minIndex = i;
            }
        }

        theArray[minIndex] = theArray[startScan];
        theArray[startScan] = minValue;
    }

}

//pass array display 5 VALUEs per line
void displayArray(int *theArray, int thesize)
{
    const int NUMS_PER_ROW = 5;
    int counter = 0;
    for(int i = 0; i < thesize; i++)
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


//asks user 1-99
int getInteger()
{
    //data validation of array that is between 1-99
    bool valid=true;
    int value;

    cout << "What number from 1-99 are you looking for?" << endl;
        //data validation of player's choice
        do {
            cin >>value;
            valid =true;
            if (cin.fail() || value<MINVALUE || value>MAXVALUE)
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Computer says no, invalid move" << endl;
                valid = false;
            }
            } while (not valid);


    return value;
}

//return true if value is in the array false otherwise has to binary search
bool binarySearch(int value, int *theArray, int size)
{
    int low = 0;
    int high = size - 1;

    while ( low < high )
    {
        int mid = (low + high) / 2;
        if ( theArray[mid] == value )
            return true;
        if ( theArray[mid] > value )
            high = mid - 1;
        if ( theArray[mid] < value)
            low =  mid + 1;
    }

    return false;
}



