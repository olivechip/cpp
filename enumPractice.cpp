#include <iostream>

enum class Jobs
{
    JOBLESS,
    PLD,
    WAR,
    GNB,
    DRK
};

void changeClass(Jobs &user, int userInput);
std::string jobToString(Jobs job);

int main()
{
    int userInput;
    Jobs user = Jobs::JOBLESS;

    do
    {
        std::cout << "***************************************\n";
        std::cout << "Welcome to the FFXIV TANK class picker!\n";
        std::cout << "You are currently: " << jobToString(user) << "\n";
        std::cout << "Please select one of the following: \n";
        std::cout << "1. PLD\n";
        std::cout << "2. WAR\n";
        std::cout << "3. GNB\n";
        std::cout << "4. DRK\n";
        std::cin >> userInput;
    } while (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4);

    changeClass(user, userInput);
    std::cout << "Class changed to: " << jobToString(user) << "\n";
    std::cout << "***************************************\n";

    return 0;
}

void changeClass(Jobs &user, int userInput)
{
    switch (userInput)
    {
    case (1):
        user = Jobs::PLD;
        break;
    case (2):
        user = Jobs::WAR;
        break;
    case (3):
        user = Jobs::GNB;
        break;
    case (4):
        user = Jobs::DRK;
        break;
    default:
        break;
    }
}

std::string jobToString(Jobs job)
{
    switch (job)
    {
    case Jobs::JOBLESS:
        return "Jobless";
    case Jobs::PLD:
        return "Paladin";
    case Jobs::WAR:
        return "Warrior";
    case Jobs::GNB:
        return "Gunbreaker";
    case Jobs::DRK:
        return "Dark Knight";
    default:
        return "";
    }
}