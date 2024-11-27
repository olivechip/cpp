#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct BankAccount
{
    string name;
    int pin;
    int account;
    double balance;

    void deposit(double amount)
    {
        balance += amount;
        cout << "Successfully deposited: $" << amount << endl;
        cout << "--------------------------------------\n";
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            std::cerr << "Insufficient funds" << endl;
            cout << "--------------------------------------\n";
        }
        else
        {
            balance -= amount;
            cout << "Successfully withdrew: $" << amount << endl;
            cout << "--------------------------------------\n";
        }
    }

    void display()
    {
        cout << "Your current balance is: $" << balance << endl;
        cout << "--------------------------------------\n";
    }
};

void newAccount(std::vector<BankAccount> &bankAccounts);
void existingAccount(std::vector<BankAccount> &bankAccounts);

int main()
{
    std::vector<BankAccount> bankAccounts;
    int mode = 0;

    do
    {
        cout << "---------- Welcome to Simple Bank ----------\n";
        cout << "Please select one of the following:\n";
        cout << "1) New customer\n";
        cout << "2) Existing customer\n";
        cin >> mode;

        if (mode == 1)
        {
            newAccount(bankAccounts);
        }
        else if (mode == 2)
        {
            existingAccount(bankAccounts);
        }
    } while (mode != 0 | mode != 1 || mode != 2);

    return 0;
}

void newAccount(std::vector<BankAccount> &bankAccounts)
{
    string newName;
    int newPin;

    cout << "---------- Account Creation ----------\n";
    cout << "What is your name? ";
    cin >> newName;
    cout << "Please enter a four-digit PIN: ";
    cin >> newPin;

    BankAccount newUser = {newName, newPin, static_cast<int>(bankAccounts.size()) + 1, 0.00};
    bankAccounts.push_back(newUser);

    if (&bankAccounts[bankAccounts.size() - 1])
    {
        cout << "Account created successfully!\n";
        cout << "Your account number is " << newUser.account << endl;
        cout << "Please remember your account number!\n";
        cout << "--------------------------------------\n";
    }
    else
    {
        "Account creation failed";
        cout << "--------------------------------------\n";
    }
}

void existingAccount(std::vector<BankAccount> &bankAccounts)
{
    int accountNumber;
    cout << "Please enter your account number: ";
    cin >> accountNumber;
    cout << "--------------------------------------\n";

    if (accountNumber > 0 && accountNumber <= bankAccounts.size())
    {
        int choice;
        BankAccount &userAccount = bankAccounts[accountNumber - 1];

        do
        {
            cout << "Welcome back, " << userAccount.name << "!\n";

            cout << "Please select one of the following:\n";
            cout << "1) Display current balance\n";
            cout << "2) Deposit\n";
            cout << "3) Withdraw\n";
            cout << "4) Go Back to Main Menu\n";

            cin >> choice;

            if (choice == 1)
            {
                userAccount.display();
            }
            else if (choice == 2)
            {
                cout << "Deposit Amount: ";
                double depositAmount;
                cin >> depositAmount;
                userAccount.deposit(depositAmount);
            }
            else if (choice == 3)
            {
                cout << "Withdrawal Amount: ";
                double withdrawalAmount;
                cin >> withdrawalAmount;
                userAccount.withdraw(withdrawalAmount);
            }

        } while (choice != 4);
    }
    else
    {
        std::cerr << "Invalid account number\n";
    }
}