#include <iostream>
#include <limits>


using namespace std;

//Calculation of circle area once user inputs radius
double circleArea(double radius2)
{
    const double PI =3.14159;
    return  PI *(radius2 * radius2);

}

//Calculation of squares area once user inputs side length
double squareArea (double length_only)
{
    return length_only * length_only;
}

//Calculation of rectangles area once user inputs side length and width
double rectangleArea(double rLenght, double rWidth)
{

    return rLenght * rWidth;
}

//Calculation of triangle's area once user inputs height and width
double triangleArea(double tHeight, double tWidth)
{
    return tHeight * tWidth *0.5;
}
int main()
{

/*Requirements of project:
-define constants in program (done)
-PI is a const(done)
-asking what shape user wants
-equations in the functions for the calls below
-floating points for area, radius, side, and width(done)
-main to display return = area/result
*/
    bool valid=true;
    char repeat ='n';
    char answer1;
    const char CIRCLE = 'c', SQUARE = 's', RECTANGLE = 'r', TRIANGLE = 't';
    double radius, sqLength, recLength, recWidth, triHeight, triWidth;
    long Bignum = numeric_limits <streamsize>:: max();

do {
        cout << "Let's find the area of some shapes"<< endl;
        cout << "What shape would you like to find the area of? 'c' for circle, 's' for square, "<<
                "'r' for rectangle, or 't' for triangle." << endl;

            //data validation
        do {
            cin >> answer1;
            answer1=tolower(answer1);
            valid =true;
            if (cin.fail() || (answer1 != CIRCLE && answer1 != SQUARE &&  answer1 !=RECTANGLE &&  answer1 !=TRIANGLE))
            {
                cin.clear();
                cin.ignore(Bignum, '\n');
                cout << "computer says no, need c, s, r, or t" << endl;
                valid = false;

            }
            } while (not valid);


/*calling function for shape area per the users character input.
-circle = one variable
-Square = one variable
-rectangle = two variables
-triangle = two variables
*/
    switch (answer1)
     {
     case CIRCLE:
        cout << "Circle, please enter the radius"<< endl;
        cin >> radius;
        cout<< "The area of the circle is, " << circleArea(radius)<< endl;
        break;
      case SQUARE:
            cout << "Square, please enter the length of the squares side"<< endl;
            cin >> sqLength;
            cout << "The area of the square is, "<<squareArea(sqLength)<< endl;
        break;
    case RECTANGLE:
            cout << "Rectangle, please enter the length"<< endl;
            cin >> recLength;
            cout << "Please enter the width"<< endl;
            cin >> recWidth;
            cout << "The area of the rectangle is, " << rectangleArea(recLength,recWidth)<< endl;
        break;
    case TRIANGLE:
            cout << "Triangle, please enter the height"<< endl;
            cin >> triHeight;
            cout << "Please enter the width"<< endl;
            cin >> triWidth;
            cout << "The area of the triangle is, " << triangleArea( triHeight,triWidth )<< endl;
        break;
    default:
        cout << "Computer says no, need c, s, r, or t" << endl;
     }
//Go again, find additional areas
        cout <<"Find more areas, y/n?" << endl;
        cin >> repeat;
 } while (repeat =='y');

    return 0;
}
