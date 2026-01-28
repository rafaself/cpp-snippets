#include <iostream>

int main() {
    srand(time(NULL));
    
    int num = rand();

    std::cout << num;
}