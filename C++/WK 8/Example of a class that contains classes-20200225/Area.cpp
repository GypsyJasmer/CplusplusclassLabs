#include "Area.h"

Area::Area()
{

}
Area::Area(float s, float r)
{
    sq.setSide(s);
    ci.setRadius(r);
}
void Area::setSide(float s)
{
    sq.setSide(s);
}
void Area::setRadius(float r)
{
    ci.setRadius(r);
}

float Area::getArea()
{
    return sq.getArea() + ci.getArea();
}
