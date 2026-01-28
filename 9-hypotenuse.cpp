#include <iostream>
#include <cmath>

int main() {
    double adjacentCathete, oppositeCathete;

    std::cout << "Enter adjacent cathete: ";
    std::cin >> adjacentCathete;

    std::cout << "Enter opposite cathete: ";
    std::cin >> oppositeCathete;
    
    double hypotenuse = sqrt(pow(adjacentCathete, 2) + pow(oppositeCathete, 2));

    std::cout << "Hypotenuse: " << hypotenuse << "\n";
}