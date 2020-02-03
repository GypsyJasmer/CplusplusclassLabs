#include <iostream>

using namespace std;

void passbyvalue(int x);
void passbyreference(int *x);
void add(int &x);

int main()
{
    int betty=13;
    int sandi=13;

    passbyvalue(betty);
    passbyreference(&sandi);

    cout<< "Betty now is "<< betty<<endl;
    cout<<"Sandi now is " <<sandi << endl;

    int data=10;
    add(data); //passing data in add function

    /*data was 10 however in the
    add function w/ no return we can PBR into main
    because of the connection pbr makes.
    */
    cout << "Value in data = " << data << endl;

    return 0;

    return 0;
}

void add(int &x);
{
    int input; //Variable from user
    cout << "Enter the value to be added in data" << endl;
    cin >> input;

    /*input is user variable not passed memory
    x is data because we are passing that in the add (data) function.
    it becomes PBR because of the & but that allows the variable
    to be returned in main without the add function having to return as in pbv
    */
    x=x+input
}
void passbyvalue(int x)
{
    x=99;
}
void passbyreference(int *x)
{
    *x=100;
}
