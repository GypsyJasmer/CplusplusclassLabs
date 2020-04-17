#include "Circle.h"

Circle::Circle()
{
    radius = 1.0;
}
Circle::Circle(float r)
{
    radius = r;
}

void Circle::setRadius(float r)
{
    radius = r;
}
float Circle::getRadius()
{
    return radius;
}
float Circle::getArea()
{
    return radius * radius * PI;
}
