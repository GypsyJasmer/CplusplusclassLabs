#ifndef CIRCLECLASSES1_H
#define CIRCLECLASSES1_H

const double PI = 3.14159;

class Circle {
// Why protected and not private?
//private:
protected:
  double
    radius;

public:
  Circle();
  Circle(double radius);
  void setRadius(double radius);
  double getRadius();
  double getDiameter();
  double getCircumference();
  double getSurfaceArea();
}; // class Circle

class Cylinder : public Circle {
private:
  double
    height;
public:
  Cylinder();
  Cylinder(double radius, double height);
  double getSurfaceArea();
  double getVolume();
}; // class Cylinder

class Sphere : public Circle {
  // why no private member variables?
public:
  Sphere();
  Sphere(double radius);
  double getSurfaceArea();
  double getVolume();
}; // class Sphere

#endif