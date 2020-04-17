//
//  StructList.h
//  List_of_Cars
//
//  Created by Jim Bailey on 2/17/18.
//  Copyright © 2018 jim. All rights reserved.
//

#ifndef StructList_h
#define StructList_h

#include <string>


struct Link {
    Link * next;
    int value;
};


class StructList {
private:
    Link *head;
    
    // recursive methods
    void recDestruct(Link * ptr);
    bool recFind(Link * ptr, int value);
    
public:
    StructList();
    ~StructList();
    
    void addValue(int value);
    
    bool findValue(int value);
    
    int removeHead();
    
    std::string displayList();
};


#endif /* StructList_h */
