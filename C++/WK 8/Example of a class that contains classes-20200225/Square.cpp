#include "Square.h"

Square::Square()
{
    side = 1.0;
}

Square::Square(float s)
{
    side = s;
}

void Square::setSide(float s)
{
    side = s;
}

float Square::getSide()
{
    return side;
}

float Square::getArea()
{
    return side * side;
}
