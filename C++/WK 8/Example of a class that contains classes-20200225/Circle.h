#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    public:
        Circle();
        Circle(float r);

        void setRadius(float r);
        float getRadius();
        float getArea();

    private:
        static const float PI = 3.14159;
        float radius;
};

#endif // CIRCLE_H
