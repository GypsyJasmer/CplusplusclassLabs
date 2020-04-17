#ifndef CREDITCARD_H_INCLUDED
#define CREDITCARD_H_INCLUDED

#include "Person.h"

class CreditCard
{
    private:
        Person owner;
        double balance;
        int cardNum;
        double ccLimit;


    public:

         //constructor
         //should have a person variable calling person.h //no ; after constructor this time
        CreditCard (std::string fName="",std::string lName="",std::string mailing="", int ccNum=0, double limit=0)
        :owner(fName, lName, mailing), balance(0), cardNum(ccNum), ccLimit(limit) {}

        //mutator
        void setCardBal (double cardBal) {balance=cardBal;}
        void setCCNum (int ccNum );
        void setCreditLimit (double limit) {ccLimit=limit;}



        //accessor
        double getBalance(){return balance;}
        int getCardNumber() {return cardNum;}
        //returns the first and last name of card owner
        std::string getOwnerName() {return owner.getFirstName() + owner.getLastName();}
        //returns card holder's address
        std::string getAddress() {return owner.getAddress();}

        //other methods protocols
        bool payBalance(double payment);
        bool makeCharge(double charge);



};

#endif // CREDITCARD_H_INCLUDED
