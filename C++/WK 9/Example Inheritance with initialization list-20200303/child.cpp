#include "child.h"

Child::Child(std::string n, int a, std::string h)
    : Parent(n, a)
{
    hobby = h;
}

std::string Child::getHobby()
{
    return hobby;
}

void Child::setHobby(std::string h)
{
    hobby = h;
}
