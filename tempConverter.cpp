#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    double temp;
    char unit;

    cout << "-----------Temperature Conversion---------- \n";
    cout << "F = Farenheit \n";
    cout << "C = Celsius \n";
    cout << "What unit would you like to convert to: \n";
    cin >> unit; 

    if (unit == 'F'){
        cout << "Please enter the temperature in Celsius: \n";
        cin >> temp;
        temp = (1.8 * temp) + 32.0;
        cout << temp << "F \n";
    } else if (unit == 'C'){
        cout << "Please enter the temperature in Farenheit \n";
        cin >> temp;
        temp = (temp -32)/1.8;
        cout << temp << "C \n";
    } else {
        cout << "Please enter a valid unit! \n";
        return 1;
    }
    
    cout << "------------------------------------------- \n";
    return 0;
}