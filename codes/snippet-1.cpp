#include <iostream>
#include <string>
#include <array>

struct Tracked {
    std::string s;

    static inline int copies = 0;
    static inline int moves  = 0;

    Tracked(const char* v) : s(v) {}

    Tracked(const Tracked& other) : s(other.s) {
        ++copies;
        std::cout << "[COPY]  \"" << s << "\"\n";
    }

    Tracked(Tracked&& other) noexcept : s(std::move(other.s)) {
        ++moves;
        std::cout << "[MOVE]\n";
    }

    static void reset() { copies = 0; moves = 0; }
};

int main() {
    std::array<Tracked, 3> names = { "Rafael", "Gabriel", "Pastel" };

    Tracked::reset();
    std::cout << "\n--- for (auto n : names) ---\n";
    for (auto n : names) {
        std::cout << n.s << " ";
    }
    std::cout << "\nCopies=" << Tracked::copies << " Moves=" << Tracked::moves << "\n";

    Tracked::reset();
    std::cout << "\n--- for (const auto& n : names) ---\n";
    for (const auto& n : names) {
        std::cout << n.s << " ";
    }
    std::cout << "\nCopies=" << Tracked::copies << " Moves=" << Tracked::moves << "\n";

    Tracked::reset();
    std::cout << "\n--- for (auto& n : names) ---\n";
    for (auto& n : names) {
        n.s += "!";
    }
    for (const auto& n : names) {
        std::cout << n.s << " ";
    }
    std::cout << "\nCopies=" << Tracked::copies << " Moves=" << Tracked::moves << "\n";
}
