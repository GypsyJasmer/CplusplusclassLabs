#include <iostream>
using namespace std;

// Base class (super class)
class Shape
{
    protected:
    int width;

    public:
    Shape() { width = 0; }  // Default constructor
    Shape(int w) { width = w; }     // Overloaded constructor

    int getWidth() {return width;}
    void setWidth(int w) { width = w;}
};

// Rectange "is-a" Shape
class Rectangle : public Shape
{
    protected:
    int height;

    public:
    Rectangle() : Shape() { height = 0;}    // Call base class constructor to set width
    Rectangle(int h, int w) : Shape(w) { height = h;}

    int getHeight() { return height;}
    void setHeight(int h) { height = h;}
    int calcArea() {return width * height;}
    int calcPerimeter() {return 2 * width + 2 * height;}
};

// Square "is-a" Rectangle and it "is-a" Shape as well.
// This version inherits from Rectangle
class Square : public Rectangle
{
    public:
    Square() : Rectangle() { }  // Call base class constructor to set width and height
    Square(int w) : Rectangle(w, w) {}

    void setSide(int h) { width = h; height = h;}       // Instead of gettting & setting height and width
    int getSide() { return getWidth();}                 // just use one function to do both for squares.
};

// This version inherits from Shape. It "is-a" Shape
class Square2 : public Shape
{
    public:
    Square2() { width = 0; }
    Square2(int w) : Shape(w) {}

    int getSide() { return width;}
    void setSide(int h) { width = h; }
    int calcArea() {return width * width;}
    int calcPerimeter() { return 4 * width; }
};

int main()
{
    Shape sh1(3);
    cout << "Shape width: " << sh1.getWidth() << endl << endl;

    Rectangle rec(5, 2);
 //   rec.setWidth(5);
 //   rec.setHeight(2);
    cout << "Rectangle height: " << rec.getHeight() << ", Rectangle width: " << rec.getWidth() << endl;
    cout << "Area: " << rec.calcArea() << endl;
    cout << "Perimeter: " << rec.calcPerimeter() << endl << endl;

    Square mySquare(10);
  //  mySquare.setSide(10);
     cout << "Square side: " << mySquare.getSide() << endl;
    cout << "Area: " << mySquare.calcArea() << endl;
    cout << "Perimeter: " << mySquare.calcPerimeter() << endl << endl;

    Square2 sq2(6);
 //   sq2.setWidth(2);
    cout << "Square 2 Area: " << sq2.calcArea() << endl;

    return 0;
}





















