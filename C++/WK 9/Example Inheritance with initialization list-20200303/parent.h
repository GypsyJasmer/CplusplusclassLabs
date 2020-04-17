#ifndef PARENT_H
#define PARENT_H

#include <string>

class Parent
{
    public:
        Parent(std::string name = "", int age = 0);
        std::string getName();
        int getAge();
        void setName(std::string n);
        void setAge(int a);
    protected:
    private:
        std::string name;
        int age;
};

#endif // PARENT_H
