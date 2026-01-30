#include <iostream>
#include <vector>
#include <iterator>

std::vector<int> bubble_sort(std::vector<int> input);
void print_array(const std::vector<int>& input);

int main() {
    int numbers[] = {9, 5, 1, 2, 6, 0, 4, 7, 8, 3};

    std::vector<int> v(std::begin(numbers), std::end(numbers));
    std::vector<int> sorted_array = bubble_sort(v);

    std::cout << "Original array: ";
    print_array(v);

    std::cout << "\n";

    std::cout << "Sorted array: ";
    print_array(sorted_array);

    std::cout << "\n";
}

void print_array(const std::vector<int>& input) {
    const std::size_t n = input.size();

    std::cout << '[';
    for (std::size_t i = 0; i < n; ++i) { 
        std::cout << input[i];
        if (i + 1 < n) std::cout << ", ";
    }
    std::cout << ']';
}

std::vector<int> bubble_sort(std::vector<int> input) {
    const std::size_t n = input.size();
    if (n < 2) return input;

    for (std::size_t i = 0; i < n - 1; i++) {
        bool didSwap = false;

        for(std::size_t j = 1; j < n - i; j++) {
            if (input[j - 1] > input[j]) {
                int temp = input[j - 1];
                input[j - 1] = input[j];
                input[j] = temp;

                didSwap = true;
            }
        }

        if (!didSwap) break;
    }

    return input;
}
