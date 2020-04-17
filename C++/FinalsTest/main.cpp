#include <iostream>

using namespace std;

class Vehicle{
    private:
        int price;
        int speed;
    public:
        Vehicle() { price = speed= 0; }
        void setPrice(int p) { price=p; }
        void setSpeed(int s) { speed=s; }
        int getPrice() { return price; }
        int getSpeed() { return speed; }

        // the following method is const so that it can be called from == in square
        int calcPrice() const { return price; }


};

class Bicycle : public Vehicle {
    public:
            // this uses parents methods
            // other approach would make width and height protected in Vehicle
            //   and access them directly
        void setPrice(int p) {
                                Vehicle::setPrice(p);
                                Vehicle::setSpeed(p);
                             }

            // this uses a const reference for efficiency and safety
        bool operator==(const Bicycle &other)
        {
            return ( this->calcPrice() == other.calcPrice() );
        }
};

class Tricycle : public Vehicle {
    public:
            // this uses parents methods
            // other approach would make width and height protected in Vehicle
            //   and access them directly
        void setPrice(int p) {
                                Vehicle::setPrice(p);
                                Vehicle::setSpeed(p);
                             }

            // this uses a const reference for efficiency and safety
        bool operator==(const Tricycle &other)
        {
            return ( this->calcPrice() == other.calcPrice() );
        }
};




int main()
{

    Vehicle*arr[2];
    arr[0]==new Bicycle; //new memory allocation
    arr[1]==new Tricycle;

    arr[0]==Vehicle::setPrice(500);
    arr[1]==Vehicle::setPrice(50);

    cout<<"The bicycle costs" <<arr[0]->getPrice()<<" and has "<< arr[0]->wheels()<<"wheels"<<endl;
    cout<<"The tricycle costs" <<arr[1]->getPrice()<<" and has "<< arr[1]->wheels()<<"wheels"<<endl;

    delete[0]; //deleting memory/cleaning up the heap
    delete[1];

    return 0;

}
