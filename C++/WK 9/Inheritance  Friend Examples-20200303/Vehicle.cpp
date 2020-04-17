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
    public:
    void changeGear(int gear) { speed *= gear;}
};

int main()
{
    Car myCar;
    myCar.setSpeed(100);
    cout << myCar.getSpeed() << endl;
    cout << myCar.getDirection() << endl;
    myCar.changeGear(4);
    cout << myCar.getSpeed() << endl;
    return 0;
}





