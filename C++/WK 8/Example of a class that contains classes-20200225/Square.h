#ifndef SQUARE_H
#define SQUARE_H


class Square
{
    public:
        Square();
        Square(float s);

        void setSide(float s);
        float getSide();
        float getArea();

    private:
        float side;
};

#endif // SQUARE_H
