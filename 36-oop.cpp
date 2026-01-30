#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstddef>
#include <utility>

const std::string GLOBAL_VAR = "I am the Global Var!\n";

namespace app {
    const std::string introduction = "*** Welcome to the Car's App! ***\n";
}

enum class Color { RED, GREEN, BLUE, YELLOW };

static const char* color_name(Color c) {
    switch (c) {
        case Color::RED:    return "RED";
        case Color::GREEN:  return "GREEN";
        case Color::BLUE:   return "BLUE";
        case Color::YELLOW: return "YELLOW";
    }
    return "UNKNOWN";
}

class Car {
    std::string secret = "My secret is: I haven't any secret!";

public:
    std::string make;
    std::string model;
    int year{};
    Color color{Color::RED};

    explicit Car(Color c) : color(c) {}

    Car(std::string make_, std::string model_, int year_, Color c)
        : make(std::move(make_)), model(std::move(model_)), year(year_), color(c) {}

    void accelerate() const {
        std::cout << "The " << model << " is accelerating!\n";
    }

    void brake() const {
        std::cout << "You step on the brakes!\n";
    }

    Color get_color() const {
        return color;
    }

    void show_secret(int password = 0) const {
        if (password == 123) std::cout << secret << '\n';
        else std::cout << "Wrong password!\n";
    }
};

class Transformer : public Car {
public:
    std::string name;

    explicit Transformer(std::string name_)
        : Car(Color::YELLOW), name(std::move(name_)) {}

    void introduce() const {
        std::cout << "Beware! Maybe I am not only a miserable car!\n";
        std::cout << "I am " << name << "!\n";
    }
};

static void print_car(const Car& c) {
    std::cout << "{ make: " << c.make
              << ", model: " << c.model
              << ", year: " << c.year
              << ", color: " << color_name(c.color)
              << " }\n";
}

static void print_array(const std::vector<int>& v) {
    std::cout << "[";
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << "]";
}

int main() {
    std::cout << app::introduction;
    std::cout << ::GLOBAL_VAR;

    int numbers[] = {9, 5, 1, 2, 6, 0, 4, 7, 8, 3};

    std::vector<Car> cars = {
        Car{"ford", "mustang", 1972, Color::BLUE},
        Car{"fiat", "uno",     1997, Color::GREEN},
        Car{"vw",   "gol",     2010, Color::RED},
    };

    Transformer transformer1("Bumblebee");

    std::cout << "\nIndex-based for on C-style array:\n";
    for (std::size_t i = 0; i < std::size(numbers); ++i) {
        std::cout << "numbers[" << i << "]=" << numbers[i] << "\n";
    }

    std::cout << "\nRange-based for by value (copy) on array:\n";
    for (int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "\nRange-based for by const reference on vector<Car>:\n";
    for (const Car& c : cars) {
        print_car(c);
    }

    std::cout << "\nRange-based for by reference (mutates): add 1 year to all:\n";
    for (Car& c : cars) {
        c.year += 1;
    }
    for (const Car& c : cars) {
        print_car(c);
    }

    std::cout << "\nRange-based for by value on Car (does not mutate originals):\n";
    for (Car c : cars) {
        c.year += 100;
    }
    std::cout << "After the loop, the original vector is unchanged:\n";
    for (const Car& c : cars) {
        print_car(c);
    }

    std::cout << "\nIterator-based for:\n";
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        std::cout << it->model << " (" << color_name(it->color) << ")\n";
    }

    std::cout << "\nBreak/continue: find the first BLUE car:\n";
    const Car* first_blue = nullptr;
    for (const Car& c : cars) {
        if (c.color != Color::BLUE) continue;
        first_blue = &c;
        break;
    }
    if (first_blue) {
        std::cout << "Found: " << first_blue->model << "\n";
    } else {
        std::cout << "No BLUE car found.\n";
    }

    std::cout << "\nFor with two variables (i++, j--):\n";
    for (std::size_t i = 0, j = std::size(numbers) - 1; i < j; ++i, --j) {
        std::cout << "i=" << i << " (" << numbers[i] << "), "
                  << "j=" << j << " (" << numbers[j] << ")\n";
    }

    std::cout << "\nTransformer:\n";
    transformer1.introduce();
    transformer1.show_secret(123);

    std::vector<int> nums(std::begin(numbers), std::end(numbers));
    std::cout << "\nNumbers as vector: ";
    print_array(nums);
    std::cout << "\n";

    return 0;
}
