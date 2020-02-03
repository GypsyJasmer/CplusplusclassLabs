#include <iostream>
#include <iomanip>
#include <cstdlib>


using namespace std;

int main()
{

    int num1, num2;
    char answer2;

//We're asking the user to enter two integer and a mathematical operator.
    cout << "Please enter two integers (Whole numbers)" << endl;
    cin >> num1 >> num2;
    cout << "Please enter a mathematical operation; * , / , %, +, or -. " << endl;
    cin >> answer2;

//Creating a condition to error if user put 0 for their second int and operator of division/ or mode%
    if (answer2 == '/' or answer2 == '%')
        {
            if (num2 == 0)

        {
        cout << "Can not divide by zero" << endl;
            return 0;

            }}
//going into choosing the correct math operator and error out if incorrect operator inputed by user.

int result = 0;

     switch (answer2)
     {
     case '*':
        result =  num1 * num2;
        break;
      case '/':
        result =  num1 / num2;
        break;
    case '%':
        result =  num1 % num2;
        break;
    case '+':
        result =  num1 + num2;
        break;
    case '-':
        result =  num1 - num2;
        break;
    default:
        cout << "Error" << endl;

return 0;
     }

cout << "Equation " << num1 << answer2 << num2 << " = " << result <<endl;

    return 0;
}
