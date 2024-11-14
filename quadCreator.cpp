#include <iostream>

int main()
{

    using std::cin;
    using std::cout;

    cout << "------------Quad Creator--------------\n";

    int x;
    int y;
    char s;

    cout << "Width: ";
    cin >> x;
    cout << "Height: ";
    cin >> y;
    cout << "Symbol: ";
    cin >> s;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            cout << s;
        }
        cout << "\n";
    }

    cout << "--------------------------------------\n";

    return 0;
}