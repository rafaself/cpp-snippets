#include <iostream>

int main() {
    int x = 10;
    int* p = &x;

    std::cout << x << std::endl;
    std::cout << &x << std::endl;

    std::cout << p << std::endl;
    std::cout << &p << std::endl;
    std::cout << *p << std::endl;
}