#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <random>
#include <ctime>
#include <cctype>

bool is_valid_option(char c);
char normalize_option(char c);
char get_computer_option(std::mt19937& rng);
std::string get_option_title(char option);
int get_result(char user, char computer);
void play_round(std::mt19937& rng);

int main()
{
    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));

    while (true)
    {
        play_round(rng);

        std::cout << "\nPlay again? (y/n): ";
        char again{};
        if (!(std::cin >> again)) return 0;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        again = static_cast<char>(std::tolower(static_cast<unsigned char>(again)));
        if (again != 'y') break;
    }

    std::cout << "\nBye!\n";
    return 0;
}

void play_round(std::mt19937& rng)
{
    std::cout << "\n********** Rock, Paper, Scissors **********\n";
    std::cout << "r -> Rock\n";
    std::cout << "p -> Paper\n";
    std::cout << "s -> Scissors\n\n";

    char user{};
    while (true)
    {
        std::cout << "What do you choose (r/p/s): ";
        if (!(std::cin >> user)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Try again.\n\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        user = normalize_option(user);

        if (is_valid_option(user)) break;

        std::cout << "Invalid option! Try again.\n\n";
    }

    char computer = get_computer_option(rng);

    std::cout << "\nUser - " << get_option_title(user)
              << " x Machine - " << get_option_title(computer) << '\n';

    int result = get_result(user, computer);
    if (result == 0) std::cout << "It's a tie!\n";
    else if (result > 0) std::cout << "User won!\n";
    else std::cout << "Computer won!\n";
}

bool is_valid_option(char c)
{
    return c == 'r' || c == 'p' || c == 's';
}

char normalize_option(char c)
{
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

char get_computer_option(std::mt19937& rng)
{
    static std::uniform_int_distribution<int> dist(0, 2);
    const char options[3] = {'r', 'p', 's'};
    return options[dist(rng)];
}

std::string get_option_title(char option)
{
    switch (option)
    {
    case 'r': return "Rock";
    case 'p': return "Paper";
    case 's': return "Scissors";
    default: throw std::invalid_argument("Invalid option.");
    }
}

int get_result(char user, char computer)
{
    if (user == computer) return 0;

    const bool user_wins =
        (user == 'r' && computer == 's') ||
        (user == 'p' && computer == 'r') ||
        (user == 's' && computer == 'p');

    return user_wins ? 1 : -1;
}
