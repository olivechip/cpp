#include <iostream>

using std::cin;
using std::cout;

char getPlayerChoice();
char getComputerChoice();
bool determineWinner(char player, char computer);

int main()
{
    char player;
    char computer;

    do
    {
        player = getPlayerChoice();
        cout << "\nYour choice: " << player << "\n";

        computer = getComputerChoice();
        cout << "Computer's Choice: " << computer << "\n\n";

        if (player == computer)
        {
            cout << "It's a tie! Please choose again.\n\n";
        }
        else
        {
            determineWinner(player, computer) ? cout << "You won!\n\n" : cout << "You lose!\n\n";
        }

    } while (player == computer);

    return 0;
}

char getPlayerChoice()
{
    char player;

    do
    {
        cout << "Rock Paper Scissors Game\n";
        cout << "************************\n";
        cout << "Choose one of the following:\n\n";
        cout << "'r' for rock\n";
        cout << "'p' for paper\n";
        cout << "'s' for scissors\n";
        cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice()
{
    char choice;

    srand(time(NULL));
    choice = rand() % 3 + 1;

    switch (choice)
    {
    case (1):
        choice = 'r';
        break;
    case (2):
        choice = 'p';
        break;
    case (3):
        choice = 's';
        break;
    }
    return choice;
}

bool determineWinner(char player, char computer)
{
    if (player == 'r' && computer == 'p')
    {
        cout << "Rock beats paper!\n";
        return true;
    }
    else if (player == 'r' && computer == 's')
    {
        cout << "Rock loses to scissors!\n";
        return false;
    }
    else if (player == 'p' && computer == 'r')
    {
        cout << "Paper beats rock!\n";
        return true;
    }
    else if (player == 'p' && computer == 's')
    {
        cout << "Paper loses to scissors!\n";
        return false;
    }
    else if (player == 's' && computer == 'r')
    {
        cout << "Rock loses to scissors!\n";
        return false;
    }
    else if (player == 's' && computer == 'p')
    {
        cout << "Scissors beats paper!\n";
        return true;
    }
}