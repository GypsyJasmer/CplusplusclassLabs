#include <iostream>
#include "Triangle.h"

using namespace std;


//other methods

//all sides are equal

bool Triangle::isEquilateral()
{
    if(side1==side2 && side2==side3)
        {

            return true;
        }
        return false;
}

bool Triangle::isScalene()
{
    //changed isosceles equation to equal not equal to.
    if (side1!=side2 && side1!=side3 && side2!=side3)
        {

            return true;
        }
    return false;
}

//at LEAST two sides are equal
bool Triangle::isIsosceles()
{
    if(side1==side2 || side1==side3 || side2==side3)
        {

            return true;
        }
    return false;
}

//Pythagorean Theorem
bool Triangle::isRight()
{
    int side1Sq = side1*side1==side2*side2+side3*side3;
    int side2Sq = side2*side2==side1*side1+side3*side3;
    int side3Sq = side3*side3==side2*side2+side1*side1;

    //a^2+b^2=c^2
    if(side1Sq || side2Sq || side3Sq)
        {

            return true;
        }
    return false;
}




