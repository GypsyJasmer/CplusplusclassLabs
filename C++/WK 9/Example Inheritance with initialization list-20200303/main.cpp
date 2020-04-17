#include <iostream>

#include "child.h"

using namespace std;

int main()
{
    Parent pa("Pa", 50);

    cout << pa.getName() << " " << pa.getAge() << endl;

    Child kid("junior", 27, "gaming");
    cout << kid.getName() << " " << kid.getAge() << " " << kid.getHobby() << endl;

    return 0;
}
