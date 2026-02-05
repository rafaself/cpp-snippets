#include <iostream>

int main() {
    const int SIZE = 15;

    std::string foods[SIZE];

    fill(foods, foods + SIZE / 2, "pizza");
    fill(foods + SIZE / 2, foods + SIZE, "juice");

    for(int i = 0; i < SIZE; i++) {
        std::cout << foods[i] << '\n';
    }
}