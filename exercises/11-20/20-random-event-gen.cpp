#include <iostream>

int main()
{
    srand(time(0));

    int randNum = rand() % 5 + 1;

    switch (randNum)
    {
    case 1:
        std::cout << "You won something.\n";
        break;
    case 2:
        std::cout << "You won something.\n";
        break;
    case 3:
        std::cout << "You won something very good.\n";
        break;
    case 4:
        std::cout << "You won something.\n";
        break;
    case 5:
        std::cout << "You won something extraordinary.\n";
    }

    return 0;
}