/*
1.write draw shape functions
2. get basic main working
3. read from file (cin change to input)
4. write to file was nested for loop and cout is replaced with output << (in function)
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void draw_triangle(char char_out, int width, int length);
void draw_square(char char_out, int width, int length);
void draw_diamond(char char_out, int width, int length);
void draw_rectangle(char char_out, int length);


int main()
{
    char 'T', 'S', 'D', 'R';

cout << "What shape do you want to draw? /n"
        "'T' for triangle, 'S' for square, /n"
        "'D' for diamond, and 'R' for rectangle." << endl;

    //enter data validation with TOUPPER

   ifstream infile;

   infile.open("infile.txt");

   ofstream outfile;

   outfile.open("output.txt");

   if (!infile.good())
   {
       cout << "Program failed to open correctly"<< endl;
   }
   else
   {
       string buffer;
       //see notes
       while(!infile.eof())
       {
           getline((infile, buffer);
           cout << buffer << endl;
       }

   }
   return 0;

}

void draw_triangle(char char_out, int width, int length)
{
    /* if code is for a TRIANGLE
    read num1 from infile.dat
    draw a triangle using out_char*/
}
void draw_square(char out_char, int size, ofstream & outfile)
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
        outfile << "The output char is " << out_char << " and the size is " << size << endl;
}
void draw_diamond(char char_out, int width, int length)
void draw_rectangle(char char_out, int length)
{
    /* if code is for a RECT
    read num1 and num2 from infile.dat
    draw a rectangle using out_char
    */
}



int main()
{
    char shape, out_char;
    int size;
    ifstream infile("input.txt");


    ... // some code here
    infile >> shape;
    if ( shape == SQUARE )
    {
        infile >> out_char;
        infile >> size;
        drawSquare(out_char, size);
    }



    ... // some more code here
    infile.close();
    return 0;
}

Now, if you are writing to a file in a function, you have two choices.  You can open it in main and pass it as a parameter to the function
int main()
{
    ofstream writeFile("output.txt");
    ..... // some code here
    drawSquare(out_char, size, writeFile);
    ......// some more code here
    writeFile.close();
    return 0;
}
------
void drawSquare(char out_char, int size, ofstream & outfile)
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
        outfile << "The output char is " << out_char << " and the size is " << size << endl;
}


/*OR
you can open it for appending in the method and close when done
int main()
{
    ..... // some code here
    drawSquare(out_char, size);
    ......// some more code here
    return 0;
}
----

void drawSquare(char out_char, int size)
{
     ofstream outfile(output.txt, ios::app);
     outfile << "The output char is " << out_char << " and the size is " << size << endl;
     outfile.close();
}
*/
