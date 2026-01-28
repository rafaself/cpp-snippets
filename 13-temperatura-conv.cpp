#include <iostream>
#include <string>
#include <cctype>

std::string toLower(std::string s)
{
    for (char &ch : s)
        ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    return s;
}

bool isExitCommand(const std::string &s)
{
    return toLower(s) == "exit()";
}

bool parseDouble(const std::string &s, double &out)
{
    try
    {
        size_t idx = 0;
        out = std::stod(s, &idx);
        return idx == s.size();
    }
    catch (...)
    {
        return false;
    }
}

bool readUnitRecursive(char &unit)
{
    std::cout << "What unit would you like to convert to (C/F) or exit(): ";
    std::string input;
    if (!(std::cin >> input))
        return false;

    if (isExitCommand(input))
        return false;

    input = toLower(input);
    if (input.size() == 1 && (input[0] == 'c' || input[0] == 'f'))
    {
        unit = input[0];
        return true;
    }

    std::cout << "Invalid unit! Try again.\n\n";
    return readUnitRecursive(unit);
}

bool readTemperatureRecursive(const std::string &prompt, double &temperature)
{
    std::cout << prompt;
    std::string input;
    if (!(std::cin >> input))
        return false;

    if (isExitCommand(input))
        return false;

    if (parseDouble(input, temperature))
        return true;

    std::cout << "Invalid number! Try again.\n\n";
    return readTemperatureRecursive(prompt, temperature);
}

int main()
{
    std::cout << "********** TEMPERATURE CONVERSION **********\n";
    std::cout << "C = Celsius\n";
    std::cout << "F = Fahrenheit\n";
    std::cout << "Type exit() anytime to quit.\n";
    std::cout << "********************************************\n\n";

    while (true)
    {
        char unit{};
        if (!readUnitRecursive(unit))
            break;

        double temperature{};
        if (unit == 'f')
        {
            if (!readTemperatureRecursive("Enter the temperature in Celsius (or exit()): ", temperature))
                break;
            double result = (temperature * 1.8) + 32;
            std::cout << "\nResult: " << temperature << "°C = " << result << "°F\n\n";
        }
        else
        {
            if (!readTemperatureRecursive("Enter the temperature in Fahrenheit (or exit()): ", temperature))
                break;
            double result = (temperature - 32) / 1.8;
            std::cout << "\nResult: " << temperature << "°F = " << result << "°C\n\n";
        }
    }

    std::cout << "\nExiting...\n";
    return 0;
}
