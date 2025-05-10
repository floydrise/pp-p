#include <iostream>

int main() {
    static constexpr double y_to_d = 0.0069;
    constexpr double k_to_d = 0.096;
    constexpr double p_to_d = 1.33;
    char currency;
    double amount = 1;
    double result = 0;

    std::cout << "Please enter amount followed by currency ('y', 'k', 'p') separated with a space: ";
    std::cin >> amount >> currency;

    switch (currency) {
        case 'y':
            result = amount * y_to_d;
            break;
        case 'k':
            result = amount * k_to_d;
            break;
        case 'p':
            result = amount * p_to_d;
            break;
        default:
            result = 0;
    }

    std::cout << "Result from conversion is: " << result << '\n';
    return 0;
}
