#include <iostream>

int main()
{
    std::string cars[] = {"Corvette", "Mustang", "Camry"};

    std::cout << cars << std::endl;
    std::cout << cars[0] << std::endl;

    std::string foods[3];

    foods[0] = "Pizza";

    std::cout << foods[0] << std::endl;
    std::cout << foods[1] << '\n';
}