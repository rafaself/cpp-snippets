#include <iostream>

template <size_t N>
double sum_array_numbers(const double (&arr)[N]) {
    double sum = 0.0;
    for (double number : arr) {
        sum += number;
    }
    return sum;
}

int main() {
    double prices[] = {65.1, 9.0, 5.0, 45.6};
    std::cout << sum_array_numbers(prices) << "\n";
}
