#include <iostream>
#include <sstream>
#include "carlist.h"
//#include "car.h"

using namespace std;


/**************************************
// constructor, defines head
**************************************/
CarList::CarList()
{
    head = nullptr;
}

/**************************************
// destructor, deletes items, using recursion
**************************************/

CarList::~CarList()
{
    recDestruct(head);
}

/**************************************
// recursive method to walk down list, deleting items starting at tail
**************************************/

void CarList::recDestruct(Link * ptr)
{
    if ( ptr )
    {
        recDestruct(ptr->next);
        //delete the car also
        delete ptr->info;
        delete ptr;
    }
}
/**************************************
// recursive method to search the list
// uses overloaded equality operator in Car
**************************************/
bool CarList::recFind(Link * ptr, Car& info)
{
    if ( ptr == nullptr )
        return false;

    if (*(ptr->info) == info)
        return true;

    return recFind(ptr->next, info);
}


/**************************************
// creates a new car on heap
//creates new link
//adds link to head of list
input is make, color, year. Creates a new car,
creates a new link that points to that car,adds
the link to the head of the list
**************************************/
void CarList::addCar(std::string make, std::string color, int year)
{
    Link * tempLink = new Link;
    tempLink->info = new Car;
    //variable.method(pass through)
    tempLink->info->setYear(year);
    tempLink->info->setColor(color);
    tempLink->info->setMake(make);
    tempLink->next = head;
    head = tempLink;
}


/**************************************
// look for a car on the list
// create an instance of it, use recursive method to see if there
input is make, color, year. Creates a temporary car with those inputs. Uses the
overloaded equality operator to check the list to see if such a car exists. Returns true if found, false
otherwise
**************************************/
bool CarList::findCar(std::string make, std::string color, int year)
{
    Car finalCar(make, color, year);

    //expecting finalCar as an arguement
    return recFind(head,finalCar);
}


/**************************************
// remove the item at head and return its value
if list is empty, returns nullptr. Otherwise returns a pointer to the car at the head
of the list and deletes that struct
**************************************/
Car* CarList::removeHead()
{
        // deal with empty list
    if ( head == nullptr)
        return nullptr;

        // non-empty, so get first item and process
    Link * tempLink = head;
    Car * info = new Car;

    //
    info->setMake(head ->info-> getMake());
    info->setColor(head -> info -> getColor());
    info->setYear(head -> info -> getYear());

        // update head
    head = head->next;

        // delete old link
    delete tempLink;


    return info;
}


 /**************************************
 // build a sring  by walking down the list
// uses overloaded extraction operator in Car
return a string containing the Cars in the list. Use the overloaded << operator to
create this list. There should be a comma and space after each car.
**************************************/
string CarList::displayList()
{
    stringstream buffer;

        // start at the head
    Link * ptr = head;

        // until done with list
    while ( ptr )
    {
        buffer << ptr->info->getYear() << " "<<ptr->info->getColor()<< " "<<ptr->info->getMake()<<", ";
        ptr = ptr->next;
    }

        // now return the string
    return buffer.str();
}






