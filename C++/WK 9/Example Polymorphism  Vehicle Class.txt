#include <iostream>
using namespace std;

class Vehicle
{
    protected:
    int speed;
    int direction;
    public:
    Vehicle() { speed = 0; direction = 360;}
    int getSpeed() { return speed;}
    void setSpeed(int s) {speed = s;}
    int getDirection() {return direction;}
    void setDirection(int d) { direction = d; }
};

class Car :  public Vehicle
{
    private:
    int gear;
    int engineRPM;
    public:
    Car() {gear = 1; engineRPM = 0;}
    void changeGear(int g) { gear = g;}
    int getSpeed() {return engineRPM * gear / 100; }
    void setSpeed(int s) {engineRPM = s * 100 / gear;}
};

void accelerate(Vehicle* v1)
{
    for( int i = 0; i < 10; i++)
    {
        v1->setSpeed(v1->getSpeed()+ 10);
        cout << "Speed: " << v1->getSpeed() << endl;
    }
}

int main()
{
    Car myCar;
    myCar.setSpeed(100);
    cout << myCar.getSpeed() << endl;
    cout << myCar.getDirection() << endl;
    myCar.changeGear(4);
    cout << myCar.getSpeed() << endl;
    accelerate(&myCar);

    return 0;
}





