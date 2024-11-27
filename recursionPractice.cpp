#include <iostream>

void walk(int steps);
void walkR(int steps);
int factorial(int num);

int main()
{
    // walk(10);
    // walkR(10);
    std::cout << factorial(5) << "\n";
    return 0;
}

void walk(int steps)
{
    for (int i = 0; i < steps; i++)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
void walkR(int steps)
{
    if (steps > 0)
    {
        std::cout << steps << " ";
        walkR(steps - 1);
    }
}
int factorial(int num)
{
    if (num > 1)
    {
        return num * factorial(num - 1);
    }
    else
    {
        return 1;
    }
}