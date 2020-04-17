//
//  StructList.cpp
//  List_of_Cars
//
//  Created by Jim Bailey on 2/17/18.
//  Copyright © 2018 jim. All rights reserved.
//

#include "StructList.h"
#include <sstream>

// constructor, defines head
StructList::StructList()
{
    head = nullptr;
}

// destructor, deletes items, using recursion
StructList::~StructList()
{
    recDestruct(head);
}

// recursive method to walk down list, deleting items starting at tail
void StructList::recDestruct(Link * ptr)
{
    if ( ptr )
    {
        recDestruct(ptr->next);
        delete ptr;
    }
}

// recursive method to search the list
// uses overloaded equality operator in Car
bool StructList::recFind(Link * ptr, int value)
{
    if ( ptr == nullptr )
        return false;
    
    if (ptr->value == value )
        return true;
    
    return recFind(ptr->next, value);
}

// creates a new car on heap
//creates new link
//adds link to head of list
void StructList::addValue(int value)
{
    Link * tempLink = new Link;
    tempLink->value = value;
    tempLink->next = head;
    head = tempLink;
}

// look for a car on the list
// create an instance of it, use recursive method to see if there
bool StructList::findValue(int value)
{
    return recFind(head, value);
}

// remove the item at head and return its value
int StructList::removeHead()
{
        // deal with empty list
    if ( head == nullptr )
        return -1;
    
        // non-empty, so get first item and process
    Link * tempLink = head;
    int value = head->value;
    
        // update head
    head = head->next;
    
        // delete old link
    delete tempLink;
    
        // return the value
    return value;
}

// build a sring  by walking down the list
// uses overloaded extraction operator in Car
std::string StructList::displayList()
{
    std::stringstream buffer;
    
        // start at the head
    Link * ptr = head;
    
        // until done with list
    while ( ptr )
    {
        buffer << ptr->value << ", ";
        ptr = ptr->next;
    }
    
        // now return the string
    return buffer.str();
}
