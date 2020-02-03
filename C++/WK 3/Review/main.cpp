#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int ROW = 6;
const int COL = 10;

void loadArray(int arrayTwo[][COL]);
void sumArray(int arrayTwo[][COL], int arrayOne[]);
void display(int arrayTwo[][COL], int arrayOne[]);


int main()
{
    int arrayTwo[ROW][COL];
    int arrayOne[ROW];


    loadArray(arrayTwo);
    sumArray(arrayTwo, arrayOne);
    display(arrayTwo, arrayOne);
    return 0;
}
// get 1 -99 integers from the user and fill the array
// no error checking
void loadArray(int arrayTwo[][COL])
{
srand(time(NULL)); //seed generator

for (int i = 0; i < ROW; i++)
    for (int j = 0; j < COL; j++)
    {
        arrayTwo[i][j] = rand()%99 +1; //range from 1 to 99

    }


}
// sum rows of arrayTwo into arrayOne
void sumArray(int arrayTwo[][COL], int arrayOne[])
{
for (int i = 0; i < ROW; i++)
{
arrayOne[i] = 0;
for (int j = 0; j < COL; j++)
arrayOne[i] += arrayTwo[i][j];
}
}
// display values, sums, and averages
void display(int arrayTwo[][COL], int arrayOne[])
{
for (int i = 0; i < ROW; i++)
{
for (int j = 0; j < COL; j++)
cout << setw(5) << arrayTwo[i][j];
cout << " sum " << arrayOne[i] << " average " << arrayOne[i]/COL << endl;
}
}
