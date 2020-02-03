//
//  recursion.cpp
//  Recursion
//
//  Created by jim bailey on 1/23/19.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0 International License.
//website help https://stackoverflow.com/questions/4367260/creating-a-recursive-method-for-palindrome
//https://www.geeksforgeeks.org/recursive-function-check-string-palindrome/

#include "recursion.h"
#include <iostream>

using namespace std;

// this is your recursive palindrome program
// it might have different arguments, depending on how you solved the problem
bool isPalindrome(string value)
{
    if(value.length() <=1) //base case
        {
            return true;
        }
    //calling the recursive function isPalindrome
    return (value[0]==value[value.length()-1] && isPalindrome(value.substr (1, value.length()-2)));



/*string reverser(string input)
{
    int length = static_cast<int>(input.length());
    if (length == 0) //base case
        return "";
    length--;

    return input[length] + reverser(input.substr(0, length));
}*/

}








