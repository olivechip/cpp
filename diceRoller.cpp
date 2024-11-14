#include <iostream>

using std::cout;

int rollDice()
{
    int num = rand() % 6 + 1;
    cout << "You rolled a " << num << "!\n";
    return num;
}

int main()
{
    using std::cin;
    using std::cout;

    char input;

    cout << "Roll dice? y/n\n";
    cin >> input;

    if (input == 'y')
    {
        srand(time(NULL));
        int num = rollDice();

        switch (num)
        {
        case 1:
            cout << "You won a cookie!\n";
            break;
        case 2:
            cout << "You won a t-shirt!\n";
            break;
        case 3:
            cout << "You won a mug!\n";
            break;
        case 4:
            cout << "You won a mattress!\n";
            break;
        case 5:
            cout << "You won a fridge!\n";
            break;
        case 6:
            cout << "You won a car!\n";
            break;
        default:
            break;
        }
    } else {
        cout << ":(\n";
    }

    return 0;
}