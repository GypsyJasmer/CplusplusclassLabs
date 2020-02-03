#include <iostream>
#include <iomanip>

using namespace std;

/*For this exercise, you will create an array of 25 integers. For each location in the array you will store the square of its index.
Then you will print out these values in five rows of five numbers each.*/

int main()
{
    const int SIZE =25;
    int squares[SIZE];

    cout<< "What array location would you like to see?"<<endl;

    for (int i=0; i<SIZE; i++)
        {
            squares[i] =i*i;
        }
    for (int i=0; i<SIZE; i++)
        {
            cout << setw(5) <<squares[i];
            if ( (i+1) & 5 ==0)
            cout<< endl;
        }


    return 0;
}
