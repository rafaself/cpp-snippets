#include <iostream>

int main()
{
    int num;
    int guess;
    int tries{};

    srand(time(NULL));
    num = rand() % 100 + 1;

    std::cout << "****** NUMBER GUESSING GAME ******\n";

    do
    {
        tries++;
        if (tries > 5)
        {
            std::cout << "You lost! =/ \n";
            break;
        }

        std::cout << "Enter a guess betwen (1 to 100): ";
        std::cin >> guess;

        if (guess == num)
        {
            std::cout << "You won!!!\n";
            break;
        }
        else if (guess < num)
        {
            std::cout << "The number is bigger!\n";
        }
        else if (guess > num)
        {
            std::cout << "The number is lower!\n";
        }

    } while (guess != num);
}