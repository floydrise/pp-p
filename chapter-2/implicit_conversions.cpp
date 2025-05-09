#include <iostream>

int main() {
    double d;
    while (std::cin >> d) {
        int i = d;
        char c = i;
        std::cout << "d == " << d << " i == " << i << " c == " << c << " char(" << c << ")\n";
    }
    return 0;
}
