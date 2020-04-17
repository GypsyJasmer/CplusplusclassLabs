#include <iostream>
#include "car.h"
#include "carlist.h"

using namespace std;

//#define TEST_CAR
#define TEST_CARLIST

#ifdef TEST_CAR
#include "Car.h"
#endif

#ifdef TEST_CARLIST
#include "car.h"
#include "carlist.h"
#endif

int main()
{
    #ifdef TEST_CAR
        // default constructor (Ford, Black, 1910)
    cout << "Testing Car class" << endl;
    Car car1;

        // overloaded constructors
    Car car2("Pinto", "Purple", 1968);
    Car truck1("Toyota", "Blue", 2010);
    Car truck2("Jeep", "Green", 2008);

        // test default constructor
    cout << "Testing default constructor" << endl;
    cout << "Should be a: Black 1910 Ford" <<endl << "Actually is: ";
    cout << car1.getColor() << " " << car1.getYear() << " " << car1.getMake() << endl << endl;

        // test overloaded constructor
    cout << "Testing overloaded constructor" << endl;
    cout << "Should be a: Purple 1968 Pinto" << endl << "Actually is: ";
    cout << car2.getColor() << " " << car2.getYear() << " " << car2.getMake() << endl << endl;

        // test setters
    cout << "Testing setters" << endl;
    cout << "Should be a Blue 2010 Toyota, is ";
    cout << truck1.getColor() << " " << truck1.getYear() << " " << truck1.getMake() << endl;
    truck1.setColor("Green");
    truck1.setYear(2008);
    truck1.setMake("Jeep");
    cout << "Now should be a Green 2008 Jeep, is ";
    cout << truck1.getColor() << " " << truck1.getYear() << " " << truck1.getMake() << endl << endl;

        // testing extraction operator
    cout << "Testing extraction operator, next two lines should match" << endl;
    cout << car2.getYear() << " " << car2.getColor() << " " << car2.getMake() << endl;
    cout << car2 << endl << endl;

        // testing overloaded equality
    cout << "Testing equality" << endl;
    cout << car1 << ((car1 == truck1)?" is same as ":" is not same as ") << truck1 << endl;
    cout << truck1 << ((truck1 == truck2)?" is same as ":" is not same as ") << truck2 << endl << endl;

    cout << "Done with testing Car class" << endl << endl;
#endif // TEST_CAR

#ifdef TEST_CARLIST
    cout << "Testing CarList class" << endl;

    CarList theList;

        // testing adding items and displaying them
    theList.addCar("Taxi", "Yellow", 1992);
    theList.addCar("Ford", "White", 2017);
    theList.addCar("Honda", "Blue", 2010);
    theList.addCar("Chevy", "Green", 2012);

    cout << "Display list, should be: " << endl;
    cout << " 2012 Green Chevy, 2010 Blue Honda, 2017 White Ford, 1992 Yellow Taxi, " << endl;
    cout << "Actualy is: " << endl;
    cout << " " << theList.displayList() << endl << endl;

        // testing find
    cout << "Testing find " << endl;
    Car car1("Chevy", "Blue", 2018);
    Car car2("Ford", "White", 2017);
    cout << car1 << ((theList.findCar("Chevy", "Blue", 2018))?" is ":" is not " ) << "in the list" << endl;
    cout << car2 << ((theList.findCar("Ford", "White", 2017))?" is ":" is not " ) << "in the list" << endl << endl;

        // testing removehead
    cout << "Testing remove head" << endl;
    cout << "Should be: " << theList.displayList() << endl;
    cout << "Actually is: ";
        // this list will terminate when nullptr is returned
    while ( Car * tempCar = theList.removeHead() )
    {
        cout << *tempCar << ", ";
        delete tempCar;
    }

        // testing find on empty list
    cout << endl <<endl << "Testing find on empty List " << endl;
    cout << car2 << ((theList.findCar("Ford", "White", 2017))?" is ":" is not " ) << "in the list" << endl << endl;


    cout << "Done with testing CarList class" << endl << endl;
#endif // TEST_CARLIST

    return 0;
}


