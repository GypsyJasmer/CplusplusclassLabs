#include <iostream>


using namespace std;

int main()
{

 /* Goal: user to enter a positive number between 1-100
    display the smallest and largest number entered
    accept until value of 0 is entered

 */

 int input, smallest = 100, largest =1;

 while (input>1 || input< 100 && input !=0)
 {
     cout <<"Please enter a number between 1-100 and enter 0 to quit."<<endl;
     cin >> input;
        if(input > largest && input<=100)
            largest = input;
        if (input < smallest && input >=1)
            smallest = input;

        if(input>100 || input < 1)
            cout << "Error"<< endl;
 }

  while (input ==0)
 {
    input++;
 }

    cout << "The smallest number you entered is " << smallest<< endl;
    cout << "The largest number you entered is " << largest<< endl;




    return 0;
}
