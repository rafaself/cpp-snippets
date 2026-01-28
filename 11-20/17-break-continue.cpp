#include <iostream>

int main() {
    for (int i = 0; i <= 20; i++) {
        if (i == 13) {
            break;
        } else if (i == 4) {
            continue;
        }
        std::cout << i << '\n';
    }
}