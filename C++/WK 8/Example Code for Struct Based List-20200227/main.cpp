//
//  main.cpp
//  StuctList Tester
//
//  Created by Jim Bailey on 2/17/18.
//  Copyright © 2018 jim. All rights reserved.
//

#include <iostream>

using namespace std;

#include "StructList.h"


int main()
{

    cout << "Testing StructList class" << endl;
    
    StructList theList;
    
        // testing adding items and displaying them
    theList.addValue(6);
    theList.addValue(12);
    theList.addValue(33);
    theList.addValue(99);
    
    cout << "Display list, should be: " << endl;
    cout << " 99, 33, 12, 6," << endl;
    cout << "Actualy is: " << endl;
    cout << " " << theList.displayList() << endl << endl;
    
        // testing find
    cout << "Testing find " << endl;
    cout << 42 << ((theList.findValue(42))?" is ":" is not " ) << "in the list" << endl;
    cout << 99 << ((theList.findValue(99))?" is ":" is not " ) << "in the list" << endl << endl;
    
        // testing removehead
    cout << "Testing remove head" << endl;
    cout << "Should be: " << theList.displayList() << endl;
    cout << "Actually is: ";
        // this list will terminate when -1 is returned
    int value;
    while ( (value = theList.removeHead()) != -1 )
    {
        cout << value << ", ";
    }
    
        // testing find on empty list
    cout << endl <<endl << "Testing find on empty List " << endl;
    cout << 99 << ((theList.findValue(99))?" is ":" is not " ) << "in the list" << endl << endl;
    
    
    cout << "Done with testing StructList class" << endl << endl;

    
    return 0;
}
