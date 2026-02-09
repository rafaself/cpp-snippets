#include <iostream>

int main()
{                    // 0  4    8  12    16  20  24  28    32  36   40   44
    int A[3][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 12}}};

    int *p = (*(*(A + 1) + 1) + 1);

    std::cout << A << '\n'; // ex.: 0x7ffd89cbe3c0
    std::cout << p << '\n'; // ex.: 0x7ffd89cbe3dc
                            // 0x7ffd89cbe3dc - 0x7ffd89cbe3c0 = 28 or 1c

    // +16 +8 +4: 0 -> 28 (val: 8)
    std::cout << *p << '\n';
}