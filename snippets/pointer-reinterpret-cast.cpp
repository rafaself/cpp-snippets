#include <iostream>
#include <cstdint>
#include <bitset>

int main()
{
    int n = 1025;
    int *p = &n;

    std::cout << n << '\n';
    std::cout << reinterpret_cast<std::uintptr_t>(p) << '\n';

    char *p0 = (char *)p;
    std::cout << p0 << '\n';
    std::cout << reinterpret_cast<std::uintptr_t>(p0) << '\n';
}