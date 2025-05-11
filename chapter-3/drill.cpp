#include <iostream>

int main() {
    bool terminate = false;
    while (!terminate) {
        char inp;
        double a, b;
        std::cout << "Input two digits separated with a space: ";
        std::cin >> a >> b;
        if (a == b) {
            std::cout << "The numbers are equal" << '\n';
        } else {
            const double smaller = std::min(a, b);
            const double bigger = std::max(a, b);
            std::cout << "The smaller value is: " << smaller << '\n';
            std::cout << "The bigger value is: " << bigger << '\n';
            if ((bigger - smaller) < (1.0 / 100)) {
                std::cout << "Almost equal!" << '\n';
            }
        };
        std::cout << "Do you wanna exit (y/n)? ";
        std::cin >> inp;
        if (inp == 'y') terminate = true;
    }
    std::cout << "Exited the loop" << '\n';
    return 0;
}
