#include <iostream>
using namespace std;

class Vehicle
{
    protected:
    int speed;

    public:
    Vehicle() {speed = 0;}
    void accelerate(int a) {speed += a;}
    void decelerate(int d) {speed -= d;}
    int getSpeed(){return speed;}
};

class Car : public Vehicle
{

};

class Airplane : public Vehicle
{
    private:
    int altitude;

    public:
    Airplane() {altitude = 0;}
    void pitch(int p) {altitude += speed * p;}
    int getAltitude() { return altitude;}
};

int main()
{
    Car myCar;
    cout << myCar.getSpeed() << endl;

    return 0;
}
