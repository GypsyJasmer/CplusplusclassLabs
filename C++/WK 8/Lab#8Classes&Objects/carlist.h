//
//  StructList.h
//  List_of_Cars
//
//  Created by Jim Bailey on 2/17/18.
//  Copyright © 2018 jim. All rights reserved.
//

#ifndef CARLIST_H_INCLUDED
#define CARLIST_H_INCLUDED

#ifndef CarList_h
#define CarList_h

#include <string>
#include "car.h"


struct Link {
    Link * next;
    Car* info;
};


class CarList {
    private:
        Link *head;

        // recursive methods
        void recDestruct(Link * ptr);
        bool recFind(Link * ptr, Car& info);

    public:
        CarList();
        ~CarList();//destructor when list goes away delete all the links of the list.

        //input is color, color, year. Creates a new car, creates a new link that points to that car,adds the link to the head of the list
        void addCar(std::string make, std::string color, int year);
        bool findCar(std::string make, std::string color, int year);
        Car* removeHead();
        std::string displayList();



};


#endif /* CarList_h */


#endif // CARLIST_H_INCLUDED
