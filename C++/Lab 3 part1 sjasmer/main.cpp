#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
   double sales_price, commission;


//We're asking the user to input the sales price of the home they sold so we can calculate their commission.
   cout << "Please input the sales price, including cents, $0.00" << endl;
   cin >> sales_price;

//Doing the math for what commission is earned
    if (sales_price < 100000.00)
        commission =  sales_price * 0.05;

  else if (sales_price >= 100000.00 and sales_price <= 300000.00)
        commission = 5000.00+(sales_price - 100000.00)*0.10;

  else if (sales_price > 300000.00)
        commission = 25000.00+(sales_price-300000.00)*0.15;


//output sales and commission earned after validating the sales price.
  cout << "Sales Price = $" << sales_price << endl;
  cout << "Commission = $" << commission << endl;


    return 0;
}
