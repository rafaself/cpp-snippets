#include <iostream>

int main()
{
    int columns;
    int rows;

    std::cout << "** Matrix settings **" << std::endl;

    std::cout << "Numbers of rows: ";
    std::cin >> rows;

    std::cout << "Numbers of columns:";
    std::cin >> columns;

    std::cout << "\nLet's see the matrix!" << std::endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << '[' << i << j << "]";
        }

        std::cout << std::endl;
    }

    std::cout << "We saw the matrix!" << std::endl;
}