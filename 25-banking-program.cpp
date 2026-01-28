#include <iostream>
#include <iomanip>
#include <limits>

static void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static int readOption()
{
    int option{};
    while (true) {
        std::cout << "Insert your option: ";
        if (std::cin >> option) {
            clearInput();
            return option;
        }
        std::cout << "Invalid input! Try again.\n";
        clearInput();
    }
}

static double readAmount(const char* prompt)
{
    double value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            clearInput();
            return value;
        }
        std::cout << "Invalid number! Try again.\n";
        clearInput();
    }
}

void deposit(double& balance);
void withdraw(double& balance);
void show_balance(double balance);

int main()
{
    double balance{0.0};

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "********** BANKING SYSTEM **********\n";

    int option = 0;
    do
    {
        std::cout << "\nYou've the following options:\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Show balance\n";
        std::cout << "4. Exit\n";

        option = readOption();

        switch (option)
        {
        case 1:
            deposit(balance);
            break;
        case 2:
            withdraw(balance);
            break;
        case 3:
            show_balance(balance);
            break;
        case 4:
            std::cout << "\nThank you for choosing with us!\n";
            break;
        default:
            std::cout << "\nInsert a valid option!\n";
        }
    } while (option != 4);

    return 0;
}

void deposit(double& balance)
{
    double v = readAmount("\nInsert the amount to deposit: ");

    if (v <= 0.0)
    {
        std::cout << "Invalid value! The value has to be a positive number.\n";
        return;
    }

    balance += v;
    std::cout << "You deposited $ " << v << ". Now, your balance is $ " << balance << '\n';
}

void withdraw(double& balance)
{
    double v = readAmount("\nInsert the amount to be withdrawn: ");

    if (v <= 0.0)
    {
        std::cout << "Invalid value! The value has to be a positive number.\n";
        return;
    }

    if (v > balance)
    {
        std::cout << "You don't have this much money!\n";
        return;
    }

    balance -= v;
    std::cout << "You withdrew $ " << v << ". Now, your balance is $ " << balance << '\n';
}

void show_balance(double balance)
{
    std::cout << "\nYour balance is $ " << balance << "!\n";
}
