#include <iostream>

int main() {
    int x; // declaration
    x = 5; // assignment

    int y = 6;

    int sum = y + x;

    std::cout << x << '\n'; 
    std::cout << y << '\n';
    std::cout << sum << '\n';

    int age = 21;
    int year = 2026;

    double days = 7.5;
    double price = 12.5;
    double gpa = 2.5;
    double temperature = 25.1;

    std::cout << price << '\n';
    std::cout << days << '\n';

    char grade = 'A';
    char initial = 'B';

    std::cout << initial << '\n';

    bool isStudent = true;
    bool isHover = true;
    bool forSale = true;

    // string 
    std::string name = "Rafa";
    std::cout << name << std::endl;
    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;
}