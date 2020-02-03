//
//  main.cpp
//  Recursion
//
//  Created by jim bailey on 1/23/19.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0 International License.
//

#include <iostream>
#include "recursion.h"

using namespace std;


int main()
{

    cout << "Testing palindromes" << endl << endl;

    const int NUM_WORDS = 5;
    string words[] = {"avid diva", "civic", "banana", "racecar", "dog"};

    for(int i = 0; i < NUM_WORDS; i++)
    {
        cout << words[i] << (isPalindrome(words[i])?" is ":" is not ") << "a palindrome" << endl;
    }

    cout << "They should all pass except banana and dog" << endl << endl;
    cout << "Done testing palindromes" << endl << endl;


    return 0;
}
