#include <iostream>
#include <fstream>
#include <limits>
#include <cctype>

using namespace std;


void draw_triangle(char out_char, int base);
void draw_square(char out_char, int side);
void draw_diamond(char out_char, int n);
void draw_rectangle(char out_char, int rows, int columns);

int main()
{

    char out_char, shape;
    const char SQUARE = 'S', RECTANGLE = 'R', TRIANGLE = 'T', DIAMOND = 'D';
    int num1, num2;


    //Reading infile for char to draw shapes listed below.
    ifstream infile;
    infile.open("infile.txt");


while(infile>> shape && shape!='E')  //E= exit and infile works as a bool will loop while true.
{
    switch (shape)
     {
     case DIAMOND: //diamond one variable
        infile>>out_char;
        infile>>num1;
        draw_diamond(out_char, num1);
        break;
      case SQUARE: //square one variable
        infile>>out_char;
        infile >>num1;
        draw_square(out_char, num1);
        break;
    case RECTANGLE: //two variables
        infile>>out_char;
        infile >>num1;
        infile>>num2;
        draw_rectangle(out_char, num1, num2);
        break;
    case TRIANGLE: //one variable
        infile>>out_char;
        infile>>num1;
        draw_triangle(out_char, num1);
        break;
    default:
        cout << "Error" << endl;
     }


}

    infile.close(); //closing file

    return 0;


}

void draw_triangle(char out_char, int base)
{

    for (int i=0; i<base; i++)
        {
           for (int j=0; j<=i; j++)
            {
                cout<< out_char;
            }
            cout << endl;
        }
}
void draw_square(char out_char, int side)
{
    for (int i=0; i<side; i++)
    {
        for (int j=0; j<side; j++)
        {
            cout<<out_char;
        }
        cout << endl;
    }
}

void draw_diamond(char out_char, int n)
{
  int space = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < space; j++)
           {
            cout << " ";
           }
            for (int j = 0; j <= i; j++)
                {
                    cout <<out_char<< " ";
                }
        cout << endl;
        space--;
    }
    space = 0;

    for (int i = n-1; i >0; --i)
    {
        for (int j = -1;j < space; j++)
        {
            cout<< " ";
        }
        for (int j = 0; j < i; j++ )
        {
            cout<< out_char<< " ";
        }
        cout<< endl;
        space++;
    }
}

void draw_rectangle(char out_char, int rows, int columns)
{
    for (int i =0; i<columns; i++)
    {
        for(int j=0; j<rows; j++)
            {
                cout <<out_char;
            }
        cout << endl;
    }
}


