#include <iostream>
#include <vector>

int main() {
    double gpa = 2.5;
    std::cout << "Size of double: " << sizeof(gpa) << " bytes." << std::endl;

    std::string name = "Rafa";
    std::cout << "Size of string object: " << sizeof(name) << " bytes." << '\n';

    char grade = 'F';
    std::cout << "Size of char: " << sizeof(grade) << " bytes." << '\n';

    bool student = true;
    std::cout << "Size of bool: " << sizeof(student) << " bytes." << '\n';

    std::cout << "\n- Array of chars -\n";
    char grades[] = {'A', 'B', 'C', 'D', 'E'};
    std::cout << "Size of the array: " << sizeof(grades) << " bytes." << '\n';
    std::cout << "Length of the array: " << sizeof(grades) / sizeof(char) << " elements." << '\n';

    std::cout << "\n- Array of strings -\n";
    std::string names[] = {"Rafael", "Gabriel", "Pastel"};
    std::cout << "Size of the array: " << sizeof(names) << " bytes." << '\n';
    std::cout << "Length of the array: " << std::size(names) << " elements.\n";
}