#include <iostream>

namespace my_namespace {
    void skip_to_int() {
        if (std::cin.fail()) {
            std::cin.clear();
            for (char ch; std::cin >> ch;) {
                if (isdigit(ch) || ch == '-') {
                    std::cin.unget();
                    return;
                }
            }
        }
        throw std::invalid_argument("no input");
    }

    int get10() {
        std::cout << "Please write a number between 1 and 10: ";
        int n = 0;
        while (true) {
            std::cin >> n;
            if (std::cin) {
                if (n >= 1 && n <= 10) return n;
                std::cout << "Sorry " << n << " " << "is not in the [1:10] range, please try again: ";
            } else {
                std::cout << "Sorry that was not a number, please try again: ";
                skip_to_int();
            }
        }
    }

    int get_int() {
        int n = 0;
        while (true) {
            if (std::cin >> n) {
                return n;
            }
            std::cout << "Sorry that's not a number, please try again: ";
            skip_to_int();
        }
    }

    int get_int(const int low, const int high, const std::string &greeting, const std::string &sorry) {
        std::cout << greeting << "[" << low << ", " << high << "]: ";
        while (true) {
            const int n = get_int();
            if (n >= low && n <= high) return n;
            std::cout << sorry << ": [" << low << ':' << high << "]\n";
        }
    }
}

int main() {
    try {
        const int strength = my_namespace::get_int(1, 10, "enter strength", "Not in range, try again");
        std::cout << "Strength: " << strength << '\n';
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
