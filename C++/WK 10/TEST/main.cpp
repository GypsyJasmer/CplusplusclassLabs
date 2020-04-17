#include <iostream>

using namespace std;

// complete it with constructors, setters and getters
class Rectangle{

    private:

        int length;
        int width;

    public:


           // constructor with default values
       Rectangle(int length = 0, int width = 0) : length(length), width(width) {}

            // setters
        void setLength(int length);
        void setWidth(int width);

            // getters
        int getLength();
        int getWidth();
        int getArea();
};

// complete it with constructors, setters, getters
class Rug{
    private:
        Rectangle dimensions;
        string color;

    public:
            // constructor
            Rug(string color = " ") :dimensions(length, width), color(c){}

            // setters
        void setLength(int length) {this->length=length;}
        void setWidth(int width) {this ->width=width;}
        void setColor(string color) {c=color}


            //getters
        int getLength() {return length;}
        int getWidth() {return width;}
        int getArea() {return length*width;}
        string getColor() {return c;}

};

int main()
{
    Rug den;
    Rug livingRoom(8, 10, "Green");

    den.setColor("blue");
    den.setLength(5);
    den.setWidth(4);

    cout << "The den has area " << den.getArea() << " and is " << den.getColor() << endl;      cout << "The den has area " << livingRoom.getArea() << " and is " << livingRoom.getColor() << endl;

    return 0;
}
