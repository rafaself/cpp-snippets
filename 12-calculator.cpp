#include <iostream>
#include <limits>

static void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static bool readDouble(const char* prompt, double& value)
{
    while (true) {
        std::cout << prompt;

        if (std::cin >> value) return true;

        std::cout << "Error: invalid number. Try again.\n";
        clearInput();
    }
}

static char readOpRecursive()
{
    std::cout << "Select the operation (+ - * /) or 0 to exit: ";

    char op{};
    if (!(std::cin >> op)) {
        std::cout << "Error: invalid input. Try again.\n";
        clearInput();
        return readOpRecursive();
    }

    if (op == '0') return op;

    if (op == '+' || op == '-' || op == '*' || op == '/') return op;

    std::cout << "Error: insert a valid operation (+ - * /) or 0 to exit.\n";
    return readOpRecursive();
}

int main()
{
    std::cout << "********** CALCULATOR **********\n\n";

    while (true) {
        char op = readOpRecursive();
        if (op == '0') break;

        double num1{}, num2{}, result{};

        readDouble("First number: ", num1);
        readDouble("Second number: ", num2);

        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 == 0.0) {
                    std::cout << "Error: division by zero.\n\n";
                    continue;
                }
                result = num1 / num2;
                break;
        }

        std::cout << "\nResult: " << num1 << ' ' << op << ' ' << num2
                  << " = " << result << "\n\n";
    }

    std::cout << "********************************\n";
    return 0;
}
