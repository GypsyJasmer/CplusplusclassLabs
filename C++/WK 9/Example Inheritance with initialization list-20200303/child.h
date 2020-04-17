#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

class Child : public Parent
{
    public:
        Child(std::string n = "", int age = 0, std::string h = "");
        std::string getHobby();
        void setHobby(std::string h);
    protected:
    private:
        std::string hobby;
};

#endif // CHILD_H
