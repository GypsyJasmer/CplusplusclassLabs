#include <iostream>
using namespace std;
// This example demostrates the use of a friend function


class Car
{
    int speed;
    string model;
    public:
    Car() { speed = 0; }
    Car(const Car& c) { model = c.model; speed = 0; }
    void setModel(string m) { model = m; }
    string getModel() { return model; }
    int getSpeed() { return speed; }
    void accelerate() { speed += 5; }
    void brake() { speed -= 5; }
};

const int FLEET_SIZE = 10;
class Fleet
{
    Car* cars[FLEET_SIZE];
    int nCars;
    public:
    Fleet() { nCars = 0; }
    Fleet(const Fleet& f)
    {
        nCars = f.nCars;
        for (int i = 0; i < nCars; i++)
            cars[i] = new Car(*f.cars[i]);
    }

    void addCar(Car c) { cars[nCars++] = new Car(c); }
    Car* getCar() { return cars[nCars - 1]; }
    void displayFleet()
    {
        for (int i = 0; i < nCars; i++)
            cout << cars[i]->getModel() << endl;
    }

};

int main()
{
    Car honda;
    honda.setModel("Civic");
    for (int i = 0; i < 11; i++)    // accelerate to 55 - shouldn't get a ticket.
        honda.accelerate();
    cout << honda.getModel() << " is going " << honda.getSpeed() << endl;

    Car ferrari;
    ferrari.setModel("Enzo");
    for (int i = 0; i < 20; i++)    // accelerate to 100 - should get a ticket!
        ferrari.accelerate();
    cout << ferrari.getModel() << " is going " << ferrari.getSpeed() << endl;

    Car ferrari2(ferrari);
    cout << ferrari2.getModel() << " is going " << ferrari2.getSpeed() << endl;

    Car ferrari3;
    ferrari3 = ferrari;
    cout << ferrari3.getModel() << " is going " << ferrari3.getSpeed() << endl;


    Fleet yourFleet;
    yourFleet.addCar(honda);
    yourFleet.addCar(ferrari);
    yourFleet.addCar(ferrari2);
    yourFleet.displayFleet();

    Fleet myFleet(yourFleet);
    cout << "change last car to Dino" << endl;
    yourFleet.getCar()->setModel("Dino");
    cout << "yourFleet:" << endl;
    yourFleet.displayFleet();
    cout << "myFleet:" << endl;
    myFleet.displayFleet();

    return 0;
}








