#include <iostream>

// uncomment PERSON_TEST to test your person
// uncomment CC_TEST to test your credit card
#define PERSON_TEST
#define CC_TEST

#ifdef CC_TEST
#include "CreditCard.h"
#endif // CC_TEST

#ifdef PERSON_TEST
#include "Person.h"
#endif // PERSON_TEST

using namespace std;

//#define

int main()
{
#ifdef PERSON_TEST
    Person bob;
    Person marge("Marge", "Inovera", "321 Stats Lane");

    cout << "Bob (all should be blank)" << endl;
    cout << "First Name: " << bob.getFirstName() << " ";
    cout << "Last Name: " << bob.getLastName() << " ";
    cout << "Address: " << bob.getAddress() << " " << endl << endl;

    cout << "Marge, expected output is:" << endl;
    cout << "First Name: Marge Last Name: Inovera Address: 321 Stats Lane" << endl;
    cout << "Acutal Result: " << endl;
    cout << "First Name: " << marge.getFirstName() << " ";
    cout << "Last Name: " << marge.getLastName() << " ";
    cout << "Address: " << marge.getAddress() << " " << endl << endl;

#endif //PERSON_TEST

#ifdef CC_TEST
    CreditCard discover("Lou", "Pole", "456 Haven Ave", 8675309, 5000);
    cout << "Card Number - Expected: 8675309, Actual: " << discover.getCardNumber() << endl;
    cout << "Card Holder Name - Expected: Lou Pole, Actual: " << discover.getOwnerName() << endl;
    cout << "Address - Expected: 456 Haven Ave, Actual: " << discover.getAddress() << endl;
    cout << "Balance - Expected: 0, Actual: " << discover.getBalance() << endl;



    if (discover.makeCharge(3000))
        cout << "Charge applied (correct)" << endl;
    else
        cout << "Charge failed" << endl;
    cout << "Balance - Expected: 3000, Actual: " << discover.getBalance() << endl;

    if (discover.makeCharge(4000))
        cout << "Account over limit (error)" << endl;
    else
        cout << "Card declined (correct)" << endl;
    cout << "Balance - Expected: 3000, Actual: " << discover.getBalance() << endl;

    if (discover.payBalance(400))
        cout << "Payment accepted (correct)" << endl;
    else
        cout << "Payment denied (error)" << endl;
    cout << "Balance - Expected: 2600, Actual: " << discover.getBalance() << endl;

    if (discover.payBalance(-500))
        cout << "Payment accepted (error)" << endl;
    else
        cout << "Payment denied (correct)" << endl;
    cout << "Balance - Expected: 2600, Actual: " << discover.getBalance() << endl;

    discover.setCreditLimit(10000);

    if (discover.makeCharge(4000))
        cout << "Charge applied (correct)" << endl;
    else
        cout << "Charge failed" << endl;
    cout << "Balance - Expected: 6600, Actual: " << discover.getBalance() << endl;

    if (discover.payBalance(7000))
        cout << "Payment accepted (correct)" << endl;
    else
        cout << "Payment denied (error)" << endl;
    cout << "Balance - Expected: -400, Actual: " << discover.getBalance() << endl;

#endif // CC_TEST

    return 0;
}
