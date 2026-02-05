#include <iostream>

void showTheNumber();

int theNumber = 10;

int main() {
    int theNumber = 15;

    std::cout << ::theNumber << std::endl;
    std::cout << theNumber << std::endl;

    showTheNumber();
}

void showTheNumber() {
    int theNumber = 20;

    std::cout << ::theNumber << std::endl;
}

