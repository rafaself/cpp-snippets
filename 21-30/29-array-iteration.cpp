#include <iostream>

int main() {
    std::string students[] = {"Spongebob", "Batman", "Spider-man"};

    std::cout << "Iterating through indexes\n";
    for(int i = 0; i < size(students); i++) {
        std::cout << students[i] << std::endl;
    }

    std::cout << "\nIterating through elements\n";
    for (std::string student : students) {
        std::cout << student << std::endl;
    }
}