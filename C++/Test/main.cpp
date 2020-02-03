/*Write the necessary functions for the following program. Do not change main, just write the functions.

Area of a rectangle is length * width.
Area of a square is side * side;

getNumber returns a positive integer (validates as needed)
*/

#include <iostream>

int getNumber();
void area(int& area, int length, int width);

using namespace std;

int main()

{

    cout << "Enter length and width of a rectangle: ";

    int length = getNumber();

    int width = getNumber();

    cout << "Its area is " << area(length, width) << endl;



    cout << "Enter the side of a square ";

    int side = getNumber();

    cout << "Its area is " << area(side) << endl;



    return 0;

}

int getNumber() //needed data validation
{
    int value;
    cin >> value;
    return value;

}
void area(int& area, int length, int width)
{
    if (width==0)
        area=length*length;

    else
        area=length*width;
}
