#include <iostream>

int main() {
    std::cout << "Write a digit: ";
    char ch;
    int val = 0;
    try {
        while (std::cin) {
            std::cin >> ch;
            if (ch == 'q') {
                break;
            }
            if (ch == ';') {
                if (val > 9999) throw std::invalid_argument("Value should be 4 digits max");
                const int thousands = val / 1000;
                const int hundreds = (val % 1000) / 100;
                const int tens = (val % 100) / 10;
                const int ones = val % 10;
                std::cout << val << " is ";
                std::cout << thousands << " thousands " << hundreds << " hundreds " << tens << " tens " << ones <<
                        " ones "
                        << std::endl;
                break;
            }
            switch (ch) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9': {
                    std::cin.putback(ch);
                    std::cin >> val;
                    // val = val * 10 + (ch - '0');
                    break;
                }
                default:
                    throw std::invalid_argument("Bad input");
            }
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
