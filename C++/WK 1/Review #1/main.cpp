/*
Write a program that fills a 2D array with the multiplication table up to 5 * 5.
You should define the array in main, then have one function that fills it with values and another that displays it.

website help
http://www.cplusplus.com/forum/beginner/123585/
*/
#include <iostream>
#include <limits>


using namespace std;

// global constants
const int MAX_ROW=5;
const int MAX_COL=5;
const long BIGNUM = numeric_limits <streamsize>::max();


void getValues(int sandi[MAX_ROW][MAX_COL]);
void display(int sandi[MAX_ROW][MAX_COL]);


int main()
{

    int sandi[MAX_ROW][MAX_COL];

	for(int row=0; row<5; row++)
	{
		for(int column=0; column <5; column++)
		{
			sandi[row][column]=row*column;
        }
	}

    //I'm pretty sure I have to take the value given and store it but still a little confused.
	value=getValues(sandi);
    display(sandi);


return 0;
}

//I don't understand what values you want filled or what the user is supposed to input.
void getValues(int sandi[MAX_ROW][MAX_COL])
{
    cout << "Enter a positive integer." <<endl;

    int value;
    bool valid = true;

    do {
        cin >>value;
        valid =true;
        if (cin.fail() || value > 0)
        {
            cin.clear();
            cin.ignore(BIGNUM, '\n');
            cout << "Computer says no, Enter a positive integer << endl;
            valid = false;
        }
        } while (not valid);


/*OR
        cin>>value[0];
        cin>>value[1];
        cin>>value[2];
        cin>>value[3];
        cin>>value[4];
        cin>>value[5];

*/

}

//cout of the display of the table.
void display(int sandi[MAX_ROW][MAX_COL])
{
    for(int row=0; row<5; row++)
	{
		for(int column=0; column <5; column++)
		{
			cout<<sandi[row][column]<<endl;
        }
}
