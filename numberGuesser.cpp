#include <iostream>

int main()
{
    using std::cin;
    using std::cout;

    int target;
    int guess;
    int tries;

    srand(time(NULL));
    target = rand() % 100 + 1;

    do
    {
        cout << "Guess a number between 1-100: ";
        cin >> guess;
        tries++;

        if (guess < target)
        {
            cout << "Too low!\n";
        }
        else if (guess > target)
        {
            cout << "Too high!\n";
        }
        else
        {
            cout << "Correct! It took you " << tries << " tries to guess it!\n";
        }
    } while (guess != target);

    return 0;
}