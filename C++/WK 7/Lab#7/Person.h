#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
//#include <iostream>
#include <string>

//using namespace std; use std:: in header files


class Person
{
    private:
        std::string firstName, lastName, address;

    public:

         //constructor
         Person (std::string fName="", std::string lName="", std::string mailing="")
         {firstName=fName; lastName=lName; address=mailing;}

        //mutator
        void setfName(std::string fName) {firstName=fName;}
        void setlName(std::string lName) {lastName=lName;}
        void setMailing(std::string mailing) {address=mailing;}

        //accessor
        std::string getFirstName() {return firstName;}
        std::string getLastName() {return lastName;}
        std::string getAddress() {return address;}

        //other methods


};


#endif // PERSON_H_INCLUDED
