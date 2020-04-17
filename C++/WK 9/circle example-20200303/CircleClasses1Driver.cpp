#include <iostream>
#include "CircleClasses1.h"

using namespace std;

int main() {
  Circle
    myCircle;
  Cylinder
    myCylinder = Cylinder(0,10);
  Sphere
    mySphere;

  for(double r = 0; r <= 5.0; r ++) {
    myCircle.setRadius(r);
    myCylinder.setRadius(r);
    mySphere.setRadius(r);

    cout << "For radius " << r << ":\n\n"
      << "Circle:\n\n" 
      << "radius:        " << myCircle.getRadius() << endl
      << "circumference: " << myCircle.getCircumference() << endl
      << "area:          " << myCircle.getSurfaceArea() << endl;

    cout << "\nCylinder:\n\n" 
      << "radius:        " << myCylinder.getRadius() << endl
      << "circumference: " << myCylinder.getCircumference() << endl
      << "area:          " << myCylinder.getSurfaceArea() << endl
      << "volume:        " << myCylinder.getVolume() << endl;

    cout << "\nSphere:\n\n" 
      << "radius:        " << mySphere.getRadius() << endl
      << "circumference: " << mySphere.getCircumference() << endl
      << "area:          " << mySphere.getSurfaceArea() << endl
      << "volume:        " << mySphere.getVolume() << endl
      << "________________________________________________\n\n";

  } // for(double r = 0; r <= 5.0; r ++)


  cout << "One sphere, two surface areas: "
    << mySphere.getSurfaceArea() << "  " 
    << mySphere.Circle::getSurfaceArea() << endl;

  cout << "One sphere, two surface areas: "
    << mySphere.getSurfaceArea() << "  " 
    << Circle(mySphere).getSurfaceArea() << endl;

  return 0;










} // main()