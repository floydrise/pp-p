#include <iostream>
#include <algorithm>

int main() {
    // declare vector and take input
    std::vector<double> temps;
    std::cout << "Input temperatures and terminate with a non-number value: ";
    for (double temp; std::cin >> temp;) {
        temps.push_back(temp);
    }

    if (temps.size() == 0) {
        std::cerr << "No temps in the vector, terminating!" << '\n';
        return EXIT_FAILURE;
    }

    double sum = 0;
    for (double temp: temps) {
        sum += temp;
    }
    std::cout << "Average temperature is: " << sum / temps.size() << '\n';
    std::sort(temps.begin(), temps.end());
    std::cout << "The median temperature is:" << temps[temps.size() / 2] << '\n';

    return EXIT_SUCCESS;
}
