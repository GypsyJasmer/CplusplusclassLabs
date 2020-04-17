#include "CircleClasses1.h"

//using namespace std;

// Circle Methods

Circle::Circle() {
  radius = 0.0;
}

Circle::Circle(double radius) {
  this->radius = radius;
}

void Circle::setRadius(double radius) {
  this->radius = radius;
}

double Circle::getRadius() {
  return radius;
}

double Circle::getDiameter() {
  return radius * 2;
}

double Circle::getCircumference() {
  return radius * 2 * PI;
}

double Circle::getSurfaceArea() {
  return radius * radius * PI;
}

// Cylinder Methods

Cylinder::Cylinder() {
  height = 0;
  // why not this, too: radius = 0;
}

Cylinder::Cylinder(double radius, double height) : Circle(radius) {
  this->height = height;
  // why not set radius in here?
}

double Cylinder::getSurfaceArea() {
  double
    end,
    sides;

  // We need to get the surface area of a circle for the ends
  // We could do this:
  // double ends = radius * radius * PI;
  //
  // But why not use the circle surface area method:
  end = Circle::getSurfaceArea();

  sides = getCircumference() * height;
  return 2 * end + sides;
}

double Cylinder::getVolume() {
  return height * Circle::getSurfaceArea();
}

// Sphere Methods

Sphere::Sphere() {
  // Why nothing else?
}

Sphere::Sphere(double radius) : Circle(radius) {
  // Why nothing else?
}

double Sphere::getSurfaceArea() {
  return 4.0 * PI * radius * radius;
}
double Sphere::getVolume() {
  return 4.0/3.0 * PI * radius * radius * radius;
}

