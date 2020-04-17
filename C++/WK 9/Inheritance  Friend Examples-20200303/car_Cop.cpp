#include <iostream>
using namespace std;
// This example demostrates the use of a friend function

class Car;  // Forwar declaration needed since Cop uses Car

class Cop
{
    static const int speedLimit = 55;

    public:
    bool giveTicket(Car&);      // Uses pass by reference to get access to actual member variables of Car objects
};


class Car
{
    int speed;

    public:
    Car() { speed = 0; }
    void accelerate() { speed += 5; }
    void brake() { speed -= 5; }
    friend bool Cop::giveTicket(Car&);  // Friend function. Gives access to private speed variable
};

// Function definition must be after both the Car and Cop declarations
bool Cop::giveTicket(Car& c)
{ return c.speed > speedLimit; }


int main()
{
    Car honda;
    for (int i = 0; i < 11; i++)    // accelerate to 55 - shouldn't get a ticket.
        honda.accelerate();
    Cop police;
    if( police.giveTicket(honda) )
        cout << "Siren and flashing light behind the Honda!" << endl;

    Car ferrari;
    for (int i = 0; i < 20; i++)    // accelerate to 100 - should get a ticket!
        ferrari.accelerate();
    if( police.giveTicket(ferrari) )
        cout << "Siren and flashing light behind the Ferrari!" << endl;

    return 0;
}








