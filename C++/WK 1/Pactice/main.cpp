#include <iostream>
/*Create a two-dimensional integer array in main that is 4x5.
Write an input function that you pass the array into.
It then asks the user for 20 numbers and fills the array with them.
Create a one-dimensional integer array in main of size 4.
Write a summing function that you pass the two arrays into.
For each row in the first array, it places the sum of that row in the appropriate location in the second array.
Write an output function that takes your two arrays and outputs them.
For each row it should list the elements of the first array in order,
then it should show the sum of those values (from the second array), then it should show the average of those values*/

using namespace std;

const int COL = 5;

void filler(int theArray[][COL], int sizeofArray); //loads the array
void calc(int theArray[][COL], int twoD[], int sizeofArray);
void display(int theArray[][COL], int sizeofArray); //diaplays

int main()
{
    const int ROW=4;
    int oneDarray[ROW];
    int twoDarray[ROW][COL];
    int sum=0, average;


    filler(twoDarray, ROW);
    calc(oneDarray, twoDarray, ROW);
    display(twoDarray, ROW);


    return 0;
}

void filler(int theArray[][COL], int sizeofArray)
{
    cout<< "Enter 20 integers for the array"<<endl;

    for(int i=0; i<sizeofArray; i++)
        for(int j=0;j<COL; j++)
            cin>>theArray[i][j];
}
void calc(int theArray[][COL], int twoD[], int sizeofArray)
{
    int sum=0, average;
    for(int row=0, row<sizeofArray, row++) //sum loop
        for(int col, col<COL, col++)
    {
        sum+=filler[][];
        average=sum/SIZE
    }

}
void display(int theArray[][COL], int sizeofArray)
{
    for(int row=0; row<sizeofArray; row++)
        for(int column=0; column<COL; column++)
           {
               cout <<theArray[row][column] << " ";
           }
        cout<<endl;
}
