#include <iostream>
using namespace std;
// This example demostrates the use of a friend function

class Car
{
    int speed;
    string model;

    public:
    Car() { speed = 0; model = "Car";}
    Car(const Car& c) { speed = 0; model = c.model; }
    void operator=(const Car& c) { speed = 0; model = c.model; }
    void accelerate() { speed += 5; }
    void brake() { speed -= 5; }
    string getModel() { return model; }
    void setModel(string m) { model = m; }
    int getSpeed() { return speed; }
};

const int FLEET_SIZE = 10;
class Fleet
{
    Car* cars[FLEET_SIZE];
    int numCars;

    public:
    Fleet() { numCars = 0; }
    Fleet(const Fleet& f) {
        numCars = f.numCars;
        for (int i = 0; i < numCars; i++)
            cars[i] = new Car(*f.cars[i]); }
    void operator+=(const Car& c) {addCar(c); }
    Fleet operator+(const Car& c) {
        addCar(c);
        return *this;
    }
    void addCar(const Car &c) { cars[numCars++] = new Car(c); }
    Car* getCar() { return cars[numCars - 1]; }
    void display() {
        for (int i = 0; i < numCars; i++)
            cout << cars[i]->getModel() << endl;  }
};

int main()
{
    Car honda;
    honda.setModel("Civic");
    for (int i = 0; i < 11; i++)    // accelerate to 55 - shouldn't get a ticket.
        honda.accelerate();

    Car ferrari;
    ferrari.setModel("Enzo");
    for (int i = 0; i < 20; i++)    // accelerate to 100 - should get a ticket!
        ferrari.accelerate();

    Car ferrari2(ferrari);
    cout << "Ferrari2: " << ferrari2.getSpeed() << endl;
    Car ferrari3;
    ferrari3 = ferrari;
    cout << "Ferrari3: " << ferrari3.getModel() << " " << ferrari3.getSpeed() << endl;

    cout << "My fleet:" << endl;
    Fleet myFleet;
    myFleet.addCar(honda);
    myFleet.addCar(ferrari);
    myFleet.addCar(ferrari2);
    myFleet.addCar(ferrari3);
 //   myFleet.addCar(honda):
    myFleet += honda;
    myFleet = myFleet + honda;
    myFleet.display();

    cout << "Your fleet:" << endl;

    Fleet yourFleet(myFleet);
    myFleet.getCar()->setModel("Dino");
    yourFleet.display();

    return 0;
}








