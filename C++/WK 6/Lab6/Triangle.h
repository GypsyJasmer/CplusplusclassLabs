#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

class Triangle
{
    private:
        int side1, side2, side3; //three sides to a triangle all in
    public:
        //set the length of each side to 3, 4, 5 and needs an overloaded construction that takes 3 arguments so the length of each can be specified
        Triangle(int a=3, int b=4, int c=5) {side1=a; side2=b; side3=c;} //constructor

        //mutator
        //Are my setters defined or so they need to list a separate function outside of class public?
        void setA(int a){side1=a;}
        void setB(int b){side2=b;}
        void setC(int c){side3=c;}

        //accessor
        int getA() {return side1;}
        int getB() {return side2;}
        int getC() {return side3;}

        //other methods
        bool isEquilateral();
        bool isScalene();
        //at LEAST two sides are equal
        bool isIsosceles();
        //Pythagorean Theorem
        bool isRight();

};


#endif // TRIANGLE_H_INCLUDED


