#include <iostream>

int main() {
    char currency;
    double amount = 1;
    double result = 0;
    std::cout << "Please enter amount followed by currency ('y', 'k', 'p') separated with a space: ";
    std::cin >> amount >> currency;
    if (currency == 'y') {
        static constexpr double y_to_d = 0.0069;
        result = amount * y_to_d;
    } else if (currency == 'k') {
        constexpr double k_to_d = 0.096;
        result = amount * k_to_d;
    } else if (currency == 'p') {
        constexpr double p_to_d = 1.33;
        result = amount * p_to_d;
    } else {
        result = 0;
    }
    std::cout << "Result from conversion is: " << result << '\n';
    return 0;
}
