//#include <iostream>
#include "CreditCard.h"


using namespace std;



/**************************************
this function takes a double value as an argument and applies that payment to
the balance. Payments must be non-negative values, but a negative balance is acceptable.
This function should return a Boolean value: true if the payment was applied and false if it
was not (due to negative payment amount).
**************************************/
bool CreditCard::payBalance(double payment)
{

    if(payment>0)
    {
        //apply payment to balance
        balance=balance-payment;
        return true;
    }

    return false;
}

/**************************************
this function takes a double value and charges that amount to the card,
increasing the balance. Charges must be positive and cannot cause the balance to exceed
the credit limit. This function should return a Boolean: true if the charge could was applied,
false otherwise.
**************************************/
bool CreditCard::makeCharge(double charge)
{
    //cout<<ccLimit<<endl;

    if(charge>0 && balance+charge<ccLimit) //balance after charge needs to be less then limit
    {
        //applying charge
        balance=balance+charge;
        return true;
    }

    return false;


}


