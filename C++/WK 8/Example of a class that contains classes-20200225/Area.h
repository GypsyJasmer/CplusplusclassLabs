#ifndef AREA_H
#define AREA_H

#include "Circle.h"
#include "Square.h"

class Area
{
    public:
        Area();
        Area(float s, float r);
        void setSide(float s);
        void setRadius(float r);

        float getArea();

    private:
        Circle ci;
        Square sq;

};

#endif // AREA_H
