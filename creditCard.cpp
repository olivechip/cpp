#include <iostream>

int getDigit(const int number);
int sumEven(const std::string cc);
int sumOdd(const std::string cc);

int main()
{
    using std::cin;
    using std::cout;
    using std::string;

    string cc;
    int result = 0;

    cout << "Enter a credit card number: ";
    cin >> cc;

    result = sumEven(cc) + sumOdd(cc);
    if (result % 10 == 0)
    {
        cout << cc << " is valid \n";
    }
    else
    {
        cout << cc << " is not valid \n";
    }

    return 0;
}

int getDigit(const int number)
{
    return number % 10 + (number / 10 % 10);
}

int sumEven(const std::string cc)
{
    int sum = 0;
    for (int i = cc.size() - 2; i >= 0; i -= 2)
    {
        sum += getDigit((cc[i] - '0') * 2);
    }
    return 0;
}

int sumOdd(const std::string cc)
{
    int sum = 0;
    for (int i = cc.size() - 1; i >= 0; i -= 2)
    {
        sum += cc[i] - '0';
    }
    return 0;
}