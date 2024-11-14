#include <iostream>

int main()
{
    using std::cout;

    char op;
    double num1;
    double num2;
    double res;

    std::cout << "------------CALCULATOR-----------\n";
    std::cout << "Enter first number: \n";
    std::cin >> num1;

    std::cout << "Enter arithmetic operator: \n";
    std::cin >> op;

    std::cout << "Enter second number: \n";
    std::cin >> num2;

    switch (op)
    {
    case '+':
        res = num1 + num2;
        break;
    case '-':
        res = num1 - num2;
        break;
    case '*':
        res = num1 * num2;
        break;
    case '/':
        res = num1 / num2;
        break;
    default:
        std::cout << "Please enter a valid operator! \n";
        return 1;
    }

    std::cout << "Result: \n"
              << res << "\n";
    std::cout << "---------------------------------\n";

    return 0;
}