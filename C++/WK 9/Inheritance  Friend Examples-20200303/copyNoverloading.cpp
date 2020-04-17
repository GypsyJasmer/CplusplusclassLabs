#include <iostream>
using namespace std;
// This example demostrates the use of a friend function


class Car
{
    int speed;
    string name;

    public:
    Car() { speed = 0; }
    Car(string n) { name = n; speed = 0; }
    void accelerate() { speed += 5; }
    void brake() { speed -= 5; }
    string getName() { return name; }
    int getSpeed() {return speed;}
 //   void setName(string n) { name = n; }
};

const int FLEET_SIZE = 10;

class Fleet
{
    Car* cars[FLEET_SIZE];
    int numCars;

    public:
    Fleet() { numCars = 0; }
    // TODO: add check for numCars < FLEET_SIZE in addCar
    void addCar(Car carObj)  { cars[numCars++] = new Car(carObj);}
    void removeCar() { delete cars[numCars--]; }
    void displayCars() { for (int i = 0; i < numCars; i++) cout << cars[i]->getName() << endl; }
};

int main()
{
    Car honda("Civic");
    for (int i = 0; i < 11; i++)    // accelerate to 55 - shouldn't get a ticket.
        honda.accelerate();
    cout << honda.getName() << " speed " << honda.getSpeed() << endl;

    Car ferrari("Ferrari");
    for (int i = 0; i < 20; i++)    // accelerate to 100 - should get a ticket!
        ferrari.accelerate();
    cout << "Ferrari speed: " << ferrari.getSpeed() << endl;

    // Use default copy constructor
    Car ford(honda);
    cout << "Ford speed: " << ford.getSpeed() << endl;

    Fleet myCars;
    myCars.addCar(honda);
    myCars.addCar(ferrari);
    cout << "My cars: " << endl;
    myCars.displayCars();

    // Use default copy constructor
    Fleet moreCars(myCars);
    cout << "More cars: " << endl;
    moreCars.displayCars();

    // change in myCars affects moreCars
    myCars.removeCar();
    cout << "More cars: " << endl;
    moreCars.displayCars();

    return 0;
}








