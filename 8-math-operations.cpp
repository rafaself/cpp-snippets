#include <iostream>
#include <cmath>

int main() {
    double x = 3;
    double y = 4;
    double maxNumber, minNumber, powerNumber, 
    squareRootNumber, absoluteNumber, ceilNumber, floorNumber;

    maxNumber = std::max(x, y);
    minNumber = std::min(x, y);
    powerNumber = pow(x, y);
    squareRootNumber = sqrt(x);
    absoluteNumber = abs(x);
    ceilNumber = ceil(x);
    floorNumber = floor(x);

    std::cout << "Max: " << maxNumber << "\n";
    std::cout << "Min: " << minNumber << "\n";
    std::cout << "Power: " << powerNumber << "\n";
    std::cout << "Square Root: " << squareRootNumber << "\n";
    std::cout << "Absolute: " << absoluteNumber << "\n";
    std::cout << "Ceil: " << ceilNumber << "\n";
    std::cout << "Floor: " << floorNumber << "\n";
}