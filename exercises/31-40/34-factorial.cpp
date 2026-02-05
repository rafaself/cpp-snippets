#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

unsigned long long factorial(int n);

int main()
{
    std::cout << factorial(5) << '\n';
}

unsigned long long factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }

    static std::vector<unsigned long long> memo = {1ULL, 1ULL};

    if (static_cast<std::size_t>(n) < memo.size()) {
        return memo[n];
    }

    for (int i = static_cast<int>(memo.size()); i <= n; ++i) {
        unsigned long long prev = memo.back();

        if (prev > std::numeric_limits<unsigned long long>::max() / static_cast<unsigned long long>(i)) {
            throw std::overflow_error("factorial overflows unsigned long long");
        }

        memo.push_back(prev * static_cast<unsigned long long>(i));
    }

    return memo[n];
}