/*
In order to give you more prac:ce with pointers, you are to do all array element accesses with a pointer
instead of using subscrip:ng. (int * ptr = array; *ptr = value; instead of array[0] = value;)
-used Jim's documents from our example problems.
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// global constants
const long BIGNUM = numeric_limits <streamsize>::max();

// function protocols
void getSize(int theArray[]);
int createArray(int theArray[], int theSize);
void sortArray(int theArray[], int theSize);
void displayArray(int theArray[], int theSize);
bool binarySearch(int theArray[], int theSize);
int getInteger(int theArray[], int theSize);

int main()
{
/*Process
-you will get a value from the user between 10 and 20,
-create an array of this size using dynamic memory allocation,
-fill the array with random numbers between 1 and 99,
-sort the array,
-then display the array
-You will then ask the user for 3 numbers and for each value you will say whether it
is in the array or not.
*/
    int theArray[SIZE];


    arraySize=getSize(arr, theSize);
    createArray(arr, theSize);
    sortArray(arr, theSize);
    displayArray(arr, theSize);

//inner loop 3x's
while(//3's)
    {
    binarySearch(arr[], theSize)
    getInteger
    //output if found
    }


    return 0;
}


//ask user for array size values 10-20
int getArraySize((int theArray[], int theSize)
{
    //data validation of array that is between 10-20.return value to main.
int arraySize;
bool valid = true;

cout << "Please enter a number from 10-20" << endl;
    //data validation of player's choice
    do {
        cin >>arraySize;
        valid =true;
        if (cin.fail() || arraySize <10 || arraySize>20)
        {
            cin.clear();
            cin.ignore(BIGNUM, '\n');
            cout << "Computer says no, invalid move" << endl;
            valid = false;
        }
        } while (not valid);


    return arraySize;
}

//initiate array fill w/ rand 1 -99 integers
int createArray(int theArray[], int theSize)
{

//dynamic memory allocation
srand(time(NULL)); //seed generator

    for(int i = 0; i < theSize; i++)
        arr[i] = rand() % 99 + 1;
}

//pass main array & length, array sorted in ascending order.
// insertion sort, smallest to largest
void sortArray(int theArray[], int theSize)
{
    // Go through entire array
    for(int i = 1; i < theSize; i++)
    {
        int temp = arr[i];
        int index = i - 1;
        while ( index > -1 and arr[index] > temp )
        {
            swap(arr[index], arr[index+1]);
            index--;
        }

    }

}

//pass array display 5 values per line
void displayArray(int theArray[], int theSize)
        const int NUMS_PER_ROW = 5;
    int counter = 0;
    for(int i = 0; i < theSize; i++)
    {
        cout << setw(6) << arr[i];
        counter++;
        if (counter >= NUMS_PER_ROW)
        {
            counter = 0;
            cout << endl;
        }
    }
}

//return true if value is in the array false otherwise has to binary search
bool binarySearch(int theArray[], int theSize)
{
    int low = 0;
    int high = theSize - 1;

    while ( low < high )
    {
        int mid = (low + high) / 2;
        if ( arr[mid] == theValue )
            return true;
        if ( arr[mid] > theValue )
            high = mid - 1;
        if ( arr[mid] < theValue )
            low =  mid + 1;
    }

    return false;
}

//asks user 1-99
int getInteger(int theArray[], int theSize)
{
        //data validation of array that is between 1-99
int value;
bool valid = true;

cout << "What number from 1-99 are you looking for?" << endl;
    //data validation of player's choice
    do {
        cin >>value;
        valid =true;
        if (cin.fail() || value <1 || value>99)
        {
            cin.clear();
            cin.ignore(BIGNUM, '\n');
            cout << "Computer says no, invalid move" << endl;
            valid = false;
        }
        } while (not valid);


    return value;
}
