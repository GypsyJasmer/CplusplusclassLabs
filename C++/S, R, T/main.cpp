#include <iostream>


using namespace std;


//Functions for shapes

void draw_square(int side1)
{
    int sqSide;
    cout << "What is the side length" << endl;
    cin >> sqSide;
    for (int i=0; i<sqSide; i++)
    {
        for (int j=0; j<sqSide; j++)
            cout<< "*";
            cout << endl;
    }
}
void draw_triangle(int side2)
{

    cout << "What is the side length" << endl;
    int trSide;
    cin >> trSide;
    for (int i=0; i<trSide; i++)
        {
           for (int j=0; j<=i; j++)
            cout<< "*";
            cout << endl;
    }

}
void draw_rectangle(int L, int W)
{
    int length1, width2;
    cout << "What is the length?" << endl;
    cin >> length1;
    cout << "What is the width?" << endl;
    cin >> width2;

    for (int i =1; i<=width2; i++)
    {
        for(int j=1; j<=length1; j++)
            cout << "*";
            cout << endl;
    }
}


int main()
{

//choose between shape

    cout << "Enter square, rectangle or triangle" << endl;
    string answer;
    cin >> answer;

    if (answer == "square")
    {

        int sqLength;
        draw_square(sqLength);
    }
    else
         if (answer == "rectangle")
         {

            int recLength, recWidth;
            draw_rectangle(recWidth, recLength);
        }
        else
             if (answer == "triangle")
             {
                int trLength;
                draw_triangle(trLength);
             }



    return 0;
}
