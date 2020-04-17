#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <ostream>


class Car{
    int year;
    std::string color;
    std::string make;

public:
    //overloaded constructor required

    Car(std::string m="Ford", std::string c="Black", int vehYear=1910)
    //Overloaded << operator that adds year, color, make to the provided output stream
        {make=m; color=c; year=vehYear; }
        //~Car(){} //destructor


    //mutator
    void setYear (int vehYear) {year=vehYear;}
    void setColor(std::string c) {color=c;}
    void setMake(std::string m) {make=m;}

    //accessor
    int getYear() const {return year;}
    std::string getColor() const {return color;}
    std::string getMake() const {return make;}

    //other methods

    // defining equality requires a friend if both right and left
    friend bool operator==(const Car & lhs, const Car & rhs)
    {
        bool result = (  lhs.make == rhs.make && lhs.color == rhs.color &&lhs.year == rhs.year);

        return result;
    }

        // defining insertion as a friend method
    friend std::ostream & operator<<(std::ostream & os, const Car & rhs)
    {
    os << "Year =  " << rhs.year;
    os << ", Color = " << rhs.color;
    os << ", Year = " << rhs.make;
    return os;
    }


};
#endif // CAR_H_INCLUDED



/* code for class
int Car::counter = 0;
Car* Car::cars[Car::SIZE];

Car::Car(string make, string color)
{
    this->make = make;
    this->color = color;

    cars[counter] = this;
    counter++;
}
Car::Car()
{
    make = "Ford";
    color = "Black";

    cars[counter] = this;
    counter++;
}*/
