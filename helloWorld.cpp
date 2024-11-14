#include <iostream>
#include <cmath>

int main()
{
    using std::cin;
    using std::cout;

    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        int num = rand() % 6 + 1;
        cout << num << "\n";
    }

    return 0;
}