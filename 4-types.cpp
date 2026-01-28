#include <iostream>
#include <vector>

typedef std::vector<std::pair<std::string, int>> pairlist_t;
typedef std::string text_t;
typedef int number_t;

using utext_t = std::string;
using unumber_t = int;

int main() {
    /*
        typedef: reserved keyword used to create an additional name (alias) for another data type. New identifier for an existing type.
    */

    pairlist_t pairlist;
    text_t firstName = "Rafa";

    number_t age = 20;

    std::cout << firstName << std::endl;
    std::cout << age << '\n';

    utext_t secondaName = "uRafa";
    unumber_t secondAge = 21;

    std::cout << secondaName << std::endl;
    std::cout << secondAge << '\n';
}