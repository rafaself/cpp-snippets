#include <iostream>

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index;
    int typedNumber;

    std::cout << "Type a number: ";
    std::cin >> typedNumber;

    for(int i = 0; i < std::size(numbers); i++) {
        if(numbers[i] == typedNumber) {
            std::cout << "The index of this number in the array is [" << i << "]\n";
        }
    }
}